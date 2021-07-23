/* Assignment: 3
Author: alex serdukov, ID: 323274787 , campus : ashdod
*/


#include<stdio.h>

void Histogram(char arr);
void function7(char *arr);
void function8(char *arr);
void function9(char *arr);
void function10(char *arr);


void main()
{
	int i;
	char arr[80] = "One two three 456 seven Eight nine";
	printf("enter ur string , max 80 char\n");
	gets(arr);
	Histogram(arr);
	function10( &arr);
	for (i = 0; arr[i]; ++i)
	{
		printf("%c", arr[i]);
	}

}
void Histogram(char arr[])
{
	int arrtest[26] = { 0 };
	int i, j, counter=0;
	for (i = 0;arr[i];++i)
	{
		if ('A' <= arr[i] <= 'Z')
		{
			arrtest[arr[i] - 'A']++ ;
		}
		if ('a' <= arr[i] <= 'z')
		{
			arrtest[arr[i] - 'a']++;
		}
	}
	for (j = 0; j<26;++j)
	{
		if (arrtest[j] > 0)
		{
			printf("%c ",j+'a');
			for (i = 0;i < arrtest[j];++i)
			{
				printf("*");
			}
			printf("\n");
		}
	}
}
void function7(char *arr)
{
	int i, TempMax, TempMin, k = 0 ,j ;
	char ArrayTest[80];
	for (i = 0; arr[i];++i); // calculate the length of arr
	--i; 
	TempMax = i ; // string without \0
	/////// string is "One two three 456 seven Eight nine /////
	for (i; i >= 0; --i)
	{
		if (arr[i] == ' ' || i==0)
		{
			TempMin = i; // min place of char in word 
			if (arr[TempMax] == ' ') // end char of the word
			{
				TempMax--;
			}
			if (arr[TempMin] == ' ')//start char of the word
			{
				TempMin++;
			}
			for (TempMin;TempMin <= TempMax; ++TempMin) // copies the word to ArrayTest
			{
				ArrayTest[k] = arr[TempMin];
				k++;				
			}
			TempMax = i;
			ArrayTest[k] = ' ';
			k++;
		}
		
	}
	for (i = 0; arr[i]; ++i)
	{
		arr[i] = ArrayTest[i];
	}
}
void function8(char *arr)
{
	char arrtest[80];
	int i, max, min = 0, k = 0, j = 0, temp;
	for (i = 0;arr[i];++i); // calculate length of string
	i--;
	for (j = 0; j <= i; ++j)
	{
		if (arr[j] == ' ' || &arr[j]==&arr[i])
		{
			max = j ;
			temp = max;
			if (arr[max] == ' ')
			{
				--max;
			}
			if (arr[min] == ' ')
			{
				++min;
			}
			for (max; min <= max; --max)
			{
				arrtest[k] = arr[max];
				k++;
			}
			min = temp;
			arrtest[k] = ' ';
			k++;
		}
		

	}
	for (i = 0; arr[i]; ++i)
	{
		arr[i] = arrtest[i];
	}
}
void function9(char  *arr)
{
	int i, j, counter1 = 1, counter;
	int Tempmin = 0;
	for (counter = 0;arr[counter] ;counter++); /// Calculate string length
	--counter;
	for (i = 0; i <= counter;i++)
	{
		if (arr[i] == ' ' || &arr[i] == &arr[counter])
		{
			for (Tempmin; Tempmin < i;Tempmin++)
			{
				arr[Tempmin] = arr[Tempmin] + counter1;
				counter1++;
			}

			while (arr[i] == ' ')
			{
				arr[i] = ' ';
				i++;
			}
			counter1 = 1;
			Tempmin = i;
		}	
	}
} 
void function10(char *arr)
{
	function7(arr);
	function8(arr);
	function9(arr);
}


	


