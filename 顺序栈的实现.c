#include<stdio.h>
#include<stdlib.h>


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


void stackprint(Stack* st) {
	//这个借口只供测试用, 不供给用户
	for (int i = st->size - 1; i >= 0; i--) {
		printf("%d ", st->arr[i]);
	}
	printf("\n");
}


int main() {
	Stack st;
	StackInit(&st, 5);

	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	stackprint(&st);

	StackPop(&st);
	stackprint(&st);
	StackPop(&st);
	stackprint(&st);

	DataType top = getStackTop(&st);
	printf("top : %d\n", top);
	int size = getStackSize(&st);
	printf("size = %d\n", size);

	//这里一般取栈顶元素之前要调用判空函数
	if (StackEmpty(&st) == 0) {
		DataType top1 = getStackTop(&st);
		printf("top : %d\n",top1);
	}


	system("pause");
	return 0;
}