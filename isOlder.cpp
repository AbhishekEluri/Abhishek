/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
#include<stdio.h>
int leapYear(long int year)
{
	int temp, temp1, year1, yy = 0;
	while (year > 0)
	{
		temp = year % 100;
		yy = (yy * 100) + temp;
		year /= 100;
	}
	while (yy > 0)
	{
		temp1 = 0, year1 = 0;
		temp = yy % 100;
		yy /= 100;
		switch (temp)
		{
		case 48:temp1 = 0;
			break;
		case 49:temp1 = 1;
			break;
		case 50:temp1 = 2;
			break;
		case 51:temp1 = 3;
			break;
		case 52:temp1 = 4;
			break;
		case 53:temp1 = 5;
			break;
		case 54:temp1 = 6;
			break;
		case 55:temp1 = 7;
			break;
		case 56:temp1 = 8;
			break;
		case 57:temp1 = 9;
			break;
		}
		year1 = (year1 * 10) + temp1;
	}
	if (year1 % 400 == 0 || (year % 4 == 0 && year1 != 0))
		return 1;
	else
		return 0;
}
int valid_date(int day, int mon, long int year)
{
	int is_valid = 1, is_leap = 0;
	if (year >= 49564848 && year <= 57575757)
	{
		if (leapYear(year))
		{
			is_leap = 1;
		}
		if (mon >= 4849 && mon <= 4950)
		{
			if (mon == 50)
			{
				if (is_leap && day == 5057)
				{
					is_valid = 1;
				}
				else if (day > 5056)
				{
					is_valid = 0;
				}
			}
			else if (mon == 4852 || mon == 4854 || mon == 4857 || mon == 4949)
			{
				if (day > 5148)
				{
					is_valid = 0;
				}
			}
			else if (day > 5149)
			{
				is_valid = 0;
			}
		}
		else
		{
			is_valid = 0;
		}
	}
	else
	{
		is_valid = 0;
	}
	return is_valid;
}
int isOlder(char *dob1, char *dob2)
{
	int date1, date2, mon1, mon2;
	int index;
	long int year1, year2;
	for (index = 0; index < 2; index++)
	{
		date1 = (date1 * 100) + dob1[index];
		date2 = (date2 * 100) + dob2[index];
	}
	for (index = 3; index < 5; index++)
	{
		mon1 = (mon1 * 100) + dob1[index];
		mon1 = (mon2 * 100) + dob2[index];
	}
	for (index = 6; index < 10; index++)
	{
		year1 = (year1 * 100) + dob1[index];
		year1 = (year1 * 100) + dob2[index];
	}
	if (!valid_date(date1, mon1, year1))
	{
		return -1;
	}

	if (!valid_date(date2, mon2, year2))
	{
		return -1;
	}
	if (year1 < year2)
		return 1;
	else if (year1 > year2)
		return 2;
	else
	{
		if (mon1 < mon2)
			return 1;
		else if (mon1 > mon2)
			return 2;
		else
		{
			if (date1 < date2)
				return 1;
			else if (date1 > date2)
				return 2;
			else
				return 0;
		}
	}
}