#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>

// Function to encrypt data using Crypto++ library
std::string encryptData(const std::string& data);

// Function to decrypt data using Crypto++ library
std::string decryptData(const std::string& data);

#endif // ENCRYPTION_H
