/************************/
//队列
#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Queue {
    int *data;
    int head, tail, length;
} Queue;

void init(Queue *q, int length) {
    q->data = (int *)malloc(sizeof(int) * length);
    q->length = length;
    q->head = 0;
    q->tail = -1;
}

int push(Queue *q, int element) {
    if (q->tail + 1 >= q->length) {
        return ERROR;
    }
    q->tail++;
    q->data[q->tail] = element;
    return OK;
}

void output(Queue *q) {
    for (int i = q->head; i <= q->tail; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

// 请在下面实现队首元素输出函数 front
int front(Queue *q) {
    return q->data[q->head];
}

// 请在下面实现删除队首元素函数 pop
void pop(Queue *q) {
    q->head++;
}

// 请在下面实现判断队列是否为空的函数 empty
int empty (Queue *q) {
    return q->head > q->tail;
}

void clear(Queue *q) {
    free(q->data);
    free(q);
}

int main() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    init(queue, 100);
    for (int i = 1; i <= 10; i++) {
        push(queue, i);
    }
    output(queue);
    if (!empty(queue)) {
        printf("%d\n", front(queue));
        pop(queue);
    }
    output(queue);
    clear(queue);
    return 0;
}


/*****************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Queue {
    int *data;
    int head, tail, length;
} Queue;

void init(Queue *q, int length) {
    q->data = (int *)malloc(sizeof(int) * length);
    q->length = length;
    q->head = 0;
    q->tail = -1;
}

int push(Queue *q, int element) {
    if (q->tail + 1 >= q->length) {
        return ERROR;
    }
    q->data[++q->tail] = element;
    return OK;
}
void output(Queue *q) {
    if (!empty(q)) {
        printf("%d", q->data[q->head]);
    }
    for (int i = q->head + 1; i <= q->tail; ++i) {
        printf(" %d", q->data[i]);
    }
    printf("\n");
}
int front(Queue *q) {
    return q->data[q->head];
}
void pop(Queue *q) {
    ++(q->head);
}

int empty(Queue *q) {
    return q->head > q->tail;
}

void clear(Queue *q) {
    free(q->data);
    free(q);
}

int main() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    init(queue, 100);
    int m, n, k;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &k);
        push(queue, k);
    }
    scanf("%d", &n);
    while (n--) {
        pop(queue);
    }
    printf("%d\n", front(queue));
    output(queue);
    clear(queue);
    return 0;
}



/**************************************************************/


#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Queue {
    int *data;
    int length, head, tail;
} Queue;

void init(Queue *q, int length) {
    q->data = (int *)malloc(sizeof(int) * length);
    q->length = length;
    q->head = 0;
    q->tail = -1;
}

int push(Queue *q, int element) {
    if (q->tail + 1 >= q->length) {
        return ERROR;
    }
    q->tail++;
    q->data[q->tail] = element;
    return OK;
}
void output(Queue *q) {
    //if (!empty(q)) {
    //    return ERROR;
    //}
    for (int i = q->head; i < q->tail; ++i) {
        printf("%d ", q->data[i]);
    }
    printf("%d\n", q->data[q->tail]);
}
int front(Queue *q) {
    return q->data[q->head];
}
void pop(Queue *q) {
    q->head++;
}

int empty(Queue *q) {
    return q->head > q->tail;
}

void clear(Queue *q) {
    free(q->data);
    free(q);
}

int main() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    init(queue, 100);
    int n, p, m;
    scanf("%d", &n);
    for (int i = 0; i < n; ++n) {
        scanf("%d", &p);
        push(queue, p);
    }
    //output(queue);
    scanf("%d", &m);
    while (m--) {
        pop(queue);
    }
    printf("%d", front(queue));
    output(queue);
    clear(queue);
    return 0;
}


/*************************************************************/
/*******
 * 栈
 *
 ******/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ERROR 0
#define OK 1

typedef struct Stack {
    int *elements;
    int max_size, top_index;
} Stack;

void init(Stack *s, int length) {
    s->elements = (int *)malloc(sizeof(int) * length);
    s->max_size = length;
    s->top_index = -1;
}

int push(Stack *s, int element) {
    if (s->top_index >= s->max_size - 1) {
        return ERROR;
    }
    s->top_index++;
    s->elements[s->top_index] = element;
    return OK;
}

int pop(Stack *s) {
    if (s->top_index < 0) {
        return ERROR;
    }
    s->top_index--;
    return OK;
}

int top(Stack *s) {
    return s->elements[s->top_index];
}

int empty(Stack *s) {
    if (s->top_index < 0) {
        return 1;
    } else {
        return 0;
    }
}

int precede(char a, char b) {
    if (a == '*' && b == '+') {
        return 1;
    } else {
        return 0;
    }
}

int operate(char theta, int a, int b) {
    if (theta == '+') {
        return a + b;
    } else {
        return a * b;
    }
}

void calc(Stack *numbers, Stack *operators) {
    int a = top(numbers);
    pop(numbers);
    int b = top(numbers);
    pop(numbers);
    push(numbers, operate(top(operators), a, b));
    pop(operators);
}

void clear(Stack *s) {
    free(s->elements);
    free(s);
}

int main() {
    int n;
    scanf("%d", &n);
    Stack *numbers = (Stack *)malloc(sizeof(Stack));
    init(numbers , n);
    Stack *operators = (Stack *)malloc(sizeof(Stack));
    init(operators, n);
    char *buffer = (char *)malloc(sizeof(char) * (n + 1));
    scanf("%s", buffer);
    int i = 0;
    while (i < n) {
        if (isdigit(buffer[i])) {
            push(numbers, buffer[i] - '0');
            i++;
        } else {
            if (empty(operators) || precede(buffer[i], top(operators)) ) {
                push(operators, buffer[i]);
                i++;
            } else {
                calc (numbers, operators);
            }
        }
    }
    while (!empty(operators)) {
        calc(numbers, operators);
    }
    printf("%d\n", top(numbers));
    clear(numbers);
    clear(operators);
    free(buffer);
    return 0;
}
/****************************************************************************/
///////////
//nacat.c//
///////////

#include <stdio.h>
#include <string.h>
#include "roman.h"

