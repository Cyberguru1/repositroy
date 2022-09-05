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

/**
 * error_sep_op - finds inputed syntax errrors
 * @input: input string
 * @i: index
 * @last: last char read
 * Return: index of char
 */
int error_sep_op(char *input, int i, char last)
{
    int count;

    count = 0;
    if (*input == '\0')
      return (0);
    
    if (*input == ' ' || * input == '\t')
       return (error_sep_op(input + 1, i + 1, last));

    if (*input == ';')
      if (last == '|' || last == '&' || last == ';')
        return (i);
    if (*input == '|')
    {
         if (last == ';' || last == '&') return (i);
         if (last == '|')
         {
             count = repeated_char(input, 0);
             if (count == 0 || count > 1) return (i);
         }
    }
    if (*input == '&')
    {
        if (last == ';' || last == '|') return (i);

        if (last == '&')
        {
            count = repeated_char(input, 0);
            if (count == 0 || count > 1) return (i);
        }
    }
    return (error_sep_op(input + 1, i + 1, *input));

}
