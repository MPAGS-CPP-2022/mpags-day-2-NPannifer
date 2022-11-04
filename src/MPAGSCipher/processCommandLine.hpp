#ifndef MAPGCIPHER_PROCESSCOMMANDLINE_HPP
#define MAPGCIPHER_PROCESSCOMMANDLINE_HPP

#include <vector>
#include <string>

bool processCommandLine(
const std::vector<std::string>& cmdLineArgs,
bool& helpRequested,
bool& versionRequested,
std::string& inputFileName,
std::string& outputFileName,
int& shift);

#endif // MAPGCIPHER_PROCESSCOMMANDLINE_HPP
