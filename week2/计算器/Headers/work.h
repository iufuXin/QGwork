#pragma once
//工具类的封装



// 运算符结构体
struct Node
{
    char data;
    struct Node* next;
};
// 数字结构体
struct numNode
{
    int data;
    struct numNode* next;
};
//栈
struct stack
{
    struct Node* stackTop;//栈顶标记
    int size;//栈的长度
};
//数字栈
struct numstack
{
    struct numNode* stackTop;//栈顶标记
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
//创建数字栈
struct numstack* creatNumStack() {
    //创建过程就是初始化过程
    struct numstack* myStack = (struct numstack*)malloc(sizeof(struct numstack));
    myStack->stackTop = NULL;
    myStack->size = 0;
    return myStack;
}
//创建结构体结点
struct Node* creatNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
//创建数字结构体结点
struct numNode* creatNumNode(int data) {
    struct numNode* newNode = (struct numNode*)malloc(sizeof(struct numNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
//运算符入栈操作
void push(struct stack* myStack,char data) {
    //创建结点
    struct Node* newNode = creatNode(data);
    //入栈就是表头插入
    newNode->next = myStack->stackTop;
    myStack->stackTop = newNode;
    myStack->size++;
}
//数字入栈操作
void numpush(struct numstack* myStack, char data) {
    //创建结点
    struct numNode* newNode = creatNumNode(data);
    //入栈就是表头插入
    newNode->next = myStack->stackTop;
    myStack->stackTop = newNode;
    myStack->size++;
}

//获取栈顶元素
char topData(struct stack* myStack) {
    if (myStack->stackTop == NULL) {
        return NULL;
    }
    return myStack->stackTop->data;
}


//出栈操作 就是表头删除
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
//数字出栈操作
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
//优先级的判断
int priority(char ch) {
    if (ch == '*') {
        return 2;
    }
    else if (ch == '/') {
        return 2;//除法与乘法是同一个优先级
    }
    else if (ch == '+') {
        return 1;
    }
    else if (ch == '-') {
        return 1;//此处同理
    }
    else {
        return 0;
    }
}

//去空格和对表达式里是否有字母以及左右括号的判断
char* removeSpacing(char* buf) {
    char* newBuf = (char*)malloc(sizeof(char*));
    int i, j = 0;
    //记录左，右括号数量
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
//中辍转后辍
char* change(char* buf,struct stack* stack_sym) {
    char* newBuf = (char*)malloc(sizeof(char*));
    newBuf[0] = {'\0'};//用于存放后辍的表达式
    int i = 0, j = 0;
    //记录上一个是否是数字还是字符，以防用户输入连续的两个运算符，0代表数字，1代表字符
    int num = 0;
    //记录入栈的次数
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
                printf("表达式错误！！！\n");
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
//计算后辍表达式，并返回结果
int result(struct stack* stack_sym,char* newBuf,struct numstack* stack_num) {
    //记录最终结果
    int result = 0;
    for (int i = 0; newBuf[i] != '\0'; ) {
        if (newBuf[i] >= '0' && newBuf[i] <= '9') {
            //暂存数字
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


