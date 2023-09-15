#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "structures.h"
#include "text.h"

bool text_read(struct Text* text) {

    assert(text->buffer);

    text->strings_addresses = (struct String*) calloc(text->nstrings, sizeof(struct String));

    if (!text->strings_addresses) {

        printf("No memory\n");
        return false;
    }

    text->strings_addresses[0] = {text->buffer, 0};
    size_t number_string = 1;
    size_t number_char = 0;
    size_t len = 1;

    while (text->buffer[number_char]) {

        assert(number_char < text->sizefile);

        if (text->buffer[number_char] == '\n') {

            assert(number_string < text->nstrings);

            text->buffer[number_char] = '\0';

            text->strings_addresses[number_string++] = {text->buffer + number_char + 1, 0};

            text->strings_addresses[number_string - 2].len = len;

            len = 0;
        }
        number_char++;
        len++;
    }

    text->strings_addresses[number_string - 1].len = len;


    return true;
}


void print_text(const struct Text* text) {

    assert(text->buffer);
    assert(text->strings_addresses->address);

    for (size_t i = 0; i < text->nstrings; i++) {

        printf("%s\n", text->strings_addresses[i].address);
    }
    putchar('\n');
}


void destroy_text(struct Text* text) {

    assert(text->buffer);
    assert(text->strings_addresses);

    free(text->strings_addresses);
    text->strings_addresses = NULL;

    text->nstrings = 0;

    free(text->buffer);
    text->buffer = NULL;

    text->sizefile = 0;
}

