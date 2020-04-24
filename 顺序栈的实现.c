#include<stdio.h>
#include<stdlib.h>


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


void stackprint(Stack* st) {
	//������ֻ��������, �������û�
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

	//����һ��ȡջ��Ԫ��֮ǰҪ�����пպ���
	if (StackEmpty(&st) == 0) {
		DataType top1 = getStackTop(&st);
		printf("top : %d\n",top1);
	}


	system("pause");
	return 0;
}