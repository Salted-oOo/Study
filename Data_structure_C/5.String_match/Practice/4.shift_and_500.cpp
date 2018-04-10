#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int p[20];

void shift_and(char *s, char *t) {
    int str_encode[256][20] = {0};
    int len = 0;
    int times = 0;
    for (int i = 0; t[i]; i++) { 
        str_encode[t[i]][i / 32] |= (1 << (i % 32));
        len++;
        times++;
    }
    for (int i = 0; s[i]; i++) {
        times++;
        int flag = !!(p[0] >> 31);
        p[0] = (p[0] << 1 | 1);
        
        for(int j = 1; j < 320; j++) {
            if(flag == 0) {
                p[j] = (p[j] << 1);
            } else {
                flag = !!(p[j] >> 31);
                p[j] = (p[j] << 1 | 1);
            }
        }
        for(int j = 0; j < 320; j++) {
            p[j] = p[j] & str_encode[s[i]][j];
        }
        int k = len / 32, z = len % 32;
        if (p[k] & (1 << (z - 1))) {
            printf("SHIFT AND YES : %d\n", times);
            return ;
        }
    }
    printf("SHIFT AND NO : %d\n", times);
    return ;   
}

int main() {
    char s[] = "aecaea aecaed";
    char t[] = "aecaed";        
    shift_and(s, t);

    return 0;
}