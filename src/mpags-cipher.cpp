#include <cctype>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>


#include "TransformChar.hpp"
#include "processCommandLine.hpp"
#include "runCaesarCipher.hpp"

std::string transformChar( const char in_char );



int main(int argc, char* argv[])
{
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};

    bool helpRequested{false};
    bool versionRequested{false};
    std::string inputFile{""};
    std::string outputFile{""};
    int shift{0};

    bool commandLineArgValid{processCommandLine(cmdLineArgs, helpRequested, versionRequested, inputFile, outputFile, shift)};
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
            << "  -ccs KEY         Caesar-Cipher-Shift: key to encrypt with\n\n"
            << "                   to decrypt use reverse sign.\n\n"
            << std::endl;
        return 0;
    }

    if (versionRequested) {
        std::cout << "0.3.0" << std::endl;
        return 0;
    }

    char inputChar{'x'};
    std::string inputText;

    if (inputFile.empty()){
        while (std::cin >> inputChar) {
            inputText += transformChar(inputChar);
        }
    }else{
        std::ifstream in_file {inputFile};
        bool ok_to_read = in_file.good();

        if(!ok_to_read){std::exit(-1);}

        while (in_file >> inputChar) {
        inputText += transformChar(inputChar);
        }
    }

    std::string cipherText{runCaesarCipher(inputText,shift)};

    if (outputFile.empty()){
        std::cout << inputText << std::endl;
    }else{
        std::ofstream out_file {outputFile};
        bool ok_to_write = out_file.good();

        if(!ok_to_write){std::exit(-1);}

        out_file << cipherText;
    }

    return 0;
}