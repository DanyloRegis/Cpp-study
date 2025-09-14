#include <iostream>
using namespace std;

class Human {
private:
    string name;
    int age;
    
public:
    
    Human() : name("Unknown"), age(0) {}
    
  
    Human(string n, int a) : name(n), age(a) {}
    
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    
    void introduce() {
        cout << "Hello, my name is " << name << " and I am " << age << " years old." << endl;
    }
};

int main() {
    Human person1;
    person1.introduce();
    
    Human person2("Alice", 30);
    person2.introduce();        
    return 0;
}