#include "Bank.h"
#include <iostream>
#include <limits>
using namespace std;
Bank::Bank(){
    nextAccountNumber = 1001;
}
long long Bank::generateAccountNumber(){
    return nextAccountNumber++;
}
void Bank::createAccount() {
    string name;
    double initialBalance;

    cout << "\nEnter Customer Name: ";
    getline(cin >> ws, name);

    cout << "Enter Initial Balance: Rs. ";
    cin >> initialBalance;

    if (cin.fail() || initialBalance < 0) {
        cout << "Invalid initial balance.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    long long number = generateAccountNumber();

    Account newAccount(name, number, initialBalance);

    accounts.push_back(newAccount);

    cout << "\nAccount created successfully!\n";
    cout << "Your Account Number is: " << number << endl;
}

// Search Account
void Bank::searchAccount() {
    long long number;

    cout << "\nEnter Account Number: ";
    cin >> number;

    for (const Account& acc : accounts) {
        if (acc.getAccountNumber() == number) {
            acc.displayDetails();
            return;
        }
    }

    cout << "Account not found.\n";
}

// Display All Accounts
void Bank::displayAllAccounts() {
    if (accounts.empty()) {
        cout << "\nNo accounts available.\n";
        return;
    }

    for (const Account& acc : accounts) {
        acc.displayDetails();
    }
}
Account* Bank::findAccount(long long accountNumber) {
    for (Account& acc : accounts) {
        if (acc.getAccountNumber() == accountNumber) {
            return &acc;
        }
    }

    return nullptr;
}