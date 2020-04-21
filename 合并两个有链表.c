#include<stdio.h>
#include<stdlib.h>


struct ListNode {
    int val;
    struct ListNode* next;
    
};


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head, * tail, * tmp;
    head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        }
        else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if (l1 == NULL) {
        tail->next = l2;
    }
    else {
        tail->next = l1;
    }
    tmp = head;
    head = head->next;
    free(tmp);
    return head;

}




int main() {


	system("pause");
	return 0;
}