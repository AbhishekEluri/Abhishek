int count(int num1, int num2) {
	int count_variable = 0;
	if (num2 < 0 || num1 <= 0)
		return -1;
	else
	{
		count_variable = num2 / num1;
		return count_variable;
	}
	return 0;
}