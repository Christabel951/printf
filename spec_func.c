#include <unistd.h>
/*
 * _printch - print characters to display
 * @c: char to be printed
 * Return: number of bytes
 */
int _printch(char c)
{
	return (write(1, &c, 1));
}
/**
 * _strlen - calc length of string.
 * @s: pointer to a char.
 * Return: length of string
 */
int _strlen(char *s)
{
	int counter = 0;

	while (*s != '\0')
	{
		s++;
		counter++;
	}
	return (counter);
}
/*
 * _printstr - print characters in string
 * @str: string value to be printed
 * Return: number of bytes
 */
int _printstr(char *str)
{
	if (str)
		return (write(1, str, _strlen(str)));
	return (-1);
}
