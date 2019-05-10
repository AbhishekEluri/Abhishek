#include <stdio.h>

int countFactorials(long l, long h)
{
	if (l < 0 || h < 0 || l < h)
		return -1;
	int factorial = 1, incr = 1;
	int count = 0;
	while (factorial <= h)
	{
		if (factorial > l)
			count++;
		factorial *= incr;
		incr++;
	}
	return count;
}
