#include "Account.h"
#include <iostream>
#include <iomanip>
using namespace std;
Account::Account(string name , long long number , double initialbalance){
    accountHolder = name;
    accountNumber = number;
    balance = initialbalance;
}
void Account::deposit(double amount){
    if(amount > 0){
        balance += amount;
        cout << "Amount deposited successfully." << endl;
    }else{
        cout << "Invalid deposit amount." << endl;
    }
}
bool Account::withdraw(double amount){
    if(amount <= 0){
        cout << "Invalid withdraw money" << endl;
        return false;
    }else if(amount > balance){
        cout << "Insufficient balance" << endl;
        return false;
    }else{
        balance -= amount;
        cout << "amount added successfully" << endl;
        return true;
    }
}
    void Account::checkBalance() const{
        cout << fixed << setprecision(2) ;
        cout << "Current Balance Rs. " << balance << endl;
    }
    void Account::displayDetails() const {
    cout << "\n----- Account Details -----\n";
    cout << "Account Holder: " << accountHolder << endl;
    cout << "Account Number: " << accountNumber << endl;
    checkBalance();
}

// Get account number
long long Account::getAccountNumber() const {
    return accountNumber;
}

// Get balance
double Account::getBalance() const {
    return balance;
}


        