#include <stdio.h>
#include <stdlib.h>

int f(int **maze, int i, int j, int raw_hp, int maximumHP) {
	if (i < 1 || j < 1) return 0;
	if (i == 1 && j == 1) return raw_hp + maze[1][1];
	int hp, hp1 = 0, hp2 = 0;
	hp1 = f(maze, i - 1, j, raw_hp, maximumHP);
	hp2 = f(maze, i, j - 1, raw_hp, maximumHP);
	if (hp1 == 0 && hp2 == 0) return 0;
	hp = (hp1 > hp2 ? hp1 : hp2) + maze[i][j];
	if (hp <= 0) return 0;
	return hp > maximumHP ? maximumHP : hp;
}




int escape(int **maze, int n, int m,
			    int initialHP, int maximumHP) {
	return f(maze, n, m, initialHP, maximumHP);
}
int main() {
	int n, m, v, c;
	scanf("%d %d %d %d", &n, &m, &v, &c);
	int  **a = malloc(sizeof(int*) * (n + 1));
	for (int i = 0; i <= n; ++i) {
		a[i] = malloc(sizeof(int) * (m + 1));
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	printf("%d\n", escape(a, n, m, v, c));
	return 0;
}