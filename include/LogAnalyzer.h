#pragma once

#include "LogEntry.h"
#include <map>
#include <string>
#include <vector>

ckass LogAnalyzer {
    private:
        std::vector<LogEntry> entries;
        std::map<std::string, int> counters;

    public:
        void readFile(const std::string& fileName);
        void analyze();
        void printResults() const;
};