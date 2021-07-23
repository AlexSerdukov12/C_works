/* Assignment: 3
Author: alexei serdukov, ID: 323274787
campus ashdod
*/

#include<stdio.h>
#include<string.h>
void primes(int arr[], int );
void quick(int arr[], int);

void main()
{
    int i, counter = 12;
    int arr[100];
    primes(arr, 100);
    int arr1[12];
    for (i = 0; i < 12; i++)
    {
        printf("inser a  number , %d numbers left\n", counter);
        scanf_s("%d", &arr1[i]);
        counter--;
    }
    quick(arr1, 12);
    
}
void primes(int arr[] , int size1)
{
    int bakra = 1;
    int i, j, num = 3, counter = 1;
    arr[0] = 2;
    for (i = 1;i < size1;i++)
    {
        for (j = 0;j < i;j++)
        {
            if (num % arr[j] == 0)
            {
                bakra = 2;
            }
        }
        if (bakra == 1)
        {
            arr[i] = num;
            num++;
            counter++;
        }
        else
        {
            i--;
            num++;
        }
        bakra = 1;
    }
    for (i = 0;i < 100;i++)
    {
        printf("%d\n", arr[i]);
    }
    printf("%d prime number \n", counter);
}
void quick(int arr[], int size1)
{
    int i, j, num, num1;
    int left = 0,right = size1 - 1;
    while (left<= right)
    {
        for (i = 0;i <= size1 - 1;i++)
        {
            if (arr[i] >= 0)
            {
                num = arr[i];
                break;
            }
        }
        left++;
        for (j = size1 - 1; j >= 0; j--)
        {
            if (arr[j] <= 0)
            {
                num1 = arr[j];
                break;
            }
        }
        right--;
        arr[i] = num1;
        arr[j] = num;
    }
    for (i = 0; i < size1 - 1; i++)
    {
        printf("%d ", arr[i]);
    }
}


