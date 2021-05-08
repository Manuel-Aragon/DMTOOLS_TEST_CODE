//Two functions that will convert between ascii and hex inside of strings, with simple test inside of main.
#include <string>
#include <iostream>
#include <sstream>


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

int main()
{
  std::string test = "TEST NAME MOMDOASMDKL:SADJASKLDJASKLD:SA KLASDJKLASDJASLK:D  SKALJDLK:ASDJALKS:DJASL:KDJSAKD  ";
  std::cout << test << std::endl;
  std::cout << asciiToHex(test) << std::endl;
  std::cout << hexToAscii(asciiToHex(test)) << std::endl;
}