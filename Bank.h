#ifndef BANK_H
#define BANK_H
#include "Account.h"
#include <vector>
using namespace std;
class Bank{
    private:
    vector<Account> accounts;
    long long nextAccountNumber;
    public:
    Bank();
    void createAccount();
    void searchAccount();
    void displayAllAccounts();
    long long generateAccountNumber();
    Account* findAccount(long long accountNumber);
};
#endif