#define _CRT_SECURE_NO_WARNINGS 1
#include <work.h>
#include <conio.h>



int main() {
	char choose;
	struct treeNode* root = NULL;
	while (true)
	{
		system("cls");
		show();
		scanf_s("%c", &choose,1);
		getchar();//吞掉空格
		system("cls");
		if (choose == 'A') {
			char input[100] = { 0 };
			printf("请输入数据：");
			gets_s(input,100);
			while (check(input))
			{
				printf("数据输入有误，请重新输入！\n");
				gets_s(input, 100);
			}
			int data = 0;
			//将字符转为数字
			for (int i = 0; input[i] != '\0'; i++) {
				data = data * 10 + input[i] - 48;
			}
			printf("%d", data);
			root = insert(root, data);
			printf("插入成功！，回车确定\n");
			getchar();
		}
		else if (choose == 'B') {
			if (root == NULL) {
				printf("还没有输入数据！！！\n");
			}
			else
			{
				printf("以下为先序遍历的结果：\n");
				precursor(root);
			}
			printf("\n回车确定！");
			getchar();
		}
		else if (choose == 'C') {
			if (root == NULL) {
				printf("还没有输入数据！！！\n");
			}
			else
			{
				printf("以下为中序遍历的结果：\n");
				inorderTravelsal(root);
			}
			printf("\n回车确定！");
			getchar();
		}
		else if (choose == 'D') {
			if (root == NULL) {
				printf("还没有输入数据！！！\n");
			}
			else
			{
				printf("以下为后序遍历的结果：\n");
				postorder(root);
			}
			printf("\n回车确定！");
			getchar();
		}
		else if (choose == 'E') {
			if (root == NULL) {
				printf("你还没有输入任何值！回车确定！");
			}
			else
			{
				char input[100] = { 0 };
				printf("请输入要删除的数据：");
				gets_s(input, 100);
				while (check(input))
				{
					printf("数据输入有误，请重新输入！\n");
					gets_s(input, 100);
				}
				int data = 0;
				//将字符转为数字
				for (int i = 0; input[i] != '\0'; i++) {
					data = data * 10 + input[i] - 48;
				}
				root = deleteNode(root, data);
				printf("\n删除成功！！！，回车确定！");
			}
			getchar();
		}
		else if (choose == 'F') {
			if (root == NULL) {
				printf("你还没有输入任何数据！回车确定");
			}
			else
			{
				destroyTree(root);
				root = NULL;
				printf("销毁成功，回车确定");
			}
			getchar();
		}
		else if (choose == 'G') {
			exit(0);
		}

	}
}



