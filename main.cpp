#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Account{
    private:
    string accountHolder;
    long long accountNumber;
    double balance;
    public:
    Account(string name , long long number , double initialBalance){
        accountHolder = name;
        accountNumber = number;
        balance = initialBalance;
    }
    void deposit(double amount){
        if(amount > 0){
            balance += amount;
            cout << "Deposit successfull " << endl;
        }else{
            cout << "Invalid deposit amount " << endl;
        }
    }
    void withdraw(double amount){
        if(amount <= 0  ){
            cout << "Invalid withdrawal amount" << endl;


        }else if(amount > balance){
            cout << "Insufficient balance " << endl;
        }else{
            balance -= amount;
            cout << "Withdrawal successful." << endl;
        }
    }
    void checkBalance() const {
        cout << "Current Balance: Rs. " << fixed << setprecision(2) << balance << endl ;

    }
    void displayDetails() const{
        cout << "-----Account details-----"<< endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account number: " << accountNumber << endl;
        checkBalance();
    }
};
int main(){
    Account acc1("Shubh" , 123456789 , 5000.00 );
    acc1.displayDetails();
}