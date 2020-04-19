#include<stdio.h>
#include<stdlib.h>


//给定一个带有头结点 head 的非空单链表，返回链表的中间结点。
//如果有两个中间结点，则返回第二个中间结点。

//输入：[1, 2, 3, 4, 5]
//输出：此列表中的结点 3 (序列化形式：[3, 4, 5])

//输入：[1, 2, 3, 4, 5, 6]
//输出：此列表中的结点 4 (序列化形式：[4, 5, 6])


struct ListNode {
    int val;
    struct ListNode* next;
    
};


struct ListNode* middleNode(struct ListNode* head) {
    //快慢指针
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}



int main() {

	system("pause");
	return 0;
}