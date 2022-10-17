#include <stdio.h>
#include <stdlib.h>

/**
 * rev_str - reverses a string
 * @str: string parameter to be reversed
 * Return: number of characters printed
 */
int rev(char *str)
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

	for (count = 0; ptr[count]; count++)
		putchar(ptr[count]);

	putchar('\n');
	free (ptr);

	return (count);
	
}

int main(void)
{
	char str[] = "Why did the chicken cross the road? Applying ROT13 to a piece of text.";
	int len;

	len = rev(str);

	printf("%d\n", len);

	return (0);
}
