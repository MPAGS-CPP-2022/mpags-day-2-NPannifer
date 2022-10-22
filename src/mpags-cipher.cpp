#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
    const vector<string> cmdLineArgs{argv, argv + argc};
    const size_t nCmdLineArgs{cmdLineArgs.size()};

    bool helpRequested{false};
    bool versionRequested{false};
    string inputFile{""};
    string outputFile{""};

    for (size_t i{1}; i < nCmdLineArgs; ++i) {
        if (cmdLineArgs[i] == "-h" || cmdLineArgs[i] == "--help") {
            helpRequested = true;
        } else if (cmdLineArgs[i] == "--version") {
            versionRequested = true;
        } else if (cmdLineArgs[i] == "-i") {
            if (i == nCmdLineArgs - 1) {
                cerr << "[error] -i requires a filename argument"
                          << endl;
                return 1;
            } else {
                inputFile = cmdLineArgs[i + 1];
                ++i;
            }
        } else if (cmdLineArgs[i] == "-o") {
            if (i == nCmdLineArgs - 1) {
                cerr << "[error] -o requires a filename argument"
                          << endl;
                return 1;
            } else {
                outputFile = cmdLineArgs[i + 1];
                ++i;
            }
        } else {
            cerr << "[error] unknown argument '" << cmdLineArgs[i]
                      << "'\n";
            return 1;
        }
    }

    if (helpRequested) {
        cout
            << "Usage: mpags-cipher [-h/--help] [--version] [-i <file>] [-o <file>]\n\n"
            << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
            << "Available options:\n\n"
            << "  -h|--help        Print this help message and exit\n\n"
            << "  --version        Print version information\n\n"
            << "  -i FILE          Read text to be processed from FILE\n"
            << "                   Stdin will be used if not supplied\n\n"
            << "  -o FILE          Write processed text to FILE\n"
            << "                   Stdout will be used if not supplied\n\n"
            << endl;
        return 0;
    }

    if (versionRequested) {
        cout << "0.1.0" << endl;
        return 0;
    }

    char inputChar{'x'};
    string inputText;

    if (!inputFile.empty()) {
        cerr << "[warning] input from file ('" << inputFile
                  << "') not implemented yet, using stdin\n";
    }

    while (cin >> inputChar) {

        if (isalpha(inputChar)) {
            inputText += toupper(inputChar);
            continue;
        }

        switch (inputChar) {
            case '0':
                inputText += "ZERO";
                break;
            case '1':
                inputText += "ONE";
                break;
            case '2':
                inputText += "TWO";
                break;
            case '3':
                inputText += "THREE";
                break;
            case '4':
                inputText += "FOUR";
                break;
            case '5':
                inputText += "FIVE";
                break;
            case '6':
                inputText += "SIX";
                break;
            case '7':
                inputText += "SEVEN";
                break;
            case '8':
                inputText += "EIGHT";
                break;
            case '9':
                inputText += "NINE";
                break;
        }

    }

    if (!outputFile.empty()) {
        cerr << "[warning] output to file ('" << outputFile
                  << "') not implemented yet, using stdout\n";
    }

    cout << inputText << endl;

    return 0;
}