#include <stdio.h>

#define DEBUG
#define PI

#ifdef DEBUG
#define log(format, a...) { \
	printf("[%s : %d] ", __func__, __LINE__); \
	printf(format, ##a); \
	printf("\n"); \
} 
#else
#define log(format, a...) {}
#endif

int main() {
	int a = 1, b = 6;
	int PI;
	log("%d %d", a, b);
	printf("%d", PI);
	return 0;
}
// 编译命令 : g++ -DDEBUG -DPI=3 log.c