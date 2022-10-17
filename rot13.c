#include <stdio.h>
#include <stdlib.h>

int rot(char *str)
{
	int i, j, len, count;
	char *ptr;
	char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (len = 0; str[len] != '\0'; len++)
		;

	ptr = malloc(sizeof(char) * len + 1);

	for (i = 0; str[i] != '\0'; i++)
	{
		ptr[i] = str[i];
	}
	ptr[i] = '\0';

	for (i = 0; ptr[i] != '\0'; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (ptr[i] == alpha[j])
			{
				ptr[i] = rot[j];
				break;
			}
		}
	}
	for (count = 0; ptr[count]; count++)
	{
		putchar(ptr[count]);
	}
	putchar('\n');
	free (ptr);

	return (count);
	
}

int main(void)
{
	char str[] = "Why did the chicken cross the road?";
	int len;

	len = rot(str);

	printf("%d\n", len);

	return (0);
}
