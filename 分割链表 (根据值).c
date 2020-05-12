#include<stdio.h>
#include<stdlib.h>


typedef struct ListNode {
    int val;
    struct ListNode* next;
}ListNode;


ListNode* partition(ListNode* pHead, int x) {
    if (pHead == NULL)
        return NULL;
    struct ListNode* LH, * GH, * cur, * cur1, * cur2;
    //LH 小于x的表头
    //cur1 小于x的表尾
    //GH 大于x的表头
    //cur2 大于x的表尾
    LH = (struct ListNode*)malloc(sizeof(struct ListNode));
    GH = (struct ListNode*)malloc(sizeof(struct ListNode));
    cur = pHead;
    cur1 = LH;
    cur2 = GH;
    while (cur != NULL) {
        if (cur->val < x) {
            cur1->next = cur;
            cur1 = cur;
            cur = cur->next;
        }
        else {
            cur2->next = cur;
            cur2 = cur;
            cur = cur->next;
        }
    }
    cur1->next = GH->next;
    cur2->next = NULL;
    struct ListNode* tmp = LH;
    LH = LH->next;
    free(tmp);
    free(GH);
    return LH;
}


int main() {

	system("pause");
	return 0;
}