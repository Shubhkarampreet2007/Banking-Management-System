
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Bank.h"
#include <vector>
#include <string>

using namespace std;

struct TransactionRecord {
    string type;
    double amount;
    long long accountNumber;
    long long relatedAccountNumber;
    string dateTime;
};

class Transaction {
private:
    Bank& bank;
    vector<TransactionRecord> history;

    void recordTransaction(string type, double amount,
                           long long accountNumber,
                           long long relatedAccountNumber = 0);
void saveTransaction(const TransactionRecord& record);
void loadHistory();
public:
    Transaction(Bank& b);

    void deposit();
    void withdraw();
    void balanceEnquiry();
    void transfer();
    void displayHistory();
};

#endif
