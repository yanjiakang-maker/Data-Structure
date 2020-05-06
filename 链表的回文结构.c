#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
}ListNode;


bool chkPalindrome1(ListNode* A) {
    if (A == NULL || A->next == NULL)
        return true;
    struct ListNode* fast, *slow, *cur, *prev, *next;
    fast = slow = A;
    //找到中间元素
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    //然后翻转链表后半段
    cur = slow;
    prev = NULL;
    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    //依次比较
    cur = A;
    while (prev != NULL && cur != NULL) {
        if (cur->val != prev->val)
            return false;
        cur = cur->next;
        prev = prev->next;
    }
    return true;
}

bool chkPalindrome2(ListNode* A) {
    int arr[900];
    int i = 0;
    struct ListNode* cur = A;
    while (cur != NULL) {
        arr[i] = cur->val;
        i++;
        cur = cur->next;
    }
    int start = 0;
    int end = i - 1;
    while (start < end) {
        if (arr[start] != arr[end])
            return false;
        start++;
        end--;
    }
    return true;

}
int main() {

	system("pause");
	return 0;
}