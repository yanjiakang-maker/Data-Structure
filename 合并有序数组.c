#include<stdio.h>
#include<stdlib.h>


//�������������������� nums1 �� nums2�����㽫 nums2 �ϲ��� nums1 �У�ʹ num1 ��Ϊһ���������顣
//��ʼ�� nums1 �� nums2 ��Ԫ�������ֱ�Ϊ m �� n ��
//����Լ��� nums1 ���㹻�Ŀռ䣨�ռ��С���ڻ���� m + n�������� nums2 �е�Ԫ�ء�



void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    //�����ֵ��ʼ�ϲ�, ����ǰ
    int end1 = m - 1;//nums1��ĩβ
    int end2 = n - 1;//nums2��ĩβ
    int end = m + n - 1;//�ϲ��������ĩβ
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
    //����ѭ������֮���ж��ĸ�����û����, û�����ֱ�Ӹ�ֵ����ǰ��
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