//
//Contains Functions to be used throughout DMTools Project
//

#include "DMTools_functions.h"

//convert from ascii to Hex
std::string asciiToHex(std::string asciiString)
{
  std::string hexString;
  std::stringstream toHex_stream;
  for (const auto &item : asciiString){
    toHex_stream << std::hex << int(item);
  }
  hexString = toHex_stream.str();
  return hexString;
}

//convert from Hex to ascii
std::string hexToAscii(std::string hexString)
{
  std::string asciiString;
  std::stringstream toAscii_stream;    
  for (size_t i = 0; i < hexString.length(); i += 2)
    {
        std::string part = hexString.substr(i, 2);
        char ch = stoul(part, nullptr, 16);
        asciiString += ch;
    }
  return asciiString;
}

//split string 
std::vector <std::string> split(std::string originalString, char delimiter)
{
	std::stringstream ss(originalString);
	std::string s;
	std::vector <std::string> splitString;

	while (getline(ss, s, delimiter)) {
		splitString.push_back(s);
	}
	return splitString;
}