#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int binary_search(int *nums, int n, int x) {
    int head, tail, mid;
    head = 0, tail = n - 1;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (nums[mid] < x) {
            tail = mid;
        } else {
            head = mid + 1;
        }
    }
    return head;
}

int *lengthOfLNIS(int *nums, int length) {
    int *f = (int *)calloc(length + 1, sizeof(int));
    int *ans = (int *)calloc(length + 1, sizeof(int)); 
    f[0] = INT_MAX;
    for (int i = 1; i <= length; i++) {
        f[i] = INT_MIN;
    }
    for (int i = 0; i < length; i++) {
        int ind = binary_search(f, length - 1, nums[i]);
        ans[i] = ind;
        f[ind] = nums[i];
        if (ind > ans) ans = ind;
    }
    free(f);
    return ans;
}
int lengthOfLCS(char *str1, char *str2) {
	int *f1 = lengthOfLNIS(nums, length);
	for (int i = 0, j = length - 1; i < j; i++, j--) {
		nums[i] ^= nums[j];
		nums[j] ^= nums[i];
		nums[i] ^= nums[j];
	}
	int *f2 = lengthOfLNIS(nums, length);
	int ans = INT_MIN, temp_ans;
	for (int i = 0; i < length; i++) {
		temp_ans = f1[i] + f2[length - 1 - i] - 1;
		if (temp_ans > ans) ans = temp_ans;
	}
	return length - ans;
}
int main() {
	char a[1000+10];
	char b[1000+10];
	scanf("%s %s", a, b);
	printf("%d\n", lengthOfLCS(a, b));
}