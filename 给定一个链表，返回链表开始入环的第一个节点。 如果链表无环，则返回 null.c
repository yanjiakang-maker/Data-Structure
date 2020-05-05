#include<stdio.h>
#include<stdlib.h>


struct ListNode {
    int val;
    struct ListNode* next;
    
};


//  如果链表中有环的话, 那么fast和slow必然会在环内相遇
//  我们设从头到换入口的距离为L, 环的长度为C, 环入到相遇点的距离为X
//  那么我们可以知道: 
//  fast走过的距离为 : L + X + N * C
//  slow走过的距离为 : L + X
// 并且我们知道fast走过的距离是slow的两倍
// 所以有 : 2 * (L + X) = L + X + N * C
// 整理得到 L = N * C - X 
// 当N取1 也就意味着 从头到入口的距离就是相遇点到入口的距离
// 所以说, slow 和 start 同时走, 相遇的那个点就是入口结点

struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* fast, * slow;
    fast = slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        //走到相遇点
        if (fast == slow) {
            struct ListNode* meet = slow;
            struct ListNode* start = head;
            while (meet != start) {
                meet = meet->next;
                start = start->next;
            }
            return meet;
        }
    }
    return NULL;
}

int main() {

	system("pause");
	return 0;
}