typedef struct {
    int roman_flag;
    FILE *fin;
    FILE *fout;
} System_args;

int init(int, char *[], System_args *);
void read_and_output(System_args *);
void close_all(System_args *);

int main(int argc, char *argv[])
{
    System_args main_args;
    if (init(argc, argv, &main_args) == 0) {
        return 0;
    }
    read_and_output(&main_args);
    close_all(&main_args);
    return 0;
}

int init(int argc, char *argv[], System_args *args) {
    if (argc < 2) {
        return 0;
    }
    args->roman_flag = (strcmp(argv[1], "-r") == 0 ? 1 : 0);
    args->fin = stdin;
    args->fout = stdout;
    if (argc >= 3) {
        args->fin = fopen(argv[2], "r");
        if (argc >= 4) {
            args->fout = fopen(argv[3], "w");
        }
    }
    return 1;
}

void close_all(System_args *args) {
    if (args->fin != stdin) {
        fclose(args->fin);
        args->fin = NULL;
    }
    if (args->fout != stdout) {
        fclose(args->fout);
        args->fout = NULL;
    }
    return ;
}

void read_and_output(System_args *args) {
    if (args->fin == NULL || args->fout == NULL) return ;
    int line_index = 1;
    int output_line_index = 1;
    char dst[25];
    char c;
    while (fscanf(args->fin, "%c", &c) != EOF) {
        if (output_line_index == 1) {
            if (args->roman_flag) {
                fprintf(args->fout, "%s\t", to_roman_numeral(dst, line_index));
            } else {
                fprintf(args->fout, "%d\t", line_index);
            }
            output_line_index = 0;
        }
        fprintf(args->fout, "%c", c);
        if (c == '\n') {
            output_line_index = 1;
            ++line_index;
        }
    }
    return ;
}

/************************************************************/

/**********
 *Makefile
 *********/

CC = gcc
    CFLAGS = -std = c99 - Wall - Werror
    RM = rm

    MAINOBJS = roman.o ncat.o

    .PHONY: clean

    ncat: $(MAINOBJS)
    $(CC) $(CFLAGS) - o ncat $(MAINOBJS)

    ncat.o: ncat.c roman.h
    $(CC) $(CFLAGS) - c - o ncat.o ncat.c

    roman.o : roman.c roman.h
    $(CC) $(CFLAGS) - c - o roman.o roman.c

    clean:
    $(RM) - rf * .o ncat

/**********************************************************


/*******************
单项循环链表变双向*******************/


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prior;
} Node, *LinkedList;

Node insert(LinkedList head, int index, int value) {
    Node *p, ret;
    int raw_index = index, len = 0;
    p = head;
    ret.data = 0;
    while (p && index) {
        p = p->next;
        --index;
        ++len;
        if (p == head) break;
    }
    if (index == 0) {
        Node *node = (Node *)malloc(sizeof(Node));
        node->data = value;
        node->next = node;
        if (p != NULL) {
            node->next = p->next;
            p->next = node;
        }
        node->prior = NULL;
        if (p == head && len == raw_index) {
            head = node;
        }
        ret.data = 1;
    }
    ret.next = head;
    return ret;
}

LinkedList build(LinkedList head) {
    Node *p, *q;
    if (head == NULL) {
        return head;
    }
    p = head;
    q = head->next;
    do {
        q->prior = p;
        p = p->next;
        q = q->next;
    } while (q != head->next);
    return head;
}

void output(LinkedList head, int m) {
    int len = 0;
    Node *p = head, *q;
    while (p->data != m) {
        p = p->next;
    }
    q = p;
    printf("%d", p->data);
    p = p->prior;
    while (p != q) {
        printf(" %d", p->data);
        p = p->prior;
    }
    printf("\n");
    return ;
}

void clear(LinkedList head) {
    Node *p, *q;
    if (head == NULL) {
        return ;
    }
    p = head->next;
    head->next = NULL;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    return ;
}

int main() {
    LinkedList linkedlist = NULL;
    Node ret;
    int n, m, num;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num);
        ret = insert(linkedlist, i, num);
        if (ret.data == 0) {
            printf("ERROR\n");
            return 1;
        }
        linkedlist = ret.next;
    }
    linkedlist = build(linkedlist);
    scanf("%d", &m);
    output(linkedlist, m);
    fflush(stdout);
    clear(linkedlist);
    return 0;
}

/************************************************************/
/////////////
//二叉树构建//
////////////

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *lchild, *rchild;
} Node;

Node* init(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}

Node* build_demo() {
    Node *node = init(1);
    node->lchild = init(2);
    node->rchild = init(3);
    node->lchild->lchild = init(4);
    node->lchild->rchild = init(5);
    node->rchild->rchild = init(6);
    return node;
}

void preorder(Node *node) {
    printf("%d ", node->data);
    if (node->lchild != NULL) {
        preorder(node->lchild);
    }
    if (node->rchild != NULL) {
        preorder(node->rchild);
    }
}

void inorder(Node *node) {
    if (node->lchild != NULL) {
        inorder(node->lchild);
    }
    printf("%d ", node->data);
    if (node->rchild != NULL) {
        inorder(node->rchild);
    }
}

// 请在下面实现后序遍历函数 postorder
void postorder(Node *node) {
    if (node->lchild != NULL) {
        postorder(node->lchild);
    }
    if (node->rchild != NULL) {
        postorder(node->rchild);
    }
    printf("%d ", node->data);
}

void clear(Node *node) {
    if (node->lchild != NULL) {
        clear(node->lchild);
    }
    if (node->rchild != NULL) {
        clear(node->rchild);
    }
    free(node);
}

int main() {
    Node *root = build_demo();
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    clear(root);
    return 0;
}

/*********************************************************/
////////////////
//神奇的二叉树///
///////////////
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
} Node;

Node *init(char data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}

Node *build(char *pre_str, char *in_str, int len) {
    Node *p = init(pre_str[0]);
    int pos = strchr(in_str, pre_str[0]) - in_str;
    if (pos > 0) {
        p->lchild = build(pre_str + 1, in_str, pos);
    }
    if (len - pos - 1 > 0) {
        p->rchild = build(pre_str + pos + 1, in_str + pos + 1, len - pos - 1);
    }
    return p;
}

