#include <iostream>
#include <fstream>
#include <cstring>

void readFile(const char *filePath) {
    std::ifstream file(filePath);
    if (!file) {
        std::cerr << "Error: Could not open file " << filePath << std::endl;
        return;
    }

    const size_t bufferSize = 1024;
    char buffer[bufferSize];
    while (file.read(buffer, bufferSize)) {
        std::cout.write(buffer, file.gcount());
    }
    std::cout.write(buffer, file.gcount());
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Error: No file path provided." << std::endl;
        return 1;
    }
    readFile(argv[1]);
    return 0;
}
