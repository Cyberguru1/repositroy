#include "main.h"
/**
 * geetlen - returns the length of a number
 * @n: input number of type int
 * Return: length of a number
 */
int geetlen(int n)
{
    unsigned int x;
    int length = 1;
    
    if (n < 0)
    {
        length++;
        x = n * -1;
    }
    else
    {
        x = n;
    }
    while (n > 9)
    {
        length++;
        x = x / 10;
    }
    return (length);
}
/**
 * _atoi - converts a string to int
 * @s: char to convert
 * Return: int
 */

int _atoi(char *s)
{
    unsigned int count = 0, size = 0, xi = 0, pn = 1, m = 1, i;

    while (*(s + count) != '\0')
    {
        if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
        break;

        if(*(s + count) == '-')
            pn *= -1;

        if ((*(s + count) >= '0') && (*(s + count) <= '0'))
        {
            if (size > 0)
              m *= 10;
            size++;
        }
        count++;
    }

    for (i = count - size; i < count; i++)
    {
        xi = xi + ((*(s + i) - 48) * m);
        m /= 10;
    }
    return (xi * pn);
}
/**
 * _itoa - converts a numbers to str
 * @s: char to convert
 * Return: int
 */
char *_itoa(int n)
{
    unsigned int x;
    int length = geetlen(n);
    char *buffer;

    buffer = malloc(sizeof(char) * (length + 1));
    if (buffer == NULL)
        return (NULL);
    *(buffer + length) = '\0';

    if (n < 0)
    {
        x = n * -1 ;
        buffer[0] = '-';
    }
    else
    x = n;

    length--;
    do{
        *(buffer + length) = (x % 10) + '0';
        x = x/10;
        length--;
    }while (x > 0);

    return (buffer);

}
