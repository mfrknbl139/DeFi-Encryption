#include "crypto/Encryption.h"
#include "crypto/Hashing.h"
#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>
#include <iostream>
#include <string>
#include <cassert>

int main() {
    // Example test: Hashing functionality
    std::string originalText = "Hello, world!";
    std::string hashedText = simpleHash(originalText); // Assuming simpleHash is a function you implemented

    assert(!hashedText.empty() && "Hashed text should not be empty.");

    // Example test: Encryption and decryption (simplified)
    std::string encryptedData = encryptData(originalText); // Assuming encryptData is your function
    std::string decryptedData = decryptData(encryptedData); // Assuming decryptData is your function

    assert(decryptedData == originalText && "Decrypted data should match the original.");

    std::cout << "All tests passed." << std::endl;
    return 0;
}
