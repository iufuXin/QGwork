#include <stdio.h>
#include <stdlib.h>
#include <work.h>


int main() {
	//为方便管理，定义一个装数字的栈，一个装运算符的栈
	struct stack * stack_sym;
	struct numstack * stack_num;
	//初始化
	stack_num = creatNumStack();
	stack_sym = creatStack();
	int i=0;

	//缓冲区
	char buf[100] = { 0 };
	char* backdrop_expression = { 0 };//用于存放后辍表达式
	while (true)
	{
		printf("请输入表达式：（该程序只能进行整数运算）\n");
		gets_s(buf, 100);
		char* newBuf = removeSpacing(buf);//去空格操作
		//printf("%c", newBuf[1]);
		if (newBuf == NULL) {
			printf("表达式有误！！！\n");
			continue;
		}
		else if ((newBuf[0] >= '0' && newBuf[0] <= '9') || newBuf[0]=='(') {
			//中辍转后后辍
			backdrop_expression = change(newBuf, stack_sym);
			if (backdrop_expression != NULL) {
				//计算后辍计算式
				int result1 = result(stack_sym, backdrop_expression, stack_num);
				printf("结果是%d\n", result1);
			}
		}
		else
		{
			printf("表达式有误！！！\n");
		}
	}
	system("pause");
	return 0;
}



