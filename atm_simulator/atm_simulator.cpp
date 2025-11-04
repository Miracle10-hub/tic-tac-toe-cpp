
#include <iostream>
using namespace std;

double balance = 1000.0; // Starting balance
int pin = 1234;

void checkBalance() {
    cout << "Your balance is: R" << balance << "\n\n";
}

void depositMoney() {
    double amount;
    cout << "Enter amount to deposit: R";
    cin >> amount;
    if(amount > 0) {
        balance += amount;
        cout << "Deposit successful. New balance: R" << balance << "\n\n";
    } else {
        cout << "Invalid amount.\n\n";
    }
}

void withdrawMoney() {
    double amount;
    cout << "Enter amount to withdraw: R";
    cin >> amount;
    if(amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Withdrawal successful. New balance: R" << balance << "\n\n";
    } else {
        cout << "Invalid amount or insufficient balance.\n\n";
    }
}

int main() {
    int enteredPin;
    cout << "Welcome to the ATM Simulator\n";
    cout << "Enter your PIN: ";
    cin >> enteredPin;

    if(enteredPin != pin) {
        cout << "Incorrect PIN. Exiting...\n";
        return 0;
    }

    int choice;
    do {
        cout << "\nATM Menu:\n";
        cout << "1. Check Balance\n2. Deposit\n3. Withdraw\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: checkBalance(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: cout << "Thank you for using ATM Simulator.\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while(choice != 4);

    return 0;
}
