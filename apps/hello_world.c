#include <stdio.h>
#include "displaymsg.h"
#include <stdlib.h>

/*! EXECUTABLE TO TEST THE LIB
 *
 * This simple executable only test the two functions implemented
 * in file `src/displaymsg.c` with the input string "hello world"
 */

int main()
{
    char
        c,
        special_msg[] = "hello world";
    display_msg(special_msg);
    c = get_indexed_char(special_msg, 3);
    printf("\nThe fourth character is %c\n", c);
    display_msg("another hello");
    return 0;
}
