// ANNOTATED FILE w. todos

#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std; //added

int main(int argc, char* argv[])
{
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};
    const std::size_t nCmdLineArgs{cmdLineArgs.size()}; //do as function

    bool helpRequested{false};          // pass into function by reference
    bool versionRequested{false};       // pass into function by reference
    std::string inputFile{""};          // pass into function by reference
    std::string outputFile{""};         // pass into function by reference

//-----------------handle-Cmd-args------------------//
/*
void processCmdArgs(
    bool& _helpRequested,
    bool& _versionRequested,
    string& _inputFile,
    string& _outputFile
    const vector<string>& cmdLineArgs){}

-remove else if, use returns
-check for unknown first errors first
-handle errors with exceptions

-creat sub funcitons:
-isHelp string -> bool
-isVersion string -> bool
-getFilename (check flag or empty) cmdArgs 
(-formatFilename (remove extention))
(-printFileExtensionWarning() - warning user of non-text file type not being supported, all filetpye treated as text_)
*/
//-----------------handle-Cmd-args------------------//
    for (std::size_t i{1}; i < nCmdLineArgs; ++i) {
        if (cmdLineArgs[i] == "-h" || cmdLineArgs[i] == "--help") {
            helpRequested = true;
        } else if (cmdLineArgs[i] == "--version") {
            versionRequested = true;
        } else if (cmdLineArgs[i] == "-i") {
            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -i requires a filename argument"
                          << std::endl;
                return 1;
            } else {
                inputFile = cmdLineArgs[i + 1];
                ++i;
            }
        } else if (cmdLineArgs[i] == "-o") {
            if (i == nCmdLineArgs - 1) {
                std::cerr << "[error] -o requires a filename argument"
                          << std::endl;
                return 1;
            } else {
                outputFile = cmdLineArgs[i + 1];
                ++i;
            }
        } else {
            std::cerr << "[error] unknown argument '" << cmdLineArgs[i]
                      << "'\n";
            return 1;
        }
    }
//-----------------handle-Cmd-args------------------//
//-----------------handle-Cmd-args------------------//

    if (helpRequested) {
        std::cout
            << "Usage: mpags-cipher [-h/--help] [--version] [-i <file>] [-o <file>]\n\n" //make into string "help message"
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
        std::cout << "0.1.0" << std::endl;
        return 0;
    }


    char inputChar{'x'};
    std::string inputText;

    if (!inputFile.empty()) {
        std::cerr << "[warning] input from file ('" << inputFile
                  << "') not implemented yet, using stdin\n";
    }
//----------Input//----Convert-to-upper--------------------//
/*
Need to handle to cases input file or user input
if inputExists -> read input; else read from file commandline
functions: readInputFrom(string "file_path"), readInputFrom(istream& stream) -OVERLOAD FUNCTION
these return inputTEXT string

num to string
remove non letters
then convert to upper

*/
//----------Input//----Convert-to-upper--------------------//

    while (std::cin >> inputChar) {
        if (std::isalpha(inputChar)) {
            inputText += std::toupper(inputChar);
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
//-----------------Convert-to-upper--------------------//
//-----------------Convert-to-upper--------------------//

//------------------Encrypt/Decrypt--------------------//
/*
take command line args -ec <shift> -dc <shift>
allow negative arg
update help

function to call void shiftLetters(string& <Letter>, int shift)


*/
//------------------Encrypt/Decrypt--------------------//


//----------------Output--------------------//
/*
if output ->output to file

if none print
*/
//----------------Output--------------------//


    if (!outputFile.empty()) {
        cerr << "[warning] output to file ('" << outputFile
                  << "') not implemented yet, using stdout\n";
    }

    std::cout << inputText << std::endl;
    return 0;
}
//------------------Encrypt/Decrypt-Function--------------------//
//------------------Encrypt/Decrypt-Function-------------------//

/*

Ceasar Cipher method.
0. convert string to upper
1. convert string to in array "abcd" -> {0,1,2,3}
2. added shift element wise modulo 26
3. convert back to string

funcitons needed:
stringToIntArr
    charToInt
intArrToString
    intToChar

shiftIntArr(vector<int>&)

*/