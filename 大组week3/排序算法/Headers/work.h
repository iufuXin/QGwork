#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <Windows.h>
#include <WinBase.h>
#include <conio.h> // 头文件
//函数声明
void insertSort(int arr[], int* size);
void Merge(int arr[], int l, int m, int r);
void MergeSort(int arr[], int l, int r);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void printArr(int arr[], int* size);
void countSort(int arr[], int* size);
void radixCountSort(int arr[], int* size);
int* creatArr(int* size,int* arr);
void showbegin();
void show(int line);
void HideCursor();
void gotoxy(int x, int y);


#define upkey 72// 宏定义
#define downkey 80
#define leftkey 75
#define rightkey 77
#define LINE 6

//插入排序，传入数组经及数组的长度
void insertSort(int arr[], int* size) {
	int i, j, temp;
	for (i = 1; i < *size; i++)
	{
		//遍历数组
		temp = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > temp)
		{
			//当前面一个比后面的大时，将前面的值赋给后面的值
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}
//归并排序中的合并函数
void Merge(int arr[],int l,int m,int r) {
	//l是左子数组的起始索引，m是中间索引，r是右子数组的结束索引
	int i, j, k, n1, n2;
	n1 = m - l + 1;//左子数组的长度
	n2 = r - m;//右子数组的长度
	//创建临时数组L,R
	int* L = (int*)malloc(n1 * sizeof(int));
	int* R = (int*)malloc(n2 * sizeof(int));
	//将左子数复制到L[]
	for ( i = 0; i < n1; i++)
	{
		L[i] = arr[l + i];
	}
	//将右子数组复制到R[]
	for (j = 0; j < n2; j++)
	{
		R[j] = arr[m + 1 + j];
	}
	//合并L,R数组到arr[]中，注意，只是合并到字母l到字母r索引
	i = j = 0;//初始化L数组和R数组的索引
	k = l;//初始化arr的索引
	while (i < n2 && j < n2) {
		//如果L[i]小于等于R[i]，则进入数组arr中
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		//arr数组的索引加1
		k++;
	}
	//复制L[]中剩余的元素
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	//复制R[]中剩余的元素
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}
//归并排序,传入起始索引和末索引，并不是数组长度
void MergeSort(int arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		MergeSort(arr, l, m);
		MergeSort(arr, m + 1, r);
		Merge(arr, l, m, r);
	}
}
//快速排序,传入的是索引
void quickSort(int arr[],int low,int high) {
	//递归的返回的条件：如果低索引小于或等于高索引，则返回
	if (low < high) {
		//找到分区点
		int pi = partition(arr, low, high);
		//递归的对分区点左边的子数组进行快速排序
		quickSort(arr, low, pi - 1);
		//递归的对分区点右边的子数组进行快排
		quickSort(arr, pi + 1, high);
	}
}
//快速排序中的分区函数，用于将数组分为两部分，一部分包含小于分区点的元素，一部分包含大于分区点的元素
int partition(int arr[], int low, int high) {
	//选择最后一个元素作为基准
	int pivot = arr[high];
	int i = (low - 1);//小于基准元素的索引
	//分区过程
	for (int j = low; j <= high - 1; j++) {
		//如果当前元素小于等于基准
		if (arr[j] <= pivot) {
			i++;//增加小于基准元素的索引
			//交换arr[i]与arr[j]
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	//交换基准元素与arr[i+1]
	int temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	//返回分区点的索引
	return (i + 1);
}
//计数排序
void countSort(int arr[], int* size) {
	int max, min;//定义最大值和最小值
	max = min = arr[0];
	//找出最大最小值
	for (int i = 1; i < *size; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	for (int i = 1; i < *size; i++) {
		if (min > arr[i]) {
			min = arr[i];
		}
	}
	int range = max - min;
	int* count = (int *)malloc((range + 1) * sizeof(int));
	if (count == NULL) {
		printf("分配内存失败\n");
		return ;
	}
	//初始化数组
	for (int i = 0; i <= range; i++) {
		count[i] = 0;
	}
	//统计每个元素出现的次数
	for (int i = 0; i < *size; i++) {
		count[arr[i]-min]++;
	}
	//计算每个元素的位置
	for (int i = 1; i <= range; i++) {
		count[i] += count[i - 1];
	}
	//建立一个临时数组存放排序后的元素
	int* output = (int*)malloc(*size * sizeof(int));
	//从右往左将元素放入输出数组
	for (int i = *size - 1; i >= 0; i--) {
		output[count[arr[i]-min] - 1] = arr[i];
		count[arr[i]-min]--;
	}
	//复制回原数组
	for (int i = 0; i < *size; i++) {
		arr[i] = output[i];
	}
	//释放内存
	free(output);
	free(count);
}
//基数计数排序
void radixCountSort(int arr[], int* size) {
	//获取最大值
	int max = arr[0];
	for (int i = 1; i < *size; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	for (int exp = 1; max / exp > 0; exp *= 10) {
		int count[10] = { 0 };
		int* output = (int*)malloc(*size * sizeof(int));
		//统计每个位上的数字个数
		for (int i = 0; i < *size; i++) {
			count[(arr[i] / exp) % 10]++;
		}
		//更改count数组，使他现在包含当前位上的每个数字的起始索引
		for (int i = 1; i < 10; i++) {
			count[i] += count[i - 1];
		}
		//把数字放回到output数组中正确的位置
		for (int i = *size - 1; i >= 0; i--) {
			output[count[(arr[i] / exp) % 10] - 1] = arr[i];
			count[(arr[i] / exp) % 10]--;
		}
		//复制回原数组
		for (int i = 0; i < *size; i++) {
			arr[i] = output[i];
		}

	}
}
//生成数组
int* creatArr(int* size,int* arr) {
	printf("请输入创建的数组长度：\n");
	scanf_s("%d", size);
	//_getch();
	int choose = 0;//记录数组的取值范围
	printf("请输入生成最大位数：\n");
	scanf_s("%d", &choose);
	choose = (int)pow(10, choose);
	int* array = (int*)malloc(*size* sizeof(int));
	printf("正在生成中……");
	if (array != NULL) {
		// 设置随机数种子
		srand((unsigned int)time(NULL));
		// 填充数组
		int i;
		for (i = 0; i < *size; ++i) {
			array[i] = rand() % choose + 1;// 生成0到99之间的随机数
		}
	}
	return array;
}



//输出数组
void printArr(int arr[], int* size) {
	printf("排序后数组为：\n");
	for (int i = 0; i < *size && i<= 200;i++) {
		printf("%d ", *arr++);
	}
	printf("\n请等一等，等下会自动返回！！！\n");
}
//菜单展示
void showbegin() {
	printf("--------------------\n");
	printf("A:插入排序\n");
	printf("B:归并排序\n");
	printf("C:快排（递归版）\n");
	printf("D:计数排序\n");
	printf("E:基数计数排序\n");
	printf("F:退出\n");
	printf("--------------------\n");
}

void show(int line)// 输出高亮的一行
{
	gotoxy(0, 0);
	showbegin();
	gotoxy(0, line);
	if (line == 1)
		printf("\033[1;34;45mA:插入排序\n\033[0m");
	if (line == 2)
		printf("\033[1;34;45mB:归并排序\n\033[0m");
	if (line == 3)
		printf("\033[1;34;45mC:快排（递归版）\n\033[0m");
	if (line == 4)
		printf("\033[1;34;45mD:计数排序\n\033[0m");
	if (line == 5)
		printf("\033[1;34;45mE:基数计数排序\n\033[0m");
	if (line == 6)
		printf("\033[1;34;45mF:退出\n\033[0m");
}

void gotoxy(int x, int y)// 光标移动的函数
{
	COORD pos = { x,y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}

void HideCursor()// 隐藏光标
{
	HANDLE fd = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cinfo;
	cinfo.bVisible = 0;
	cinfo.dwSize = 1;
	SetConsoleCursorInfo(fd, &cinfo);
}


void menu_control()// 菜单控制函数
{
	char c1, c2, ch;
	int line, sec;
	long long j;// 记录时间
	time_t t;
	struct tm* lt;
	int* size=(int*)malloc(sizeof(int));//记录数组的长度
	while (1)
	{
		int* arr = NULL;
		system("cls");   //清屏
		system("color 0");  //设置背景及字幕颜色
		Beep(2000, 250); //声音提示
		HideCursor();    //隐藏光标
		showbegin(); //显示菜单
		line = 1;// 高亮位置
		gotoxy(0, line); //
		printf("\033[1;34;45mA:插入排序\n\033[0m"); //输出高亮

		for (; (c1 = _getch()) != '\r';)  // 读取上下按键的操作
		{
			//LEFT(-32,75), UP(-32,72), DOWN(-32,80),Right(-32,77)
			if (c1 == -32)
			{
				c2 = _getch(); //读取按键
				ch = c2;
				if (ch == upkey && line != 1)
				{
					line--;
					show(line);
					continue;
				}
				else if (ch == downkey && line != LINE)
				{
					line++;
					show(line);
					continue;
				}
				else if (ch == upkey && line == 1)
				{
					line = LINE;
					show(line);
					continue;
				}
				else if (ch == downkey && line == LINE)
				{
					line = 1;
					show(line);
					continue;
				}
			}

			if (c1 == 'a' || c1 == 'A')
			{
				system("cls");   //清屏
				gotoxy(0, 0);    //光标位置
				line = 0;
				clock_t start = clock();
				arr=creatArr(size,arr);
				insertSort(arr, size);
				printArr(arr, size);
				clock_t finish = clock() - start;
				printf("所用时间为%d ms\n", finish);
				break;
			}
			else if (c1 == 'b' || c1 == 'B')
			{
				system("cls");
				gotoxy(0, 0);
				line = 0;				
				clock_t start = clock();
				arr=creatArr(size,arr);
				MergeSort(arr, 0, *size - 1);
				printArr(arr, size);
				clock_t finish = clock() - start;
				printf("所用时间为%d ms\n", finish);
				break;
			}
			else if (c1 == 'c' || c1 == 'C')
			{
				system("cls");
				gotoxy(0, 0);
				line = 0;
				clock_t start = clock();
				arr=creatArr(size,arr);
				quickSort(arr, 0, *size-1);
				printArr(arr, size);
				clock_t finish = clock() - start;
				printf("所用时间为%d ms\n", finish);
				break;
			}
			else if (c1 == 'd' || c1 == 'D')
			{
				system("cls");
				gotoxy(0, 0);
				line = 0;
				clock_t start = clock();
				arr=creatArr(size,arr);
				countSort(arr, size);
				printArr(arr, size);
				clock_t finish = clock() - start;
				printf("所用时间为%d ms\n", finish);
				break;
			}
			else if (c1 == 'e' || c1 == 'E')
			{
				system("cls");
				gotoxy(0, 0);
				line = 0;
				clock_t start = clock();
				arr=creatArr(size,arr);
				radixCountSort(arr, size);
				printArr(arr, size);
				clock_t finish = clock() - start;
				printf("所用时间为%d ms\n", finish);
				break;
			}
			else if (c1 == 'f' || c1 == 'F')
			{
				system("cls");
				gotoxy(0, 0);
				break;
				exit(0);
				line = 0;
				break;
			}
		}

		if (line == 1)
		{
			system("cls");
			gotoxy(0, 0);
			clock_t start = clock();
			arr=creatArr(size,arr);
			insertSort(arr, size);
			printArr(arr, size);
			clock_t finish = clock() - start;
			printf("所用时间为%d ms\n", finish);
			Sleep(1000);
		}
		else if (line == 2)
		{
			system("cls");
			gotoxy(0, 0);
			clock_t start = clock();
			arr=creatArr(size,arr);
			MergeSort(arr, 0, *size - 1);
			printArr(arr, size);
			clock_t finish = clock() - start;
			printf("所用时间为%d ms\n", finish);
			Sleep(1000);
		}
		else if (line == 3)
		{
			system("cls");
			gotoxy(0, 0);
			clock_t start = clock();
			arr=creatArr(size,arr);
			quickSort(arr, 0, *size - 1);
			printArr(arr, size);
			clock_t finish = clock() - start;
			printf("所用时间为%d ms\n", finish);
			Sleep(1000);
		}
		else if (line == 4)
		{
			system("cls");
			gotoxy(0, 0);
			clock_t start = clock();
			arr=creatArr(size,arr);
			countSort(arr, size);
			printArr(arr, size);
			clock_t finish = clock() - start;
			printf("所用时间为%d ms\n", finish);
			Sleep(1000);
		}
		else if (line == 5)
		{
			system("cls");
			gotoxy(0, 0);
			clock_t start = clock();
			arr=creatArr(size,arr);
			radixCountSort(arr, size);
			printArr(arr, size);
			clock_t finish = clock() - start;
			printf("所用时间为%d ms\n", finish);
			Sleep(1000);
		}
		else if (line == 6)
		{
			system("cls");
			gotoxy(0, 0);
			exit(0);
			break;
		}
		time(&t);
		lt = localtime(&t); // 获取时间结构体
		sec = lt->tm_sec;

		do   // 用来计时停留的时间
		{
			time(&t);
			lt = localtime(&t);
			j = lt->tm_sec - sec;
			if (j < 0) j = j + 60;
		} while (j < 3);
	}
}
