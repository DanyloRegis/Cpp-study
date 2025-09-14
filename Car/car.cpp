#include <iostream>
using namespace std;

struct Car {  // Correção: "struct" em vez de "sturct"
    string make;
    string model;
    int year;

    void displayInfo() {
        cout << year << " " << make << " " << model << endl;
    }
};

int main(){

    Car car01;
    Car car02;

    car01.make = "Toyota";
    car01.model = "Corolla";
    car01.year = 2020;
    car01.displayInfo();

    car02.make = "Honda";
    car02.model = "Civic";
    car02.year = 2019;
    car02.displayInfo();

    return 0;
}
