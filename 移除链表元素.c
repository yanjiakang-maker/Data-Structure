#include<stdio.h>
#include<stdlib.h>


//ɾ�������е��ڸ���ֵ val �����нڵ㡣
//���� : 1->2->6->3->4->5->6, val = 6
//��� : 1->2->3->4->5


 struct ListNode {
    int val;
    struct ListNode* next;
    
};


struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head == NULL) {
        return NULL;
    }

    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    while (cur != NULL) {
        if (cur->val == val) {
            //�ȱ���cur ��Ľ��
            struct ListNode* tmp = cur->next;
            //Ȼ����Ҫ�ж��Ƿ���ͷ���
            if (prev == NULL) {
                head = tmp;
                free(cur);
                cur = tmp;
            }
            else {
                prev->next = tmp;
                free(cur);
                cur = tmp;
            }
        }
        else {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}


int main() {

	system("pause");
	return 0;
}