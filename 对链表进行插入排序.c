#include<stdio.h>
#include<stdlib.h>


typedef struct ListNode {
    int val;
    struct ListNode* next;
}ListNode;


ListNode* deleteDuplication(ListNode* pHead)
{

    if (pHead == NULL || pHead->next == NULL)
        return pHead;
    struct ListNode* cur, * prev, * next, * tmp;
    prev = NULL;
    cur = pHead;
    next = cur->next;
    while (next != NULL) {
        if (next->val != cur->val) {
            prev = cur;
            cur = next;
            next = next->next;
        }
        else {
            //找到一地个不重复的结点
            while (next != NULL && next->val == cur->val)
                next = next->next;
            //删掉中间的结点
            while (cur != next) {
                tmp = cur->next;
                free(cur);
                cur = tmp;
            }
            //重新链接(要考虑是否删除了头)
            if (prev == NULL)
                pHead = cur;
            else
                prev->next = cur;
            //让next向后走继续下一次操作
            if (next != NULL)
                next = next->next;
        }
    }
    return pHead;
}




int main() {

	system("pause");
	return 0;
}