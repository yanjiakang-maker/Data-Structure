#include<stdio.h>
#include<stdlib.h>


//删除链表中等于给定值 val 的所有节点。
//输入 : 1->2->6->3->4->5->6, val = 6
//输出 : 1->2->3->4->5


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
            //先保存cur 后的结点
            struct ListNode* tmp = cur->next;
            //然后需要判断是否是头结点
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