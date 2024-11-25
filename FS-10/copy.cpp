#include <iostream>
#include <fstream>
#include <cstring>
#include <sys/stat.h>
#include <unistd.h>

void print_usage()
{
	std::cerr << "Usage: ./copy source-file destination-file\n";
}

bool file_exists(const std::string& path)
{
	struct stat buffer;
	return (stat(path.c_str(), &buffer) == 0);
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		print_usage();
		return 1;
	}

	std::string source_path = argv[1];
	std::string dest_path = argv[2];
	if (!file_exists(source_path))
	{
		std::cerr << "Error: \n";
		return 1;
	}
	std::ifstream source_file(source_path, std::ios::binary);
	if (!source_file.is_open())
	{
		std::cerr << "Error: \n";
		return 1;
	}
	std::ofstream dest_file(dest_path, std::ios::binary | std::ios::trunc);
	if (!dest_file.is_open())
	{
		std::cerr << "Error: \n";
		return 1;
	}
	char buffer[1024];
	size_t total_copied = 0;
	size_t data_copied = 0;
	size_t holes_copied = 0;
	while (source_file.read(buffer, sizeof(buffer)))
	{
		size_t bytes_read = source_file.gcount();
		total_copied += bytes_read;
		size_t bytes_data = 0;
		size_t bytes_holes = 0;
		for (size_t i = 0; i < bytes_read; ++i)
		{
			if (buffer[i] != '\0')
                		++bytes_data;
			else
				++bytes_holes;
		}
		data_copied += bytes_data;
		holes_copied += bytes_holes;
		dest_file.write(buffer, bytes_read);
	}
	size_t bytes_read = source_file.gcount();
	if (bytes_read > 0)
	{
		total_copied += bytes_read;
		size_t bytes_data = 0;
		size_t bytes_holes = 0;
		for (size_t i = 0; i < bytes_read; ++i)
		{
			if (buffer[i] != '\0')
				++bytes_data;
			else
				++bytes_holes;
		}
		data_copied += bytes_data;
		holes_copied += bytes_holes;
		dest_file.write(buffer, bytes_read);
	}
	source_file.close();
	dest_file.close();
	std::cout << "Successfully copied " << total_copied << " bytes (data: " << data_copied << ", hole: " << holes_copied << ").\n";

	return 0;
}
