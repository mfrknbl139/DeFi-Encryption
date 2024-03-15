#include "Wallet.h"
#include "Hashing.h" // For generating a wallet address based on a public key
#include "Encryption.h" // For key generation and encryption functionalities

Wallet::Wallet() {
    // In a real-world scenario, generate a public/private key pair
    // For this example, we simulate this with a simple unique identifier
    privateKey = "private_key_sim";
    publicKey = "public_key_sim";
    address = simpleHash(publicKey); // Use a hash of the public key as the address
}

std::string Wallet::getAddress() const {
    return address;
}

void Wallet::addTransaction(Transaction& transaction) {
    transactions.push_back(transaction);
}
