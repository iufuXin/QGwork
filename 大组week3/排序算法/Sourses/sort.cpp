#define _CRT_SECURE_NO_WARNINGS 1
#include <work.h>

int main() {
	//int arr[10] = { 12,4,65,99,2,34,56,31,52,35 };
	int arr[11] = { 0,2,5,3,7,9,10,3,7,6,11 };
	int n = sizeof(arr) / sizeof(arr[0]);
	//insertSort(arr, n);
	//MergeSort(arr, 0, n - 1);
	//quickSort(arr, 0, n - 1);
	//countSort(arr, n);
	//radixCountSort(arr, n);
	//printArr(arr, n);
	menu_control();
	int a;
	scanf("%d", &a);
	return 0;
}




