#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

int main(int argc, char* argv[]) 
{
	if (argc != 2) 
	{
		std::cerr << "Usage: " << argv[0] << " <filepath>" << std::endl;
		return 1;
	}

	const char* filepath = argv[1];
	int fd1 = open(filepath, O_RDWR | O_CREAT, 0644);
	if (fd1 < 0) 
	{
		std::cerr << "Error: " << filepath << std::endl;
		return 1;
	}

	int fd2 = dup(fd1);
	if (fd2 < 0) 
	{
		std::cerr << "Error" << std::endl;
		close(fd1);
		return 1;
	}

	const char* first_line = "first line\n";
	if (write(fd1, first_line, strlen(first_line)) < 0) 
	{
		std::cerr << "Error" << std::endl;
		close(fd1);
		close(fd2);
		return 1;
	}

	const char* second_line = "second line\n";
 	if (write(fd2, second_line, strlen(second_line)) < 0) 
	{
		std::cerr << "Error" << std::endl;
		close(fd1);
		close(fd2);
		return 1;
	}

	close(fd1);
	close(fd2);

	return 0;
}
