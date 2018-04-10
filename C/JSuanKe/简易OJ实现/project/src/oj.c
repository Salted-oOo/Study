#include <stdio.h>
#include "run.h"

int main()
{
	const char *name_program = "./program";
	const char *name_in = "./in.txt";
	const char *name_out = "./out.txt";
	const char *name_right = "./right.txt";
	run(name_program, name_in, name_out);
	FILE *fpright = fopen(name_right, "r");
	FILE *fpout = fopen(name_out, "r");

	// Input your code here.
	char c1, c2;
	int ret1, ret2;
	int right_flag = 1;
	while (right_flag) {
		ret1 = fscanf(fpright, "%c", &c1);
		ret2 = fscanf(fpout, "%c", &c2);
		if (ret1 == EOF || ret == EOF) break;
		if (c1 != c2) {
			right_flag = 0;
		}
	}
	if (right_flag == 1) {
		if (ret1 != EOF || ret2 != EOF) {
			if ((ret1 != EOF && c1 == '\n') ||
				(ret2 != EOF && c2 == '\n')) {
				ret1 = fscanf((ret1 != EOF ? fpright : fpout), "%c", &c1);
				right_flag = (ret1 == EOF ? 1 : 0);
			} else {
				right_flag = 0;
			}

		}
	}
	printf("%s", right_flag ? "Accept" : "Wrong Answer");
	fclose(fpout);
	fclose(fpright);
	return 0;
}
