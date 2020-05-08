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
    //��ȡ����������ĳ���
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
    //�ó����������� num(���̲�ֵ) �� , Ȼ������һ����, �ҵ���һ�������㼴��
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