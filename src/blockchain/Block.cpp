#include "Block.h"
#include "Hashing.h" // Assuming Hashing.cpp provides a simpleHash function

Block::Block(uint32_t indexIn, const std::string &dataIn) : index(indexIn), data(dataIn) {
    nonce = -1;
    time = time(nullptr);
    hash = calculateHash();
}

std::string Block::calculateHash() const {
    std::stringstream ss;
    ss << index << time << data << nonce << prevHash;
    return simpleHash(ss.str()); // simpleHash is a simplified hashing function
}
