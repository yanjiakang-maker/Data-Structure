#include<stdio.h>
#include<stdlib.h>


struct ListNode {
    int val;
    struct ListNode* next;
    
};


//  ����������л��Ļ�, ��ôfast��slow��Ȼ���ڻ�������
//  �������ͷ������ڵľ���ΪL, ���ĳ���ΪC, ���뵽������ľ���ΪX
//  ��ô���ǿ���֪��: 
//  fast�߹��ľ���Ϊ : L + X + N * C
//  slow�߹��ľ���Ϊ : L + X
// ��������֪��fast�߹��ľ�����slow������
// ������ : 2 * (L + X) = L + X + N * C
// ����õ� L = N * C - X 
// ��Nȡ1 Ҳ����ζ�� ��ͷ����ڵľ�����������㵽��ڵľ���
// ����˵, slow �� start ͬʱ��, �������Ǹ��������ڽ��

struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* fast, * slow;
    fast = slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        //�ߵ�������
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