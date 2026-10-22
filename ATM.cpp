#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

// Structure to track transaction records
struct Transaction {
    std::string type;    // "Deposit" or "Withdrawal"
    double amount;       // Amount moved
    double balanceAfter; // Updated balance
};

// C++ Account Class (Backend Domain Logic)
class Account {
private:
    std::string accountNumber;
    double balance;
    std::vector<Transaction> history;

public:
    Account(std::string accNum, double initialBalance = 0.0)
        : accountNumber(accNum), balance(initialBalance) {}

    std::string getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    bool deposit(double amount) {
        if (amount <= 0) {
            std::cout << "\n [ERROR] Deposit amount must be positive.\n";
            return false;
        }
        balance += amount;
        history.push_back({"Deposit", amount, balance});
        std::cout << "\n [SUCCESS] Successfully deposited $" 
                  << std::fixed << std::setprecision(2) << amount << "\n";
        return true;
    }

    bool withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "\n [ERROR] Withdrawal amount must be positive.\n";
            return false;
        }
        if (amount > balance) {
            std::cout << "\n [ERROR] Insufficient funds! Current Balance: $" 
                      << std::fixed << std::setprecision(2) << balance << "\n";
            return false;
        }
        balance -= amount;
        history.push_back({"Withdrawal", amount, balance});
        std::cout << "\n [SUCCESS] Successfully withdrew $" 
                  << std::fixed << std::setprecision(2) << amount << "\n";
        return true;
    }

    void printHistory() const {
        std::cout << "\n---------------------------------------------\n";
        std::cout << " TRANSACTION LOG FOR ACC NO: " << accountNumber << "\n";
        std::cout << "---------------------------------------------\n";

        if (history.empty()) {
            std::cout << " No transactions recorded yet.\n";
        } else {
            std::cout << std::left << std::setw(15) << "Type"
                      << std::setw(15) << "Amount"
                      << "Balance After\n";
            std::cout << "---------------------------------------------\n";
            for (const auto &tx : history) {
                std::cout << std::left << std::setw(15) << tx.type
                          << "$" << std::setw(14) << std::fixed << std::setprecision(2) << tx.amount
                          << "$" << tx.balanceAfter << "\n";
            }
        }
        std::cout << "---------------------------------------------\n";
    }
};

int main() {
    // Create an account with Acc No: "1001" and Initial Balance: $500.00
    Account myAccount("1001", 500.0);

    int choice = 0;
    do {
        // Top Header Display showing Account Number at the top-left
        std::cout << "\n=============================================\n";
        std::cout << " ACC NO: " << myAccount.getAccountNumber() 
                  << "               C++ SMART ATM \n";
        std::cout << "=============================================\n";
        std::cout << " Current Balance: $" << std::fixed << std::setprecision(2) 
                  << myAccount.getBalance() << "\n";
        std::cout << "---------------------------------------------\n";
        std::cout << " 1. Deposit Funds\n";
        std::cout << " 2. Withdraw Funds\n";
        std::cout << " 3. View Transaction History\n";
        std::cout << " 4. Exit\n";
        std::cout << " Select an option (1-4): ";

        // Validate user option input
        if (!(std::cin >> choice)) {
            std::cout << "\n [ERROR] Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                double depAmount;
                std::cout << " Enter deposit amount: $";
                if (std::cin >> depAmount) {
                    myAccount.deposit(depAmount);
                } else {
                    std::cout << "\n [ERROR] Invalid monetary value.\n";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                }
                break;
            }

            case 2: {
                double drawAmount;
                std::cout << " Enter withdrawal amount: $";
                if (std::cin >> drawAmount) {
                    myAccount.withdraw(drawAmount);
                } else {
                    std::cout << "\n [ERROR] Invalid monetary value.\n";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                }
                break;
            }

            case 3:
                myAccount.printHistory();
                break;

            case 4:
                std::cout << "\n Thank you for using C++ Smart ATM. Goodbye!\n\n";
                break;

            default:
                std::cout << "\n [ERROR] Invalid choice. Please select 1 to 4.\n";
        }
    } while (choice != 4);

    return 0;
}
