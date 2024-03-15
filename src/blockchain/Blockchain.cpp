#include "Blockchain.h"
#include "Hashing.h" // For hashing functionalities

Blockchain::Blockchain() {
    chain.emplace_back(Block(0, "Genesis Block"));
    difficulty = 4;
}

void Blockchain::addBlock(Block newBlock) {
    newBlock.prevHash = getLastBlock().getHash();
    newBlock.mineBlock(difficulty);
    chain.push_back(newBlock);
}

Block Blockchain::getLastBlock() const {
    return chain.back();
}
