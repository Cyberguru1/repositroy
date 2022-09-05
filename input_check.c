#include "main.h"
/**
 * repeated_char - counts the repetitions of character in a string
 * @input: inputed string
 * @i: index of char to check at
 * Return: number of repetitions
 */
int repeated_char(char *input, int i)
{
    if(*(input - i) == *input)
       return (repeated_char(input - 1, i + 1));
    return (i);
}
