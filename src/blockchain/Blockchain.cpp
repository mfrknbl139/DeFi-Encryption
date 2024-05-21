#include "blockchain/Blockchain.h"
#include "crypto/Hashing.h"
#include <iostream>

Blockchain::Blockchain() {
    chain.emplace_back(Block(0, "Genesis Block"));
    difficulty = 4;
}

void Blockchain::addBlock(Block newBlock) {
    newBlock.setPrevHash(getLastBlock().getHash());
    newBlock.mineBlock(difficulty);
    chain.push_back(newBlock);
}

Block Blockchain::getLastBlock() const {
    return chain.back();
}

uint32_t Blockchain::getNextBlockNumber() const {
    return static_cast<uint32_t>(chain.size());
}

void Blockchain::printChain() const {
    for (const auto& block : chain) {
        std::cout << "Block " << block.getIndex() << " [" << block.getHash() << "]" << std::endl;
        std::cout << "Previous Hash: " << block.getPrevHash() << std::endl;
        std::cout << "Data: " << block.getData() << std::endl;
        std::cout << "Nonce: " << block.getNonce() << std::endl;
        std::cout << "Timestamp: " << block.getTimestamp() << std::endl;
        std::cout << "-------------------------------" << std::endl;
    }
}
