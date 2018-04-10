#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Queue{
    int *data;
    int length, head, tail;
}Queue;

void init(Queue *q, int length) {
    q->data = (int *)malloc(sizeof(int) * length);
    q->length = length;
    q->head = 0;
    q->tail = -1;
}

int empty(Queue *q) {
    return q->head > q->tail;
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
    // }
    for (int i = q->head; i < q->tail; i++) {
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

void clear(Queue *q) {
    free(q->data);
    free(q);
}

int main() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    init(queue, 100);
    int n, p, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p);
        push(queue, p);
       // printf("---%d---", queue->data[i]);
    }
    //output(queue);
    scanf("%d", &m);
    while (m--) {
        if (!empty(queue)) {
            pop(queue);
        }
    }
    printf("%d\n", front(queue));
    output(queue);
    clear(queue);
    return 0;
}
