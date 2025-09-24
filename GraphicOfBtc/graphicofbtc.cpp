#include <SFML/Graphics.hpp>
#include <curl/curl.h>
#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
#include <chrono>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <ctime>

// Callback para receber dados do curl
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* data) {
    size_t totalSize = size * nmemb;
    data->append((char*)contents, totalSize);
    return totalSize;
}

class BitcoinChart {
private:
    sf::RenderWindow window;
    std::vector<float> prices;
    std::mutex dataMutex;
    bool running;
    float currentPrice;
    sf::Font font;
    bool fontLoaded;
    
public:
    BitcoinChart() : window(sf::VideoMode(1000, 600), "Bitcoin Price - Tempo Real"), 
                    running(true), currentPrice(0.0f), fontLoaded(false) {
        prices.resize(500, 0.0f);
        
        // Tenta carregar várias fontes possíveis
        std::vector<std::string> fontPaths = {
            "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf",
            "/usr/share/fonts/truetype/liberation/LiberationSans-Regular.ttf",
            "/usr/share/fonts/truetype/freefont/FreeSans.ttf",
            "/usr/share/fonts/truetype/ubuntu/Ubuntu-R.ttf"
        };
        
        for (const auto& path : fontPaths) {
            if (font.loadFromFile(path)) {
                fontLoaded = true;
                std::cout << "Fonte carregada: " << path << std::endl;
                break;
            } else {
                std::cout << "Failed to load font: " << path << std::endl;
            }
        }
        
        if (!fontLoaded) {
            std::cout << "Nenhuma fonte encontrada. Texto não será exibido." << std::endl;
        }
    }
    
    // Busca o preço do Bitcoin
    bool fetchBitcoinPrice() {
        CURL* curl;
        CURLcode res;
        std::string response;
        
        curl = curl_easy_init();
        if (!curl) {
            std::cerr << "Erro ao inicializar CURL" << std::endl;
            return false;
        }
        
        // API mais simples e confiável
        std::string url = "https://api.coingecko.com/api/v3/simple/price?ids=bitcoin&vs_currencies=usd";
        
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0");
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        
        res = curl_easy_perform(curl);
        
        if (res != CURLE_OK) {
            std::cerr << "Erro CURL: " << curl_easy_strerror(res) << std::endl;
            curl_easy_cleanup(curl);
            return false;
        }
        
        long http_code = 0;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
        curl_easy_cleanup(curl);
        
        if (http_code != 200) {
            std::cerr << "HTTP Error: " << http_code << std::endl;
            std::cerr << "Response: " << response << std::endl;
            return false;
        }
        
        std::cout << "API Response: " << response << std::endl;
        return parseBitcoinPrice(response);
    }
    
    // Parse da resposta JSON - versão mais robusta
    bool parseBitcoinPrice(const std::string& json) {
        std::cout << "Parsing JSON: " << json << std::endl;
        
        try {
            // Limpa espaços e quebras de linha
            std::string cleanJson;
            for (char c : json) {
                if (c != ' ' && c != '\n' && c != '\r' && c != '\t') {
                    cleanJson += c;
                }
            }
            
            std::cout << "Cleaned JSON: " << cleanJson << std::endl;
            
            // Procura pelo padrão "usd":número
            size_t usdPos = cleanJson.find("\"usd\":");
            if (usdPos == std::string::npos) {
                std::cerr << "Padrão 'usd:' não encontrado" << std::endl;
                return false;
            }
            
            // Encontra o início do número
            size_t numStart = usdPos + 5; // depois de "usd":
            while (numStart < cleanJson.length() && 
                  (cleanJson[numStart] == ' ' || cleanJson[numStart] == ':')) {
                numStart++;
            }
            
            // Encontra o fim do número
            size_t numEnd = numStart;
            while (numEnd < cleanJson.length() && 
                  (isdigit(cleanJson[numEnd]) || cleanJson[numEnd] == '.')) {
                numEnd++;
            }
            
            if (numStart >= numEnd) {
                std::cerr << "Número não encontrado após 'usd:'" << std::endl;
                return false;
            }
            
            std::string priceStr = cleanJson.substr(numStart, numEnd - numStart);
            std::cout << "Price string: '" << priceStr << "'" << std::endl;
            
            if (priceStr.empty()) {
                std::cerr << "String do preço vazia" << std::endl;
                return false;
            }
            
            float priceUSD = std::stof(priceStr);
            std::cout << "Parsed price: " << priceUSD << std::endl;
            
            {
                std::lock_guard<std::mutex> lock(dataMutex);
                currentPrice = priceUSD;
                
                // Adiciona ao histórico
                if (prices.size() >= 500) {
                    std::rotate(prices.begin(), prices.begin() + 1, prices.end());
                    prices[prices.size() - 1] = priceUSD;
                } else {
                    prices.push_back(priceUSD);
                }
            }
            
            std::cout << "BTC: $" << priceUSD << std::endl;
            return true;
            
        } catch (const std::exception& e) {
            std::cerr << "Erro no parse: " << e.what() << std::endl;
            return false;
        }
    }
    
    // Desenha texto
    void drawText(const std::string& text, float x, float y, int size, sf::Color color) {
        if (fontLoaded) {
            sf::Text sfText;
            sfText.setFont(font);
            sfText.setString(text);
            sfText.setCharacterSize(size);
            sfText.setFillColor(color);
            sfText.setPosition(x, y);
            window.draw(sfText);
        }
        // Sem fallback - já mostramos no console
    }
    
