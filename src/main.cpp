#include "Blockchain.h"
#include "Wallet.h"
#include "Transaction.h"
#include "Utils.h"
#include <iostream>

int main() {
    // Initialize blockchain and wallets
    Blockchain simpleChain;
    Wallet aliceWallet;
    Wallet bobWallet;

    // Simulate transactions
    Transaction tx1(aliceWallet.getAddress(), bobWallet.getAddress(), 100);
    Transaction tx2(bobWallet.getAddress(), aliceWallet.getAddress(), 50);

    std::cout << "Alice's Address: " << aliceWallet.getAddress() << std::endl;
    std::cout << "Bob's Address: "   << bobWallet.getAddress() << std::endl;

    // Add a block to the blockchain
    simpleChain.addBlock(Block(1, tx1.toString()));
    simpleChain.addBlock(Block(2, tx2.toString()));

    // Output the blockchain data
    std::cout << "Blockchain: " << std::endl;
    simpleChain.printChain();

    return 0;
}
