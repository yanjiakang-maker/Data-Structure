#include<stdio.h>
#include<stdlib.h>

//对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。
//例如，如果 X = 1231，那么其数组形式为[1, 2, 3, 1]。
//给定非负整数 X 的数组形式 A，返回整数 X + K 的数组形式。



void reverse(int* arr, int left, int right) {
    while (left < right) {
        int tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
        left++;
        right--;
    }
}

int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {
    //先取到最高位
    int tmp = K;
    int knum = 0;
    while (tmp != 0) {
        knum++;
        tmp /= 10;
    }
    //开空间 , 考虑最高位的进位  多给一位
    int newAszie = ASize > knum ? ASize + 1 : knum + 1;
    int* newArray = (int*)malloc(newAszie * sizeof(int));

    //模拟加法运算 , 从低位开始
    //低位先放在前面 , 最后给一个反转即可
    int i = 0;
    int idx = ASize - 1;
    int step = 0;//保存进位
    while (idx >= 0 || K > 0) {
        //这里 while 只是或的关系 , 只要满足一个就可以进到循环里
        //当前位的加法
        newArray[i] = step;
        if (idx >= 0)
            newArray[i] += A[idx];
        if (K > 0)
            newArray[i] += K % 10;

        //更新进位
        if (newArray[i] >= 10) {
            //如果大于10 保留个位 并且给step一个进位
            newArray[i] -= 10;
            step = 1;
        }
        else {
            //这里必需加这个else 如不不加的话只要有一次需要进位 step就一直为1了
            step = 0;
        }
        //继续下一位的运算
        i++;
        idx--;
        K /= 10;
    }
    //判断最高位是否需要进位
    if (step == 1) {
        newArray[i] = 1;
        i++;
    }
    //反转数组
    reverse(newArray, 0, i - 1);
    *returnSize = i;
    return newArray;
}



int main() {

    system("pause");
    return 0;
}