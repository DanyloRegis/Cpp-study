#include <iostream>
#include <ctime>
using namespace std;

void dredBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWin(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main() {
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool gameOver = false;

    srand(time(0)); // inicializa a semente do rand uma vez só

    cout << "Welcome to Tic Tac Toe!" << endl;
    cout << "You are X and the computer is O." << endl;
    dredBoard(spaces);

    while (!gameOver) {
        cout << "Your turn..." << endl;
        playerMove(spaces, player);

        if (checkWin(spaces, player, computer)) {
            gameOver = true;
            break;
        }
        if (checkTie(spaces)) {
            cout << "It's a tie!" << endl;
            gameOver = true;
            break;
        }

        cout << "Computer's turn..." << endl;
        computerMove(spaces, computer);

        if (checkWin(spaces, player, computer)) {
            gameOver = true;
            break;
        }
        if (checkTie(spaces)) {
            cout << "It's a tie!" << endl;
            gameOver = true;
            break;
        }
    }

    return 0;
}

void dredBoard(char *spaces) {
    cout << " " << spaces[0] << " | " << spaces[1] << " | " << spaces[2] << " " << endl;
    cout << "---|---|---" << endl;
    cout << " " << spaces[3] << " | " << spaces[4] << " | " << spaces[5] << " " << endl;
    cout << "---|---|---" << endl;
    cout << " " << spaces[6] << " | " << spaces[7] << " | " << spaces[8] << " " << endl;
}

void playerMove(char *spaces, char player) {
    int move;
    cout << "Enter your move (1-9): ";
    cin >> move;
    move--;
    if (move < 0 || move > 8 || spaces[move] != ' ') {
        cout << "Invalid move! Try again." << endl;
        playerMove(spaces, player);
    } else {
        spaces[move] = player;
        dredBoard(spaces);
    }
}

void computerMove(char *spaces, char computer) {
    int move = rand() % 9;
    if (spaces[move] != ' ') {
        computerMove(spaces, computer);
    } else {
        spaces[move] = computer;
        dredBoard(spaces);
    }
}

bool checkWin(char *spaces, char player, char computer) {

    if ((spaces[0] == player && spaces[1] == player && spaces[2] == player) ||
        (spaces[3] == player && spaces[4] == player && spaces[5] == player) ||
        (spaces[6] == player && spaces[7] == player && spaces[8] == player) ||
        (spaces[0] == player && spaces[3] == player && spaces[6] == player) ||
        (spaces[1] == player && spaces[4] == player && spaces[7] == player) ||
        (spaces[2] == player && spaces[5] == player && spaces[8] == player) ||
        (spaces[0] == player && spaces[4] == player && spaces[8] == player) ||
        (spaces[2] == player && spaces[4] == player && spaces[6] == player)) {
        cout << "You win!" << endl;
        return true;
    }

    // Verifica se computador ganhou
    if ((spaces[0] == computer && spaces[1] == computer && spaces[2] == computer) ||
        (spaces[3] == computer && spaces[4] == computer && spaces[5] == computer) ||
        (spaces[6] == computer && spaces[7] == computer && spaces[8] == computer) ||
        (spaces[0] == computer && spaces[3] == computer && spaces[6] == computer) ||
        (spaces[1] == computer && spaces[4] == computer && spaces[7] == computer) ||
        (spaces[2] == computer && spaces[5] == computer && spaces[8] == computer) ||
        (spaces[0] == computer && spaces[4] == computer && spaces[8] == computer) ||
        (spaces[2] == computer && spaces[4] == computer && spaces[6] == computer)) {
        cout << "Computer wins!" << endl;
        return true;
    }

    return false;
}

bool checkTie(char *spaces) {
    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') {
            return false; 
        }
    }
    return true;
}
