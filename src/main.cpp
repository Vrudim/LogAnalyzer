#include "LogAnalyzer.h"
#include "LogException.h"

#include <iostream>

int main()
{
    try {
        LogAnalyzer analyzer;

        analyzer.readFile("data/app.log");
        analyzer.analyze();
        analyzer.printResults();

    } catch (const LogException& e) {
        std::cerr << "Errore: " << e.what() << '\n';
        return 1;

    } catch (const std::exception& e) {
        std::cerr << "Errore inatteso: " << e.what() << '\n';
        return 1;
    }

    return 0;
}