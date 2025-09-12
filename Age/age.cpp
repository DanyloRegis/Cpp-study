#include <iostream>
using namespace std;
int main(){
    string name;
    cout << "Enter your name: ";
    cin >> name;
    double age;
    cout << "Enter your age: ";
    cin >> age;

    cout << "Hello " << name << ", you are " << age << " years old" << endl;

    if (age == 18){
        cout << "Wecome to adulthood site! " << endl
                << "You are just 18!" << endl;  
    }else if(age <0){
        cout << "You haven't been born yet, dude!" << endl;
    }else {
        cout << "You are an adult!" << endl;
    }

    return 0;
}