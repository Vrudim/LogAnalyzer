#include "LogAnalyzer.h"
#include "LogException.h"

#include <fstream>
#include <sstream>
#include <iostream>

void LogAnalyzer::readFile(const std::string& filename){
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw LogException("Impossibile aprire il file " + filename);
    }

    std::string riga;

    while (std::getline(file, riga)){
        if(riga.empty()) continue;

        std::istringstream stream(riga);
        std::string date;
        std::string level;
        std::string message;

        stream>>date>>level;

        if(stream.fail()) throw LogException("Log invalido: " + riga);

        std::getline(stream, message);
        if(!message.empty() && message[0] == ' ') message.erase(0,1);

        entries.emplace_back(date, level, message);
    }
}

void LogAnalyzer::analyze() {
    counters.clear();
    for(const LogEntry& entry : entries) counters[entry.getLevel()]++;
}

void LogAnalayzer::printResults() const {
    for(const auto& [level, count] : counters) std::cout << level << ": " << count << '\n';
}