void postorder1(Node *node) {
    if (node->lchild) {
        postorder1(node->lchild);
    }
    if (node->rchild) {
        postorder1(node->rchild);
    }
    printf("%c", node->data);
}

void postorder2(Node *node) {
    if (node->rchild) {
        postorder2(node->rchild);
    }
    if (node->lchild) {
        postorder2(node->lchild);
    }
    printf("%c", node->data);
}

int main() {
    char *pre_str, *in_str;
    pre_str = (char *)malloc(51);
    in_str = (char *)malloc(51);
    scanf("%s%s", pre_str, in_str);
    Node *root = build(pre_str, in_str, strlen(pre_str));
    postorder1(root);
    printf("\n");
    postorder2(root);
    printf("\n");
    return 0;
}


/***********************************************************/
/*******************
   递归删除指定节点
 *******************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR 0
#define OK 1

typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
} Node, *pNode;

typedef struct Stack {
    pNode *data;
    int size, top;
} Stack, *pStack;

void init_stack(Stack *s, int len) {
    s->data = (pNode *)malloc(sizeof(pNode) * len);
    s->size = len;
    s->top = -1;
}

int push_stack(Stack *s, pNode e) {
    if (s->top >= s->size - 1) {
        return ERROR;
    }
    s->data[++(s->top)] = e;
    return OK;
}

int pop_stack(Stack *s) {
    if (empty_stack(s)) {
        return ERROR;
    }
    --(s->top);
    return OK;
}

pNode top_stack(Stack *s) {
    if (empty_stack(s)) return NULL;
    return s->data[s->top];
}

int empty_stack(Stack *s) {
    return s->top == -1;
}

void clear_stack(Stack *s) {
    free(s->data);
    free(s);
}

pNode init(char data) {
    pNode p = (pNode)malloc(sizeof(Node));
    p->data = data;
    p->lchild = NULL;
    p->rchild = NULL;
    return p;
}

void clear(pNode p) {
    if (!p) return ;
    if (p->lchild) {
        clear(p->lchild);
    }
    if (p->rchild) {
        clear(p->rchild);
    }
    free(p);
}

pNode build(char *str) {
    pNode p = NULL, last_p = NULL;
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    init_stack(stack, strlen(str));
    int k = 0;
    while (str[0]) {
        switch (str[0]) {
        case '(' :
            k = 0;
            push_stack(stack, p);
            p = NULL;
            break;
        case ')' :
            last_p = top_stack(stack);
            pop_stack(stack);
            break;
        case ',' :
            k = 1;
            p = NULL;
            break;
        case ' ':
            break;
        default :
            p = init(str[0]);
            if (!empty_stack(stack) && k == 0) {
                top_stack(stack)->lchild = p;
            } else if (!empty_stack(stack) && k == 1) {
                top_stack(stack)->rchild = p;
            }
            break;
        }
        ++str;
    }
    if (p && !last_p) last_p = p;
    clear_stack(stack);
    return last_p;
}

void output(pNode p, char x) {
    if (p == NULL || p->data == x) {
        return ;
    }
    printf("%c", p->data);
    if ((p->lchild == NULL || p->lchild->data == x) &&
            (p->rchild == NULL || p->rchild->data == x)) {
        return ;
    }
    printf("(");
    if (p->lchild && p->lchild->data != x) {
        output(p->lchild, x);
    }
    if (p->rchild && p->rchild->data != x) {
        printf(",");
        output(p->rchild, x);
    }
    printf(")");
    return ;
}

int main() {
    char str[35], ch;
    int ind = 0;
    while (scanf("%c", &ch)) {
        if (ch == '\n') break;
        str[ind++] = ch;
    }
    str[ind] = 0;
    scanf("%c", &ch);
    pNode p = build(str);
    output(p, ch);
    clear(p);
    return 0;
}

/**************************************************/
/*******************
   Huffman Coding
 *******************/


#define maxn 1000

struct huffnode
{
    char ch; //字符
    int weight; //权值
    int parent; //父节点下标
    int lchild;
    int rchild;
} HTree[maxn * 2];
char *HCode[maxn * 2];

/* 创建最优二叉树 */
/* 数组c[0..n-1]和w[0..n-1]存放了n个字符及其概率，构造Huffman树HT */


void select(int n, int &r1, int &r2)
{

    int minx1 = -1, ans1 = -1, ans2 = -1;
    for (int i = 1; i <= n; i++)
    {
        if (HT[i].parent == 0)
        {
            if (minx1 < 0 || HTree[i].weight < minx1)
            {
                minx1 = HTree[i].weight;
                ans1 = i;
            }
        }
    }
    minx1 = -1;
    for (int i = 1; i <= n; i++)
    {
        if (HTree[i].parent == 0 && i != ans1)
        {
            if (minx1 < 0 || HTree[i].weight < minx1)
            {
                minx1 = HTree[i].weight;
                ans2 = i;
            }
        }
    }

    r1 = ans1;
    r2 = ans2;
}

void createHTree(char c[], int w[], int n )
{
    int i, s1, s2;
    if (n <= 1)
        return;


    /* 根据n个权值构造n棵只有根结点的二叉树 */
    for (i = 1; i <= n; i++)
    {
        HTree[i].ch = c[i - 1];
        HTree[i].weight = w[i - 1];
        HTree[i].parent = HTree[i].lchild = HTree[i].rchild = 0;
    }
    for (; i < 2 * n; ++i)
    {
        HTree[i].ch = '0';
        HTree[i].parent = 0;
        HTree[i].lchild = 0;
        HTree[i].rchild = 0;
    }
    /* 构造Huffman树 */
    for (i = n + 1; i < 2 * n; i++)
    {
        /* 从HT[1..i-1]中选择parent为0且weight最小的两棵树，其序号为s1和s2 */
        select(i - 1, s1, s2);
        HTree[s1].parent = i;
        HTree[s2].parent = i;
        HTree[i].lchild = s1;
        HTree[i].rchild = s2;
        HTree[i].weight = HTree[s1].weight + HTree[s2].weight;
    }
}

