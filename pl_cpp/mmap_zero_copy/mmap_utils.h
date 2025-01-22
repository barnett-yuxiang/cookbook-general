#ifndef MMAP_UTILS_H
#define MMAP_UTILS_H

#include <string>

void create_test_file(const std::string &filename);
void mmap_read_file(const std::string &filename);

#endif // MMAP_UTILS_H