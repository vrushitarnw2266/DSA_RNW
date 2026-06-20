#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <stdexcept>

// Platform-specific console color handling
#ifdef _WIN32
#include <windows.h>
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
void enableVirtualTerminalProcessing() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) return;
    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) return;
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}
#else
void enableVirtualTerminalProcessing() {}
#endif

// ANSI color escape codes for premium CLI styling
namespace Color {
    const std::string RESET   = "\033[0m";
    const std::string BOLD    = "\033[1m";
    const std::string RED     = "\033[31m";
    const std::string GREEN   = "\033[32m";
    const std::string YELLOW  = "\033[33m";
    const std::string BLUE    = "\033[34m";
    const std::string MAGENTA = "\033[35m";
    const std::string CYAN    = "\033[36m";
    const std::string WHITE   = "\033[37m";
    const std::string BG_BLUE = "\033[44m";
    const std::string UNDERLINE = "\033[4m";
}

// 1. BASE CLASS: BankAccount (Encapsulation)
class BankAccount {
private:
    int accountNumber;
    std::string accountHolderName;
    double balance;

protected:
    // Protected setter to allow derived classes (like CheckingAccount) to modify balance when needed
    void setBalance(double newBalance) {
        balance = newBalance;
    }

public:
    BankAccount(int accNum, const std::string& holderName, double initialBalance)
        : accountNumber(accNum), accountHolderName(holderName), balance(initialBalance) {
        if (initialBalance < 0) {
            balance = 0;
        }
    }

    virtual ~BankAccount() {}

    // Getters (Encapsulation accessor methods)
    int getAccountNumber() const {
        return accountNumber;
    }

    std::string getAccountHolderName() const {
        return accountHolderName;
    }

    double getBalance() const {
        return balance;
    }

    // Basic transaction methods
    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    virtual bool withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }

    // Virtual methods for polymorphism
    virtual double calculateInterest() const {
        return 0.0;
    }

    virtual std::string getAccountType() const = 0;

    virtual void displayAccountInfo() const {
        std::cout << Color::CYAN << "-------------------------------------------\n" << Color::RESET;
        std::cout << Color::BOLD << "Account Type  : " << Color::RESET << getAccountType() << "\n";
        std::cout << Color::BOLD << "Account Number: " << Color::RESET << accountNumber << "\n";
        std::cout << Color::BOLD << "Holder Name   : " << Color::RESET << accountHolderName << "\n";
        std::cout << Color::BOLD << "Balance       : " << Color::GREEN << "$" << std::fixed << std::setprecision(2) << balance << Color::RESET << "\n";
    }
};

// 2. DERIVED CLASS: SavingsAccount (Inheritance)
class SavingsAccount : public BankAccount {
private:
    double interestRate; // Annual interest rate (e.g., 0.04 for 4%)

public:
    SavingsAccount(int accNum, const std::string& holderName, double initialBalance, double rate)
        : BankAccount(accNum, holderName, initialBalance), interestRate(rate) {}

    // Polymorphic overrides
    double calculateInterest() const override {
        return getBalance() * interestRate;
    }

    std::string getAccountType() const override {
        return "Savings Account";
    }

    void displayAccountInfo() const override {
        BankAccount::displayAccountInfo();
        std::cout << Color::BOLD << "Interest Rate : " << Color::RESET << (interestRate * 100.0) << "%\n";
        std::cout << Color::BOLD << "Est. Interest : " << Color::GREEN << "$" << calculateInterest() << Color::RESET << "\n";
        std::cout << Color::CYAN << "-------------------------------------------\n" << Color::RESET;
    }
};

