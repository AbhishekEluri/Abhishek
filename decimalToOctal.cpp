/*
OVERVIEW:
1)Write a function which takes a decimal number as input and returns the octal number for decimalToOctal().
E.g.: decimalToOctal(10) returns 12.

2)Write a function which takes a fractional decimal number as input and returns the octal number for decimalToOctalFraction()
until precision two
E.g.: decimalToOctal(6.06) returns 6.03

INPUTS: Single decimal number num;

OUTPUT: Octal value of the Decimal Number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/
#include<stdlib.h>
#include<math.h>

int decimalToOctal(int num)
{
	int temp1, temp2, org_octal_value = 0, rev_octal_value = 0;
	while (num > 0)
	{
		temp1 = num % 8;
		rev_octal_value = (rev_octal_value * 10) + temp1;
		num = num / 10;
	}
	while (rev_octal_value > 0)
	{
		temp2 = rev_octal_value % 10;
		org_octal_value = (org_octal_value * 10) + temp2;
		rev_octal_value = rev_octal_value / 10;
	}
	return org_octal_value;
}

float decimalToOctalFraction(float num)
{
	int temp, i = 0, decimal_part, count = 0;
	float fractional_part, temp1, octal_value = 0.0;
	decimal_part = (int)num;
	fractional_part = num - decimal_part;
	while (fractional_part != 0.00 && count < 2)
	{
		temp1 = fractional_part * 8;
		temp = (int)temp1;
		octal_value += (temp*pow(10.0, i));
		fractional_part = temp1 - temp;
		i--;
		count++;
	}
	octal_value += decimalToOctal(decimal_part);
	return octal_value;
}

