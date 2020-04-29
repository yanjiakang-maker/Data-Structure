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
            //�ҵ�һ�ظ����ظ��Ľ��
            while (next != NULL && next->val == cur->val)
                next = next->next;
            //ɾ���м�Ľ��
            while (cur != next) {
                tmp = cur->next;
                free(cur);
                cur = tmp;
            }
            //��������(Ҫ�����Ƿ�ɾ����ͷ)
            if (prev == NULL)
                pHead = cur;
            else
                prev->next = cur;
            //��next����߼�����һ�β���
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