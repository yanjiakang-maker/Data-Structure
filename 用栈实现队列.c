#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int DataType;

typedef struct Stack {
    DataType* arr;
    int size;
    int capacity;
}Stack;


//初始化
void StackInit(Stack* st, int n) {
    //创建一个n个元素的栈
    st->size = 0;
    st->capacity = n;
    st->arr = (DataType*)malloc(sizeof(DataType) * n);
}


//进栈
void StackPush(Stack* st, DataType data) {
    //插入时先检查栈是否已满
    if (st->size >= st->capacity) {
        //扩容
        st->capacity += st->capacity;
        st->arr = (DataType*)realloc(st->arr, st->capacity * sizeof(DataType));
    }
    //尾插
    st->arr[st->size] = data;
    st->size++;
}


//出栈
void StackPop(Stack* st) {
    if (st->size == 0) {
        //空栈, 删除失败
        return;
    }
    //尾删
    st->size--;
}


//得到栈顶元素
DataType getStackTop(Stack* st) {
    return st->arr[st->size - 1];
}


//得到栈的大小
int getStackSize(Stack* st) {
    return st->size;
}


//判空
int StackEmpty(Stack* st) {
    if (st->size == 0) {
        return 1;
    }
    return 0;
}


//销毁
void StackDestory(Stack* st) {
    free(st->arr);
    st->arr = NULL;
    st->capacity = 0;
    st->size = 0;
}


typedef struct {
    //用两个栈实现队列
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
    //入队, 就是入栈操作
    StackPush(&obj->pushST, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    //出队, 用两个栈相互转移数据拿到队头元素
    //把pushST 数据全部出栈然后 入栈到popST, 刚好能拿到最先入栈的元素
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