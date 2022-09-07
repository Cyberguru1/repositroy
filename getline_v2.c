#include "main.h"
/**
 * get_line - program that returns input
 * @buff: buffer to store input
 * @buffsize: size of buffer
 * @fp: file descrptor
 * Return: size of bytes on sucess or -1 on failure
 */
ssize_t get_line(char **buff, size_t *buffsize, FILE *fp)
{   char *ptr, *eptr, *nbuff;
	ssize_t nbuffsize, d;
	int c;
	
	if (*buff == NULL || *buffsize == 0)
	{	*buffsize = BUFFSIZE;
		*buff = malloc(*buffsize);
		if (*buff == NULL)
		return (-1);
	}
	for (ptr = *buff, eptr = *buff + *buffsize;;)
	{
		c = fgetc(fp);
		if (c == -1)
		{
			if (feof(fp))
			return (ptr == *buff ? -1 : ptr - *buff);
			else
			return (-1);
		}
		*ptr++ = c;
		if (c == '\n')
		{	*ptr = '\0';
			return (ptr - *buff);
		}
		if (ptr + 2 >= eptr)
		{   nbuffsize = *buffsize * 2;
			d = ptr - *buff;
			nbuff = realloc(*buff, nbuffsize);
			if (nbuff == NULL)
			return (-1);
			*buff = nbuff;
			*buffsize = nbuffsize;
			eptr = nbuff + nbuffsize;
			ptr = nbuff + d;
		}
	}
}
