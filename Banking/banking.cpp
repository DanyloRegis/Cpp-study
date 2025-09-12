#include <iostream>
#include <iomanip>

using namespace std;
void showBalance(double balance);
double Deposit(double balance, double amount);
double Withdraw(double balance, double cash);

int main() {
    double balance = 0;
    double cash, amount;
    int option;

    
    do
    {

        cout << "Welcome to the Banking System!" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Exit" << endl;
        cin >> option;

            switch (option) {
        
            cout << "Withdrew: $" << cash << endl;    case 1:
                showBalance(balance);
                break;
            case 2:
                cout << "Enter amount to deposit: $";
                cin >> amount;
                balance = Deposit(balance, amount);
                break;
            case 3:
                cout << "Enter amount to withdraw: $";
                cin >> cash;
                balance = Withdraw(balance, cash);
                break;
            case 4:
                cout << "Thank you for using the Banking System. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (option != 4);
    
    
    return 0;
}

void showBalance(double balance) {
    cout << "Current Balance: $" << setprecision(2) << fixed << balance << endl;
}

double Deposit(double balance, double amount) {
    balance += amount;
    cout << "Deposited: $" << setprecision(2) << fixed << amount << endl;
    cout << "New Balance: $" << balance << endl;
    return balance;
}

double Withdraw(double balance, double cash) {
    if (cash > balance) {
        cout << "Insufficient funds. Withdrawal failed." << endl;
    } else {
        balance -= cash;
        cout << "Withdrew: $" << setprecision(2) << fixed << cash << endl;
        cout << "New Balance: $" << setprecision(2) << fixed << balance << endl;
    }
    return balance;
}
