# 🏦 Banking Management System

## 📌 Project Overview

The **Banking Management System** is a console-based application developed using **C++ and Object-Oriented Programming (OOP)**. It is designed to perform basic banking operations efficiently, such as creating accounts, depositing money, withdrawing money, transferring funds, and viewing transaction history.

The project uses file handling to store account details and transaction records so that data can be retrieved even after the program is closed.

## 🎯 Objectives

- To develop a simple and efficient banking application.
- To implement Object-Oriented Programming concepts in C++.
- To manage customer account information.
- To perform basic banking transactions.
- To maintain records using file handling.

## ✨ Features

- **Create Account:** Create a new bank account with customer details.
- **Search Account:** Search for an account using its account number.
- **Display Accounts:** View the available account details.
- **Deposit Money:** Add money to an existing account.
- **Withdraw Money:** Withdraw money with balance validation.
- **Balance Enquiry:** Check the current account balance.
- **Fund Transfer:** Transfer money between two accounts.
- **Transaction History:** View previously recorded transactions.
- **Data Persistence:** Store and retrieve account details and transaction history using text files.

## 🛠️ Technologies Used

- **Programming Language:** C++
- **Concepts:** Object-Oriented Programming
- **IDE:** Visual Studio Code
- **Compiler:** G++ (MinGW)
- **Version Control:** Git
- **Repository Hosting:** GitHub

## 🧠 OOP Concepts Used

1. **Classes and Objects:** The project is divided into classes representing different banking operations.
2. **Encapsulation:** Data members are kept private and accessed through public member functions.
3. **Abstraction:** Internal implementation details are separated from the operations available to the user.
4. **Modularity:** The program is divided into separate header and implementation files for better organization and maintenance.

## 🏗️ Project Structure

```text
Banking-Management-System/
│
├── main.cpp
│
├── Account.h
├── Account.cpp
│
├── Bank.h
├── Bank.cpp
│
├── Transaction.h
├── Transaction.cpp
│
├── accounts.txt
├── transactions.txt
│
├── README.md
│
└── Screenshots/
```

## 💾 File Handling

The application uses file handling to maintain records between program executions.

- **accounts.txt:** Stores account information, including account holder name, account number, and balance.
- **transactions.txt:** Stores transaction details, including transaction type, amount, account numbers, and date and time.

The program uses file input and output operations to save and retrieve these records.

## ▶️ How to Compile and Run

### Prerequisites

- Visual Studio Code or any C++ IDE.
- G++ compiler installed and configured.

### Compilation

Open the terminal in the project directory and execute:

```bash
g++ -std=c++14 main.cpp Account.cpp Bank.cpp Transaction.cpp -o BankingSystem
```

### Execution

**Windows:**

```powershell
.\BankingSystem.exe
```

## 🧪 Testing

The application can be tested using the following operations:

- Creating and searching bank accounts.
- Depositing and withdrawing money.
- Checking account balances.
- Transferring funds between accounts.
- Viewing transaction history.
- Closing and reopening the application to verify data persistence.

## 🚀 Future Enhancements

- Password-based authentication.
- Graphical User Interface (GUI).
- Improved security and data encryption.
- Database integration.
- Detailed account statements.

## 👩‍💻 Project Team

**Developed by:**

- Shubhkarampreet Kaur
- Shilu Devi

**Course:** Bachelor of Technology – Computer Science and Engineering

## 🔗 GitHub Repository

[Banking Management System – GitHub](https://github.com/Shubhkarampreet2007/Banking-Management-System)

---

*This project was developed as part of an academic Object-Oriented Programming course to apply C++ programming and software development concepts in a practical application.*
