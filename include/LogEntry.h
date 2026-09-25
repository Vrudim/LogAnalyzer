#pragma once

#include <string>

class LogEntry{
    protected:
        std::string date;
        std::string level;
        std::string message;
    
    public:
        LogEntry(
            const std::string& date,
            const std::string& level,
            const std::string& message
        );

        virtual ~LogEntry() = default;
        virtual std::string getLevel() const;
        virtual void print() const;
};