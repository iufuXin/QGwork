#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <Windows.h>
#include <WinBase.h>
#include <conio.h> // ͷ�ļ�
//��������
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


#define upkey 72// �궨��
#define downkey 80
#define leftkey 75
#define rightkey 77
#define LINE 6

//�������򣬴������龭������ĳ���
void insertSort(int arr[], int* size) {
	int i, j, temp;
	for (i = 1; i < *size; i++)
	{
		//��������
		temp = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > temp)
		{
			//��ǰ��һ���Ⱥ���Ĵ�ʱ����ǰ���ֵ���������ֵ
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}
//�鲢�����еĺϲ�����
void Merge(int arr[],int l,int m,int r) {
	//l�������������ʼ������m���м�������r����������Ľ�������
	int i, j, k, n1, n2;
	n1 = m - l + 1;//��������ĳ���
	n2 = r - m;//��������ĳ���
	//������ʱ����L,R
	int* L = (int*)malloc(n1 * sizeof(int));
	int* R = (int*)malloc(n2 * sizeof(int));
	//�����������Ƶ�L[]
	for ( i = 0; i < n1; i++)
	{
		L[i] = arr[l + i];
	}
	//���������鸴�Ƶ�R[]
	for (j = 0; j < n2; j++)
	{
		R[j] = arr[m + 1 + j];
	}
	//�ϲ�L,R���鵽arr[]�У�ע�⣬ֻ�Ǻϲ�����ĸl����ĸr����
	i = j = 0;//��ʼ��L�����R���������
	k = l;//��ʼ��arr������
	while (i < n2 && j < n2) {
		//���L[i]С�ڵ���R[i]�����������arr��
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		//arr�����������1
		k++;
	}
	//����L[]��ʣ���Ԫ��
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	//����R[]��ʣ���Ԫ��
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}
//�鲢����,������ʼ������ĩ���������������鳤��
void MergeSort(int arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		MergeSort(arr, l, m);
		MergeSort(arr, m + 1, r);
		Merge(arr, l, m, r);
	}
}
//��������,�����������
void quickSort(int arr[],int low,int high) {
	//�ݹ�ķ��ص����������������С�ڻ���ڸ��������򷵻�
	if (low < high) {
		//�ҵ�������
		int pi = partition(arr, low, high);
		//�ݹ�ĶԷ�������ߵ���������п�������
		quickSort(arr, low, pi - 1);
		//�ݹ�ĶԷ������ұߵ���������п���
		quickSort(arr, pi + 1, high);
	}
}
//���������еķ������������ڽ������Ϊ�����֣�һ���ְ���С�ڷ������Ԫ�أ�һ���ְ������ڷ������Ԫ��
int partition(int arr[], int low, int high) {
	//ѡ�����һ��Ԫ����Ϊ��׼
	int pivot = arr[high];
	int i = (low - 1);//С�ڻ�׼Ԫ�ص�����
	//��������
	for (int j = low; j <= high - 1; j++) {
		//�����ǰԪ��С�ڵ��ڻ�׼
		if (arr[j] <= pivot) {
			i++;//����С�ڻ�׼Ԫ�ص�����
			//����arr[i]��arr[j]
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	//������׼Ԫ����arr[i+1]
	int temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	//���ط����������
	return (i + 1);
}
//��������
void countSort(int arr[], int* size) {
	int max, min;//�������ֵ����Сֵ
	max = min = arr[0];
	//�ҳ������Сֵ
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
		printf("�����ڴ�ʧ��\n");
		return ;
	}
	//��ʼ������
	for (int i = 0; i <= range; i++) {
		count[i] = 0;
	}
	//ͳ��ÿ��Ԫ�س��ֵĴ���
	for (int i = 0; i < *size; i++) {
		count[arr[i]-min]++;
	}
	//����ÿ��Ԫ�ص�λ��
	for (int i = 1; i <= range; i++) {
		count[i] += count[i - 1];
	}
	//����һ����ʱ������������Ԫ��
	int* output = (int*)malloc(*size * sizeof(int));
	//��������Ԫ�ط����������
	for (int i = *size - 1; i >= 0; i--) {
		output[count[arr[i]-min] - 1] = arr[i];
		count[arr[i]-min]--;
	}
	//���ƻ�ԭ����
	for (int i = 0; i < *size; i++) {
		arr[i] = output[i];
	}
	//�ͷ��ڴ�
	free(output);
	free(count);
}
//������������
void radixCountSort(int arr[], int* size) {
	//��ȡ���ֵ
	int max = arr[0];
	for (int i = 1; i < *size; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	for (int exp = 1; max / exp > 0; exp *= 10) {
		int count[10] = { 0 };
		int* output = (int*)malloc(*size * sizeof(int));
		//ͳ��ÿ��λ�ϵ����ָ���
		for (int i = 0; i < *size; i++) {
			count[(arr[i] / exp) % 10]++;
		}
		//����count���飬ʹ�����ڰ�����ǰλ�ϵ�ÿ�����ֵ���ʼ����
		for (int i = 1; i < 10; i++) {
			count[i] += count[i - 1];
		}
		//�����ַŻص�output��������ȷ��λ��
		for (int i = *size - 1; i >= 0; i--) {
			output[count[(arr[i] / exp) % 10] - 1] = arr[i];
			count[(arr[i] / exp) % 10]--;
		}
		//���ƻ�ԭ����
		for (int i = 0; i < *size; i++) {
			arr[i] = output[i];
		}

	}
}
//��������
int* creatArr(int* size,int* arr) {
	printf("�����봴�������鳤�ȣ�\n");
	scanf_s("%d", size);
	//_getch();
	int choose = 0;//��¼�����ȡֵ��Χ
	printf("�������������λ����\n");
	scanf_s("%d", &choose);
	choose = (int)pow(10, choose);
	int* array = (int*)malloc(*size* sizeof(int));
	printf("���������С���");
	if (array != NULL) {
		// �������������
		srand((unsigned int)time(NULL));
		// �������
		int i;
		for (i = 0; i < *size; ++i) {
			array[i] = rand() % choose + 1;// ����0��99֮��������
		}
	}
	return array;
}



//�������
void printArr(int arr[], int* size) {
	printf("���������Ϊ��\n");
	for (int i = 0; i < *size && i<= 200;i++) {
		printf("%d ", *arr++);
	}
	printf("\n���һ�ȣ����»��Զ����أ�����\n");
}
//�˵�չʾ
void showbegin() {
	printf("--------------------\n");
	printf("A:��������\n");
	printf("B:�鲢����\n");
	printf("C:���ţ��ݹ�棩\n");
	printf("D:��������\n");
	printf("E:������������\n");
	printf("F:�˳�\n");
	printf("--------------------\n");
}

void show(int line)// ���������һ��
{
	gotoxy(0, 0);
	showbegin();
	gotoxy(0, line);
	if (line == 1)
		printf("\033[1;34;45mA:��������\n\033[0m");
	if (line == 2)
		printf("\033[1;34;45mB:�鲢����\n\033[0m");
	if (line == 3)
		printf("\033[1;34;45mC:���ţ��ݹ�棩\n\033[0m");
	if (line == 4)
		printf("\033[1;34;45mD:��������\n\033[0m");
	if (line == 5)
		printf("\033[1;34;45mE:������������\n\033[0m");
	if (line == 6)
		printf("\033[1;34;45mF:�˳�\n\033[0m");
}

void gotoxy(int x, int y)// ����ƶ��ĺ���
{
	COORD pos = { x,y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}

void HideCursor()// ���ع��
{
	HANDLE fd = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cinfo;
	cinfo.bVisible = 0;
	cinfo.dwSize = 1;
	SetConsoleCursorInfo(fd, &cinfo);
}


void menu_control()// �˵����ƺ���
{
	char c1, c2, ch;
	int line, sec;
	long long j;// ��¼ʱ��
	time_t t;
	struct tm* lt;
	int* size=(int*)malloc(sizeof(int));//��¼����ĳ���
	while (1)
	{
		int* arr = NULL;
		system("cls");   //����
		system("color 0");  //���ñ�������Ļ��ɫ
		Beep(2000, 250); //������ʾ
		HideCursor();    //���ع��
		showbegin(); //��ʾ�˵�
		line = 1;// ����λ��
		gotoxy(0, line); //
		printf("\033[1;34;45mA:��������\n\033[0m"); //�������

		for (; (c1 = _getch()) != '\r';)  // ��ȡ���°����Ĳ���
		{
			//LEFT(-32,75), UP(-32,72), DOWN(-32,80),Right(-32,77)
			if (c1 == -32)
			{
				c2 = _getch(); //��ȡ����
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
				system("cls");   //����
				gotoxy(0, 0);    //���λ��
				line = 0;
				clock_t start = clock();
				arr=creatArr(size,arr);
				insertSort(arr, size);
				printArr(arr, size);
				clock_t finish = clock() - start;
				printf("����ʱ��Ϊ%d ms\n", finish);
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
				printf("����ʱ��Ϊ%d ms\n", finish);
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
				printf("����ʱ��Ϊ%d ms\n", finish);
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
				printf("����ʱ��Ϊ%d ms\n", finish);
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
				printf("����ʱ��Ϊ%d ms\n", finish);
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
			printf("����ʱ��Ϊ%d ms\n", finish);
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
			printf("����ʱ��Ϊ%d ms\n", finish);
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
			printf("����ʱ��Ϊ%d ms\n", finish);
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
			printf("����ʱ��Ϊ%d ms\n", finish);
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
			printf("����ʱ��Ϊ%d ms\n", finish);
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
		lt = localtime(&t); // ��ȡʱ��ṹ��
		sec = lt->tm_sec;

		do   // ������ʱͣ����ʱ��
		{
			time(&t);
			lt = localtime(&t);
			j = lt->tm_sec - sec;
			if (j < 0) j = j + 60;
		} while (j < 3);
	}
}
