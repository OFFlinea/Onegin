#include <stdio.h>
#include "structures.h"
#include "stdio.h"
#include "file.h"
#include "text.h"
#include "sort.h"


int main() {

    struct Text text = {};

    const size_t LEN_FILE = 15;

    char filename_result[LEN_FILE] = "Result.txt";

    clean_file(filename_result);

    file_read(&text);

    text_read(&text);

    Sort_choice(text.strings_addresses, text.nstrings, false);

    print_text(&text);

    file_write(text.strings_addresses, text.nstrings, filename_result);

    Sort_choice(text.strings_addresses, text.nstrings, true);

    print_text(&text);

    file_write(text.strings_addresses, text.nstrings, filename_result);

    replace_0_to_n(text.buffer, text.sizefile);
    file_write_buf(text.buffer, text.sizefile, filename_result);

    destroy_text(&text);

    return 0;

}
