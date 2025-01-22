#include "mmap_utils.h"

int main()
{
    std::string filename = "testfile.txt";

    create_test_file(filename); // Generate a test file
    mmap_read_file(filename);   // Use mmap to read the file without copying

    return 0;
}