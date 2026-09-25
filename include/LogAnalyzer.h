#pragma once

#include "LogEntry.h"
#include <map>
#include <string>
#include <vector>

class LogAnalyzer {
    private:
        std::vector<LogEntry> entries;
        std::map<std::string, int> counters;

    public:
        void readFile(const std::string& filename);
        void analyze();
        void printResults() const;
};