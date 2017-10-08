#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MC(T, n) ((T *)malloc(sizeof(T) * n))
#define init_stack(s, n, T) (__init_stack(s, n, sizeof(T)))
#define push_stack(s, value) ({ \
    __typeof(value) __temp = (value); \
    __push_stack(s, (const char *)(&(__temp))); \
})
#define empty_stack(s) (__empty_stack(s))
#define pop_stack(s) (__pop_stack(s))
#define top_stack(s, T) (*((T *)__top_stack(s)))
#define clear_stack(s) (__clear_stack(s))
#define swap(a, b) { \
    __typeof(a) __temp = (a); \
    (a) = (b); (b) = (__temp); \
}
 
#define ERROR 0
#define OK 1
 
void __init_stack(Stack *s, int n, int value_size);
int __push_stack(Stack *s, const char *value);
int __empty_stack(Stack *s);
int __pop_stack(Stack *s);
char *__top_stack(Stack *s);
void __clear_stack(Stack *s);

typedef struct Stack {
    char *data;
    int top, size;
    int value_size;
} Stack;
 
typedef struct MergeSortArgs {
    int *arr;
    int l ,r, mid;
    int status;
} MergeSortArgs;

void __merge_sort(int *arr, int l, int r) {
    //if (r < l) return ;
    //if (r == l) return ;
    //if (r - l == 1) {
    //    if (arr[r] > arr[l]) {
    //        swap(arr[r], arr[l]);
     //   }
     //   return ;
    //}



    int mid = (l + r) / 2;
    //merge_sort(arr, l, mid);
    //merge_sort(arr, mid + 1, r);

    MergeSortArgs *temp = (MergeSortArgs *)malloc(sizeof(MergeSortArgs) * (r - l + 1));

    int ind1 = l, ind2 = mid + 1, k = 0;
    while (ind1 <= mid || ind2 <= r) {
        if (ind2 > r) {
            temp->arr[k++] = arr[ind1++];
        } else if (ind1 > mid) {
            temp->arr[k++] = arr[ind2++];
        } else if (arr[ind2] > arr[ind1]) {
            temp->arr[k++] = arr[ind2++];
        } else {
            temp->arr[k++] = arr[ind1++];
        }
    }
    for (int i = l; i < r; i++) {
        arr[i] = temp->arr[i - l];
    }
    free(temp);
    return ;
}

void init_merge_sort_args(MergeSortArgs *msa, int *arr, int l, int r, int status) {
    msa->arr = arr;
    msa->l = l;
    msa->r = r;
    msa->status = 0;
    msa->mid = (l + r) / 2;
    return ;
}

void merge_sort(int *arr, int l, int r){
    Stack *s = MC(Stack, 1);
    init_stack(s, 1000, MergeSortArgs);
    MergeSortArgs msa;
    init_merge_sort_args(&msa, arr, 0, r, 0)
    push_stack(s, msa);
    while (!empty_stack(s)) {
        MergeSortArgs *tmsa = &top_stack(s, MergeSortArgs);
        switch (tmsa->status) {
            case 0:
                if (tmsa->r < tmsa->l) {
                    tmsa->status = 4;
                } else if (tmsa->r == tmsa->l) {
                    tmsa->status = 4;
                } else if (tmsa->r - tmsa->l == 1) {
                    if (tmsa->arr[r] > tmsa->arr[l]) {
                        swap(tmsa->arr[r], tmsa->arr[l]);
                    }           
                    tmsa->status = 4;
                } else {
                    tmsa->status = 1;
                }
                break;
            case 1:
                init_merge_sort_args(&msa, arr, msa->l, msa->mid, 0);
                push_stack(s, msa);
                tmsa->status = 2;
                break;
            case 2:
                init_merge_sort_args(&msa, arr, msa->mid, msa->r, 0);
                push_stack(s, msa);
                tmsa->status = 2;
                break;
            case 3:
                __merge_sort(tmsa->arr, tmsa->l, tmsa->r);
                tmsa->status = 4
                break;
            case 4:
                pop_stack(s);
                break;
            default :
                printf("ERROR\n");
                break;
        }
    }
    return ;
}


int main() {
    int arr[10] = {9, 7, 5, 4, 2 ,1 ,3, 10, 6, 8};
    merge_sort(arr, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
 
void __init_stack(Stack *s, int n, int value_size) {
    s->data = (char *)malloc(value_size * n);
    s->top = -1;
    s->size = n;
    s->value_size = value_size;
    return ;
}
 
int __push_stack(Stack *s, const char *value) {
    if (s->top == s->size - 1) {
        return ERROR;
    }
    ++(s->top);
    memcpy(s->data + s->top * s->value_size, value, s->value_size);
    return OK;
}
 
int __empty_stack(Stack *s) {
    return s->top == -1;
}
 
int __pop_stack(Stack *s) {
    if (__empty_stack(s)) {
        return ERROR;
    }
    --(s->top);
    return OK;
}
 
char *__top_stack(Stack *s) {
    if (__empty_stack(s)) {
        return NULL;
    }
    return s->data + s->top * s->value_size;
}
 
void __clear_stack(Stack *s) {
    free(s->data);
    free(s);
    return ;
}