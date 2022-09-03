#include "main.h"

int _strlen(char *s)
{
    int i;
    while (*s)
    {
        s++;
        i++;
    }
    return i;
}
 char *_strdup(char *s1)
 {
     int i;
     int x;
     char *s2;

     i = _strlen(s1);
     s2 = malloc(sizeof(char) * (i + 1));

     if(!s2)
         return NULL;

     for (x = 0; x <= i; x++)
     {
         s2[x] = s1[x];
     }
     
    return (s2);

 }
 
 int main(void)
 {
     char *str2;
     char str1[] = "hamza";

    str2 = _strdup(str1);

    printf("%s", str2);
 }