#include "blockchain/Block.h"
#include "crypto/Hashing.h"
#include <sstream>
#include <iomanip>

// Varsayılan yapıcı
Block::Block() : index(0), timestamp(0), data(""), nonce(-1), hash(""), prevHash("") {}

// Parametreli yapıcı
Block::Block(uint32_t indexIn, const std::string& dataIn) : index(indexIn), data(dataIn) {
    nonce = -1;
    timestamp = std::time(nullptr);
    hash = calculateHash();
}

std::string Block::calculateHash() const {
    std::stringstream ss;
    ss << index << timestamp << data << nonce << prevHash;
    return simpleHash(ss.str());
}

void Block::mineBlock(uint32_t difficulty) {
    char* cstr = new char[difficulty + 1];
    for (uint32_t i = 0; i < difficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[difficulty] = '\0';
    std::string str(cstr);

    do {
        nonce++;
        hash = calculateHash();
    } while (hash.substr(0, difficulty) != str);

    delete[] cstr;
}
