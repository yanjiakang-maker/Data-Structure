#include<stdio.h>
#include<stdlib.h>


struct ListNode {
   int val;
   struct ListNode* next;
   
};


struct ListNode* insertionSortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    struct ListNode* cur, * prev, * start, * newH;
    prev = head;
    cur = head->next;
    newH = (struct ListNode*)malloc(sizeof(struct ListNode));
    newH->next = head;
    while (cur != NULL) {
        if (cur->val >= prev->val) {
            prev = cur;
            cur = cur->next;
        }
        else {
            //�ӱ�ͷ��ʼ�ҵ���һ������cur������
            start = newH;
            while (start->next && start->next->val <= cur->val)
                start = start->next;
            //��cur���뵽start��start->next֮��
            prev->next = cur->next;
            cur->next = start->next;
            start->next = cur;
            //��curָ����һ����Ҫ�����Ԫ��
            cur = prev->next;
        }
    }
    cur = newH->next;
    free(newH);
    return cur;
}



int main() {

	system("pause");
	return 0;
}