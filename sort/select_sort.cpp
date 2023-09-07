#include <iostream>
#include <string.h>

#define RST_SUCCESS 0
#define RST_ERROR  -1

using namespace std;

int selectSort (int *arr, int arr_size)
{
	int numberPos = 0;
	if (arr == NULL)
	{
		return RST_ERROR;
	}
	
	if (arr_size == 1)
	{
		return RST_SUCCESS;
	}
	
	for(int i = 0; i < arr_size - 1; i++)
	{
		numberPos = i;
		for (int j = i+1; j < arr_size; j ++)
		{
			if (arr[numberPos] > arr[j])
			{
				numberPos = j;
			}
		}
		if (numberPos != i)
		{
			int temp = 0;
			temp = arr[i];
			arr[i] = arr[numberPos];
			arr[numberPos] = temp;
		}
	}
	
	return RST_SUCCESS;
}

int main (){
    int arr[4] = {9,2,3,4};
    int size = sizeof(arr) / sizeof(int);
	int ret = selectSort(arr, size);

    cout << arr[0] << arr[1] << arr[2] << arr[3] << endl;
}