// 3. DERIVED CLASS: CheckingAccount (Inheritance)
class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNum, const std::string& holderName, double initialBalance, double limit)
        : BankAccount(accNum, holderName, initialBalance), overdraftLimit(limit) {}

    double getOverdraftLimit() const {
        return overdraftLimit;
    }

    // Overriding withdraw to handle overdraft limits
    bool withdraw(double amount) override {
        if (amount > 0 && (getBalance() + overdraftLimit) >= amount) {
            setBalance(getBalance() - amount);
            return true;
        }
        return false;
    }

    bool checkOverdraft(double amount) const {
        return amount > (getBalance() + overdraftLimit);
    }

    std::string getAccountType() const override {
        return "Checking Account";
    }

    void displayAccountInfo() const override {
        BankAccount::displayAccountInfo();
        std::cout << Color::BOLD << "Overdraft Lmt : " << Color::RESET << "$" << overdraftLimit << "\n";
        std::cout << Color::BOLD << "Max Available : " << Color::GREEN << "$" << (getBalance() + overdraftLimit) << Color::RESET << "\n";
        std::cout << Color::CYAN << "-------------------------------------------\n" << Color::RESET;
    }
};

// 4. DERIVED CLASS: FixedDepositAccount (Inheritance)
class FixedDepositAccount : public BankAccount {
private:
    int term; // Duration in months
    double interestRate;

public:
    FixedDepositAccount(int accNum, const std::string& holderName, double initialBalance, int durationMonths, double rate)
        : BankAccount(accNum, holderName, initialBalance), term(durationMonths), interestRate(rate) {}

    // Polymorphic overrides
    double calculateInterest() const override {
        // Simple interest: Principal * Rate * Time(years)
        return getBalance() * interestRate * (term / 12.0);
    }

    std::string getAccountType() const override {
        return "Fixed Deposit Account";
    }

    void displayAccountInfo() const override {
        BankAccount::displayAccountInfo();
        std::cout << Color::BOLD << "FD Term Length: " << Color::RESET << term << " months\n";
        std::cout << Color::BOLD << "Interest Rate : " << Color::RESET << (interestRate * 100.0) << "%\n";
        std::cout << Color::BOLD << "Maturity Int. : " << Color::GREEN << "$" << calculateInterest() << Color::RESET << "\n";
        std::cout << Color::CYAN << "-------------------------------------------\n" << Color::RESET;
    }
};

// 5. DSA DATA STRUCTURE: Custom Binary Search Tree

class AccountBST {
private:
    struct Node {
        BankAccount* account;
        Node* left;
        Node* right;

        Node(BankAccount* acc) : account(acc), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Helper functions for BST operations
    Node* insert(Node* node, BankAccount* acc, bool& success) {
        if (!node) {
            success = true;
            return new Node(acc);
        }

        if (acc->getAccountNumber() < node->account->getAccountNumber()) {
            node->left = insert(node->left, acc, success);
        } else if (acc->getAccountNumber() > node->account->getAccountNumber()) {
            node->right = insert(node->right, acc, success);
        } else {
            success = false; // Duplicate Account Number
        }
        return node;
    }

    Node* findMin(Node* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    Node* remove(Node* node, int accNum, bool& success) {
        if (!node) {
            success = false;
            return nullptr;
        }

        if (accNum < node->account->getAccountNumber()) {
            node->left = remove(node->left, accNum, success);
        } else if (accNum > node->account->getAccountNumber()) {
            node->right = remove(node->right, accNum, success);
        } else {
            success = true;
            // Node found
            if (!node->left && !node->right) {
                // Leaf Node
                delete node->account;
                delete node;
                return nullptr;
            } else if (!node->left) {
                // One child (right)
                Node* temp = node->right;
                delete node->account;
                delete node;
                return temp;
            } else if (!node->right) {
                // One child (left)
                Node* temp = node->left;
                delete node->account;
                delete node;
                return temp;
            } else {
                // Two children: Get inorder successor (min in right subtree)
                Node* temp = findMin(node->right);
                
                // Swap the bank account pointers
                BankAccount* tempAcc = node->account;
                node->account = temp->account;
                temp->account = tempAcc;

                // Delete the successor node which now has the account to delete
                node->right = remove(node->right, tempAcc->getAccountNumber(), success);
            }
        }
        return node;
    }

    BankAccount* search(Node* node, int accNum) const {
        if (!node) return nullptr;
        if (node->account->getAccountNumber() == accNum) return node->account;
        
        if (accNum < node->account->getAccountNumber()) {
            return search(node->left, accNum);
        }
        return search(node->right, accNum);
    }

    void destroyTree(Node* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node->account;
            delete node;
        }
    }

