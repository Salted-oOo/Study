#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

int main() {
	srand(time(0));
	Queue *q = (Queue *)malloc(sizeof(Queue));
	init_queue(q, 100);
	char ch;
	while(scanf("%c", &ch) != EOF) {
		int opr, value;
		opr = rand() % 5;
		value = rand() % 100;
		if(opr != 0) {
			push_queue(q, value);
			printf("push %d\n", value);
		} else {
			pop_queue(q);
			printf("pop queue\n");
		}
		output_queue(q);
	}
	clear_queue(q);
	return 0;
}
