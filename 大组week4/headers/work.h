#pragma once
#include <stdio.h>
#include <stdlib.h>

#define size sizeof(struct treeNode)//结构体的长度

//函数声明
struct treeNode* findMinDataNode(struct treeNode* root);//找出最小值的结点
struct treeNode* deleteNode(struct treeNode* root, int data);//在树中删除结点
struct treeNode* searchData(struct treeNode* root, int data);//在树中查找特定值
struct treeNode* insert(struct treeNode* root, int data);//插入结点
struct treeNode* creatNode(int data);//创建新结点
void show();//菜单
int check(char* root);//检验用户输入



//定义结构体
struct treeNode {
	int data;
	struct treeNode* left;
	struct treeNode* right;
};

//创建新结点
struct treeNode* creatNode(int data) {
	struct treeNode* newNode = (struct treeNode*)malloc(size);
	if (newNode) {
		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
	}
	else
	{
		printf("申请内存失败。\n");
		return NULL;
	}
	return newNode;
}

//插入结点
struct treeNode* insert(struct treeNode* root, int data) {
	if (root == NULL) {
		//树中没有结点就创建一个，同时也是递归结束条件
		return creatNode(data);
	}

	if (data < root->data) {
		//小于当前节点的值放在左子树中
		root->left = insert(root->left, data);
	}
	else 
	{
		//大于或等于节点的值放在右子树中
		root->right = insert(root->right, data);
	}
	
	return root;
}

//在树中查找特定值
struct treeNode* searchData(struct treeNode* root, int data) {
	if (root == NULL || root->data == data) {
		//当找到了最后的结点或者对应的数据，同时也是递归结束条件
		return root;
	}

	if (data < root->data) {
		//当前值小于结点数据时，返回在左子树中查找的结点
		return searchData(root->left, data);
	}
	//否则返回在右子树中查找的结点
	return searchData(root->right, data);
}

//在树中删除结点
struct treeNode* deleteNode(struct treeNode* root, int data) {
	if (root == NULL) {
		//递归结束的条件，同时也是没找到相应的数据
		return root;
	}
	if (data < root->data) {
		//同查找函数的原理
		root->left = deleteNode(root->left, data);
	}
	else if (data > root->data) {
		root->right = deleteNode(root->right, data);
	}
	else
	{
		//找到了要删除的结点
		//该if是用来处理只有一个节点或者没有节点的情况
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
		//有两个节点的情况
		treeNode* temp = findMinDataNode(root->right);

		//将右子树中的最小值节点替换到当前节点
		root->data = temp->data;

		//删除右子树中的最小值节点
		root->right = deleteNode(root->right, temp->data);
	}
	return root;
}

//找出最小值的结点
struct treeNode* findMinDataNode(struct treeNode* root) {
	if (root == NULL) {
		//是否为空;
		return NULL;
	}
	//找出最小值节点
	while (root->left != NULL)
	{
		root = root->left;
	}

	return root;
}
//销毁二叉树
void destroyTree(struct treeNode* root) {
	if (root != NULL) {
		//当树不为空时，销毁左子树
		destroyTree(root->left);
		//销毁右子树
		destroyTree(root->right);
		//释放内存
		free(root);
	}
}
//中序遍历二叉树
void inorderTravelsal(struct treeNode* root) {
	if (root != NULL) {
		//当树不为空时，遍历左子树
		inorderTravelsal(root->left);
		printf("%d\t", root->data);
		//遍历右子树
		inorderTravelsal(root->right);
	}
}
//先序遍历二叉树
void precursor(struct treeNode* root) {
	if (root != NULL) {
		printf("%d\t", root->data);
		precursor(root->left);
		precursor(root->right);
	}
}
//后序遍历二叉树
void postorder(struct treeNode* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d\t", root->data);
	}
}
//菜单
void show() {
	printf("A:输入数据\n");
	printf("B:先序遍历数据\n");
	printf("C:中序遍历数据\n");
	printf("D:后序遍历数据\n");
	printf("E:删除数据\n");
	printf("F:销毁\n");
	printf("G:退出\n");
	printf("请选择：");
}

//检验用户输入
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


