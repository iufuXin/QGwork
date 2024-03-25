#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <Windows.h>
#include <WinBase.h>
#include <conio.h>
#include <work.h>
#include <time.h>


int main() {

	struct stack* mystack = creatStack();
	mystack->size = 0;
	menu_control(mystack);
	system("puase");//∑¿÷π…¡∆¡
	return 0;
}












