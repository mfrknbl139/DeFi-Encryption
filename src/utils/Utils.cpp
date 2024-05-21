#include "utils/Utils.h"
#include <chrono>
#include <sstream>

std::string generateUniqueId() {
    auto now = std::chrono::high_resolution_clock::now();
    auto nanos = std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch()).count();
    std::stringstream ss;
    ss << "id_" << nanos;
    return ss.str();
}
