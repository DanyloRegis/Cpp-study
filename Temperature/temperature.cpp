#include <iostream>
using namespace std;

int main() {
    char unit;
    double temp, convertedTemp;

    cout << "Temperature Converter" << endl;
    cout << "Enter temperature unit (C for Celsius, F for Fahrenheit): ";
    cin >> unit;
    
    // Converter para maiúsculo para aceitar 'c' e 'C'
    unit = toupper(unit);
    
    cout << "Enter temperature value: ";
    cin >> temp;

    // Fazer a mesma coisa para C e F (ambos convertem para a outra unidade)
    if (unit == 'C' || unit == 'F') {
        if (unit == 'C') {
            convertedTemp = (temp * 9/5) + 32; // Celsius para Fahrenheit
            cout << temp << "°C = " << convertedTemp << "°F" << endl;
        } else {
            convertedTemp = (temp - 32) * 5/9; // Fahrenheit para Celsius
            cout << temp << "°F = " << convertedTemp << "°C" << endl;
        }
    } else {
        cout << "Invalid unit! Please enter C or F." << endl;
    }

    return 0;
}