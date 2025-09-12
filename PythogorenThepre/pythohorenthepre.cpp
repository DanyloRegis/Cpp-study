#include <iostream>
#include <cmath>
#include <iomanip>
#include <ratio>

using namespace std;

double theorem(double a, double b);

int main() {
    double a, b, c;
    cout << "Enter side a: ";
    cin >> a;
    cout << "Enter side b: ";
    cin >> b;
    c = theorem(a, b);
    cout << "Hipotenuse is: " << fixed << setprecision(2) << c << endl;
    return 0;
}

double theorem(double a, double b) {
    return sqrt(a * a + b * b);
}