/* n个叶子结点在Huffman树HT中的下标为1~n  */
/* 第i（1<= i <= n）个叶子的编码存放HC[i]中 */
void HuffmanCoding(int n)
{
    char *cd;
    int i, start, c, f;
    if (n <= 1)
        return;

    /* 分配n个字节的内存，用来存放当前得到的编码 */
    /* n个叶子结点最大的编码长度为n所以分配n个字节 */
    cd = (char*)malloc(n);
    cd[n - 1] = '\0';
    for (i = 1; i <= n; i++)
    {
        start = n - 1;
        for (c = i, f = HTree[c].parent; f != 0; c = f, f = HTree[f].parent)
        {
            /**
            c获取结点的下标，f获取其父母，如果其父母的左孩子下标与c相等，说明处于左子树，填0

            ，否则在右子树，填1，然后c跳到父母
            */
            if (HT[f].lchild == c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
        }
        /* 从叶子结点开始查找编码
           叶子结点的父结点的左子树为叶子结点，则编码为0
           否则就为父结点的右子树，则编码为1 */

        /* 分配内存，分配内存的字节数为当前得到的字符编码数 */
        HCode[i] = (char*)malloc(n - start);
        strcpy(HCode[i], &cd[start]);
    }
    free(cd);
}

/*****************************************************************/
/*******************
　建立顺序存储完全二叉树
 *******************/


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
} Node, *pNode;

pNode init(char data) {
    pNode p = (pNode)malloc(sizeof(Node));
    p->data = data;
    p->lchild = NULL;
    p->rchild = NULL;
    return p;
}

void clear(pNode p) {
    if (!p) return ;
    if (p->lchild) {
        clear(p->lchild);
    }
    if (p->rchild) {
        clear(p->rchild);
    }
    free(p);
}

void output(pNode p) {
    if (!p) return ;
    printf("%c", p->data);
    if (p->lchild == NULL && p->rchild == NULL) {
        return ;
    }
    printf("(");
    if (p->lchild) {
        output(p->lchild);
    }
    if (p->rchild) {
        printf(",");
        output(p->rchild);
    }
    printf(")");
}

int main() {
    int len = 0, size = 50;
    char *str = (char *)malloc(size);
    char ch;
    str[0] = 0;
    while (scanf("%c", &ch)) {
        if (ch == '$') {
            break;
        }
        str[len++] = ch;
        if (len == size) {
            size *= 2;
            str = realloc(str, size);
        }
    }
    pNode *p_arr = (pNode *)malloc(sizeof(pNode) * (strlen(str) / 2 + 1));
    int ind = 1;
    p_arr[ind] = NULL;
    for (int i = 0; i < len; ++i) {
        if (str[i] == ' ') continue;
        p_arr[ind] = init(str[i]);
        if (ind != 1) {
            if (ind % 2) {
                p_arr[ind / 2]->rchild = p_arr[ind];
            } else {
                p_arr[ind / 2]->lchild = p_arr[ind];
            }
        }
        ++ind;
    }
    output(p_arr[1]);
    printf("\n");
    clear(p_arr[1]);
    free(p_arr);
    free(str);
    return 0;
}

/******************************************************/

/*******************
　层次遍历二叉树
*******************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR 0
#define OK 1

typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
} Node, *pNode;

typedef struct Stack {
    pNode *data;
    int size, top;
} Stack, *pStack;

typedef struct Queue {
    pNode *data;
    int head, tail, len, cnt;
} Queue, *pQueue;

void init_queue(pQueue q, int len) {
    q->data = (pNode *)malloc(sizeof(pNode) * len);
    q->len = len;
    q->head = 0;
    q->tail = -1;
    q->cnt = 0;
}

int push_queue(pQueue q, pNode e) {
    if (q->cnt == q->len) {
        return ERROR;
    }
    q->tail = (q->tail + 1) % q->len;
    q->data[q->tail] = e;
    ++(q->cnt);
    return OK;
}

int empty_queue(pQueue q) {
    return q->cnt == 0;
}

int pop_queue(pQueue q) {
    if (empty_queue(q)) {
        return ERROR;
    }
    ++(q->head);
    --(q->cnt);
    return OK;
}

pNode front_queue(pQueue q) {
    return q->data[q->head];
}

void clear_queue(pQueue q) {
    if (!q) return ;
    free(q->data);
    free(q);
}

void init_stack(Stack *s, int len) {
    s->data = (pNode *)malloc(sizeof(pNode) * len);
    s->size = len;
    s->top = -1;
}

int push_stack(Stack *s, pNode e) {
    if (s->top >= s->size - 1) {
        return ERROR;
    }
    s->data[++(s->top)] = e;
    return OK;
}

int empty_stack(Stack *s) {
    return s->top == -1;
}

int pop_stack(Stack *s) {
    if (empty_stack(s)) {
        return ERROR;
    }
    --(s->top);
    return OK;
}

pNode top_stack(Stack *s) {
    return s->data[s->top];
}

void clear_stack(Stack *s) {
    free(s->data);
    free(s);
}

pNode init(char data) {
    pNode p = (pNode)malloc(sizeof(Node));
    p->data = data;
    p->lchild = NULL;
    p->rchild = NULL;
    return p;
}

void clear(pNode p) {
    if (!p) return ;
    if (p->lchild) {
        clear(p->lchild);
    }
    if (p->rchild) {
        clear(p->rchild);
    }
    free(p);
}

pNode build(char *str, int *node_num) {
    pNode p = NULL, last_p = NULL;
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    init_stack(stack, strlen(str));
    int k = 0;
    while (str[0]) {
        switch (str[0]) {
        case '(' :
            k = 0;
            push_stack(stack, p);
            p = NULL;
            break;
        case ')' :
            last_p = top_stack(stack);
            pop_stack(stack);
            break;
        case ',' :
            k = 1;
            p = NULL;
            break;
        case ' ':
            break;
        default :
            p = init(str[0]);
            if (!empty_stack(stack) && k == 0) {
                top_stack(stack)->lchild = p;
            } else if (!empty_stack(stack) && k == 1) {
                top_stack(stack)->rchild = p;
            }
            ++(*node_num);
            break;
        }
        ++str;
    }
    if (p && !last_p) last_p = p;
    clear_stack(stack);
    return last_p;
}

void output(pNode p, int node_num) {
    if (node_num == 0) {
        return ;
    }
    printf("%c", p->data);
    pQueue q = (pQueue)malloc(sizeof(Queue));
    pNode temp_p;
    init_queue(q, node_num);
    push_queue(q, p);
    while (!empty_queue(q)) {
        temp_p = front_queue(q);
        if (temp_p->lchild) {
            printf(" %c", temp_p->lchild->data);
            push_queue(q, temp_p->lchild);
        }
        if (temp_p->rchild) {
            printf(" %c", temp_p->rchild->data);
            push_queue(q, temp_p->rchild);
        }
        pop_queue(q);
    }
    clear_queue(q);
    return ;
}

int main() {
    char str[100] = {0}, ch;
    int ind = 0;
    scanf("%s", str);
    int node_num = 0;
    pNode p = build(str, &node_num);
    output(p, node_num);
    clear(p);
    return 0;
}

/****************************************************************/

