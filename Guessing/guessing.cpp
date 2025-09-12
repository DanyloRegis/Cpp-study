#include <iostream>
#include <cstdlib>
#include <ctime>  // Necessário para time(NULL)
using namespace std;

int main() {

    int num, guess, tries;

    srand(time(NULL));
    num = (rand() % 10 + 1);

    tries = 3;

    cout << "Welcome to the Guessing Game!" << endl;

    do {
        cout << "You have " << tries << " tries left." << endl;
        cout << "Enter your guess (1-10): ";
        cin >> guess;
        tries--;

        if (guess == num) {
            cout << "Congratulations! You guessed the number!" << endl;
            break;
        } else if (tries == 0) {
            cout << "Sorry, you've run out of tries. The number was " << num << "." << endl;
            break;
        } else if (guess < num) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Too high! Try again." << endl;
        }
    } while (true);  // Condição corrigida
    

    return 0;
}