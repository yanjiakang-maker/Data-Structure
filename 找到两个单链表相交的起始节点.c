#include<stdio.h>
#include<stdlib.h>


struct ListNode {
    int val;
    struct ListNode* next;
    
};


struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    int lenA = 0;
    int lenB = 0;
    struct ListNode* cur1 = headA;
    struct ListNode* cur2 = headB;
    //先取到两个链表的长度
    while (cur1 != NULL) {
        lenA++;
        cur1 = cur1->next;
    }
    while (cur2 != NULL) {
        lenB++;
        cur2 = cur2->next;
    }
    int num = lenA > lenB ? lenA - lenB : lenB - lenA;
    struct ListNode* longlist = headA;
    struct ListNode* shortlist = headB;
    if (lenB > lenA) {
        longlist = headB;
        shortlist = headA;
    }
    //让长的链表先走 num(长短差值) 步 , 然后他们一起走, 找到第一个相遇点即可
    while (num > 0) {
        longlist = longlist->next;
        num--;
    }
    while (longlist != NULL) {
        if (longlist == shortlist)
            return longlist;
        longlist = longlist->next;
        shortlist = shortlist->next;
    }
    return NULL;
}


int main() {

	system("pause");
	return 0;
}