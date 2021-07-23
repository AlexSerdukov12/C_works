/* Assignment: 2
Campus: Ashdod
Author: alexie serdukov, ID: 323274787
*/


#include <stdio.h>
float function(float, float);

void main()
{
	float num, epsilon, middle;
	printf("enter a number\n");
	scanf_s("%f", &num);
	printf("enter epsilon\n");
	scanf_s("%f", &epsilon);

	function(num, epsilon);
		
}
float abs(float num)
{
	if (num < 0)
	{
		return -num;
	}
	return num;
}

float  function(float num, float epsilon)
{
	float left = 1.0, right = num;
	float middle = (right + left) / 2;
	while (1)
	{

		if (middle * middle >= num)
		{
			right = middle;
			middle = (right + left) / 2;
		}
		else if (middle * middle <=num)
		{
			left = middle;
			middle = (left + right) / 2;
		}
		if (abs(middle * middle - num) <= epsilon)
		{
			break;
		}

	}
	printf(" the sqrt of %f is %.2f" , num , middle);
}