    template <typename Func>
    void inorder(Node* node, Func func) const {
        if (node) {
            inorder(node->left, func);
            func(node->account);
            inorder(node->right, func);
        }
    }

public:
    AccountBST() : root(nullptr) {}

    ~AccountBST() {
        destroyTree(root);
    }

    bool insert(BankAccount* acc) {
        bool success = false;
        root = insert(root, acc, success);
        return success;
    }

    bool remove(int accNum) {
        bool success = false;
        root = remove(root, accNum, success);
        return success;
    }

    BankAccount* search(int accNum) const {
        return search(root, accNum);
    }

    template <typename Func>
    void traverseInorder(Func func) const {
        inorder(root, func);
    }

    bool isEmpty() const {
        return root == nullptr;
    }
};

// ==========================================
// 6. INPUT VALIDATION & CLI UTILITIES
// ==========================================
int getIntegerInput(const std::string& prompt) {
    int val;
    while (true) {
        std::cout << prompt;
        if (std::cin >> val) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return val;
        } else {
            std::cout << Color::RED << "Invalid input. Please enter a valid integer.\n" << Color::RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

double getDoubleInput(const std::string& prompt) {
    double val;
    while (true) {
        std::cout << prompt;
        if (std::cin >> val) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return val;
        } else {
            std::cout << Color::RED << "Invalid input. Please enter a valid decimal number.\n" << Color::RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

std::string getStringInput(const std::string& prompt) {
    std::string line;
    std::cout << prompt;
    std::getline(std::cin, line);
    return line;
}

void printHeader() {
    std::cout << Color::CYAN << "========================================================\n" << Color::RESET;
    std::cout << Color::BLUE << Color::BOLD << "            APEX DIGITAL BANKING SYSTEM (DSA)           \n" << Color::RESET;
    std::cout << Color::CYAN << "========================================================\n" << Color::RESET;
}

// ==========================================
// MAIN PROGRAM
// ==========================================
int main() {
    // Enable VT processing for colors in Windows Command Prompt/PowerShell
    enableVirtualTerminalProcessing();

    AccountBST db;

    // Seed some accounts for a great initial demo
    db.insert(new SavingsAccount(1002, "Alice Smith", 5000.0, 0.04));
    db.insert(new CheckingAccount(1001, "Bob Jones", 1200.0, 500.0));
    db.insert(new FixedDepositAccount(1003, "Charlie Brown", 10000.0, 12, 0.06));

    int choice = 0;
    do {
        printHeader();
        std::cout << Color::YELLOW << "1." << Color::RESET << " Open New Account\n";
        std::cout << Color::YELLOW << "2." << Color::RESET << " Deposit Funds\n";
        std::cout << Color::YELLOW << "3." << Color::RESET << " Withdraw Funds\n";
        std::cout << Color::YELLOW << "4." << Color::RESET << " Display Specific Account Details\n";
        std::cout << Color::YELLOW << "5." << Color::RESET << " Calculate Interest (Polymorphic Demo)\n";
        std::cout << Color::YELLOW << "6." << Color::RESET << " List All Registered Accounts (Sorted - BST Inorder)\n";
        std::cout << Color::YELLOW << "7." << Color::RESET << " Delete/Close Account\n";
        std::cout << Color::YELLOW << "8." << Color::RESET << " Exit Program\n";
        std::cout << Color::CYAN << "--------------------------------------------------------\n" << Color::RESET;

        choice = getIntegerInput(Color::BOLD + "Select an option (1-8): " + Color::RESET);
        std::cout << "\n";

        switch (choice) {
            case 1: {
                std::cout << Color::MAGENTA << "=== OPEN A NEW ACCOUNT ===\n" << Color::RESET;
                int accNum = getIntegerInput("Enter new 4-digit Account Number (e.g. 1004): ");
                
                // Check if account already exists
                if (db.search(accNum) != nullptr) {
                    std::cout << Color::RED << "Error: Account number " << accNum << " already exists!\n\n" << Color::RESET;
                    break;
                }

                std::string name = getStringInput("Enter Account Holder's Full Name: ");
                double balance = getDoubleInput("Enter Initial Deposit Amount: $");

                std::cout << "\nAccount Types:\n";
                std::cout << "1. Savings Account (Interest earning)\n";
                std::cout << "2. Checking Account (Includes overdraft protection)\n";
                std::cout << "3. Fixed Deposit Account (Term-based locked high interest)\n";
                int type = getIntegerInput("Choose type (1-3): ");

                if (type == 1) {
                    double rate = getDoubleInput("Enter Interest Rate (e.g., 0.045 for 4.5%): ");
                    BankAccount* newAcc = new SavingsAccount(accNum, name, balance, rate);
                    if (db.insert(newAcc)) {
                        std::cout << Color::GREEN << "\nSavings Account opened successfully!\n\n" << Color::RESET;
                    } else {
                        delete newAcc;
                        std::cout << Color::RED << "\nFailed to open account due to insertion error.\n\n" << Color::RESET;
                    }
                } else if (type == 2) {
                    double limit = getDoubleInput("Enter Overdraft Limit: $");
                    BankAccount* newAcc = new CheckingAccount(accNum, name, balance, limit);
                    if (db.insert(newAcc)) {
                        std::cout << Color::GREEN << "\nChecking Account opened successfully!\n\n" << Color::RESET;
                    } else {
                        delete newAcc;
                        std::cout << Color::RED << "\nFailed to open account due to insertion error.\n\n" << Color::RESET;
                    }
                } else if (type == 3) {
                    int term = getIntegerInput("Enter Maturity Term (in months): ");
                    double rate = getDoubleInput("Enter Interest Rate (e.g., 0.06 for 6.0%): ");
                    BankAccount* newAcc = new FixedDepositAccount(accNum, name, balance, term, rate);
                    if (db.insert(newAcc)) {
                        std::cout << Color::GREEN << "\nFixed Deposit Account opened successfully!\n\n" << Color::RESET;
                    } else {
                        delete newAcc;
                        std::cout << Color::RED << "\nFailed to open account due to insertion error.\n\n" << Color::RESET;
                    }
                } else {
                    std::cout << Color::RED << "Invalid account type. Returning to menu.\n\n" << Color::RESET;
                }
                break;
            }

            case 2: {
                std::cout << Color::MAGENTA << "=== DEPOSIT FUNDS ===\n" << Color::RESET;
                int accNum = getIntegerInput("Enter Account Number: ");
                BankAccount* acc = db.search(accNum);
                if (acc) {
                    std::cout << "Account Holder: " << acc->getAccountHolderName() << "\n";
                    std::cout << "Current Balance: $" << std::fixed << std::setprecision(2) << acc->getBalance() << "\n";
                    double amount = getDoubleInput("Enter amount to deposit: $");
                    if (amount > 0) {
                        acc->deposit(amount);
                        std::cout << Color::GREEN << "Successfully deposited $" << amount << ". New Balance: $" << acc->getBalance() << "\n\n" << Color::RESET;
                    } else {
                        std::cout << Color::RED << "Invalid deposit amount.\n\n" << Color::RESET;
                    }
                } else {
                    std::cout << Color::RED << "Account not found.\n\n" << Color::RESET;
                }
                break;
            }

            case 3: {
                std::cout << Color::MAGENTA << "=== WITHDRAW FUNDS ===\n" << Color::RESET;
                int accNum = getIntegerInput("Enter Account Number: ");
                BankAccount* acc = db.search(accNum);
                if (acc) {
                    std::cout << "Account Holder: " << acc->getAccountHolderName() << "\n";
                    std::cout << "Current Balance: $" << std::fixed << std::setprecision(2) << acc->getBalance() << "\n";
                    
                    // Show maximum possible withdraw if it is a Checking Account (due to overdraft)
                    if (acc->getAccountType() == "Checking Account") {
                        CheckingAccount* checking = dynamic_cast<CheckingAccount*>(acc);
                        if (checking) {
                            std::cout << "Note: You have overdraft protection. Max withdrawable amount: $" 
                                      << (checking->getBalance() + checking->getOverdraftLimit()) << "\n";
                        }
                    }

                    double amount = getDoubleInput("Enter amount to withdraw: $");
                    if (acc->withdraw(amount)) {
                        std::cout << Color::GREEN << "Successfully withdrew $" << amount << ". New Balance: $" << acc->getBalance() << "\n\n" << Color::RESET;
                    } else {
                        std::cout << Color::RED << "Insufficient funds/Limit exceeded! Withdrawal failed.\n\n" << Color::RESET;
                    }
                } else {
                    std::cout << Color::RED << "Account not found.\n\n" << Color::RESET;
                }
                break;
            }

            case 4: {
                std::cout << Color::MAGENTA << "=== DISPLAY ACCOUNT INFORMATION ===\n" << Color::RESET;
                int accNum = getIntegerInput("Enter Account Number: ");
                BankAccount* acc = db.search(accNum);
                if (acc) {
                    // Call the virtual display function (Polymorphism in action!)
                    acc->displayAccountInfo();
                    std::cout << "\n";
                } else {
                    std::cout << Color::RED << "Account not found.\n\n" << Color::RESET;
                }
                break;
            }

            case 5: {
                std::cout << Color::MAGENTA << "=== POLYMORPHIC INTEREST CALCULATION ===\n" << Color::RESET;
                int accNum = getIntegerInput("Enter Account Number: ");
                BankAccount* acc = db.search(accNum);
                if (acc) {
                    // Demonstrate polymorphism by invoking virtual calculateInterest on a base class pointer
                    double interest = acc->calculateInterest();
                    std::cout << "Account Number : " << acc->getAccountNumber() << "\n";
                    std::cout << "Account Type   : " << acc->getAccountType() << "\n";
                    std::cout << "Holder Name    : " << acc->getAccountHolderName() << "\n";
                    std::cout << "Current Balance: $" << std::fixed << std::setprecision(2) << acc->getBalance() << "\n";
                    if (interest > 0.0) {
                        std::cout << Color::GREEN << "Calculated Interest: $" << interest << Color::RESET << "\n\n";
                    } else {
                        std::cout << Color::YELLOW << "This account type does not earn interest.\n\n" << Color::RESET;
                    }
                } else {
                    std::cout << Color::RED << "Account not found.\n\n" << Color::RESET;
                }
                break;
            }

            case 6: {
                std::cout << Color::MAGENTA << "=== ALL REGISTERED ACCOUNTS (BST Inorder Traversal) ===\n" << Color::RESET;
                if (db.isEmpty()) {
                    std::cout << Color::YELLOW << "No accounts registered in the system.\n\n" << Color::RESET;
                } else {
                    // In-order traversal displays sorted list by account number
                    db.traverseInorder([](BankAccount* acc) {
                        acc->displayAccountInfo();
                    });
                    std::cout << "\n";
                }
                break;
            }

            case 7: {
                std::cout << Color::MAGENTA << "=== DELETE/CLOSE ACCOUNT ===\n" << Color::RESET;
                int accNum = getIntegerInput("Enter Account Number to close: ");
                BankAccount* acc = db.search(accNum);
                if (acc) {
                    std::cout << "Account Holder: " << acc->getAccountHolderName() << "\n";
                    std::cout << "Final Balance: $" << std::fixed << std::setprecision(2) << acc->getBalance() << "\n";
                    std::string confirm = getStringInput("Are you sure you want to close this account? (yes/no): ");
                    if (confirm == "yes" || confirm == "y" || confirm == "YES" || confirm == "Yes") {
                        if (db.remove(accNum)) {
                            std::cout << Color::GREEN << "Account number " << accNum << " has been successfully closed.\n\n" << Color::RESET;
                        } else {
                            std::cout << Color::RED << "Error deleting account from the database.\n\n" << Color::RESET;
                        }
                    } else {
                        std::cout << Color::YELLOW << "Account closure cancelled.\n\n" << Color::RESET;
                    }
                } else {
                    std::cout << Color::RED << "Account not found.\n\n" << Color::RESET;
                }
                break;
            }

            case 8:
                std::cout << Color::GREEN << "Thank you for using Apex Digital Banking. Goodbye!\n" << Color::RESET;
                break;

            default:
                std::cout << Color::RED << "Invalid option. Please try again.\n\n" << Color::RESET;
                break;
        }
    } while (choice != 8);

    return 0;
}
