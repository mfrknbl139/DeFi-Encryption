#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <ctime>

class Block {
public:
    Block();
    Block(uint32_t indexIn, const std::string& dataIn);

    std::string calculateHash() const;
    void mineBlock(uint32_t difficulty);

    uint32_t getIndex() const { return index; }
    std::time_t getTimestamp() const { return timestamp; }
    std::string getData() const { return data; }
    std::string getHash() const { return hash; }
    std::string getPrevHash() const { return prevHash; }
    int64_t getNonce() const { return nonce; }

    void setPrevHash(const std::string& prevHashIn) { prevHash = prevHashIn; }
    void setNonce(int64_t nonceIn) { nonce = nonceIn; }
    void setTimestamp(std::time_t timestampIn) { timestamp = timestampIn; }
    void setHash(const std::string& hashIn) { hash = hashIn; }

private:
    uint32_t index;
    std::time_t timestamp;
    std::string data;
    std::string hash;
    std::string prevHash;
    int64_t nonce;
};

#endif // BLOCK_H
