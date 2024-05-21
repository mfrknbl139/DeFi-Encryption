#ifndef WALLET_H
#define WALLET_H

#include <string>
#include <vector>
#include "Transaction.h"

class Wallet {
public:
    Wallet();

    std::string getAddress() const;

    void addTransaction(const Transaction& transaction);

    std::string getPrivateKey() const { return privateKey; }
    std::string getPublicKey() const { return publicKey; }
    
    // Yeni eklenen fonksiyon
    void generateAddress();

private:
    std::string generateAddress(const std::string& publicKey) const;

    std::string privateKey;
    std::string publicKey;
    std::string address;
    std::vector<Transaction> transactions;
};

#endif // WALLET_H
