#include<stdio.h>
#include<stdlib.h>


//反转一个单链表。
//输入 : 1->2->3->4->5->NULL
//输出 : 5->4->3->2->1->NULL


struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverseList1(struct ListNode* head) {
    //头插法
    struct ListNode* cur = head;
    struct ListNode* newnode = NULL;
    while (cur != NULL) {
        //取到下一个结点
        struct ListNode* tmp = cur->next;
        cur->next = newnode;
        newnode = cur;
        cur = tmp;
    }
    return newnode;
}



struct ListNode* reverseList2(struct ListNode* head) {
    //三指针
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* n1, * n2, * n3;
    n1 = head;
    n2 = n1->next;
    n3 = n2->next;
    n1->next = NULL;
    while (n2 != NULL) {
        n2->next = n1;
        n1 = n2;
        n2 = n3;
        if (n3 != NULL) {
            n3 = n3->next;
        }
    }
    return n1;
}


int main() {

	system("pause");
	return 0;
}