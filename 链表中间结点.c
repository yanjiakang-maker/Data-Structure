#include<stdio.h>
#include<stdlib.h>


//����һ������ͷ��� head �ķǿյ���������������м��㡣
//����������м��㣬�򷵻صڶ����м��㡣

//���룺[1, 2, 3, 4, 5]
//��������б��еĽ�� 3 (���л���ʽ��[3, 4, 5])

//���룺[1, 2, 3, 4, 5, 6]
//��������б��еĽ�� 4 (���л���ʽ��[4, 5, 6])


struct ListNode {
    int val;
    struct ListNode* next;
    
};


struct ListNode* middleNode(struct ListNode* head) {
    //����ָ��
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