#include <cctype>
#include <vector>
#include <iostream>
#include <string>


#include "TransformChar.hpp"
#include "processCommandLine.hpp"


std::string transformChar( const char in_char );



int main(int argc, char* argv[])
{
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};

    bool helpRequested{false};
    bool versionRequested{false};
    std::string inputFile{""};
    std::string outputFile{""};

    bool commandLineArgValid{processCommandLine(cmdLineArgs, helpRequested, versionRequested, inputFile, outputFile)};
    if(!commandLineArgValid){std::exit(-1);}

    if (helpRequested) {

        std::cout
            << "Usage: mpags-cipher [-h/--help] [--version] [-i <file>] [-o <file>]\n\n"
            << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
            << "Available options:\n\n"
            << "  -h|--help        Print this help message and exit\n\n"
            << "  --version        Print version information\n\n"
            << "  -i FILE          Read text to be processed from FILE\n"
            << "                   Stdin will be used if not supplied\n\n"
            << "  -o FILE          Write processed text to FILE\n"
            << "                   Stdout will be used if not supplied\n\n"
            << std::endl;
        return 0;
    }

    if (versionRequested) {
        std::cout << "0.3.0" << std::endl;
        return 0;
    }

    std::cout << inputFile << "    " << outputFile << std::endl;

    char inputChar{'x'};
    std::string inputText;


    if (!inputFile.empty()) {
        std::cerr << "[warning] input from file ('" << inputFile
                  << "') not implemented yet, using stdin\n";
    }


    while (std::cin >> inputChar) {

        inputText += transformChar(inputChar);

    }

    if (!outputFile.empty()) {
        std::cerr << "[warning] output to file ('" << outputFile
                  << "') not implemented yet, using stdout\n";
    }

    std::cout << inputText << std::endl;

    return 0;
}