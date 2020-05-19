#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int DataType;

typedef struct Stack {
    DataType* arr;
    int size;
    int capacity;
}Stack;


//��ʼ��
void StackInit(Stack* st, int n) {
    //����һ��n��Ԫ�ص�ջ
    st->size = 0;
    st->capacity = n;
    st->arr = (DataType*)malloc(sizeof(DataType) * n);
}


//��ջ
void StackPush(Stack* st, DataType data) {
    //����ʱ�ȼ��ջ�Ƿ�����
    if (st->size >= st->capacity) {
        //����
        st->capacity += st->capacity;
        st->arr = (DataType*)realloc(st->arr, st->capacity * sizeof(DataType));
    }
    //β��
    st->arr[st->size] = data;
    st->size++;
}


//��ջ
void StackPop(Stack* st) {
    if (st->size == 0) {
        //��ջ, ɾ��ʧ��
        return;
    }
    //βɾ
    st->size--;
}


//�õ�ջ��Ԫ��
DataType getStackTop(Stack* st) {
    return st->arr[st->size - 1];
}


//�õ�ջ�Ĵ�С
int getStackSize(Stack* st) {
    return st->size;
}


//�п�
int StackEmpty(Stack* st) {
    if (st->size == 0) {
        return 1;
    }
    return 0;
}


//����
void StackDestory(Stack* st) {
    free(st->arr);
    st->arr = NULL;
    st->capacity = 0;
    st->size = 0;
}


typedef struct {
    //������ջʵ�ֶ���
    Stack pushST;
    Stack popST;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* mq = (MyQueue*)malloc(sizeof(MyQueue));
    StackInit(&mq->pushST, 10);
    StackInit(&mq->popST, 10);
    return mq;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    //���, ������ջ����
    StackPush(&obj->pushST, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    //����, ������ջ�໥ת�������õ���ͷԪ��
    //��pushST ����ȫ����ջȻ�� ��ջ��popST, �պ����õ�������ջ��Ԫ��
    if (StackEmpty(&obj->popST) == 1) {
        while (StackEmpty(&obj->pushST) != 1) {
            int top = getStackTop(&obj->pushST);
            StackPop(&obj->pushST);
            StackPush(&obj->popST, top);
        }
    }
    int ret = getStackTop(&obj->popST);
    StackPop(&obj->popST);
    return ret;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if (StackEmpty(&obj->popST) == 1) {
        while (StackEmpty(&obj->pushST) != 1) {
            int top = getStackTop(&obj->pushST);
            StackPop(&obj->pushST);
            StackPush(&obj->popST, top);
        }
    }
    int ret = getStackTop(&obj->popST);
    return ret;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return (StackEmpty(&obj->pushST) && StackEmpty(&obj->popST));
}

void myQueueFree(MyQueue* obj) {
    StackDestory(&obj->pushST);
    StackDestory(&obj->popST);
    free(obj);
}




int main() {

	system("pause");
	return 0;
}