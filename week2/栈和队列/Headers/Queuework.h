#pragma once
//#include <WinBase.h>
#include <Windows.h>
#include <conio.h>



#pragma once
//工具类的封装

#define upkey 72// 宏定义
#define downkey 80
#define leftkey 75
#define rightkey 77

//队的定义
struct Node
{
    int data;
    struct Node* next;
};
//指向队列的头和尾
struct Queue
{
    struct Node* frontNode;
    struct Node* tailNode;
    int size;
};
//创建节点
struct Node* creatNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
//创建队列
struct Queue* creatQueue() {
    struct Queue* myQueue = (struct Queue*)malloc(sizeof(struct Queue));
    myQueue->frontNode = myQueue->tailNode = NULL;
    myQueue->size = 0;
    return myQueue;
}
//入队
void push(struct Queue* myQueue) {
    char data;
    while (true)
    {
        //输入数据
        printf("请输入数字：（一次只能输入一个数字）\n");
        scanf_s("%c", &data, 1);
        getchar();//吞掉回车
        if (data >= '0' && data <= '9') {
            //创建结点	
            struct Node* newNode = creatNode(data-48);
            //入队就是表尾插入
            if (myQueue->size == 0) {
                myQueue->frontNode = myQueue->tailNode = newNode;
            }
            else
            {
                myQueue->tailNode->next = newNode;
                myQueue->tailNode = newNode;
            }
            myQueue->size++;
            printf("入队成功！\n");
            break;
        }
        else
        {
            printf("输入有误！！！\n");
        }
    }
}
//出队操作
void pop(struct Queue* myQueue) {
    if (myQueue->size == 0) {
        printf("没有数据！！！");
        system("pause");
        return;
    }
    else
    {
        struct Node* nextNode = myQueue->frontNode->next;
        free(myQueue->frontNode);
        myQueue->frontNode = nextNode;
        myQueue->size--;
        printf("出队成功！！！");
    }
}
//获取队头元素
int front(struct Queue* myQueue) {
    if (myQueue->size == 0) {
        printf("你还没有输入数据！！！");
        system("pause");
        return 0;
    }
    else
    {
        return myQueue->frontNode->data;
    }
}
//遍历栈
void printfStack(struct Queue* myQueue) {
    if (myQueue->size == 0) {
        printf("你还没有输入任何数据！！！");
    }
    else
    {
        struct Node* newNode = myQueue->frontNode;
        printf("队的元素如下：\n");
        while (newNode != NULL) {
            printf("%d\t", newNode->data);
            newNode = newNode->next;
        }
    }
}
//菜单展示
void showinput() {
    printf("---------------\n");
    printf("A:入队\n");
    printf("B:出队\n");
    printf("C:获取队头元素\n");
    printf("D:遍布队\n");
    printf("E:退出\n");
    printf("---------------\n");
}
// 光标移动的函数
void gotoxy(int x, int y)
{
    COORD pos = { x,y };
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
}

// 隐藏光标
void HideCursor()
{
    HANDLE fd = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cinfo;
    cinfo.bVisible = 0;
    cinfo.dwSize = 1;
    SetConsoleCursorInfo(fd, &cinfo);
}

// 输出高亮的一行
void show(int line)
{
    gotoxy(0, 0);
    showinput();
    gotoxy(0, line);
    if (line == 1)
        printf("\033[1;34;45mA:入队\n\033[0m");
    if (line == 2)
        printf("\033[1;34;45mB:出队\n\033[0m");
    if (line == 3)
        printf("\033[1;34;45mC:获取队头元素\n\033[0m");
    if (line == 4)
        printf("\033[1;34;45mD:遍历队\n\033[0m");
    if (line == 5)
        printf("\033[1;34;45mE:退出\n\033[0m");
}

void menu_control(struct Queue* myQueue)// 菜单控制函数
{
    char c1, c2, ch;
    int line;
    while (1)
    {
        system("cls");   //清屏
        system("color 00");  //设置背景及字幕颜色
        Beep(2000, 250); //声音提示
        HideCursor();    //隐藏光标
        showinput(); //显示菜单
        line = 1;// 高亮位置
        gotoxy(0, line);
        printf("\033[1;34;45mA:入队\n\033[0m"); //输出高亮
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
                else if (ch == downkey && line != 5)
                {
                    line++;
                    show(line);
                    continue;
                }
                else if (ch == upkey && line == 5)
                {
                    line = 5;
                    show(line);
                    continue;
                }
                else if (ch == downkey && line == 5)
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
                push(myQueue);
                Sleep(500);
                break;
            }
            else if (c1 == 'b' || c1 == 'B')
            {
                system("cls");
                gotoxy(0, 0);
                line = 0;
                pop(myQueue);
                break;
            }
            else if (c1 == 'c' || c1 == 'C')
            {
                system("cls");
                gotoxy(0, 0);
                line = 0;
                if (myQueue->size == 0) {
                    printf("未输入数据！！！\n");
                }
                else
                {
                    printf("栈顶元素为%d\n", front(myQueue));
                }
                Sleep(1000);
                break;
            }
            else if (c1 == 'd' || c1 == 'D')
            {
                system("cls");
                gotoxy(0, 0);
                line = 0;
                printfStack(myQueue);
                break;
            }
            else if (c1 == 'e' || c1 == 'E')
            {
                system("cls");
                gotoxy(0, 0);
                line = 0;
                exit(0);
                break;
            }
        }

        if (line == 1)
        {
            system("cls");
            gotoxy(0, 0);
            push(myQueue);
            Sleep(500);
        }
        else if (line == 2)
        {
            system("cls");
            gotoxy(0, 0);
            pop(myQueue);
            Sleep(1000);
        }
        else if (line == 3)
        {
            system("cls");
            gotoxy(0, 0);
            if (myQueue->size != 0) {
                printf("%d\n", myQueue->frontNode->data);
            }
            else
            {
                printf("队为空！！！");
            }
            Sleep(1000);
        }
        else if (line == 4)
        {
            system("cls");
            gotoxy(0, 0);
            printfStack(myQueue);
            Sleep(500);
        }
        else if (line == 5)
        {
            system("cls");
            gotoxy(0, 0);
            exit(0);
            Sleep(500);
        }
        Sleep(1000);
    }
}