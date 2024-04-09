#pragma once
#include <stdio.h>
#include <stdlib.h>

#define size sizeof(struct treeNode)//�ṹ��ĳ���

//��������
struct treeNode* findMinDataNode(struct treeNode* root);//�ҳ���Сֵ�Ľ��
struct treeNode* deleteNode(struct treeNode* root, int data);//������ɾ�����
struct treeNode* searchData(struct treeNode* root, int data);//�����в����ض�ֵ
struct treeNode* insert(struct treeNode* root, int data);//������
struct treeNode* creatNode(int data);//�����½��
void show();//�˵�
int check(char* root);//�����û�����



//����ṹ��
struct treeNode {
	int data;
	struct treeNode* left;
	struct treeNode* right;
};

//�����½��
struct treeNode* creatNode(int data) {
	struct treeNode* newNode = (struct treeNode*)malloc(size);
	if (newNode) {
		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
	}
	else
	{
		printf("�����ڴ�ʧ�ܡ�\n");
		return NULL;
	}
	return newNode;
}

//������
struct treeNode* insert(struct treeNode* root, int data) {
	if (root == NULL) {
		//����û�н��ʹ���һ����ͬʱҲ�ǵݹ��������
		return creatNode(data);
	}

	if (data < root->data) {
		//С�ڵ�ǰ�ڵ��ֵ������������
		root->left = insert(root->left, data);
	}
	else 
	{
		//���ڻ���ڽڵ��ֵ������������
		root->right = insert(root->right, data);
	}
	
	return root;
}

//�����в����ض�ֵ
struct treeNode* searchData(struct treeNode* root, int data) {
	if (root == NULL || root->data == data) {
		//���ҵ������Ľ����߶�Ӧ�����ݣ�ͬʱҲ�ǵݹ��������
		return root;
	}

	if (data < root->data) {
		//��ǰֵС�ڽ������ʱ���������������в��ҵĽ��
		return searchData(root->left, data);
	}
	//���򷵻����������в��ҵĽ��
	return searchData(root->right, data);
}

//������ɾ�����
struct treeNode* deleteNode(struct treeNode* root, int data) {
	if (root == NULL) {
		//�ݹ������������ͬʱҲ��û�ҵ���Ӧ������
		return root;
	}
	if (data < root->data) {
		//ͬ���Һ�����ԭ��
		root->left = deleteNode(root->left, data);
	}
	else if (data > root->data) {
		root->right = deleteNode(root->right, data);
	}
	else
	{
		//�ҵ���Ҫɾ���Ľ��
		//��if����������ֻ��һ���ڵ����û�нڵ�����
		if (root->left == NULL) {
			treeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			treeNode* temp = root->left;
			free(root);
			return temp;
		}
		//�������ڵ�����
		treeNode* temp = findMinDataNode(root->right);

		//���������е���Сֵ�ڵ��滻����ǰ�ڵ�
		root->data = temp->data;

		//ɾ���������е���Сֵ�ڵ�
		root->right = deleteNode(root->right, temp->data);
	}
	return root;
}

//�ҳ���Сֵ�Ľ��
struct treeNode* findMinDataNode(struct treeNode* root) {
	if (root == NULL) {
		//�Ƿ�Ϊ��;
		return NULL;
	}
	//�ҳ���Сֵ�ڵ�
	while (root->left != NULL)
	{
		root = root->left;
	}

	return root;
}
//���ٶ�����
void destroyTree(struct treeNode* root) {
	if (root != NULL) {
		//������Ϊ��ʱ������������
		destroyTree(root->left);
		//����������
		destroyTree(root->right);
		//�ͷ��ڴ�
		free(root);
	}
}
//�������������
void inorderTravelsal(struct treeNode* root) {
	if (root != NULL) {
		//������Ϊ��ʱ������������
		inorderTravelsal(root->left);
		printf("%d\t", root->data);
		//����������
		inorderTravelsal(root->right);
	}
}
//�������������
void precursor(struct treeNode* root) {
	if (root != NULL) {
		printf("%d\t", root->data);
		precursor(root->left);
		precursor(root->right);
	}
}
//�������������
void postorder(struct treeNode* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d\t", root->data);
	}
}
//�˵�
void show() {
	printf("A:��������\n");
	printf("B:�����������\n");
	printf("C:�����������\n");
	printf("D:�����������\n");
	printf("E:ɾ������\n");
	printf("F:����\n");
	printf("G:�˳�\n");
	printf("��ѡ��");
}

//�����û�����
int check(char* root) {
	for (int i = 0; root[i] != '\0'; i++) {
		if (root[i] >= '0' && root[i] <= '9') {
		}
		else
		{
			return 1;
		}
	}
	return 0;
}


