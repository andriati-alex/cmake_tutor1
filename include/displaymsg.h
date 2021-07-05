#include "msgtype.h"

/*! This is the brief fool comment that must be a single line
 *
 * Just a silly implementation to use my custom datatype `msg`
 *
 * @param m Glorious datatype that is just pointer to char. I just like to
 *          write some nonsense to have a longer description
 */
void display_msg(msg m);

/*! This is the brief fool comment that must be a single line
 *
 * Not so useless function to get char at string index
 *
 * @param m Glorious datatype that is just pointer to char
 * @param ind index to take the character
 *
 * @return character @c m[ind]
 */
char get_indexed_char(msg m, int ind);
