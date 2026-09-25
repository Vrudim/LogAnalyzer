#include "LogEntry.h"
#include <iostream>

LogEntry::LogEntry(const std::string& date, const std::string& level, const std::string& mesage) : date(date), level(level), message(mesage) {}

std::string LogEntry::getLevel() const {
    return level;
}

void LogEntry::print() const {
    std::cout << date << " " << level << " " << message << "\n";
}