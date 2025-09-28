#include <iostream>
using namespace std;

void modifyByValue(int x, int y);
void modifyByReference(int &x, int &y);

int main() {
    int a = 5;
    int b = 10;

    cout << "Before modifyByValue: a = " << a << ", b = " << b << endl;
    modifyByValue(a, b);
    cout << "After modifyByValue: a = " << a << ", b = " << b << endl;

    cout << "Before modifyByReference: a = " << a << ", b = " << b << endl;
    modifyByReference(a, b);
    cout << "After modifyByReference: a = " << a << ", b = " << b << endl;

    return 0;
}

void modifyByValue(int x, int y) {
    x += 10;
    y += 20;
}

void modifyByReference(int &x, int &y) {
    x += 10;
    y += 20;
}
