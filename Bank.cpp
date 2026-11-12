
#include "Bank.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>

using namespace std;

Bank::Bank() {
    nextAccountNumber = 1001;
    loadAccounts();
}

// Generate unique account number
long long Bank::generateAccountNumber() {
    return nextAccountNumber++;
}

// Save all account details into a file
void Bank::saveAccounts() const {
    ofstream file("accounts.txt");

    if (!file) {
        cout << "Error: Unable to save account details.\n";
        return;
    }

    for (const Account& acc : accounts) {
        file << quoted(acc.getAccountHolder()) << " "
             << acc.getAccountNumber() << " "
             << setprecision(17) << acc.getBalance() << "\n";
    }

    file.close();
}

// Load account details from the file
void Bank::loadAccounts() {
    ifstream file("accounts.txt");

    if (!file) {
        return;
    }

    string name;
    long long number;
    double balance;

    while (file >> quoted(name) >> number >> balance) {
        if (number <= 0 || balance < 0) {
            continue;
        }

        Account acc(name, number, balance);
        accounts.push_back(acc);

        if (number >= nextAccountNumber) {
            nextAccountNumber = number + 1;
        }
    }

    file.close();
}

// Create a new account
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

    saveAccounts();

    cout << "\nAccount created successfully!\n";
    cout << "Your Account Number is: " << number << endl;
}

// Search Account
void Bank::searchAccount() {
    long long number;

    cout << "\nEnter Account Number: ";
    cin >> number;

    Account* account = findAccount(number);

    if (account != nullptr) {
        account->displayDetails();
    } else {
        cout << "Account not found.\n";
    }
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

// Find account using account number
Account* Bank::findAccount(long long accountNumber) {
    for (Account& acc : accounts) {
        if (acc.getAccountNumber() == accountNumber) {
            return &acc;
        }
    }

    return nullptr;
}
