#include"stdafx.h"
#include"f1.h"
#include<math.h>

int factorial(int n)
{
	if (n <= 0||n>1000)
		return 0;
	int sum = 1;
	for (int i = 2; i <= n; i++) {
		sum = sum*i;
	}
	return sum;
}

float FAC::convert(float deg)
{
	return deg / 45.0 / atan(1.0);
}