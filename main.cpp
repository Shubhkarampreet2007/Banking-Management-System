
#include <iostream>
#include <limits>
#include "Bank.h"
#include "Transaction.h"

using namespace std;

int main() {
    Bank bank;
    Transaction transaction(bank);

    int choice;

    do {
        cout << "\n====================================\n";
        cout << "       BANK MANAGEMENT SYSTEM\n";
        cout << "====================================\n";

        cout << "1. Create New Account\n";
        cout << "2. Search Account\n";
        cout << "3. Display All Accounts\n";
        cout << "4. Deposit Money\n";
        cout << "5. Withdraw Money\n";
        cout << "6. Balance Enquiry\n";
        cout << "7. Transfer Money\n";
        cout << "8. Transaction History\n";
        cout << "9. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {

            case 1:
                bank.createAccount();
                break;

            case 2:
                bank.searchAccount();
                break;

            case 3:
                bank.displayAllAccounts();
                break;

            case 4:
                transaction.deposit();
                break;

            case 5:
                transaction.withdraw();
                break;

            case 6:
                transaction.balanceEnquiry();
                break;

            case 7:
                transaction.transfer();
                break;

            case 8:
                transaction.displayHistory();
                break;

            case 9:
                cout << "\nThank you for using our Bank Management System!\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 9);

    return 0;
}
