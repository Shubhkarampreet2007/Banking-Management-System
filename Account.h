#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
using namespace std;
class Account{
    private:
    string accountHolder;
    long long accountNumber;
    double balance;
    public:
    Account(string name , long long accNumber , double balance);
    void deposit(double amount);
    bool withdraw(double amount);
    void checkBalance() const;
    void displayDetails() const;
    long long getAccountNumber() const;
    double getBalance() const;


};
#endif