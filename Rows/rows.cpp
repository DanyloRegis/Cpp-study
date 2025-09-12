#include <iostream>
using namespace std;

int main() {

    int rows,columns;
    char symbol;

    cout << "How many rows do you want?" << endl;
    cin >> rows;

    cout << "How many columns do you want?" << endl;
    cin >> columns;

    cout << "What symbool do you want to use ?" << endl;
    cin >> symbol;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            cout << symbol;
        }
        cout << endl;
    }

    return 0;
}