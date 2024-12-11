#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <cstring>
#include <cerrno>

int main(int argc, char* argv[]) 
{
	if (argc != 2) {
		std::cerr << "use ./hacker-rm" << std::endl;
		return 1;
	}
	const char* filePath = argv[1];
	struct stat fileStat;
	if (stat(filePath, &fileStat) != 0) {
		std::cerr << "Error: " << std::strerror(errno) << std::endl;
		return 1;
	}
	int fd = open(filePath, O_WRONLY);
	if (fd == -1) {
		std::cerr << "Error: " << std::strerror(errno) << std::endl;
		return 1;
	}
	if (lseek(fd, 0, SEEK_END) == -1) {
		std::cerr << "Error: " << std::strerror(errno) << std::endl;
		close(fd);
		return 1;
	}
	off_t fileSize = fileStat.st_size;
	char nullByte = '\0';
	for (off_t i = 0; i < fileSize; ++i) {
		if (write(fd, &nullByte, 1) != 1) {
			std::cerr << "Error: " << std::strerror(errno) << std::endl;
			close(fd);
			return 1;
		}
	}
	close(fd);
	if (unlink(filePath) != 0) {
		std::cerr << "Error: " << std::strerror(errno) << std::endl;
		return 1;
	}
	std::cout << filePath << std::endl;
	return 0;
}
