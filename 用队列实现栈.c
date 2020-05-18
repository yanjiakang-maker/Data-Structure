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


//初始化
void QueueInit(Queue* q) {
    q->front = q->rear = NULL;
    q->size = 0;
}


//创建结点
QNode* QNodeCreat(DataType data) {
    QNode* node = (QNode*)malloc(sizeof(QNode));
    node->data = data;
    node->next = NULL;
    return node;
}


//进队(尾插)
void QueuePush(Queue* q, DataType data) {
    QNode* node = QNodeCreat(data);
    //看看是不是空队列
    if (q->front == NULL) {
        q->front = q->rear = node;
    }
    else {
        q->rear->next = node;
        q->rear = node;
    }
    q->size++;
}


//出队(头删)
void QueuePop(Queue* q) {
    if (q->front == NULL) {
        //队列为空, 出队失败
        return;
    }

    QNode* next = q->front->next;
    free(q->front);
    q->front = next;

    //删除后是否为空表
    if (q->front == NULL) {
        q->rear = NULL;
    }
    q->size--;
}


//得到队首元素
DataType getQueueFront(Queue* q) {
    return q->front->data;
}


//得到队尾元素
DataType getQueueBack(Queue* q) {
    return q->rear->data;
}


//得到队列长度
int getQueueSize(Queue* q) {
    return q->size;
}


//判空
int QueueEmpty(Queue* q) {
    if (q->front == NULL) {
        return 1;
    }
    return 0;
}


//销毁
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
    //用一个队列实现栈
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
    //就是入队操作
    QueuePush(&obj->q, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    //出栈是从栈顶(数组的尾)删除一个元素
    //而出队是从队列的队头(数组的头)删除一个元素
    //用队列实现栈  
    //就要让队列中除了队尾的值先出队在入队, 最后的一个元素就是要得到的元素
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