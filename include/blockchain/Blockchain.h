#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include "Block.h"

class Blockchain {
public:
    Blockchain();

    void addBlock(Block newBlock);
    Block getLastBlock() const;
    void printChain() const;
    uint32_t getNextBlockNumber() const; // Yeni fonksiyon

private:
    std::vector<Block> chain;
    uint32_t difficulty;

    Block createGenesisBlock() const;
};

#endif // BLOCKCHAIN_H
