#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define _GNU_SOURCE

/**
 * collatz - tries the collatz conjecture in finite steps
 * @n: positive integer
 * @steps: finite value for sequence
 * Return: 1 if conjecture proven, else 0
 */
int collatz(int n, int steps)
{
	int count = 0;
	char *separation = "";
	
	if (n < 0)
	{
		printf("Value cannot be negative.\n");
		return (0);
	}

	if (n == 0)
		n = n % 2;
	if (n == 1)
		n = (3 * n) + 1;
	
	printf("Value => [%d]\n", n);

	putchar('{');
	printf("%s", separation);

	while (n)
	{
		if (count == steps - 1)
			break;
		if (n == 1)
		{
			printf("%s%d", separation, n);
			putchar('}');
			printf("\n");
			printf("Number of steps taken => %d\n", count);
			return (1);
		}
		count++;

		printf("%s%d", separation, n);
		separation = ", ";

		if (n % 2 == 0)
		{
			n = n / 2;
			continue;
		}
		else if (n % 2)
		{
			n = (3 * n) + 1;
			continue;
		}
	}
	putchar('}');
	printf("\n");
	printf("Number of steps taken => %d\n", count);
	return (0);
}

int main(int argc, char **argv)
{
	int steps = 500;
	int return_val;
	int val;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: ./col value\n");
	}

	val = atoi(argv[1]);
	printf("val = %d\n", val);

	return_val = collatz(val, steps);
	
	if (return_val)
		printf("Return value of => [%d] confirms collatz sequence"
				" in [%d] steps\n",
				return_val, steps);
	else
		printf("Return value of => [%d] does not agree with collatz"
				" sequence in [%d] steps\n",
				return_val, steps);

	return (0);
}
