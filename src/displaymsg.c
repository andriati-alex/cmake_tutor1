#include <stdio.h>
#include <string.h>
#include "displaymsg.h"


void display_msg(msg s)
{
    /** Dummy function to print on screen **/
    printf("Using function display_msg : ");
    printf("%s", s);
}

char get_indexed_char(msg s, int n)
{
    /**
    Dummy function to return char at index `n` of message `s`
    In case strlen(s) is less or equal to `n` return null char '\0'
    **/
    printf("\nMessage with length = %ld", strlen(s));
    if (strlen(s) > n)
    {
        return s[n];
    }
    return '\0';
}
