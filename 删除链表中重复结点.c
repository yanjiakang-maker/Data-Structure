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
            //从表头开始找到第一个大于cur的数据
            start = newH;
            while (start->next && start->next->val <= cur->val)
                start = start->next;
            //把cur插入到start和start->next之间
            prev->next = cur->next;
            cur->next = start->next;
            start->next = cur;
            //让cur指向下一个需要排序的元素
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