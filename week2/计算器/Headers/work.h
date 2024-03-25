#pragma once
//������ķ�װ



// ������ṹ��
struct Node
{
    char data;
    struct Node* next;
};
// ���ֽṹ��
struct numNode
{
    int data;
    struct numNode* next;
};
//ջ
struct stack
{
    struct Node* stackTop;//ջ�����
    int size;//ջ�ĳ���
};
//����ջ
struct numstack
{
    struct numNode* stackTop;//ջ�����
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
//��������ջ
struct numstack* creatNumStack() {
    //�������̾��ǳ�ʼ������
    struct numstack* myStack = (struct numstack*)malloc(sizeof(struct numstack));
    myStack->stackTop = NULL;
    myStack->size = 0;
    return myStack;
}
//�����ṹ����
struct Node* creatNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
//�������ֽṹ����
struct numNode* creatNumNode(int data) {
    struct numNode* newNode = (struct numNode*)malloc(sizeof(struct numNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
//�������ջ����
void push(struct stack* myStack,char data) {
    //�������
    struct Node* newNode = creatNode(data);
    //��ջ���Ǳ�ͷ����
    newNode->next = myStack->stackTop;
    myStack->stackTop = newNode;
    myStack->size++;
}
//������ջ����
void numpush(struct numstack* myStack, char data) {
    //�������
    struct numNode* newNode = creatNumNode(data);
    //��ջ���Ǳ�ͷ����
    newNode->next = myStack->stackTop;
    myStack->stackTop = newNode;
    myStack->size++;
}

//��ȡջ��Ԫ��
char topData(struct stack* myStack) {
    if (myStack->stackTop == NULL) {
        return NULL;
    }
    return myStack->stackTop->data;
}


//��ջ���� ���Ǳ�ͷɾ��
char pop(struct stack* myStack) {
    if (myStack->stackTop == NULL) {
        return NULL;
    }
    else
    {
        struct Node* topNode = myStack->stackTop;
        topNode = topNode->next;
        char data = myStack->stackTop->data;
        free(myStack->stackTop);
        myStack->stackTop = topNode;
        myStack->size--;
        return data;
    }
}
//���ֳ�ջ����
int numPop(struct numstack* myStack) {
    if (myStack->stackTop == NULL) {
        return NULL;
    }
    else
    {
        struct numNode* topNode = myStack->stackTop;
        topNode = topNode->next;
        int data = myStack->stackTop->data;
        free(myStack->stackTop);
        myStack->stackTop = topNode;
        myStack->size--;
        return data;
    }
}
//���ȼ����ж�
int priority(char ch) {
    if (ch == '*') {
        return 2;
    }
    else if (ch == '/') {
        return 2;//������˷���ͬһ�����ȼ�
    }
    else if (ch == '+') {
        return 1;
    }
    else if (ch == '-') {
        return 1;//�˴�ͬ��
    }
    else {
        return 0;
    }
}

//ȥ�ո�ͶԱ��ʽ���Ƿ�����ĸ�Լ��������ŵ��ж�
char* removeSpacing(char* buf) {
    char* newBuf = (char*)malloc(sizeof(char*));
    int i, j = 0;
    //��¼������������
    int left_bra = 0, right_bra = 0;
    for (i = 0, j = 0; buf[i] != '\0'; i++)
    {
        if (buf[i] != ' ') {
            if (buf[i] == '(') {
                left_bra++;
            }
            else if (buf[i] == ')') {
                right_bra++;
            }

            newBuf[j] = buf[i];
            j++;
        }
        else if ((buf[i] >= 'a' && buf[i] <= 'z') || (buf[i] >= 'A' && buf[i] <= 'Z')) {
            return NULL;
        }
    }
    if (left_bra != right_bra) {
        return NULL;
    }
    else
    {
        newBuf[j] = '\0';
        return newBuf;
    }
   
}
//���ת���
char* change(char* buf,struct stack* stack_sym) {
    char* newBuf = (char*)malloc(sizeof(char*));
    newBuf[0] = {'\0'};//���ڴ�ź�꡵ı��ʽ
    int i = 0, j = 0;
    //��¼��һ���Ƿ������ֻ����ַ����Է��û����������������������0�������֣�1�����ַ�
    int num = 0;
    //��¼��ջ�Ĵ���
    int cnt = 0;
    for ( i = 0,j = 0; buf[i] != '\0'; i++)
    {
        if (buf[i] >= '0' && buf[i] <= '9') {
            newBuf[j] = buf[i];
            j++;
            num = 0;
        }
        else
        {
            if (i != 0) {
                newBuf[j] = ' ';
                j++;
            }
            if (num == 1) {
                printf("���ʽ���󣡣���\n");
                return NULL;
            }
            if (cnt == 0 && buf[i] != '(') {
                num = 1;
                push(stack_sym, buf[i]);
                cnt++;
            }
            else if ( buf[i]=='(' || topData(stack_sym)=='(') {
                num = 1;
                push(stack_sym, buf[i]);
                cnt++;
            }
            else if (buf[i] == ')')
            {
                for (; topData(stack_sym) != '(';) {
                    newBuf[j] = pop(stack_sym);
                    j++;
                }
                pop(stack_sym);
            }
            else if (priority(buf[i]) > priority(topData(stack_sym)) ) {
                num = 1;
                push(stack_sym, buf[i]);
                cnt++;
            }
            else 
            {
                num = 1;
                for (; (priority(buf[i]) < priority(topData(stack_sym))); ) {
                    newBuf[j] = pop(stack_sym);
                    j++;
                    if (topData(stack_sym) == '\0') {
                        push(stack_sym, buf[i]);
                        break;
                    }
                }
            }
        }
    }
    for ( ; stack_sym->stackTop!=NULL; j++)
    {
        newBuf[j] = pop(stack_sym);
    }
    newBuf[j] = '\0';
    return newBuf;
}
//�����ꡱ��ʽ�������ؽ��
int result(struct stack* stack_sym,char* newBuf,struct numstack* stack_num) {
    //��¼���ս��
    int result = 0;
    for (int i = 0; newBuf[i] != '\0'; ) {
        if (newBuf[i] >= '0' && newBuf[i] <= '9') {
            //�ݴ�����
            int num = 0;
            for ( ;(newBuf[i] >= '0' && newBuf[i] <= '9'); i++) {
                num = num * 10 + (newBuf[i] - 48);
            }
            if (newBuf[i] == ' ') {
                i++;
            }
            numpush(stack_num, num);
        }
        else
        {
            if (newBuf[i] == '+') {
                int mid = numPop(stack_num) + numPop(stack_num);
                numpush(stack_num,mid);
            }
            else if (newBuf[i] == '-') {
                int mid = numPop(stack_num) - numPop(stack_num);
                numpush(stack_num, mid);
            }
            else if (newBuf[i] == '*') {
                int mid = numPop(stack_num) * numPop(stack_num);
                numpush(stack_num, mid);
            }
            else if (newBuf[i] == '/') {
                int mid = numPop(stack_num) * numPop(stack_num);
                numpush(stack_num, mid);
            }
            i++;
        }
    }
    result = numPop(stack_num);
    return result;
}


