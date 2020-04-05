#include<stdio.h>
#include<stdlib.h>


int removeDuplicates(int* nums, int numsSize) {
	int tmp = 0;
	int start = 1;
	int ret = 0;
	// 跟上题的思路一致，相同的数只保留一个，依次往前放
	while (start < numsSize) {
		nums[ret] = nums[tmp];
		ret++;
		//如果两个指针指向的元素不重复，则指针同时向后移动
		if (nums[tmp] != nums[start]) {
			tmp++;
			start++;
		}
		else {
			//如果重复，找到第一个不重复的元素
			while (nums[tmp] == nums[start]) {
				start++;
			}
			//更新指针
			tmp = start;
			start++;
		}
	}

	if (tmp < numsSize) {
		nums[ret] = nums[tmp];
		ret++;
	}

	return ret;
}

int main() {
    int num[] = { 0, 0, 1, 1 ,1 ,2, 2 ,3, 3, 4 };
    int size = sizeof(num) / sizeof(num[0]);
    int ret = removeDuplicates(num, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");

	system("pause");
	return 0;
}