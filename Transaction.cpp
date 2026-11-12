
#include "Transaction.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <limits>
#include <fstream>

using namespace std;

// Constructor
Transaction::Transaction(Bank& b) : bank(b) {
    loadHistory();
}

// Record transaction
void Transaction::recordTransaction(string type, double amount,
                                    long long accountNumber,
                                    long long relatedAccountNumber) {
    time_t now = time(0);
    string dateTime = ctime(&now);

    if (!dateTime.empty() && dateTime.back() == '\n') {
        dateTime.pop_back();
    }

    TransactionRecord record;

    record.type = type;
    record.amount = amount;
    record.accountNumber = accountNumber;
    record.relatedAccountNumber = relatedAccountNumber;
    record.dateTime = dateTime;

    history.push_back(record);
    saveTransaction(record);
}

// Task 1: Deposit Money
void Transaction::deposit() {
    long long number;
    double amount;

    cout << "\nEnter Account Number: ";
    cin >> number;

    Account* account = bank.findAccount(number);

    if (account == nullptr) {
        cout << "Account not found.\n";
        return;
    }

    cout << "Enter Deposit Amount: Rs. ";
    cin >> amount;

    if (cin.fail()) {
        cout << "Invalid amount.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (amount <= 0) {
        cout << "Amount must be positive.\n";
        return;
    }

    account->deposit(amount);

    recordTransaction("Deposit", amount, number);

    cout << "New Balance: Rs. "
         << fixed << setprecision(2)
         << account->getBalance() << endl;
}

// Task 2: Withdraw Money
void Transaction::withdraw() {
    long long number;
    double amount;

    cout << "\nEnter Account Number: ";
    cin >> number;

    Account* account = bank.findAccount(number);

    if (account == nullptr) {
        cout << "Account not found.\n";
        return;
    }

    cout << "Enter Withdrawal Amount: Rs. ";
    cin >> amount;

    if (cin.fail()) {
        cout << "Invalid amount.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (amount <= 0) {
        cout << "Amount must be positive.\n";
        return;
    }

    if (account->withdraw(amount)) {
        recordTransaction("Withdraw", amount, number);

        cout << "Remaining Balance: Rs. "
             << fixed << setprecision(2)
             << account->getBalance() << endl;
    }
}

// Task 3: Balance Enquiry
void Transaction::balanceEnquiry() {
    long long number;

    cout << "\nEnter Account Number: ";
    cin >> number;

    Account* account = bank.findAccount(number);

    if (account == nullptr) {
        cout << "Account not found.\n";
        return;
    }

    cout << "\nAccount Number: " << number << endl;

    account->checkBalance();
}

// Task 4: Transfer Money
void Transaction::transfer() {
    long long senderNumber, receiverNumber;
    double amount;

    cout << "\nEnter Sender Account Number: ";
    cin >> senderNumber;

    Account* sender = bank.findAccount(senderNumber);

    if (sender == nullptr) {
        cout << "Sender account not found.\n";
        return;
    }

    cout << "Enter Receiver Account Number: ";
    cin >> receiverNumber;

    Account* receiver = bank.findAccount(receiverNumber);

    if (receiver == nullptr) {
        cout << "Receiver account not found.\n";
        return;
    }

    if (senderNumber == receiverNumber) {
        cout << "Cannot transfer to the same account.\n";
        return;
    }

    cout << "Enter Transfer Amount: Rs. ";
    cin >> amount;

    if (cin.fail()) {
        cout << "Invalid amount.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (amount <= 0) {
        cout << "Amount must be positive.\n";
        return;
    }

    if (sender->withdraw(amount)) {
        receiver->deposit(amount);

        recordTransaction("Transfer", amount,
                          senderNumber, receiverNumber);

        cout << "\nTransfer successful!\n";
        cout << "Sender Balance: Rs. "
             << sender->getBalance() << endl;

        cout << "Receiver Balance: Rs. "
             << receiver->getBalance() << endl;
    }
}

// Task 5: Transaction History
void Transaction::displayHistory() {
    if (history.empty()) {
        cout << "\nNo transaction history available.\n";
        return;
    }

    cout << "\n========== TRANSACTION HISTORY ==========\n";

    for (const TransactionRecord& record : history) {
        cout << "\nTransaction Type: " << record.type;
        cout << "\nAccount Number: " << record.accountNumber;

        if (record.relatedAccountNumber != 0) {
            cout << "\nReceiver Account Number: "
                 << record.relatedAccountNumber;
        }

        cout << "\nAmount: Rs. "
             << fixed << setprecision(2)
             << record.amount;

        cout << "\nDate & Time: " << record.dateTime;
        cout << "\n-----------------------------------------\n";
    }
}

// Save transaction in file
void Transaction::saveTransaction(const TransactionRecord& record) {
    ofstream file("transactions.txt", ios::app);

    if (!file) {
        cout << "Unable to open transaction file.\n";
        return;
    }

    file << quoted(record.type) << " "
         << record.amount << " "
         << record.accountNumber << " "
         << record.relatedAccountNumber << " "
         << quoted(record.dateTime) << endl;
}

// Load previous transaction history
void Transaction::loadHistory() {
    ifstream file("transactions.txt");

    if (!file) {
        return;
    }

    TransactionRecord record;

    while (file >> quoted(record.type)
                >> record.amount
                >> record.accountNumber
                >> record.relatedAccountNumber
                >> quoted(record.dateTime)) {

        history.push_back(record);
    }

    file.close();
}
