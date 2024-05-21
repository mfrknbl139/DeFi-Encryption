#include "models/Transaction.h"

Transaction::Transaction(const std::string& sender, const std::string& receiver, double amount)
    : fromAddress(sender), toAddress(receiver), amount(amount) {}

std::string Transaction::toString() const {
    return "From: " + fromAddress + ", To: " + toAddress + ", Amount: " + std::to_string(amount);
}