/************************
　根据三元组数列建立二叉链表
************************/

#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
} Node, *pNode;

pNode init(char data) {
    pNode p = (pNode)malloc(sizeof(Node));
    p->data = data;
    p->lchild = NULL;
    p->rchild = NULL;
    return p;
}

void clear(pNode p) {
    if (!p) return ;
    if (p->lchild) {
        clear(p->lchild);
    }
    if (p->rchild) {
        clear(p->rchild);
    }
    free(p);
}

void output(pNode p) {
    if (p == NULL) {
        return ;
    }
    printf("%c", p->data);
    if (p->lchild == NULL && p->rchild == NULL) {
        return ;
    }
    printf("(");
    if (p->lchild) {
        output(p->lchild);
    }
    if (p->rchild) {
        printf(",");
        output(p->rchild);
    }
    printf(")");
    return ;
}

pNode p_arr[26] = {0};

int main() {
    char str[4];
    pNode root = NULL, p = NULL;
    while (scanf("%s", str) != EOF) {
        if (str[0] == str[1] && str[0] == '^') {
            break;
        }
        p = init(str[1]);
        p_arr[str[1] - 'A'] = p;
        if (str[0] == '^') {
            root = p;
        } else {
            switch (str[2]) {
            case 'L' :
                p_arr[str[0] - 'A']->lchild = p;
                break;
            case 'R' :
                p_arr[str[0] - 'A']->rchild = p;
                break;
            default :
                printf("ERROR\n");
                break;
            }
        }
    }
    output(root);
    printf("\n");
    clear(root);
    return 0;
}

/********************************************************************/

void quick_sort(int *data, int left, int right) {
    if (left > right) {
        return ;
    }
    int pivot = data[left], low = left, high = right;
    while (low < high) {
        while (low < high && data[high] >= pivot) {
            high--;
        }
        data[low] = data[high];
        while (low < high && data[low] <= pivot) {
            low++;
        }
        data[high] = data[low];
    }
    data[low] = pivot;
    quick_sort(data, left, low - 1);
    quick_sort(data, low + 1, right);
}

void sort(int *data, int length) {
    int temp;
    for (int i = 0; i < length - 1; ++i) {
        temp = i;
        for (int j = i + 1; j < length; ++j) {
            if (data[temp] > data[j]) {
                temp = j;
            }
        }
        if (i != temp) {
            swap(&data[i], &data[temp]);        
        }
    }
}

/******************************************************************/
#include <stdio.h>
#include <stdlib.h>
 
int search(int *data, int n, int value) {
    int x = 0, y = n - 1;
    int mid;
    while (x < y) {
        mid = (x + y + 1) >> 1;
        if (data[mid] == value) {
            return mid;
        } else if (data[mid] > value) {
            y = mid - 1;
        } else {
            x = mid;
        }
    }
    return x;
}
 
int main() {
    int n, m, q;
    scanf("%d%d", &n, &m);
    int *data = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", data + i);
    }
    while (m--) {
        scanf("%d", &q);
        printf("%d", data[search(data, n, q)]);
        if (m) {
            printf(" ");
        }
    }
    free(data);
    return 0;
}





void shift_and(char *s, char *t) {
    int str_encoed[256] = {0};
    int p = 0, len = 0, times = 0;
    for (int i = 0; t[i]; i++) {
        str_encoed[t[i]] |= (1 << i);
        len++;
        times++;
    }
    for (int i = 0; s[i]; i++) {
        p = (p << 1 | 1) & str_encoed[s[i]];
        times++;
        if (p & (1 << (len - 1))) {
            printf("SHIFT AND YES : %d\n", times);
            return ;
        }
    }
    printf("SHIFT AND YES : %d\n", times);
    return ;
}

/************************************************************************/
int linkedListCycleLength(ListNode *head) {
    ListNode *p, *q;
    p = q = head;
    while (q && q->next) {
        p = p-> next;
        q = q->next->next;
        if (q == p) {
            break;
        }
    }
    if (p != q) return 0;
    int n = 0;
    do {
        p = p->next;
        q = q->next->next;
        n++;
    } while (p != q);
    return n;
}

/*****************************************************************/
ListNode* remove(ListNode *head, int index) {
    // 如果链表为空，删除无效
    if (head == NULL) {
        return head;
    }

    ListNode *current_node = head;
    int count = 0;

    // 删除表头的情况
    if (index == 0) {
        head = head->next;
        delete current_node;
        return head;
    }

    // 找到下标为 index-1 的结点，保存为 current_node
    while (current_node->next != NULL && count < index - 1) {
        current_node = current_node->next;
        count++;
    }

    // 判断是否找到了下标为 index-1 的结点，并且下标为 index 的结点是否不为空
    if (count == index - 1 && current_node->next != NULL) {
        ListNode *delete_node = current_node->next;
        current_node->next = delete_node->next;
        delete_node->next->pre = current_node;
        delete delete_node;
    }
    return head;
}

