# SMART ATM SYSTEM (C++) 

📌 Project Overview -

Name: Smart ATM System

Language: C++ (C++11 / C++17 compatible)

Architecture: Object-Oriented Domain Logic with Console I/O

Type: Backend Core Software Simulation

💡 Why I Created This Project

To Master Object-Oriented Programming (OOP):

Practical application of encapsulation by hiding internal variables (balance, history) and providing controlled public access methods.

To Understand Robust Input Validation:

Handling improper user inputs (e.g., text entered when numbers are expected) without crashing the application.

To Apply Clean Code & Industry Standards:

Writing header-safe code by avoiding using namespace std; to eliminate name collisions in larger C++ ecosystems.

To Implement Real-World Financial Logic:

Modeling transaction histories, deposits, and withdrawal constraints (insufficient funds checks, positive amount checks).

🛠️ How I Created This (Technical Implementation)

Account Domain Class (Account):

Private Data Members:

std::string accountNumber: Unique identifier for the account.

double balance: Current monetary value.

std::vector<Transaction> history: Dynamic storage of financial activity.

Public Interface:

deposit(double amount): Validates positive deposit amounts and records the state change.

withdraw(double amount): Checks for sufficient funds and positive amounts before completing transactions.

printHistory(): Outputs a formatted transaction log.

Transaction Record Structure (Transaction):

A lightweight struct grouping transaction type, transaction amount, and post-transaction balance.

Console UI & Flow Control (main()):

Built using a do-while loop combined with a switch statement for continuous user navigation.

Utilizes std::cin.clear() and std::cin.ignore() to safely recover from stream parsing failures when receiving invalid user input.

Formatted output using standard C++ I/O manipulators (std::setw, std::fixed, std::setprecision(2)).

✨ Key Features -

Account Management:

View current balance and account details dynamically.

Deposit Operations:

Rejects zero or negative amounts with informative error messaging.

Withdrawal Operations:

Prevents overdrafts by checking available balance before executing transactions.

Transaction History Logging:

Automatically records all deposits and withdrawals with real-time balance tracking.

Input Fault Tolerance:

Robustly handles non-numeric user choices without throwing infinite loop exceptions or crashing.

🚀 How to Run the Program

Prerequisites -

A C++ compiler (such as g++, clang++, or MSVC for VS Code / Visual Studio).

Compilation & Execution Steps

Clone or Download the Project:

git clone https://github.com/your-username/smart-atm-cpp.git
cd smart-atm-cpp


Compile the Code using g++:

g++ -std=c++17 main.cpp -o SmartATM


Run the Executable:

Linux / macOS:

./SmartATM


Windows:

SmartATM.exe
 
