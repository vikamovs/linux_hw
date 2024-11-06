#include <iostream>
#include <fstream>
#include <unistd.h>
#include <fcntl.h>

void initialize(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "./redirect-cin <input file path>" << std::endl;
		exit(1);
	}

	int fileDescriptor = open(argv[1], O_RDONLY);
	if (fileDescriptor == -1) {
		std::cerr << "Could not open file." << std::endl;
		exit(1);
	}

	if (dup2(fileDescriptor, STDIN_FILENO) == -1) {
		std::cerr << "Could not redirect input." << std::endl;
		close(fileDescriptor);
		exit(1);
	}

	close(fileDescriptor);
}

int main(int argc, char** argv) {
	initialize(argc, argv);
	std::string input;
	std::cin >> input;
	std::string reversed(input.rbegin(), input.rend());
	std::cout << reversed << std::endl;

	return 0;
}
