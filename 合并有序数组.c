#include<stdio.h>
#include<stdlib.h>


//给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 num1 成为一个有序数组。
//初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
//你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。



void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    //从最大值开始合并, 逐渐向前
    int end1 = m - 1;//nums1的末尾
    int end2 = n - 1;//nums2的末尾
    int end = m + n - 1;//合并后数组的末尾
    while (end1 >= 0 && end2 >= 0) {
        if (nums1[end1] > nums2[end2]) {
            nums1[end] = nums1[end1];
            end--;
            end1--;
        }
        else {
            nums1[end] = nums2[end2];
            end--;
            end2--;
        }
    }
    //上面循环结束之后判断哪个数组没走完, 没走完的直接赋值到最前面
    while (end1 >= 0) {
        nums1[end] = nums1[end1];
        end--;
        end1--;
    }
    while (end2 >= 0) {
        nums1[end] = nums2[end2];
        end--;
        end2--;
    }
}


int mian() {



	system("pause");
	return 0;
}