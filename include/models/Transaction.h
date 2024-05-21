#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
public:
    Transaction(const std::string& sender, const std::string& receiver, double amount);
    
    std::string toString() const;

    std::string getFromAddress() const { return fromAddress; }
    std::string getToAddress() const { return toAddress; }
    double getAmount() const { return amount; }

private:
    std::string fromAddress;
    std::string toAddress;
    double amount;
};

#endif // TRANSACTION_H
