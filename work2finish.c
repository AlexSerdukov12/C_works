/* Assignment: 2
Campus: Ashdod
Author: alexei serdukov, ID: 323274787
*/

#include<stdio.h>
void seriesfunction(int);
int EvenFunction(int);
int SumOfOdd(int);
int MaxFunction(int);
int MinFunction(int);
int MalbenFunction(int, int);
int Sidra();
int omit(int num, int dig);
void primefunction();


int main()
{
	int choise, num, hight, Length, digit;
	
	do {
		printf("1 = Series\n2 = Two primes\n3 = Rectangle\n4 = Omit digit\n5 = Third\n6 = Quit\n\n\n");
		scanf_s("%d", &choise);

		switch (choise)
		{
		case 1:
			printf("enter a number\n");
			scanf_s("%d", &num);
			seriesfunction(num);
			break;
		case 2:
			primefunction();
			break;
		case 3:
			printf("insert hight\n");
			scanf_s("%d", &hight);
			printf("insert Length\n");
			scanf_s("%d", &Length);
			MalbenFunction(hight, Length);
			break;
		case 4:
			printf("enter a number\n");
			scanf_s("%d", &num);
			printf("enter a digit\n");
			scanf_s("%d", &digit);
			printf("%d", omit(num, digit));
			break;
		case 5:
			printf("%d", Sidra());
			break;
		case 6:
			exit(1);
		default:
			printf("error");
		}
	} while (choise != 6);
}
//////function 1////////
void seriesfunction(int num)
{


	int Length = 0, Odd = 0, Min = -2, Max = 0, Even = 0;
	while (num > 0)
	{
		Length++;
		Even = EvenFunction(num);
		Odd = SumOfOdd(num);
		Max = MaxFunction(num);
		Min = MinFunction(num);
		printf("insert a number\n");
		scanf_s("%d", &num);
	}
	printf("Length = %d\nEven = %d\nSum odd = %d\nMax = % d\nMin = %d\nGood Game Bro\n", Length, Even, Odd, Max, Min);

}
int EvenFunction(int num)
{
	static int even = 0;
	if (num % 2 == 0)
	{
		even++;
	}

	return even;

}
int SumOfOdd(int num)
{
	static int Sum = 0, counter = 0;

	if (num > 0)
	{
		if (!(num % 2 == 0))
		{
			Sum = Sum + num % 2;
		}
	}
	num /= 10;

	return Sum;

}
int MaxFunction(int num)
{
	static int max = 0;
	if (max < num)
	{
		max = num;
	}
	return max;
}
int MinFunction(int num)
{
	static int min = 9999999;
	if (min > num)
	{
		min = num;
	}
	return min;
}

/////// function 2/////
void primefunction()
{
	int i = 100, j ;
	for (i;i <= 999; i++)
	{
		for (j=10; j <= i; j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (i == j)
		{
			printf("the number %d is true\n", i);
		}
	}
}



//////function 3//////

int MalbenFunction(int, int);
int MalbenFunction(int hight, int Length)
{
	int i, j, min = 18;
	for (i = 1; i <= hight; i++)
	{
		for (j = 1; j < Length; j++)
		{
			if (min > hight - i + 1)
			{
				min = hight - i + 1;
			}
			if (min > i)
			{
				min = i;
			}
			if (min > Length - j)
			{
				min = Length - j;
			}
			if (min > j)
			{
				min = j;
			}
			printf("%d", min);
			min = 18;
		}
		printf("\n");
	}
}
///////function 4//////////////
int omit(int num, int dig) {
	int factor = 1;
	int i;
	int newNum = 0;
	while (num > 0) {
		if (dig != num % 10) {
			newNum += factor * (num % 10);
			factor *= 10;
		}
		num /= 10;
	}

	return newNum;
}
///////////function 5/////////
int Sidra()
{
	int NumberCount = 0, num;
	int  high = 0, middle = 0, low = 0, newhigh, newmiddle, newlow;
	while (1)
	{
		printf("enter a number\n");
		scanf_s("%d", &num);
		if (num < 0)
		{
			break;

		}
		NumberCount++;
		if (num > high)
		{
			low = middle;
			middle = high;
			high = num;


		}
		else if (num > middle&& num < high)
		{
			low = middle;
			middle = num;

		}
		else if (num > low&& num < middle)
		{
			low = num;

		}
	}
	if (NumberCount > 2)
	{
		return low;
	}
	return -1;
}