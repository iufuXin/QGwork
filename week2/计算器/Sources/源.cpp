#include <stdio.h>
#include <stdlib.h>
#include <work.h>


int main() {
	//Ϊ�����������һ��װ���ֵ�ջ��һ��װ�������ջ
	struct stack * stack_sym;
	struct numstack * stack_num;
	//��ʼ��
	stack_num = creatNumStack();
	stack_sym = creatStack();
	int i=0;

	//������
	char buf[100] = { 0 };
	char* backdrop_expression = { 0 };//���ڴ�ź�ꡱ��ʽ
	while (true)
	{
		printf("��������ʽ�����ó���ֻ�ܽ����������㣩\n");
		gets_s(buf, 100);
		char* newBuf = removeSpacing(buf);//ȥ�ո����
		//printf("%c", newBuf[1]);
		if (newBuf == NULL) {
			printf("���ʽ���󣡣���\n");
			continue;
		}
		else if ((newBuf[0] >= '0' && newBuf[0] <= '9') || newBuf[0]=='(') {
			//���ת����
			backdrop_expression = change(newBuf, stack_sym);
			if (backdrop_expression != NULL) {
				//�����꡼���ʽ
				int result1 = result(stack_sym, backdrop_expression, stack_num);
				printf("�����%d\n", result1);
			}
		}
		else
		{
			printf("���ʽ���󣡣���\n");
		}
	}
	system("pause");
	return 0;
}



