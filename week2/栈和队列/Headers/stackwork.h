#pragma once

#pragma once
//������ķ�װ


#define upkey 72// �궨��
#define downkey 80
#define leftkey 75
#define rightkey 77

//�ṹ��
struct Node
{
    int data;
    struct Node* next;
};
//
struct stack
{
    struct Node* stackTop;//ջ�����
    int size;//ջ�ĳ���
};
//����ջ
struct stack* creatStack() {
    //�������̾��ǳ�ʼ������
    struct stack* myStack = (struct stack*)malloc(sizeof(struct stack));
    myStack->stackTop = NULL;
    myStack->size = 0;
    return myStack;
}
//�������
struct Node* creatNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
//��ջ����
void push(struct stack* myStack) {
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
            //��ջ���Ǳ�ͷ����
            newNode->next = myStack->stackTop;
            myStack->stackTop = newNode;
            myStack->size++;
            printf("��ջ�ɹ���\n");
            break;
        }
        else
        {
            printf("�������󣡣���\n");
        }
    }
    
}
//��ȡջ��Ԫ��
int topData(struct stack* myStack) {
    //�ж��Ƿ�Ϊ��
    if (myStack->size == 0) {
        system("puase");
        return myStack->size;
    }
    else
    {
        return myStack->stackTop->data;
    }
}

//��ջ���� ���Ǳ�ͷɾ��
void pop(struct stack* myStack) {
    if (myStack->stackTop == NULL) {
        printf("�㻹û���������ݣ�����\n");
        Beep(2000, 250); //������ʾ
    }
    else
    {
        struct Node* topNode = myStack->stackTop;
        topNode = topNode->next;
        free(myStack->stackTop);
        myStack->stackTop = topNode;
        myStack->size--;
        printf("��ջ�ɹ�������");
    }
}
//����ջ
void printfStack(struct stack* mystack) {
    if (mystack->stackTop == NULL) {
        printf("�㻹û�������κ����ݣ�����");
    }
    else
    {
        struct Node* newNode = mystack->stackTop;
        printf("ջ��Ԫ�����£�\n");
        while (newNode != NULL) {
            printf("%d\t", newNode->data);
            newNode = newNode->next;
        }
    }
}

//�˵�չʾ
void showinput() {
    printf("---------------\n");
    printf("A:��ջ\n");
    printf("B:��ջ\n");
    printf("C:��ȡջ��Ԫ��\n");
    printf("D:�鲼ջ\n");
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
        printf("\033[1;34;45mA:��ջ\n\033[0m");
    if (line == 2)
        printf("\033[1;34;45mB:��ջ\n\033[0m");
    if (line == 3)
        printf("\033[1;34;45mC:��ȡջ��Ԫ��\n\033[0m");
    if (line == 4)
        printf("\033[1;34;45mD:����ջ\n\033[0m");
    if (line == 5)
        printf("\033[1;34;45mE:�˳�\n\033[0m");
}

void menu_control(struct stack* mystack)// �˵����ƺ���
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
        printf("\033[1;34;45mA:��ջ\n\033[0m"); //�������
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
                    printf("δ�������ݣ�����\n");
                }
                else
                {
                    printf("ջ��Ԫ��Ϊ%d\n", topData(mystack));
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
                printf("ջΪ�գ�����");
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





