#include <iostream>
using namespace std;

int main() {

    char op;
    double num1, num2,reult;

    cout << "The Calculator" << endl;

    cout << "Enter operator (+,-,*,/): ";
    cin >> op;

    cout << "Enter #1: ";
    cin >> num1;

    cout << "Enter #2: ";
    cin >> num2;


    switch(op) {
        case '+':
            reult = num1 + num2;
            cout << num1 << " + " << num2 << " = " << reult;
            break;

        case '-':
            reult = num1 - num2;
            cout << num1 << " - " << num2 << " = " << reult;
            break;

        case '*':
            reult = num1 * num2;
            cout << num1 << " * " << num2 << " = " << reult;
            break;

        case '/':
            if(num2 != 0) {
                reult = num1 / num2;
                cout << num1 << " / " << num2 << " = " << reult;
            } else {
                cout << "Error: Division by zero!";
            }
            break;

        default:
            cout << "Error: Invalid operator!";
            break;
    }






  return 0;
}