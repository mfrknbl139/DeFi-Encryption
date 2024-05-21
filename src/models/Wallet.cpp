#include "models/Wallet.h"
#include "crypto/Hashing.h"

Wallet::Wallet() {
    privateKey = "private_key_sim";
    publicKey = "public_key_sim";
    address = generateAddress(publicKey);
}

std::string Wallet::getAddress() const {
    return address;
}

void Wallet::addTransaction(const Transaction& transaction) {
    transactions.push_back(transaction);
}

void Wallet::generateAddress() {
    address = generateAddress(publicKey);
}

std::string Wallet::generateAddress(const std::string& publicKey) const {
    return simpleHash(publicKey);
}
