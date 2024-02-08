#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char **argv) {
	// Manage invalid argument number.
	if (argc != 4)
		return (std::cerr << "Invalid argument number" << std::endl, 1);
	
	// Opening the file and assigning it to an input file stream class.
	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open())
		return(std::cerr << "Error opening input file: " << argv[1] << std::endl, 1);

	// Getting the content out using an iteration function, the ostringstream
	// variable acts as a buffer for the content. 
	std::ostringstream contentStream;
	contentStream << inputFile.rdbuf();
	inputFile.close();

	// Assigning the content to a string variable.
	std::string fileContent = contentStream.str();
	
    std::string searchString = argv[2];
    std::string replacementString = argv[3];
    std::string modifiedContent;

    size_t pos = 0;
    size_t foundPos = fileContent.find(searchString);

    while (foundPos != std::string::npos) {
        // Appending characters before the found position.
        modifiedContent += fileContent.substr(pos, foundPos - pos);

        // Appending the replacement string.
        modifiedContent += replacementString;

        // Updating the position for the next search.
        pos = foundPos + searchString.length();

        // Finding the next occurrence.
        foundPos = fileContent.find(searchString, pos);
    }

    // Append the remaining characters after the last occurrence.
    modifiedContent += fileContent.substr(pos);

	// Creating the .replace file name.
	std::string	previousFilenName = argv[1];
	previousFilenName.append(".replace");

	// Creating a file with the new name and checking if its open.
    std::ofstream	outputFile(previousFilenName.c_str());
	if (!outputFile.is_open())
		return(std::cerr << "Error opening output file: " << previousFilenName << std::endl, 1);
	
	// Truncating the content of modifiedContent into the newly created file, and then closing it.
	outputFile << modifiedContent;
	outputFile.close();
}
