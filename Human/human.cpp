#include <iostream>
using namespace std;

class Human {
private:
    string name;
    int age;
    
public:
    // Construtor padrão (adicionado)
    Human() : name("Unknown"), age(0) {}
    
    // Construtor com parâmetros
    Human(string n, int a) : name(n), age(a) {}
    
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    
    void introduce() {
        cout << "Hello, my name is " << name << " and I am " << age << " years old." << endl;
    }
};

int main() {
    Human person1; // Usando o construtor padrão
    person1.introduce();
    
    Human person2("Alice", 30); // Usando o construtor com parâmetros
    person2.introduce();        
    return 0;
}