#include <iostream>
#include <string>
#include <cctype> // para toupper()
using namespace std;

int main() {

    string questions[] = {
        "1. What is the capital of France?",
        "2. What is 2 + 2?",
        "3. What is the largest planet in our solar system?",
        "4. Who wrote 'Romeo and Juliet'?",
        "5. What is the boiling point of water in Celsius?"
    };

    string answers[][4] = {
        {"1. Paris", "2. London", "3. Berlin", "4. Madrid"},
        {"1. 3", "2. 4", "3. 5", "4. 6"},
        {"1. Earth", "2. Jupiter", "3. Saturn", "4. Mars"},
        {"1. Charles Dickens", "2. Mark Twain", "3. William Shakespeare", "4. Jane Austen"},
        {"1. 90°C", "2. 100°C", "3. 110°C", "4. 120°C"}
    };

    char correctAnswers[] = {'1', '2', '2', '3', '2'};

    int size = sizeof(questions) / sizeof(questions[0]);
    char guess;
    int score = 0;

    cout << "Hello, Quiz Game!" << endl;

    for(int i = 0; i < size; i++) {
        cout << "\n" << questions[i] << endl;
        
        for(int j = 0; j < 4; j++) {
            cout << answers[i][j] << endl;
        }
        
        cout << "Your answer: ";
        cin >> guess;
        guess = toupper(guess);

        if(guess == correctAnswers[i]) {
            cout << "Correct!" << endl;
            score++;
        } else {
            cout << "Wrong! Correct answer was: " << correctAnswers[i] << endl;
        }
    }

    cout << "\nYour score is: " << score << " out of " << size << endl;
    cout << "Thanks for playing!" << endl;

    return 0;
}
