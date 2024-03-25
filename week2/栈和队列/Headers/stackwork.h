#pragma once

#pragma once
//工具类的封装


#define upkey 72// 宏定义
#define downkey 80
#define leftkey 75
#define rightkey 77

//结构体
struct Node
{
    int data;
    struct Node* next;
};
//
struct stack
{
    struct Node* stackTop;//栈顶标记
    int size;//栈的长度
};
//创建栈
struct stack* creatStack() {
    //创建过程就是初始化过程
    struct stack* myStack = (struct stack*)malloc(sizeof(struct stack));
    myStack->stackTop = NULL;
    myStack->size = 0;
    return myStack;
}
//创建结点
struct Node* creatNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
//入栈操作
void push(struct stack* myStack) {
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
            //入栈就是表头插入
            newNode->next = myStack->stackTop;
            myStack->stackTop = newNode;
            myStack->size++;
            printf("入栈成功！\n");
            break;
        }
        else
        {
            printf("输入有误！！！\n");
        }
    }
    
}
//获取栈顶元素
int topData(struct stack* myStack) {
    //判断是否为空
    if (myStack->size == 0) {
        system("puase");
        return myStack->size;
    }
    else
    {
        return myStack->stackTop->data;
    }
}

//出栈操作 就是表头删除
void pop(struct stack* myStack) {
    if (myStack->stackTop == NULL) {
        printf("你还没有输入数据！！！\n");
        Beep(2000, 250); //声音提示
    }
    else
    {
        struct Node* topNode = myStack->stackTop;
        topNode = topNode->next;
        free(myStack->stackTop);
        myStack->stackTop = topNode;
        myStack->size--;
        printf("出栈成功！！！");
    }
}
//遍历栈
void printfStack(struct stack* mystack) {
    if (mystack->stackTop == NULL) {
        printf("你还没有输入任何数据！！！");
    }
    else
    {
        struct Node* newNode = mystack->stackTop;
        printf("栈的元素如下：\n");
        while (newNode != NULL) {
            printf("%d\t", newNode->data);
            newNode = newNode->next;
        }
    }
}

//菜单展示
void showinput() {
    printf("---------------\n");
    printf("A:入栈\n");
    printf("B:出栈\n");
    printf("C:获取栈顶元素\n");
    printf("D:遍布栈\n");
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
        printf("\033[1;34;45mA:入栈\n\033[0m");
    if (line == 2)
        printf("\033[1;34;45mB:出栈\n\033[0m");
    if (line == 3)
        printf("\033[1;34;45mC:获取栈顶元素\n\033[0m");
    if (line == 4)
        printf("\033[1;34;45mD:遍历栈\n\033[0m");
    if (line == 5)
        printf("\033[1;34;45mE:退出\n\033[0m");
}

void menu_control(struct stack* mystack)// 菜单控制函数
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
        printf("\033[1;34;45mA:入栈\n\033[0m"); //输出高亮
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
                push(mystack);
                Sleep(500);
                break;
            }
            else if (c1 == 'b' || c1 == 'B')
            {
                system("cls");
                gotoxy(0, 0);
                line = 0;
                pop(mystack);
                break;
            }
            else if (c1 == 'c' || c1 == 'C')
            {
                system("cls");
                gotoxy(0, 0);
                line = 0;
                if (mystack->size == 0) {
                    printf("未输入数据！！！\n");
                }
                else
                {
                    printf("栈顶元素为%d\n", topData(mystack));
                }
                Sleep(1000);
                break;
            }
            else if (c1 == 'd' || c1 == 'D')
            {
                system("cls");
                gotoxy(0, 0);
                line = 0;
                printfStack(mystack);
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
            push(mystack);
            Sleep(500);
        }
        else if (line == 2)
        {
            system("cls");
            gotoxy(0, 0);
            pop(mystack);
            Sleep(1000);
        }
        else if (line == 3)
        {
            system("cls");
            gotoxy(0, 0);
            if (mystack->size != 0) {
                printf("%d\n", mystack->stackTop->data);
            }
            else
            {
                printf("栈为空！！！");
            }
            Sleep(1000);
        }
        else if (line == 4)
        {
            system("cls");
            gotoxy(0, 0);
            printfStack(mystack);
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





