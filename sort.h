#ifndef SORT_H
#define SORT_H

void Swap(struct String* strings_addresses, size_t pos1, size_t pos2);

bool skip_no_alpha(const char c, int* counter, const bool revers);

int Strcmp(const struct String* str1, const struct String* str2);

int Strcmp_reverse(const struct String* str1, const struct String* str2);

void Sort_choice(struct String* strings_addresses, const size_t nstrings, int (*comp)(const String*, const String*));

size_t FindMin(struct String* strings_addresses, const size_t nstrings, int (*comp)(const String*, const String*));

#endif

