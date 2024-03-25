#pragma once
//#include <WinBase.h>
#include <Windows.h>
#include <conio.h>



#pragma once
//������ķ�װ

#define upkey 72// �궨��
#define downkey 80
#define leftkey 75
#define rightkey 77

//�ӵĶ���
struct Node
{
    int data;
    struct Node* next;
};
//ָ����е�ͷ��β
struct Queue
{
    struct Node* frontNode;
    struct Node* tailNode;
    int size;
};
//�����ڵ�
struct Node* creatNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
//��������
struct Queue* creatQueue() {
    struct Queue* myQueue = (struct Queue*)malloc(sizeof(struct Queue));
    myQueue->frontNode = myQueue->tailNode = NULL;
    myQueue->size = 0;
    return myQueue;
}
//���
void push(struct Queue* myQueue) {
    char data;
    while (true)
    {
        //��������
        printf("���������֣���һ��ֻ������һ�����֣�\n");
        scanf_s("%c", &data, 1);
        getchar();//�̵��س�
        if (data >= '0' && data <= '9') {
            //�������	
            struct Node* newNode = creatNode(data-48);
            //��Ӿ��Ǳ�β����
            if (myQueue->size == 0) {
                myQueue->frontNode = myQueue->tailNode = newNode;
            }
            else
            {
                myQueue->tailNode->next = newNode;
                myQueue->tailNode = newNode;
            }
            myQueue->size++;
            printf("��ӳɹ���\n");
            break;
        }
        else
        {
            printf("�������󣡣���\n");
        }
    }
}
//���Ӳ���
void pop(struct Queue* myQueue) {
    if (myQueue->size == 0) {
        printf("û�����ݣ�����");
        system("pause");
        return;
    }
    else
    {
        struct Node* nextNode = myQueue->frontNode->next;
        free(myQueue->frontNode);
        myQueue->frontNode = nextNode;
        myQueue->size--;
        printf("���ӳɹ�������");
    }
}
//��ȡ��ͷԪ��
int front(struct Queue* myQueue) {
    if (myQueue->size == 0) {
        printf("�㻹û���������ݣ�����");
        system("pause");
        return 0;
    }
    else
    {
        return myQueue->frontNode->data;
    }
}
//����ջ
void printfStack(struct Queue* myQueue) {
    if (myQueue->size == 0) {
        printf("�㻹û�������κ����ݣ�����");
    }
    else
    {
        struct Node* newNode = myQueue->frontNode;
        printf("�ӵ�Ԫ�����£�\n");
        while (newNode != NULL) {
            printf("%d\t", newNode->data);
            newNode = newNode->next;
        }
    }
}
//�˵�չʾ
void showinput() {
    printf("---------------\n");
    printf("A:���\n");
    printf("B:����\n");
    printf("C:��ȡ��ͷԪ��\n");
    printf("D:�鲼��\n");
    printf("E:�˳�\n");
    printf("---------------\n");
}
// ����ƶ��ĺ���
void gotoxy(int x, int y)
{
    COORD pos = { x,y };
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
}

// ���ع��
void HideCursor()
{
    HANDLE fd = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cinfo;
    cinfo.bVisible = 0;
    cinfo.dwSize = 1;
    SetConsoleCursorInfo(fd, &cinfo);
}

// ���������һ��
void show(int line)
{
    gotoxy(0, 0);
    showinput();
    gotoxy(0, line);
    if (line == 1)
        printf("\033[1;34;45mA:���\n\033[0m");
    if (line == 2)
        printf("\033[1;34;45mB:����\n\033[0m");
    if (line == 3)
        printf("\033[1;34;45mC:��ȡ��ͷԪ��\n\033[0m");
    if (line == 4)
        printf("\033[1;34;45mD:������\n\033[0m");
    if (line == 5)
        printf("\033[1;34;45mE:�˳�\n\033[0m");
}

void menu_control(struct Queue* myQueue)// �˵����ƺ���
{
    char c1, c2, ch;
    int line;
    while (1)
    {
        system("cls");   //����
        system("color 00");  //���ñ�������Ļ��ɫ
        Beep(2000, 250); //������ʾ
        HideCursor();    //���ع��
        showinput(); //��ʾ�˵�
        line = 1;// ����λ��
        gotoxy(0, line);
        printf("\033[1;34;45mA:���\n\033[0m"); //�������
        for (; (c1 = _getch()) != '\r';)  // ��ȡ���°����Ĳ���
        {
            //LEFT(-32,75), UP(-32,72), DOWN(-32,80),Right(-32,77)
            if (c1 == -32)
            {
                c2 = _getch(); //��ȡ����
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
                system("cls");   //����
                gotoxy(0, 0);    //���λ��
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
                    printf("δ�������ݣ�����\n");
                }
                else
                {
                    printf("ջ��Ԫ��Ϊ%d\n", front(myQueue));
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
                printf("��Ϊ�գ�����");
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