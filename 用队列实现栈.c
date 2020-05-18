#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef int DataType;

typedef struct QNode {
    DataType data;
    struct QNode* next;
}QNode;

typedef struct Queue {
    QNode* front;
    QNode* rear;
    int size;
}Queue;


//��ʼ��
void QueueInit(Queue* q) {
    q->front = q->rear = NULL;
    q->size = 0;
}


//�������
QNode* QNodeCreat(DataType data) {
    QNode* node = (QNode*)malloc(sizeof(QNode));
    node->data = data;
    node->next = NULL;
    return node;
}


//����(β��)
void QueuePush(Queue* q, DataType data) {
    QNode* node = QNodeCreat(data);
    //�����ǲ��ǿն���
    if (q->front == NULL) {
        q->front = q->rear = node;
    }
    else {
        q->rear->next = node;
        q->rear = node;
    }
    q->size++;
}


//����(ͷɾ)
void QueuePop(Queue* q) {
    if (q->front == NULL) {
        //����Ϊ��, ����ʧ��
        return;
    }

    QNode* next = q->front->next;
    free(q->front);
    q->front = next;

    //ɾ�����Ƿ�Ϊ�ձ�
    if (q->front == NULL) {
        q->rear = NULL;
    }
    q->size--;
}


//�õ�����Ԫ��
DataType getQueueFront(Queue* q) {
    return q->front->data;
}


//�õ���βԪ��
DataType getQueueBack(Queue* q) {
    return q->rear->data;
}


//�õ����г���
int getQueueSize(Queue* q) {
    return q->size;
}


//�п�
int QueueEmpty(Queue* q) {
    if (q->front == NULL) {
        return 1;
    }
    return 0;
}


//����
void QueueDertory(Queue* q) {
    QNode* cur = q->front;
    while (cur != NULL) {
        QNode* tmp = cur->next;
        free(cur);
        cur = tmp;
    }
    q->front = q->rear = NULL;
    q->size = 0;
}



typedef struct {
    //��һ������ʵ��ջ
    Queue q;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* ms = (MyStack*)malloc(sizeof(MyStack));
    QueueInit(&ms->q);
    return ms;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    //������Ӳ���
    QueuePush(&obj->q, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    //��ջ�Ǵ�ջ��(�����β)ɾ��һ��Ԫ��
    //�������ǴӶ��еĶ�ͷ(�����ͷ)ɾ��һ��Ԫ��
    //�ö���ʵ��ջ  
    //��Ҫ�ö����г��˶�β��ֵ�ȳ��������, ����һ��Ԫ�ؾ���Ҫ�õ���Ԫ��
    int size = getQueueSize(&obj->q);
    while (size > 1) {
        int front = getQueueFront(&obj->q);
        QueuePop(&obj->q);
        QueuePush(&obj->q, front);
        size--;
    }
    int ret = getQueueFront(&obj->q);
    QueuePop(&obj->q);
    return ret;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return getQueueBack(&obj->q);
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return QueueEmpty(&obj->q);
}

void myStackFree(MyStack* obj) {
    QueueDertory(&obj->q);
    free(obj);
}



int main() {


	system("pause");
	return 0;
}