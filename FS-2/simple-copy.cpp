#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		std::cerr << argv[0] ;
		return 1;
	}

	std::string sourcePath = argv[1];
	std::string destPath = argv[2];

	std::ifstream sourceFile(sourcePath);
	if(!sourceFile){
		std::cerr << "Could not open source file "  << sourcePath << "\n";
		return 1;
	}

	std::ofstream destFile(destPath);
	if(!destFile){
		std::cerr << "Could not open destination file " << destPath << "\n";
		return 1;
	}

	std::string line;
	while(std::getline(sourceFile, line)){
		destFile << line << "\n";
	}

	std::cout << "File copied from " << sourcePath << " to " << destPath << "\n";
	return 0;
}
