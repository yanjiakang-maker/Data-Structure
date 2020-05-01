#include<stdio.h>
#include<stdlib.h>


struct Node {
    int val;
    struct Node* next;
    struct Node* random;
};

struct Node* copyRandomList(struct Node* head) {
    if (head == NULL)
        return NULL;
    struct Node* cur, * copy, * next;
    //1. 先在原链表上拷贝结点
    cur = head;
    while (cur != NULL) {
        next = cur->next;
        copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;
        //插入拷贝结点, 顺序为 cur  copy  next
        cur->next = copy;
        copy->next = next;
        cur = next;
    }
    //2. 复制random
    cur = head;
    while (cur != NULL) {
        copy = cur->next;
        next = copy->next;
        if (cur->random != NULL)
            copy->random = cur->random->next;
        else
            copy->random = NULL;
        cur = next;
    }
    //3.拆链
    cur = head;
    struct Node* newH = cur->next;
    while (cur != NULL) {
        copy = cur->next;
        next = copy->next;
        cur->next = next;
        if (next != NULL)
            copy->next = next->next;
        cur = next;
    }
    return newH;
}


int main() {

	system("pause");
	return 0;
}