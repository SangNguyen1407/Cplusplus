#include <iostream>
#include <string.h>
#include <stdarg.h>
#include "../inc/linkedList.h"
#include "../inc/printLog.h"
#include "../inc/sort.h"
#include "../inc/fileHandler.h"
 
using namespace std;

//static int numb = 10;
int numb = 100;

int test1 ()
{
	static int i = 0;
	return i++;
}

float avg(int count, ...)
{
	va_list numbers;
	va_start(numbers, count);
	int sum = 0;
	for (int i=0; i<count; ++i)
	{
		sum += va_arg(numbers, int);
	}
	va_end(numbers);
	
	return (sum);
}

int main ()
{
	int arr[] = {5,6,1,4,3};
	int len_arr = sizeof(arr)/sizeof(int);

	// bubble sort
	bubbleSort(arr, len_arr);
	printArr(arr, len_arr);
	return RST_SUCCESS;
}