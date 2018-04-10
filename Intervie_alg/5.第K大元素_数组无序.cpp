#include <iostream>
using namespace std;

#define MAX_NUM 10

void search_num(int *nums, int max, int min, int k) {
    int min_count = 0, mid_count = 0;
    int mid = (max + min) / 2;
    for (int i = 0; i < MAX_NUM; i++) {
        if (mid < nums[i])  min_count++;
        if (mid == nums[i]) mid_count++;
    }
    if (min_count < k && (min_count + mid_count) >= k) {
        cout << "The " << k << "st is : " << mid << endl;
        return ;
    } 
    if (min_count >= k) {
        search_num(nums, max, mid + 1, k);
    } else {

        search_num(nums, mid, min, k);
    }
}

int main() {
    int nums[MAX_NUM] = {1,5,7,3,6,5,8,2,9,4};
    int max = nums[0], min = nums[0], k;
    cin >> k; 
    for (int i = 0; i < MAX_NUM; i++) {
        if (max < nums[i])  max = nums[i];
        if (min > nums[i])  min = nums[i];
    }
    search_num(nums, max, min, k);
    return 0;
}