/*#define _CRT_SECURE_NO_WARNINGS 1
//#include <work.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <WinBase.h>
#include <minwindef.h>
//#include <time.h>
*/
#include <stdio.h>
#include <stdlib.h>
#include <work.h>
#include <conio.h>
#include <Windows.h>
#include <WinBase.h>


int main() {
	struct Queue* myQueue = creatQueue();
	menu_control(myQueue);
	system("pause");
	return 0;
}


