#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void initData() {

}

char* visitPage(char *url) {
    initData();
    while (!emptyStack(&))

    pushStack(&back_stack, url);
    return url;
}


char* back() {
    char *temp;
    initData();
    if (emptyStack(&back_stack)) {
        temp = ingnore;
    } else {
        pushStack(&forward_stack, popStack(&back_stack));
        temp = topStack(&back_stack);        
        if (temp == NULL) {
            pushStack(&back_stack, popStack(&forword_stack));
            temp = ingnore;
        }
    }
    return temp;
}


char* forward() {
    char *temp;
    initData();
    if (emptyStack(&forword_stack)) {
        temp = ingnore;
    } else {
        pushStack(&back_stack, popStack(&forword_stack));
        temp = topStack(&back_stack);
    }
    return temp;
}

int 



int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        char op[1024];
        char* result;
        scanf("%s", op);
        if (strcmp(op, "VISIT") == 0) {
            char url[1024];
            scanf("%s", url);
            result = visitPage(url);
        } else if (strcmp(op, "BACK") == 0) {
            result = back();
        } else if (strcmp(op, "FORWARD") == 0) {
            result = forward();
        }
        printf("%s\n", result);
    }
    return 0;
}