ListNode *deleteValNode(ListNode *head, int val) {
    if (head == NULL) return NULL;
    ListNode *virtualHead = (ListNode *)malloc(sizeof(ListNode));
    ListNode *p, *q;
    virtualHead->next = head;
    virtualHead->pre = NULL;
    head->pre = virtualHead;
    p = head;
    while (p) {
        if (p->val == val) {
            if (p->next != NULL) {
                p->next->pre = p->pre;
            }
            p->pre->next = p->next;
            q = p;
            p = p->next;
            free(q);
        } else {
            p = p->next;
        }
    }
    head = virtualHead->next;
    if (head != NULL) {
        head->pre = NULL;
    }
    free(virtualHead);
    return head;
}
 
ListNode* twoWayLinkListUnique(ListNode *head) {
    if (head == NULL) return NULL;
    ListNode *p, *q;
    p = head;
    while (p) {
        q = deleteValNode(p->next, p->val);
        if (q != NULL) {
            q->pre = p;
        }
        p->next = q;
        p = p->next;
    }
    return head;
}


ListNode* mergeTwoSortedLinkList(ListNode *head1, ListNode *head2) {
    ListNode *p[2], *q, *ret;
    ret = (ListNode *)malloc(sizeof(ListNode));
    p[0] = head1;
    p[1] = head2;
    q = ret;
    int ind;
    while (p[0] != NULL || p[1] != NULL) {
        if (p[1] == NULL) {
            ind = 0;
        } else if (p[0] == NULL) {
            ind = 1;
        } else {
            ind = (p[0]->val < p[1]->val ? 0 : 1);
        }
        q->next = p[ind];
        p[ind] = p[ind]->next;
        q = q->next;
        q->next = NULL;
    }
    q = ret->next;
    free(ret);
    return q;
}

int getLastNode(ListNode *head, ListNode **p) {
    *p = NULL;
    if (head == NULL) {
        return 0;
    }
    int cnt = 1;
    *p = head;
    while ((*p)->next != NULL) {
        ++cnt;
        (*p) = (*p)->next;
    }
    return cnt;
}
 
ListNode* findIntersectionListNode(ListNode *head1, ListNode *head2) {
    ListNode *p[2];
    int cnt[2], sub;
    cnt[0] = getLastNode(head1, &p[0]);
    cnt[1] = getLastNode(head2, &p[1]);


    if (p[0] != p[1]) return NULL;
    p[0] = cnt[0] <= cnt[1] ? head1 : head2;
    p[1] = cnt[0] > cnt[1] ? head1 : head2;
    sub = abs(cnt[0] - cnt[1]);
    while (sub--) {
        p[1] = p[1]->next;
    }
    while (p[0] != p[1]) {
        p[0] = p[0]->next;
        p[1] = p[1]->next;
    }
    return p[0];
}

