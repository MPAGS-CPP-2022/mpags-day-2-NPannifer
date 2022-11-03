#include <vector>
#include <string>
#include <iostream>

#include "processCommandLine.hpp"

bool processCommandLine(
const std::vector<std::string>& cmdLineArgs,
bool& helpRequested,
bool& versionRequested,
std::string& inputFileName,
std::string& outputFileName,
int& shift)
{
    const std::size_t nCmdLineArgs{cmdLineArgs.size()};

    for (std::size_t i{1}; i < nCmdLineArgs; ++i) {
        if (cmdLineArgs[i] == "-h" || cmdLineArgs[i] == "--help") {
            helpRequested = true;
        } else if (cmdLineArgs[i] == "--version") {
            versionRequested = true;
        } else if (cmdLineArgs[i] == "-i") {

            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -i requires a filename argument"
                          << std::endl;

                return false;
            } else {
                inputFileName = cmdLineArgs[i + 1];
                ++i;
            }
        } else if (cmdLineArgs[i] == "-o") {
            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -o requires a filename argument"
                          << std::endl;
                return false;
            } else {
                outputFileName = cmdLineArgs[i + 1];
                ++i;
            }
        } else if (cmdLineArgs[i] == "-ccs") {
            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -ceasar-cipher-shift requires a key (int) argument"
                          << std::endl;
                return false;
            } else {
                shift = std::stoi(cmdLineArgs[i + 1]);
                ++i;
            }
        } else {

            std::cerr << "[error] unknown argument '" << cmdLineArgs[i]
                      << "'\n";
            return false;
        }
    }
    return true;
}