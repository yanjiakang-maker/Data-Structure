#include<stdio.h>
#include<stdlib.h>

//原地移除数组中所有的元素val，要求时间复杂度为O(N)，空间复杂度为O(1)


int removeElement(int* nums, int numsSize, int val) {
    int start = 0;
    int ret = 0;
    while (start < numsSize) {
        if (nums[start] != val) {
            nums[ret] = nums[start];
            start++;
            ret++;
        }
        else {
            start++;
        }
    }
    return ret;
}


int main() {
    int nums[] = { 0, 1, 2, 2, 3, 0, 4, 2 };
    int size = sizeof(nums) / sizeof(nums[0]);
   int ret = removeElement(nums, size, 2);
   printf("%d\n", ret);

	system("pause");
	return 0;
}