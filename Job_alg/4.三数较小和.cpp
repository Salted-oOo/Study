#include <stdio.h>
#include <stdlib.h>
void quick_sort(int *nums, int left, int right) {
    int x, y, z;
    while (left < right) {
        z = nums[left];
        x = left; y = right;
        while (x < y) {
            while (x < y && nums[y] > z) --y;
            if (x < y) nums[x++] = nums[y];
            while (x < y && nums[x] < z) ++x;
            if (x < y) nums[y--] = nums[x];
        }
        nums[x] = z;
        quick_sort(nums, x + 1, right);
        right = x - 1;
    }
}
 
int three_sum_smaller(int *nums, int length, int target) {
    quick_sort(nums, 0, length - 1);
    int i, left, right;
    int sum, ans;
    ans = 0;
    for (i = 2; i < length; ++i) {
        left = 0;
        right = 1;
        sum = nums[i] + nums[left] + nums[right];
        if (sum >= target) continue;
        while (right < i) {
            while (left > 0 && sum >= target) {
                sum = sum - nums[left] + nums[left - 1];
                --left;
            }
            while (left + 1 < right && sum < target) {
                sum = sum - nums[left] + nums[left + 1];
                ++left;
            }
            ans += left;
            if (sum < target) {
                ans += 1;
            }
            sum = sum - nums[right] + nums[right + 1];
            if (sum - nums[left] + nums[0] >= target) break;
            ++right;
        }
    }
    return ans;
}
int main() {
    int n, target;
    scanf("%d %d", &n, &target);
    int* num = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", num + i);
    }
    printf("%d\n", three_sum_smaller(num, n, target));
    free(num);
    return 0;
}