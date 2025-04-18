#include <iostream>
using namespace std;

class PaymentMethod {
public:
    virtual bool processPayment(double amount) = 0;
    virtual ~PaymentMethod() {}
};

class CreditCard : public PaymentMethod {
private:
    string cardNumber;

public:
    CreditCard(const string& cardNum) : cardNumber(cardNum) {}

    bool processPayment(double amount) override {
        if (cardNumber.length() == 16) { 
            cout << "Credit Card Payment of $" << amount << " processed using card: " << cardNumber << endl;
            return true;
        } else {
            cout << "Invalid Credit Card Number. Payment failed.\n";
            return false;
        }
    }
};

class DigitalWallet : public PaymentMethod {
private:
    double balance;

public:
    DigitalWallet(double initialBalance) : balance(initialBalance) {}

    bool processPayment(double amount) override {
        if (balance >= amount) {
            balance -= amount;
            cout << "Digital Wallet Payment of $" << amount << " successful. Remaining balance: $" << balance << endl;
            return true;
        } else {
            cout << "Insufficient balance in Digital Wallet. Payment failed.\n";
            return false;
        }
    }
};

int main() {
    CreditCard cc("1234567890123456");
    DigitalWallet wallet(100.0);

    PaymentMethod* payment1 = &cc;
    PaymentMethod* payment2 = &wallet;

    cout << "Processing Payments:\n\n";

    payment1->processPayment(50.0);
    cout << "----------------------\n";
    payment2->processPayment(75.0);
    cout << "----------------------\n";
    payment2->processPayment(30.0); 

    return 0;
}
