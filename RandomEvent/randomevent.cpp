#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    
    // Gera número de 1 a 10
    // 1-7: prêmios, 8-10: não ganha nada
    int randNum = rand() % 10 + 1;

    switch (randNum) {
        case 1:
            cout << "You win a new car!" << endl;
            break;
        case 2:
            cout << "You win a new boat!" << endl;
            break;  
        case 3:
            cout << "You win a new cat!" << endl;
            break;
        case 4:
            cout << "You win a new dog!" << endl;
            break;
        case 5:
            cout << "You win a new house!" << endl; 
            break;
        case 6:
            cout << "You win a new laptop!" << endl;
            break;
        case 7:
            cout << "You win a new phone!" << endl;
            break;
        default:
            cout << "Sorry, you didn't win anything this time." << endl;
            break;
    }

    return 0;
}