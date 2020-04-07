#include<stdio.h>
#include<stdlib.h>

//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。


void reverse(int* nums, int left, int right) {
    while (left < right) {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
        left++;
        right--;
    }
}

//用三次反转刚好就可以实现数组的右移
void rotate(int* nums, int numsSize, int k) {
    k %= numsSize;
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}


int main() {


	system("pause");
	return 0;
}