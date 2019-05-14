/*
OVERVIEW:
1)Write a function which takes a octal number as input and returns the hexadecimal number for
octalToHexadecimal().
E.g.: octalToHexadecimal(10) returns 8.

2)Write a function which takes a fractional octal number as input and returns the hexadecimal number for
octalToHexadecimalFraction() until precision two
E.g.: octalToHexadecimal(6.01) returns 6.04

INPUTS: Single octal number num;

OUTPUT: hexadecimal value of the octal number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int octalToHexadecimal(long int num)
{
	int num = 10, temp2, index, index1, index2, hex_value = 0;
	int hex[65];
	int decimalNumber = 0, i = 0;
	while (num != 0)
	{
		decimalNumber += (num % 10) * pow(8.0, i);
		i++;
		num /= 10;
	}
	for (index1 = 0; decimalNumber > 0; index1++)
	{
		hex[index1] = decimalNumber % 16;
		decimalNumber = decimalNumber / 10;
	}
	for (index2 = 0; index2<index1; index2++)
	{
		temp2 = hex[index2];
		hex[index2] = hex[index1 - 1 - index2];
		hex[index1 - 1 - index2] = temp2;
	}
	for (index = 0; index < index1; index++)
	{
		if (hex[index]>9)
			hex_value = (hex_value * 100) + hex[index];
		else
			hex_value = (hex_value * 10) + hex[index];
	}
	return hex_value;
}

float octalToHexadecimalFraction(float num)
{
	int i, count = 0, temp;
	int decimal_octal = (int)num;
	float temp1, fractional_octal = num - decimal_octal;
	float hexadecimal_value = 0.0;
	while (fractional_octal != 0.00 && count < 2)
	{
		temp1 = fractional_octal * 16;
		temp = (int)temp;
		if (temp>9)
			hexadecimal_value += (temp*pow(10.0, i - 1));
		else
			hexadecimal_value += (temp*pow(10.0, i));
		fractional_octal = temp1 - temp;
		i--;
		count++;
	}
	hexadecimal_value += octalToHexadecimal(decimal_octal);
	return hexadecimal_value;
}
