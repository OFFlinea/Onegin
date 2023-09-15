#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include "structures.h"
#include "sort.h"

void Swap(struct String* strings_addresses, size_t pos1, size_t pos2) {

    assert(strings_addresses);

    String temp = strings_addresses[pos1];

    strings_addresses[pos1] = strings_addresses[pos2];

    strings_addresses[pos2] = temp;
}


int Strcmp(const struct String* str1, const struct String* str2) {

    assert(str1->address);
    assert(str2->address);

    size_t nchar1 = 0, nchar2 = 0;

    while (str1->address[nchar1] != '\0' && str2->address[nchar2] != '\0') {

        if (!isalpha(str1->address[nchar1])) {

            nchar1++;
            continue;
        }

        if (!isalpha(str2->address[nchar2])) {

            nchar2++;
            continue;
        }

        if (str1->address[nchar1] > str2->address[nchar2]) {

            return 1;
        }

        if (str1->address[nchar1] < str2->address[nchar2]) {

            return -1;
        }

        nchar1++;
        nchar2++;
    }

    if (str1->address[nchar1] == '\0' && str2->address[nchar2] != '\0') {

        return -1;
    }

    else if (str2->address[nchar2] == '\0' && str1->address[nchar1] != '\0') {

        return 1;
    }
    return 0;
}


void Sort_choice(struct String* strings_addresses, const size_t nstrings, const bool revers) {

    for (size_t nstr = 0; nstr < nstrings; nstr++) {

        size_t min_str = FindMin(strings_addresses + nstr, nstrings - nstr,
        (revers) ? Strcmp_reverse : Strcmp) + nstr;

        if (min_str == nstr) {

            break;
        }
        Swap(strings_addresses, min_str, nstr);
    }
}


size_t FindMin(struct String* strings_addresses, const size_t nstrings, int (*comp)(const String*, const String*)) {

    size_t min_str = 0;

    for (size_t nstr = 0; nstr < nstrings; nstr++) {

        if ((*comp)(&strings_addresses[min_str], &strings_addresses[nstr]) > 0) {

            min_str = nstr;
        }
    }

    return min_str;
}


int Strcmp_reverse(const struct String* str1, const struct String* str2) {

    assert(str1->address);
    assert(str2->address);

    int nchar1 = str1->len - 1;
    int nchar2 = str2->len - 1;

    while (nchar1 >= 0 && nchar2 >= 0) {

        if (!isalpha(str1->address[nchar1])) {

            nchar1--;
            continue;
        }

        if (!isalpha(str2->address[nchar2])) {

            nchar2--;
            continue;
        }

        if (str1->address[nchar1] > str2->address[nchar2]) {

            return 1;
        }

        if (str1->address[nchar1] < str2->address[nchar2]) {

            return -1;
        }

        nchar1--;
        nchar2--;
    }

    if (nchar1 == -1 && nchar2 != -1) {

        return -1;
    }

    else if (nchar2 == -1 && nchar1 != -1) {

        return 1;
    }

    return 0;
}
