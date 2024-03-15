cmake_minimum_required(VERSION 3.10)
project(DeFiCryptoProject)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories
include_directories(include)
include_directories(libs/CryptoPP)

# If Crypto++ is installed system-wide, you might not need the above include_directories line for CryptoPP
# and instead use find_package to locate it, or link it directly if it's in a known location

# Define the source files and headers for the main application
file(GLOB SOURCES "src/*.cpp" "src/blockchain/*.cpp" "src/crypto/*.cpp" "src/models/*.cpp" "src/utils/*.cpp")

# Add the executable for the main application
add_executable(DeFiProject ${SOURCES})

# Link against the Crypto++ library
target_link_libraries(DeFiProject cryptopp)

# For tests
# Enable testing functionalities in CMake
enable_testing()

# Define the source files for the tests
set(TEST_SOURCES tests/crypto_tests.cpp)

# Add the executable for tests
add_executable(cryptoTests ${TEST_SOURCES})

# Link the test executable against Crypto++ (and potentially other libraries)
target_link_libraries(cryptoTests cryptopp)

# Add the test to CMake's testing framework
add_test(NAME CryptoTests COMMAND cryptoTests)
