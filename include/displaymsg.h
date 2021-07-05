/****************************************************************************
 * Copyright (C) 2021 by Alex Andriati                                      *
 *                                                                          *
 * This file is part of of silly cmake project example.                     *
 *                                                                          *
 *   cmake_example is a free and almost useless software just to practice   *
 *   some development standards which seems fundamental for whose want to   *
 *   learn a bit of cmake and distribute some package.                      *
 *                                                                          *
 *   See http://fnch.users.sourceforge.net/doxygen_c.html                   *
 ****************************************************************************/


/**
 * @file display_msg.h
 * @date 02 july 2021
 *
 * @brief File containing the function signatures following doxygen conventions
 *
 * Here typically goes a more extensive explanation of what the header
 * defines. Doxygens tags are words preceeded by either a backslash @\
 * or by an at symbol @@.
 */


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
