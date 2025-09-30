#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int main() {
    // Create the game window
    RenderWindow window(VideoMode(800, 600), "Zelda Triforce Test");

    // Load the texture (your sprite sheet)
    Texture texture;
    if (!texture.loadFromFile("sprites/zelda.png")) { // rename your file to zelda.png
        std::cerr << "Error: could not load sprite sheet!" << std::endl;
        return -1;
    }

    // Create a sprite using only the Triforce part of the sheet
    Sprite triforce(texture);

    // Select the part of the texture (x, y, width, height)
    triforce.setTextureRect(IntRect(530, 400, 64, 64));
    triforce.setPosition(200, 200);

    // Main game loop
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        // Clear the screen
        window.clear(Color::Black);

        // Draw only the Triforce
        window.draw(triforce);

        // Display the frame
        window.display();
    }

    return 0;
}
