#include <iostream>
using namespace std;

int main(){

    int var = 20;
    int *ptr; // Pointer declaration
    ptr = &var; // Pointer initialization with the address of var
    int &ref = var; // Reference declaration and initialization
    int* anotherPtr; // Another pointer initialized to nullptr
    anotherPtr = new int; // Dynamically allocating memory for an integer
    int anotherRef = *anotherPtr; // Reference to the dynamically allocated integer
    cout << "Value of var: " << var << endl;
    cout << "Value via pointer: " << *ptr << endl; // Dereferencing pointer
    cout << "Value via reference: " << ref << endl; // Using reference
    cout << "Address of var: " << &var << endl;
    cout << "Address stored in pointer: " << ptr << endl;
    cout << "Address of reference: " << &ref << endl; // Address of the
    cout << "Value of anotherRef (uninitialized): " << anotherRef << endl; // Undefined behavior





    return 0;
}