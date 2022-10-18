#include <stdio.h>
#include <stdlib.h>

/**
 * rev_str - reverses a string
 * @str: string parameter to be reversed
 * Return: number of characters printed
 */
char *rev(char *str)
{
	int i, j, len, count = 0;
	char *ptr;
	char tmp;

	for (len = 0; str[len] != '\0'; len++)
		;

	ptr = malloc(sizeof(char) * len + 1);

	for (i = 0; str[i] != '\0'; i++)
		ptr[i] = str[i];
	ptr[i] = '\0';
	
	for (i = 0; i < len; i++, len--)
	{
		tmp = ptr[len - 1];
		ptr[len - 1] = ptr[i];
		ptr[i] = tmp;
	}

	/*for (count = 0; ptr[count]; count++)
		putchar(ptr[count]);*/

	return (ptr);
	
}

int binary(int num)
{
	int i, len = 0;

	char s[100];
	char *b;

	i = 0;
	while (num > 0)
	{
		s[i] = (num % 2) + '0';
		num /= 2;
		i++;
	}
	b = rev(s);

	b[i] = '\0';

	for (i = 0; b[i]; i++)
		putchar(b[i]);
	putchar('\n');
	return (i);
}

int main(void)
{
	int len;

	len = binary(98);
	printf("%d\n", len);

	return (0);
}
