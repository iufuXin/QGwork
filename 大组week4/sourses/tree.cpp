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
		getchar();//�̵��ո�
		system("cls");
		if (choose == 'A') {
			char input[100] = { 0 };
			printf("���������ݣ�");
			gets_s(input,100);
			while (check(input))
			{
				printf("���������������������룡\n");
				gets_s(input, 100);
			}
			int data = 0;
			//���ַ�תΪ����
			for (int i = 0; input[i] != '\0'; i++) {
				data = data * 10 + input[i] - 48;
			}
			printf("%d", data);
			root = insert(root, data);
			printf("����ɹ������س�ȷ��\n");
			getchar();
		}
		else if (choose == 'B') {
			if (root == NULL) {
				printf("��û���������ݣ�����\n");
			}
			else
			{
				printf("����Ϊ��������Ľ����\n");
				precursor(root);
			}
			printf("\n�س�ȷ����");
			getchar();
		}
		else if (choose == 'C') {
			if (root == NULL) {
				printf("��û���������ݣ�����\n");
			}
			else
			{
				printf("����Ϊ��������Ľ����\n");
				inorderTravelsal(root);
			}
			printf("\n�س�ȷ����");
			getchar();
		}
		else if (choose == 'D') {
			if (root == NULL) {
				printf("��û���������ݣ�����\n");
			}
			else
			{
				printf("����Ϊ��������Ľ����\n");
				postorder(root);
			}
			printf("\n�س�ȷ����");
			getchar();
		}
		else if (choose == 'E') {
			if (root == NULL) {
				printf("�㻹û�������κ�ֵ���س�ȷ����");
			}
			else
			{
				char input[100] = { 0 };
				printf("������Ҫɾ�������ݣ�");
				gets_s(input, 100);
				while (check(input))
				{
					printf("���������������������룡\n");
					gets_s(input, 100);
				}
				int data = 0;
				//���ַ�תΪ����
				for (int i = 0; input[i] != '\0'; i++) {
					data = data * 10 + input[i] - 48;
				}
				root = deleteNode(root, data);
				printf("\nɾ���ɹ����������س�ȷ����");
			}
			getchar();
		}
		else if (choose == 'F') {
			if (root == NULL) {
				printf("�㻹û�������κ����ݣ��س�ȷ��");
			}
			else
			{
				destroyTree(root);
				root = NULL;
				printf("���ٳɹ����س�ȷ��");
			}
			getchar();
		}
		else if (choose == 'G') {
			exit(0);
		}

	}
}



