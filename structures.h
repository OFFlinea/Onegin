#ifndef STRUCTURES_H
#define STRUCTURES_H

struct String
{
    char* address;
    size_t len;
};

struct Text
{
    struct String* strings_addresses;
    size_t nstrings;
    char* buffer;
    size_t sizefile;
};

#endif