    void drawChart() {
        window.clear(sf::Color(20, 20, 35));
        
        std::lock_guard<std::mutex> lock(dataMutex);
        
        if (currentPrice == 0.0f) {
            if (fontLoaded) {
                drawText("Buscando dados do Bitcoin...", 350, 280, 24, sf::Color::White);
            }
            window.display();
            return;
        }
        
        // Encontra min e max para escala
        auto validPrices = prices;
        validPrices.erase(std::remove(validPrices.begin(), validPrices.end(), 0.0f), validPrices.end());
        
        if (validPrices.empty()) {
            window.display();
            return;
        }
        
        float minPrice = *std::min_element(validPrices.begin(), validPrices.end());
        float maxPrice = *std::max_element(validPrices.begin(), validPrices.end());
        float priceRange = std::max(maxPrice - minPrice, 100.0f);
        
        // Desenha grade e eixos
        drawGrid(minPrice, maxPrice, priceRange);
        
        // Desenha linha do gráfico
        drawPriceLine(minPrice, priceRange);
        
        // Desenha informações
        drawInfoPanel(minPrice, maxPrice);
        
        window.display();
    }
    
    void drawGrid(float minPrice, float maxPrice, float priceRange) {
        // Eixos principais
        sf::VertexArray axes(sf::Lines, 4);
        axes[0] = sf::Vertex(sf::Vector2f(80, 50), sf::Color::White);
        axes[1] = sf::Vertex(sf::Vector2f(80, 520), sf::Color::White);
        axes[2] = sf::Vertex(sf::Vector2f(80, 520), sf::Color::White);
        axes[3] = sf::Vertex(sf::Vector2f(920, 520), sf::Color::White);
        window.draw(axes);
        
        // Grade horizontal
        for (int i = 0; i <= 5; ++i) {
            float y = 520 - (470.0f * i / 5);
            sf::VertexArray line(sf::Lines, 2);
            line[0] = sf::Vertex(sf::Vector2f(80, y), sf::Color(100, 100, 100, 100));
            line[1] = sf::Vertex(sf::Vector2f(920, y), sf::Color(100, 100, 100, 100));
            window.draw(line);
            
            if (fontLoaded) {
                float price = minPrice + (priceRange * i / 5);
                std::stringstream ss;
                ss << std::fixed << std::setprecision(0) << "$" << price;
                drawText(ss.str(), 10, y - 10, 12, sf::Color::White);
            }
        }
    }
    
    void drawPriceLine(float minPrice, float priceRange) {
        sf::VertexArray line(sf::LineStrip, 0);
        
        for (size_t i = 0; i < prices.size(); ++i) {
            if (prices[i] == 0.0f) continue;
            
            float x = 80 + (i * 840.0f / prices.size());
            float y = 520 - ((prices[i] - minPrice) / priceRange * 470.0f);
            
            line.append(sf::Vertex(sf::Vector2f(x, y), 
                (i > 0 && prices[i] >= prices[i-1]) ? sf::Color::Green : sf::Color::Red));
        }
        
        if (line.getVertexCount() > 0) {
            window.draw(line);
        }
    }
    
    void drawInfoPanel(float minPrice, float maxPrice) {
        if (!fontLoaded) return;
        
        std::stringstream priceSS;
        priceSS << std::fixed << std::setprecision(2) << "BTC: $" << currentPrice;
        drawText(priceSS.str(), 300, 10, 24, sf::Color::Yellow);
        
        std::stringstream stats;
        stats << std::fixed << std::setprecision(2);
        stats << "Min: $" << minPrice << " | Max: $" << maxPrice;
        drawText(stats.str(), 300, 50, 16, sf::Color::Cyan);
        
        std::time_t t = std::time(nullptr);
        std::tm* now = std::localtime(&t);
        char timeStr[100];
        std::strftime(timeStr, sizeof(timeStr), "Atualizado: %H:%M:%S", now);
        drawText(timeStr, 300, 550, 14, sf::Color::White);
    }
    
    void dataFetchThread() {
        curl_global_init(CURL_GLOBAL_DEFAULT);
        
        std::cout << "Thread de dados iniciada..." << std::endl;
        
        // Primeira tentativa imediata
        fetchBitcoinPrice();
        
        while (running) {
            fetchBitcoinPrice();
            
            // Espera 60 segundos entre atualizações (mais tempo para API gratuita)
            for (int i = 0; i < 60 && running; ++i) {
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        }
        
        curl_global_cleanup();
        std::cout << "Thread de dados finalizada." << std::endl;
    }
    
    void run() {
        std::thread dataThread(&BitcoinChart::dataFetchThread, this);
        
        std::cout << "Monitor Bitcoin iniciado. Pressione X ou ESC para fechar." << std::endl;
        
        sf::Clock clock;
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed || 
                   (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                    running = false;
                    window.close();
                }
            }
            
            drawChart();
            sf::sleep(sf::milliseconds(50));
        }
        
        running = false;
        if (dataThread.joinable()) {
            dataThread.join();
        }
        
        std::cout << "Programa finalizado." << std::endl;
    }
};

int main() {
    std::cout << "=== Monitor de Preço do Bitcoin ===" << std::endl;
    
    BitcoinChart chart;
    chart.run();
    
    return 0;
}