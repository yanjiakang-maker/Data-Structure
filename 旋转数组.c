#include<stdio.h>
#include<stdlib.h>

//����һ�����飬�������е�Ԫ�������ƶ� k ��λ�ã����� k �ǷǸ�����


void reverse(int* nums, int left, int right) {
    while (left < right) {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
        left++;
        right--;
    }
}

//�����η�ת�պþͿ���ʵ�����������
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