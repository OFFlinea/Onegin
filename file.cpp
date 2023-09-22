#include <stdio.h>
#include <sys/stat.h>
#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "file.h"

bool file_read(struct Text* text) {

    assert(text);

    const size_t LEN_FILENAME = 15;
    const char filename[LEN_FILENAME] = "Onegin.txt";
    FILE* file = fopen(filename, "r");

    if (!file) {

        printf("%s\n", strerror(errno));
        return false;
    }

    text->sizefile = filesize(filename);

    text->buffer = (char*) calloc(text->sizefile + 1, sizeof(char));

    if (!text->buffer) {

        printf("No memory\n");
        return false;
    }

    fread(text->buffer, sizeof(char), text->sizefile, file);

    text->nstrings = nStrings(text);

    fclose(file);

    return true;
}


size_t nStrings(const struct Text* text) {

    assert(text);
    assert(text->buffer);

    size_t count_strings = 0;

    for(size_t nchar = 0; nchar < text->sizefile; nchar++) {

        count_strings += (text->buffer[nchar] == '\n') ? 1 : 0;
    }

    return count_strings + 1;
}


size_t filesize(const char filename[]) {

    assert(filename);

    struct stat sizze = {};

    if (stat(filename, &sizze) == -1) {

        printf("%s\n", strerror(errno));
        return 0;
    }

    return sizze.st_size;
}


void file_write(const struct String* strings_addresses, const size_t nstrings, const char* filename) {

    assert(strings_addresses);
    assert(strings_addresses->address);
    assert(filename);

    FILE* file = fopen(filename, "a");

    if (!file) {

        printf("%s\n", strerror(errno));
        return;
    }

    for (size_t nstr = 0; nstr < nstrings; nstr++) {

        fputs(strings_addresses[nstr].address, file);
        fputc('\n', file);
    }

    fputc('\n', file);
    fclose(file);
}


void clean_file(const char* filename) {

    assert(filename);

    FILE* file = fopen(filename, "w");
    fclose(file);
}


void file_write_buf(const char* buffer, const size_t sizefile, const char* filename) {

    assert(buffer);
    assert(filename);

    FILE* file = fopen(filename, "a");

    fwrite(buffer, sizeof(char), sizefile, file);

    fclose(file);

}


void replace_0_to_n(char* buffer, const size_t sizefile) {

    assert(buffer);

    for (size_t nchar = 0; nchar < sizefile; nchar++) {

        if (buffer[nchar] == '\0') {

            buffer[nchar] = '\n';
        }
    }
}

