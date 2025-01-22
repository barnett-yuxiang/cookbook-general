#include "mmap_utils.h"
#include <iostream>
#include <fstream>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

void create_test_file(const std::string &filename)
{
    std::ofstream file(filename, std::ios::binary);
    if (file)
    {
        file << "Hello, mmap zero-copy on macOS!\n";
        file.close();
    }
    else
    {
        std::cerr << "Failed to create test file.\n";
        exit(1);
    }
}

void mmap_read_file(const std::string &filename)
{
    int fd = open(filename.c_str(), O_RDONLY);
    if (fd == -1)
    {
        std::cerr << "Error opening file.\n";
        return;
    }

    struct stat sb;
    if (fstat(fd, &sb) == -1)
    {
        std::cerr << "Error getting file size.\n";
        close(fd);
        return;
    }

    size_t file_size = sb.st_size;

    // Use mmap for zero-copy memory mapping
    void *mapped_mem = mmap(nullptr, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (mapped_mem == MAP_FAILED)
    {
        std::cerr << "Error mapping file.\n";
        close(fd);
        return;
    }

    // Print file content directly from memory
    std::cout << "File content (via mmap): "
              << std::string(static_cast<char *>(mapped_mem), file_size)
              << std::endl;

    // Cleanup
    munmap(mapped_mem, file_size);
    close(fd);
}