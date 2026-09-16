# 🏦 ATM Banking System — C++

A console-based ATM Banking System developed in C++ as a final Object-Oriented Programming (OOP) Lab project.

## 📌 Overview

This project demonstrates the practical implementation of Object-Oriented Programming concepts through a simple banking system.

The application supports two account types:

- Student Account
- Current Account

Users can create an account, deposit money, withdraw money, and view account information.

## 🚀 Features

- Student Account creation
- Current Account creation
- Deposit functionality
- Withdrawal functionality
- Account balance display
- Account-specific withdrawal limits
- Input validation
- Exception handling
- Operator overloading
- Stack memory allocation
- Heap memory allocation
- Dynamic memory deallocation

## 🧠 OOP Concepts

The project demonstrates:

- Encapsulation
- Inheritance
- Runtime Polymorphism
- Virtual Functions
- Function Overriding
- Operator Overloading
- Constructors
- Destructors
- Exception Handling
- Stack and Heap Memory

## 🏗️ Class Structure

```text
             Account
             /     \
            /       \
 StudentAccount   CurrentAccount


The Account class contains the common account information and functionality.

StudentAccount and CurrentAccount inherit from the base class and provide account-specific behavior.

💰 Account Limits
Account Type	Withdrawal Limit
Student Account	Rs. 50,000
Current Account	Rs. 100,000
⚙️ Technologies
C++
Object-Oriented Programming
iostream
stdexcept
C++11 or later
💡 Operator Overloading

The project overloads the + and - operators for banking transactions.

account + amount;  // Deposit
account - amount;  // Withdrawal
🧩 Exception Handling

The system handles invalid operations such as:

Negative initial balance
Invalid deposit amount
Invalid withdrawal amount
Insufficient balance
Exceeding withdrawal limits
Invalid account selection
💾 Memory Management

The project demonstrates both stack and heap allocation.

Stack
StudentAccount account(...);
Heap
CurrentAccount* account = new CurrentAccount(...);

The dynamically allocated object is released using:

delete account;
🎓 Academic Project

Student: Abdullah Zawar
Department: Software Engineering
University: The University of Lahore
Course: Object-Oriented Programming

⚠️ Disclaimer

This is an academic project developed for educational purposes and is not intended to function as a real banking system.

🔮 Future Improvements

Possible future enhancements include:

GUI
Database integration
Login and authentication
ATM card and PIN system
Transaction history
Fund transfers
Multiple customer accounts
Additional account types
Permanent data storage
