/*Encapsulation restricts direct access to certain object components, allowing control through 
public methods. We implemented a 'BankAccount' class where 'balance' is private and accessed using getter
and setter methods
*/

#include <iostream>

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance = 0) : balance(initialBalance > 0 ? initialBalance : 0) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        }
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    // Create a bank account with initial balance of 100
    BankAccount account(100);

    // Demonstrate deposit
    std::cout << "Initial Balance: $" << account.getBalance() << std::endl;

    account.deposit(50);
    std::cout << "After depositing $50: $" << account.getBalance() << std::endl;

    // Demonstrate withdrawal
    account.withdraw(30);
    std::cout << "After withdrawing $30: $" << account.getBalance() << std::endl;

    // Demonstrate invalid operations
    account.deposit(-20);  // Should not change balance
    account.withdraw(500);  // Should not change balance

    std::cout << "Final Balance: $" << account.getBalance() << std::endl;

    return 0;
}