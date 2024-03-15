#include "Transaction.h"

Transaction::Transaction(const std::string& fromAddress, const std::string& toAddress, float amount) {
    this->fromAddress = fromAddress;
    this->toAddress = toAddress;
    this->amount = amount;
}

std::string Transaction::toString() const {
    return fromAddress + "->" + toAddress + ": " + std::to_string(amount);
}
