# 🏦 Bank System

A console-based **Bank Management System** built in **C++**, simulating core banking operations such as client management, deposits, withdrawals, transfers, currency exchange, and user access control.

This project was developed as a progressive learning exercise, split into multiple stages (`Project 1` → `Project 4`), each building on the previous one to add more features and better structure.

---

## ✨ Features

- **Client Management**
  - Add, update, delete, and search for clients
  - View a full list of all clients

- **Transactions**
  - Deposit funds
  - Withdraw funds
  - Transfer funds between accounts
  - View transaction/transfer logs
  - Check total balances

- **User & Access Management**
  - Login / Register system
  - Add, update, delete, and search users
  - Manage user permissions

- **Currency Exchange**
  - View and update currency exchange rates
  - Currency calculator
  - List of supported currencies

---

## 🛠️ Built With

- **Language:** C++
- **Paradigm:** Object-Oriented Programming (OOP)
- **Interface:** Console-based (CLI)
- **IDE:** Visual Studio Code (`.vscode` config included)

---

## 📂 Project Structure

The repository is organized as follows:

```
Bank-System/
│
├── Project 1/              # Early version / foundational stage
├── Project 2/              # Extended features
├── Project 3/              # Further improvements
├── Project 4/              # Most complete/advanced stage
│
├── clsBankClient.h          # Client entity & data handling
├── clsUser.h                 # User entity & authentication data
├── clsPerson.h                # Base class for Client/User (inheritance)
├── clsTransactionsScreen.h    # Deposit / Withdraw / Transfer menu
├── clsCurrencyExchange.h      # Currency exchange logic
├── clsCurrencyExchangeScreen.h
├── clsCurrencyCalculatorScreen.h
├── clsCurrenciesListScreen.h
├── clsUpdateCurrencyRateScreen.h
├── clsFindCurrencyScreen.h
├── clsClientListScreen.h / clsAddNewClientScreen.h / clsUpdateClientScreen.h
│   / clsDeleteClientScreen.h / clsFindClientScreen.h
├── clsListUsersScreen.h / clsAddNewUserScreen.h / clsUpdateUserScreen.h
│   / clsDeleteUserScreen.h / clsFindUserScreen.h / clsManageUsersScreen.h
├── clsLoginScreen.h / clsLoginRegesterScreen.h
├── clsMainScreen.h            # Main menu and navigation logic
├── clsScreen.h                # Base screen/UI class
├── clsGlobal.h                # Global variables and constants
├── clsInputValidate.h         # Input validation utilities
├── clsString.h                # String helper functions
├── clsDate.h / clsPeriod.h    # Date and time period handling
├── clsUtilLibrary.h           # General utility functions
├── InterfaceCommunication.h   # Shared interfaces between components
└── .vscode/                   # Editor configuration
```

> Note: The project follows an incremental design — each `Project N` folder represents a milestone in development, while the root-level files reflect the most refined/current implementation.

---

## 🚀 Getting Started

### Prerequisites
- A C++ compiler (e.g., **g++**, or **MSVC** via Visual Studio)
- Visual Studio Code (optional, config already provided)

### Build & Run
1. Clone the repository:
   ```bash
   git clone https://github.com/alialaidi/Bank-System.git
   cd Bank-System
   ```
2. Compile the project (adjust the entry `.cpp` file name as needed):
   ```bash
   g++ main.cpp -o BankSystem
   ```
3. Run the executable:
   ```bash
   ./BankSystem
   ```

---

## 🧭 Main Menu Overview

Once launched, the system presents a main menu with the following options:

| # | Option |
|---|--------|
| 1 | Show Client List |
| 2 | Add New Client |
| 3 | Delete Client |
| 4 | Update Client Info |
| 5 | Find Client |
| 6 | Transactions |
| 7 | Manage Users |
| 8 | Login / Register |
| 9 | Currency Exchange |
| 10 | Logout |

---

## 📌 Notes

- This is an educational project focused on practicing **OOP concepts in C++** (classes, inheritance, encapsulation) along with building a structured, menu-driven console application.
- Data persistence method (e.g., text files) should be documented here once confirmed — update this section based on how `clsGlobal.h` / file handling is implemented.


