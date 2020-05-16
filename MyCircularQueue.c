#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct {
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* mq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    mq->arr = (int*)malloc(sizeof(int) * k);
    mq->front = mq->rear = 0;
    mq->size = 0;
    mq->capacity = k;
    return mq;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj->size == obj->capacity) {
        //˵������
        return false;
    }
    //β��
    obj->arr[obj->rear] = value;
    obj->rear++;
    //��֤�ṹѭ��
    if (obj->rear == obj->capacity) {
        //��ʱ�����Ѿ�Խ��, ����
        obj->rear = 0;
    }
    obj->size++;
    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->size == 0) {
        //˵��Ϊ��, �޷�ɾ��
        return false;
    }
    //ͷɾ
    obj->front++;
    obj->size--;
    //��֤�ṹѭ��
    if (obj->front == obj->capacity) {
        obj->front = 0;
    }
    return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->size == 0)
        return -1;
    return obj->arr[obj->front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->size == 0)
        return -1;
    if (obj->rear == 0)
        return obj->arr[obj->capacity - 1];
    return obj->arr[obj->rear - 1];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if (obj->size == 0)
        return true;
    return false;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if (obj->size == obj->capacity)
        return true;
    return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->arr);
    free(obj);
}




int main() {

	system("pause");
	return 0;
}