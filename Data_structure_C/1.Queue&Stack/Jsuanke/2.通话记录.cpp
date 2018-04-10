#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Queue{
    long long *data;
    int length, head, tail;
} Queue;

void init(Queue *q, int length) {
    //q->**data = (char **)malloc(sizeof(char*) * length);
    q->data = (long long *)malloc(sizeof(long long) * length);
    q->length = length;
    q->head = 0;
    q->tail = -1;
}

long long empty(Queue *q) {
    return q->head > q->tail;
}

int push(Queue *q, long long element) {
    if (q->tail + 1 >= q->length) {
        return ERROR;
    }
    q->tail++;
    q->data[q->tail] = element;
    return OK;
}
/*void output(Queue *q) {
    //if (!empty(q)) {
    //    return ERROR;
    // }
    for (int i = q->head; i < q->tail; i++) {
        printf("%d ", q->data[i]);
    }
    printf("%d\n", q->data[q->tail]);
}
*/
long long front(Queue *q) {
    return q->data[q->head];
}
void pop(Queue *q) {
    q->head++;
}

void clear(Queue *q) {
    free(q->data);
    free(q);
}

int main() {
    Queue *queue1 = (Queue *)malloc(sizeof(Queue));
    Queue *queue2 = (Queue *)malloc(sizeof(Queue));
    Queue *queue3 = (Queue *)malloc(sizeof(Queue));
    init(queue1, 10);
    init(queue2, 10);
    init(queue3, 10);
    int n;
    long long data;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &n);
        scanf("%lld", &data);
        if (n == 0) {
            push(queue1, data);
        } else if (n == 1) {
            push(queue2, data);
        } else {
            push(queue3, data);
        }
    }
    for (int i = 0; i < 10; i++) {
        if(!empty(queue1)) {
            printf("%lld ", front(queue1));
            pop(queue1);
        } else {
            printf("0 ");
        }
        if(!empty(queue2)) {
            printf("%lld ", front(queue2));
            pop(queue2);
        } else {
            printf("0 ");
        }
        if(!empty(queue3)) {
            printf("%lld ", front(queue3));
            pop(queue3);
        } else {
            printf("0");
        }       
        printf("\n");         
    }
    clear(queue1);
    clear(queue2);
    clear(queue3);
    return 0;
}
