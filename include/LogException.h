#pragma once

#include <stdexcept>
#include <string>

class LogException : public std::runtime_error {
    public:
        explicit LogException(const std::string& message) : std::runtime_error(message) {}
};