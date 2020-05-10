#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct ListNode {
    int val;
    struct ListNode* next;
    
};


bool hasCycle(struct ListNode* head) {
    if (head == NULL) {
        return false;
    }
    struct ListNode* fast, * slow;
    fast = slow = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) {
            return true;
        }
    }
    return false;
}



int main() {

	system("pause");
	return 0;
}
