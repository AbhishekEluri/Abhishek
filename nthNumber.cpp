/*
Given a value n

1. return nth Fibonacci number for the function nthFibonacci(int)
EX: 0 for n=1 and 1 for n=2


2. return nth prime number for the function nthPrime(int)
EX: 2 for n=1 and 3 for n=2

INPUTS: single integer n

OUTPUTS: nth Fibonacci number for nthFibonacci()
nth prime number for nthPrime()

ERROR CASES: return -1 for the error cases
*/

int nthFibonacci(int n)
{
	int index, num1, num2, num3;
	if (n <= 1)
		return n;
	else
	{
		for (index = 2; index <= n; index++)
		{
			num3 = num1 + num2;
			num1 = num2;
			num2 = num3;
		}
	}
	return num2;
}

int nthPrime(int num)
{
	int count = 0, prime_count = 0;
	for (int index1 = 2;; index1++)
	{
		for (int index2 = 1; index2 <= index1; index2++)
		{
			if (index1%index2 == 0)
				count++;
		}
		if (count == 2)
			prime_count++;
		if (prime_count == num)
			return index1;
	}
}