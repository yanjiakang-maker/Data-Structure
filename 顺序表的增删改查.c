#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

typedef struct SqList
{
	DataType* arr;
	int size;
	int capacity;
}SqList;


//顺序表初始化
void SqListInit(SqList* sl) {
	//size代表的是当前元素个数
	sl->size = 0;
	//capacity代表当前最大容量
	sl->capacity = 10;
	sl->arr = (DataType*)malloc(sizeof(DataType) * sl->capacity);

	//给数组中信息赋空值
	for (int i = 0; i < sl->capacity; i++) {
		sl->arr[i] = 0;
	}
}


//销毁
void SqListDestory(SqList* sl) {
	assert(sl != NULL);
	free(sl->arr);
	sl->arr = NULL;
	sl->size = 0;
	sl->capacity = 0;
}


//打印
void SqListPrint(SqList* sl) {
	assert(sl != NULL);
	for (int i = 0; i < sl->size; i++) {
		printf("%d  ", sl->arr[i]);
	}
	printf("\n");
}


//顺序表检查是否需要扩容
void SqListChack(SqList* sl) {
	assert(sl != NULL);
	if (sl->size >= sl->capacity) {
		sl->capacity += 10;
		realloc(sl->arr, sizeof(DataType) * sl->capacity);
	}
}


//尾插
void SqListPushBack(SqList* sl, DataType val) {
	assert(sl != NULL);
	//插入算法都要进行检查是否要扩容
	SqListChack(sl);
	sl->arr[sl->size] = val;
	sl->size++;
}


//尾删
void SqListPopBack(SqList* sl) {
	assert(sl != NULL);
	if (sl->size == 0) {
		printf("顺序表为空, 删除失败!\n");
		return;
	}
	sl->arr[sl->size - 1] = 0;
	sl->size--;
}


//头插
void SqListPushFront(SqList* sl, DataType val) {
	assert(sl != NULL);
	SqListChack(sl);

	int start = sl->size;
	while (start > 0) {
		sl->arr[start] = sl->arr[start - 1];
		start--;
	}
	sl->arr[0] = val;
	sl->size++;
}


//头删
void SqListPopFront(SqList* sl) {
	assert(sl != NULL);

	int start = 1;
	while (start < sl->size) {
		sl->arr[start - 1] = sl->arr[start];
		start++;
	}
	sl->size--;
}


//查找
void SqListFind(SqList* sl, DataType val) {
	for (int i = 0; i < sl->size; i++) {
		if (sl->arr[i] == val) {
			printf("\n找到了! 元素的下标是%d \n\n",i);
			return;
		}
	}
	printf("\n没找到!\n\n");
}


//在pos位置插入
void SqListInsert(SqList* sl, int pos, DataType val) {
	assert(sl != NULL);
	if (pos < 0 || pos > sl->size) {
		printf("指定的pos位置有误! 插入失败!\n\n");
		return;
	}
	SqListChack(sl);

	int start = sl->size;
	while (start > pos) {
		sl->arr[start] = sl->arr[start - 1];
		start--;
	}
	sl->arr[pos] = val;
	sl->size++;
}


//在pos位置删除
void SqListdelete(SqList* sl, int pos) {
	assert(sl != NULL);
	if (pos < 0 || pos >= sl->size) {
		printf("指定的pos位置有误! 删除失败!\n\n");
		return;
	}

	int start = pos + 1;
	while (start < sl->size) {
		sl->arr[start - 1] = sl->arr[start];
		start++;
	}
	sl->size--;
}


int main() {
	SqList sl;
	SqListInit(&sl);

	SqListPushFront(&sl, 1);
	SqListPrint(&sl);
	SqListPushFront(&sl, 2);
	SqListPrint(&sl);
	SqListPushFront(&sl, 3);
	SqListPrint(&sl);
	SqListPushFront(&sl, 5);
	SqListPrint(&sl);
	SqListPushFront(&sl, 6);
	SqListPrint(&sl);

	SqListInsert(&sl, 2, 4);
	SqListPrint(&sl);

	SqListdelete(&sl, 7);
	SqListPrint(&sl);

	system("pause");
	return 0;
}