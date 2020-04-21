#include<stdio.h>
#include<stdlib.h>



typedef struct ListNode {
    int val;
    struct ListNode* next;
}ListNode;


ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    //快慢指针变形
    struct ListNode* fast, * slow;
    fast = slow = pListHead;
    while (k > 0) {
        if (fast != NULL)
            fast = fast->next;
        else
            return NULL;
        k--;
    }
    while (fast != NULL && slow != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}



int main() {


	system("pause");
	return 0;
}