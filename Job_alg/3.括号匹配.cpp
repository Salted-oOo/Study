
#define MC(T, n) (T *)malloc(sizeof(T) * n)
#define ERROR 0
#define OK 1

typedef struct Stack {
	int *data;
	int top, size;
} Stack;

void init(Stack *, int);
void clear(Stack *);
int empty(Stack *);
int push(Stack *);
int pop(Stack *);
int top(Stack *);


Pair* bracketsPairs(char *str) {
	int i, ind = 0;
	Stack *s = MC(Stack, 1);
	Pair *ret = MC(Pair, (strlen(str) >> 1) + 1)
	init(s, (strlen(str) >> 1) + 1);
	for (i = 0; str[i]; i++) {
		if (str[i] == '(') {
			push(s, i + 1);
		} else {
			if (empty(s)) {
				break;
			}
			ret[ind].first = top(s);
			ret[ind].second = i　+ 1;
			++ind;
			pop(s);
		}
	}
	if (str[i] || !empty(s)) {
		free(ret);
		ret = NULL;
	}
	clear(s);
	return ret;
}

void init(Stack *s, int n) {
	s->data = MC(int, n);
	s->top = -1;
	s->size = n;
}

void clear(Stack *s) {
	free(s->data);
	free(s);
}

int empty(Stack *s) {
	return s->top == -1;
}

int push(Stack *s, int data) {
    if (s->top == s->size - 1) {
        return ERROR;
    }
    s->top++;
    s->data[s->top] = data;
    return OK;
}


int pop(Stack *s) {
    if (empty(s)) {
        return ERROR;
    }
    s->top--;
    return OK;
}
int top(Stack *s) {
    return s->data[s->top];
}

