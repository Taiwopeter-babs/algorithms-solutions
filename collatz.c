#include <stdio.h>
#include <stdlib.h>
/**
 * collatz - tries the collatz conjecture in finite steps
 * @n: positive integer
 * @steps: finite value for sequence
 * Return: 1 if conjecture proven, else 0
 */
int collatz(unsigned long int n, unsigned long int steps)
{
	unsigned long int count = 0;
	char *separation = "";
	
	if (n < 0)
		n = n * -1;

	if (n == 0)
		n = n % 2;
	if (n == 1)
		n = (3 * n) + 1;
	
	printf("Value => [%lu]\n", n);

	putchar('{');
	printf("%s", separation);

	while (n)
	{
		if (count == steps - 1 || n == 1)
		{
			printf("%s%lu", separation, n);
			putchar('}');
			printf("\n");
			printf("Number of steps taken => %lu\n", count);
			if (count == steps - 1)
				return (0);
			if (n == 1)
				return (1);
		}
		count++;

		printf("%s%lu", separation, n);
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
	printf("Number of steps taken => %lu\n", count);
	return (1);
}

int main(__attribute((unused)) int argc, char **argv)
{
	unsigned long int steps = 500;
	int return_val;
	int val;

	val = atoi(argv[1]);

	return_val = collatz((unsigned long int) val, steps);
	
	if (return_val)
		printf("Return value of => [%d] confirms collatz sequence"
				" in [%lu] steps\n",
				return_val, steps);
	else
		printf("Return value of => [%d] does not agree with collatz"
				"sequence in [%lu] steps\n",
				return_val, steps);

	return (0);
}
