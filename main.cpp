#include <iostream>
#include "Bank.h"

using namespace std;

int main() {
    Bank bank;
    int choice;

    do {
        cout << "\n================================\n";
        cout << "   BANKING MANAGEMENT SYSTEM\n";
        cout << "================================\n";

        cout << "1. Create New Account\n";
        cout << "2. Search Account\n";
        cout << "3. Display All Accounts\n";
        cout << "4. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

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
                cout << "Thank you for using our banking system!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}