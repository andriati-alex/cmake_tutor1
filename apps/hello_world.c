#include <stdio.h>
#include "displaymsg.h"

/** EXECUTABLE TO TEST THE LIB

This simple executable only test the two functions implemented
in file `src/displaymsg.c` with the input string "hello world"

**/

int main()
{
    char
        c,
        msg[] = "hello world";
    display_msg(msg);
    c = get_indexed_char(msg, 3);
    printf("\nThe fourth character is %c\n", c);
    return 0;
}
