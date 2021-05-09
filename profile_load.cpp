#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


//convert from ascii to Hex
std::string asciiToHex(std::string);

//convert from Hex to ascii
std::string hexToAscii(std::string);

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

//split 
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





int main()
{
    std::string TEMP;
	std::ifstream DATAFILE;
 	DATAFILE.open("Profile.txt", std::ios::in);
 	//LOAD PROFILE NAME
 	std::getline(DATAFILE, TEMP);
		 std::string ProfileName = "";
	 ProfileName = hexToAscii(TEMP);
		 std::cout << ProfileName << std::endl;
	//LOAD Player INFORMATION
	int spaceCounter = 0;

    std::getline(DATAFILE, TEMP);
	
	std::cout << TEMP << std::endl;

	std::vector <std::string> splitStrings (0);
	splitStrings =  split(TEMP, ' ');
	

	for (int i = 0; i < splitStrings.size(); i++)
	{
		std::cout << splitStrings[i] << std::endl;	
	}

		for (int i =0; i < splitStrings.size(); i++)
	{
		splitStrings[i].assign(hexToAscii(splitStrings[i]));
	}
	
	for (int i = 0; i < splitStrings.size(); i++)
	{
		std::cout << splitStrings[i] << std::endl;	
	}

 }