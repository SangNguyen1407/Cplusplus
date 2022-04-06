#include <iostream>
#include <string.h>
#include "../inc/sort.h"
#include "../inc/printLog.h"

int bubbleSort(int *arr, int arr_size)
{
	//print_log(CODE_LOG_NORMAL, "call bubbleSort function... \n");
	if (arr == NULL && arr_size < 1){
		return RST_ERROR;
	}
	
	int temp = 0;
	for(int i = 0; i < arr_size; i++){
		for (int j = arr_size-1; j > i; j--){
			if(arr[j] < arr[j-1]){
				temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	//print_log(CODE_LOG_NORMAL, "END bubbleSort function... \n");
	return RST_SUCCESS;
}