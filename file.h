#ifndef FILE_H
#define FILE_H

bool file_read(struct Text* text);

size_t nStrings(const struct Text* text);

size_t filesize(const char filename[]);

void file_write(const struct String* strings_addresses, const size_t nstrings, const char* filename);

void file_write_buf (const char* buffer, const size_t sizefile, const char* filename);

void clean_file(const char* filename);

void replace_0_to_n(char* buffer, const size_t sizefile);

#endif

