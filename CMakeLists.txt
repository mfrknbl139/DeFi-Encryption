cmake_minimum_required(VERSION 3.10)
project(DeFiCryptoProject)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories
include_directories(include)
include_directories(libs/x64-windows/include)
include_directories(libs/x64-windows/include/cryptopp)

# Define the source files and headers for the main application
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/blockchain/*.cpp" "src/models/*.cpp" "src/utils/*.cpp" "src/crypto/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h" "include/blockchain/*.h" "include/models/*.h" "include/utils/*.h" "include/crypto/*.h")

# Add the executable for the main application
add_executable(DeFiProject ${SOURCES} ${HEADERS})

# Specify the path to Crypto++ library
set(CRYPTOPP_DIR "${CMAKE_SOURCE_DIR}/libs/x64-windows")
find_library(CRYPTOPP_LIB cryptopp PATHS ${CRYPTOPP_DIR}/lib)

# Link against the Crypto++ library
target_link_libraries(DeFiProject ${CRYPTOPP_LIB})

# Enable testing functionalities in CMake
enable_testing()

# Define the source files for the tests
file(GLOB_RECURSE TEST_SOURCES tests/*.cpp)

# Add the executable for tests
add_executable(cryptoTests ${TEST_SOURCES} src/crypto/Encryption.cpp src/crypto/Hashing.cpp)

# Link the test executable against Crypto++
target_link_libraries(cryptoTests ${CRYPTOPP_LIB})

# Add the test to CMake's testing framework
add_test(NAME CryptoTests COMMAND cryptoTests)