/*************************************************/
int* three_sum(int *nums, int length, int target) {
    int *ans = malloc(sizeof(int) * 3);
    int i, left, right;
    int sum = 0;
    for (i = 0; i < length - 2; ++i) {
        left = i + 1;
        right = length - 1;
        sum = nums[i] + nums[left] + nums[right];
        while (sum != target && left < right) {
            if (sum < target) {
                sum = sum - nums[left] + nums[left + 1];
                ++left;
            } else {
                sum = sum - nums[right] + nums[right - 1];
                --right;
            }
        }
        if (left < right) break;
    }
    ans[0] = i;
    ans[1] = left;
    ans[2] = right;
    return 
/*********************************************************/
#include <stdlib.h>
 
typedef struct {
    char **arr;
    int top, max_len;
} Stack;
 
int initStack(Stack *);
int pushStack(Stack *, char *);
char *popStack(Stack *);
int emptyStack(Stack *);
int destroyStack(Stack *);
 
Stack back_stack;
Stack forward_stack;
char nowUrl[1000];
char ignore[7] = "Ignore";
 
void initData() {
    fflush(stdout);
    static int flag = 1;
    if (flag) {
        initStack(&back_stack);
        initStack(&forward_stack);
        nowUrl[0] = '\0';
        flag = 0;
    }
}
 
char* visitPage(char *url) {
    initData();
    while (!emptyStack(&forward_stack)) {
        free(popStack(&forward_stack));
    }
    if (nowUrl[0] != '\0') {
        pushStack(&back_stack, nowUrl);
    }
    strcpy(nowUrl, url);
    return url;
}
 
char* back() {
    initData();
    char *temp = popStack(&back_stack);
    if (temp != NULL) {
        pushStack(&forward_stack, nowUrl);
        strcpy(nowUrl, temp);
    } else {
        temp = ignore;
    }
    return temp;
}
 
char* forward() {
    initData();
    char *temp = popStack(&forward_stack);
    if (temp != NULL) {
        pushStack(&back_stack, nowUrl);
        strcpy(nowUrl, temp);
    } else {
        temp = ignore;
    }
    return temp;
}
 
int initStack(Stack *s) {
    s->arr = (char **)malloc(1 * sizeof(char *));
    s->max_len = 1;
    s->top = 0;
    return 1;
}
 
int pushStack(Stack *s, char *a) {
    if (s->arr == NULL) return 0;
    if (s->top == s->max_len) {
        s->arr = (char **)realloc(s->arr, s->max_len * 2 * sizeof(char *));
        if (s->arr == NULL) return 0;
        s->max_len *= 2;
    }
    char *temp = (char *)malloc(strlen(a) + 1);
    strcpy(temp, a);
    s->arr[s->top++] = temp;
    return 1;
}
 
char *popStack(Stack *s) {
    if (!emptyStack(s)) {
        --(s->top);
        return s->arr[s->top];
    }
    return NULL;
}
 
int emptyStack(Stack *s) {
    return !(s->top);
}

/*********************************************************************/



#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
class Element {
private:
    int number;
public:
    Element() :number(0) {
        cout << "ctor" << endl;
    }
    Element(int num):number(num) {
        cout << "ctor" << endl;
    }
    Element(const Element& e):number(e.number) {
        cout << "copy ctor" << endl;
    }
    Element(Element&& e):number(e.number) {
        cout << "right value ctor" << endl;
    }
    ~Element() {
        cout << "dtor" << endl;
    }
    void operator=(const Element& item) {
        number = item.number;
    }
    bool operator==(const Element& item) {
        return (number == item.number);
    }
    void operator()() {
        cout << number ;
    }
    int GetNumber() {
        return number;
    }
};
template<typename T>
class Vector {
private:
    T* items;
    int count;
public:
    Vector() :count{ 0 }, items{nullptr} {
        
    }
    Vector(const Vector& vector) :count{vector.count} {
        items = static_cast<T*>(malloc(sizeof(T) * count));
        memcpy(items, vector.items, sizeof(T) * count);
    }
    Vector(Vector&& vector) :count{ vector.count }, items{ vector.items } {
        vector.items = nullptr;
        vector.count = 0;
    }
    ~Vector() {
        for (int i = 0; i < this->count; i++) {
            this->items[i].~Element();
        }
        free(this->items);
        this->items = nullptr;
        this->count = 0;
    }
    T& operator[](int index){
        if (index<0||index>=count) {
            cout<<"invalid index"<<endl;
            return items[0];
        }
        return items[index];
    }
    int returnCount(){
        return count;
    }
    void Clear() {
        for (int i = 0; i < this->count; i++) {
            this->items[i].~Element();
        }
        free(this->items);
        this->items = nullptr;
        this->count = 0;
    }
    
    void Add(const T& item) { 
        T *buffer = (T *)malloc(sizeof(T) * (this->count + 1));
        for (int i = 0; i < this->count; i++) {
            new(buffer + i)Element(std::move(this->items[i]));
        }
        new(buffer + this->count)Element(item);
        int total_count = this->count + 1;
        this->Clear();
        this->count = total_count;
        this->items = buffer;
        return ;
    }
    bool Insert(const T& item,int index) {
        if (index < 0 || index > this->count) return false;
        T *buffer = (T *)malloc(sizeof(T) * (this->count + 1));
        for (int i = this->count; i > index; --i) {
            new(buffer + i)Element(std::move(this->items[i - 1]));
        }
        new(buffer + index)Element(item);
        for (int i = index - 1; i >= 0; --i) {
            new(buffer + i)Element(std::move(this->items[i]));
        }
        int total_count = this->count + 1;
        this->Clear();
        this->count = total_count;
        this->items = buffer;
        return true;
    }
    bool Remove(int index) {
        if (index < 0 || index >= this->count) return false;
        T *buffer = (T *)malloc(sizeof(T) * (this->count - 1));
        for (int i = 0; i < this->count - 1; i++) {
            new(buffer + i)Element(std::move(this->items[i + (i >= index)]));
        }
        int total_count = this->count - 1;
        this->Clear();
        this->count = total_count;
        this->items = buffer;
        return true;
    }
    int Contains(const T& item) {
        for (int i = 0; i < this->count; i++) {
            if (this->items[i] == item) return i;
        }
        return -1;
    }
};
template<typename T>
void PrintVector(Vector<T>& v){
    int count=v.returnCount();
    for (int i = 0; i < count; i++)
    {
        v[i]();
        cout << " ";
    }
    cout << endl;
}
int main() {
    Vector<Element>v;
    for (int i = 0; i < 4; i++) {
        Element e(i);
        v.Add(e);
    }
    PrintVector(v);
    Element e2(4);
    if (!v.Insert(e2, 10))
    {
        v.Insert(e2, 2);
    }
    PrintVector(v);
    if (!v.Remove(10))
    {
        v.Remove(2);
    }
    PrintVector(v);
    Element e3(1), e4(10);
    cout << v.Contains(e3) << endl;
    cout << v.Contains(e4) << endl;
    Vector<Element>v2(v);
    Vector<Element>v3(move(v2));
    PrintVector(v3);
    v2.Add(e3);
    PrintVector(v2);
    return 0;
}

/********************************************************/
/*
* @Author: alivedreams
* @Date:   2017-10-24 17:53:08
* @Last Modified by:   salted_fish
* @Last Modified time: 2017-12-10 19:48:30
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <memory>
using namespace std;

enum class BinaryOpt {
    PLUS,
    MINUS,
    MUTIL,
    DIVIDE
};

class BinaryExpr;
class NumberExpr;

class Expr {
public:
    class IVisitor {
    public:
        virtual void Visit(BinaryExpr *) = 0;
        virtual void Visit(NumberExpr *) = 0;       
    };
    //Expr() = delete;
    virtual void Accept(IVisitor *) = 0;
    virtual ~Expr() = 0;
};
Expr::~Expr() {}

class BinaryExpr : public Expr{
public:
    BinaryExpr(Expr *first, BinaryOpt Op, Expr *second):
        first(first), second(second), Op(Op) {}
    virtual void Accept(IVisitor *visitor) {
        visitor->Visit(this);
    }
    std::shared_ptr<Expr> GetFirst() {return first;}
    std::shared_ptr<Expr> GetSecond() {return second;}
    BinaryOpt GetOp() {return Op;}
    virtual ~BinaryExpr() {}

private:
    std::shared_ptr<Expr> first;
    std::shared_ptr<Expr> second;
    BinaryOpt Op;
};

class NumberExpr : public Expr{
public:
    NumberExpr(int Value) : Value(Value) {}
    virtual void Accept(IVisitor *visitor) {
        visitor->Visit(this);
    }
    int GetValue() {return Value;}
    virtual ~NumberExpr() {}
private:
    int Value;

};

BinaryOpt CharToOpt(char ch) {
    switch (ch) {
        case '+' :
            return BinaryOpt::PLUS;
        case '-' :
            return BinaryOpt::MINUS;
        case '*' :
            return BinaryOpt::MUTIL;
        case '/' :
            return BinaryOpt::DIVIDE;
    }
    return BinaryOpt::PLUS;
}

Expr *__Parser(const char *&Read) {
    if (Read[0] == '(') {
        Read++;
        BinaryOpt Op = CharToOpt(Read[0]);
        Read++;
        while (Read[0] == ' ') Read++;
        Expr *first = __Parser(Read);
        while (Read[0] == ' ') Read++;
        Expr *second = __Parser(Read);
        Read++;
        return new BinaryExpr(first, Op, second); 
    } else {
        int num = 0;
        while (Read[0] != ' ' && Read[0] != ')') {
            num = num * 10 + (Read[0] - '0');
            Read++;
        }
        //cout << num << endl;
        return new NumberExpr(num);
    }
}

Expr *Parser(const char *Read) {

    return __Parser(Read);
}

class CalcNumber : public Expr::IVisitor {
public:
    int result;
    virtual void Visit(BinaryExpr *node) {
        CalcNumber firstV, secondV;
        node->GetFirst()->Accept(&firstV);
        node->GetSecond()->Accept(&secondV);
        switch (node->GetOp()) {
            case BinaryOpt::PLUS :
                this->result = firstV.result + secondV.result;
                break;
            case BinaryOpt::MINUS :
                this->result = firstV.result - secondV.result;
                break;
            case BinaryOpt::MUTIL :
                this->result = firstV.result * secondV.result;
                break;
            case BinaryOpt::DIVIDE :
                this->result = firstV.result / secondV.result;
                break;
        }
    }
    virtual void Visit(NumberExpr *node) {
        this->result = node->GetValue();
    }
};

class TransToString : public Expr::IVisitor {
public:
    TransToString() : result(""), tip("") {}
    void SetTip(std::string tip) {
        this->tip = tip;
    }
    static int OptToLevel(BinaryOpt Op) {
        switch (Op) {
            case BinaryOpt::PLUS:
            case BinaryOpt::MINUS:
                return 0;
            default :
                return 1;
        }
    }
    static char GetOptChar(BinaryOpt Op) {
        switch (Op) {
            case BinaryOpt::PLUS: return '+';
            case BinaryOpt::MINUS: return '-';
            case BinaryOpt::MUTIL: return '*';
            case BinaryOpt:: DIVIDE: return '/';
            default :
                break;
        }
        return '+';
    }

    std::string result;
    std::string tip;
    int level;
    virtual void Visit(BinaryExpr *node) {
        TransToString firstV, secondV;
        node->GetFirst()->Accept(&firstV);
        node->GetSecond()->Accept(&secondV);
        this->level = TransToString::OptToLevel(node->GetOp());
        if (firstV.level < this->level) {
            firstV.result = "(" + firstV.result + ")";
        }
        if (secondV.level < this->level) {
            secondV.result = "(" + secondV.result + ")";
        }
        if (node->GetOp() == BinaryOpt::MINUS || 
            node->GetOp() == BinaryOpt::DIVIDE) {
            if (secondV.level == this->level) {
                secondV.result = "(" + secondV.result + ")";
            }
        }
        this->result = this->tip + firstV.result + 
                       TransToString::GetOptChar(node->GetOp()) +
                       secondV.result;

    }
    virtual void Visit(NumberExpr *node) {
        this->result = "";
        int num = node->GetValue();
        do {
            this->result = static_cast<char>(num % 10 + '0') + this->result;
            num /= 10;
        }while (num);
        this->level = 2;
    }

};


int main() {
    std::shared_ptr<Expr> root(Parser("(* (+ 1 2) (- 4 5))"));
    CalcNumber ret;
    TransToString ret2;
    ret2.SetTip("output : ");
    root->Accept(&ret);
    root->Accept(&ret2);
    cout << ret.result << endl;
    cout << ret2.result << endl;
    return 0;
}

/*****************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000

typedef struct Graph {
    int n;
    int color[MAX_N];
    int mat[MAX_N][MAX_N];
} Graph;

void init_Graph(Graph *g, int input_n) {
    g->n = input_n;
    for (int i = 0; i < g->n; i++) {
        g->color[i] = 0;
        for (int j = 0; j < g->n; j++) {
            g->mat[i][j] = 0;
        }
    }
}

void insert(Graph *g, int x, int y) {
    g->mat[x][y] = 1;
    g->mat[y][x] = 1;
}

void floodfill(Graph *g) {
    int color_cnt = 0;
    int q[MAX_N];
    for (int i = 0; i < g->n; ++i) {
        if (g->color[i] == 0) {
            color_cnt++;
            g->color[i] = color_cnt;
            int l = 0,r = 0;
            q[r++] = i;
            while (l < r ) {
                int vertex = q[l++];
                for (int j = 0; j < g->n; j++) {
                    if (g->mat[vertex][j] && g->color[j] == 0) {
                        g->color[j] = color_cnt;
                        q[r++] = j; 
                    }
                }
            }
        }
    }
    for (int i = 0; i < g->n; i++) {
        printf("%d %d\n", i, g->color[i]);
    }

    
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Graph *g = (Graph *)malloc(sizeof(Graph));
    init_Graph(g, n);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        insert(g, a, b);
    }
    floodfill(g);
    free(g);
    return 0;
}

/*********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int SIZE = 26;
const char BASE = 'a';

typedef struct TrieNode {
    int is_terminal;
    struct TrieNode** childs;
} TrieNode, *Trie;

TrieNode* new_node() {
    TrieNode *p = (TrieNode *)malloc(sizeof(TrieNode));
    p->childs = (TrieNode **)malloc(sizeof(TrieNode *) * SIZE);
    for (int i = 0; i < SIZE; i++) {
        p->childs[i] = NULL;
    }
    p->is_terminal = 0;
    return p;
}

void clear(TrieNode *p) {
    if (p != NULL) {
        for (int i = 0; i < SIZE; i++) {
            if (p->childs[i] != NULL) {
                clear(p->childs[i]);
            }
        }
        free(p->childs);
        free(p);
    }
}

void insert(Trie trie, char *pattern) {
    TrieNode *p = trie;
    for (int i = 0; i < strlen(pattern); i++) {
        if (p->childs[pattern[i] - BASE] == NULL) {
            p->childs[pattern[i] - BASE] = new_node();
        }
        p = p->childs[pattern[i] - BASE];
    }
    p->is_terminal = 1;
}

int find(Trie trie, char *buffer) {
    TrieNode *p = trie;
    for (int i = 0; i < strlen(buffer); i++) {
        if (p->childs[buffer[i] - BASE] == NULL) {
            return 0;
        } 
        p = p->childs[buffer[i] - BASE];
    }
    return p->is_terminal;
}

int main() {
    Trie root = new_node();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char pattern[100];
        scanf("%s", pattern);
        insert(root, pattern);
    }
    char buffer[100];
    scanf("%s", buffer);
    if (find(root, buffer)) {
        printf("String is found.\n");
    } else {
        printf("String is not found.\n");
    }
    clear(root);
    return 0;
}

 


