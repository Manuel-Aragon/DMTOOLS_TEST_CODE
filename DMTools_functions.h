//
//Contains Functions to be used throughout DMTools Project
//
#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <vector>


//convert from ascii to Hex
std::string asciiToHex(std::string);

//convert from Hex to ascii
std::string hexToAscii(std::string);

//split string into substrings inside a vector
std::vector <std::string> split(std::string, char);