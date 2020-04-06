#include<stdio.h>
#include<stdlib.h>

typedef int DataType;

typedef struct Node {
	DataType data;
	struct Node* next;
}Node;

typedef struct SinglgList {
	Node* head;
}SinglgList;



void SinglgListInit(SinglgList* sl) {
	//空链表
	sl->head = NULL;
}


//创建一个新结点
Node* CreatNode(DataType data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}


//打印链表所有的值
void SinglgListPrint(SinglgList* sl) {
	if (sl->head == NULL) {
		printf("链表为空链表! 打印失败!\n");
		return;
	}
	Node* cur = sl->head;
	while (cur != NULL) {
		//这里 cur != NULL 循环结束时 cur已经指向了最后一个结点的下一个结点, 也就是NULL
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}


//头插
void SinglgListPushFront(SinglgList* sl, DataType data) {
	Node* node = CreatNode(data);
	if (sl->head == NULL) {
		//若为空链表, 直接把结点接在头指针后
		sl->head = node;
		return;
	}
	//如果不是空表 那就该怎么来怎么来
	node->next = sl->head;
	sl->head = node;
}


//头删
void SinglgListPopFront(SinglgList* sl) {
	if (sl->head == NULL) {
		printf("链表为空! 删除失败!\n");
		return;
	}
	Node* cur = sl->head;
	sl->head = cur->next;
	free(cur);
}


//尾插
void SinglgListPushBack(SinglgList* sl, DataType data) {
	Node* node = CreatNode(data);
	if (sl->head == NULL) {
		//如果是空表的话, 直接插在头指针后即可
		sl->head = node;
		return;
	}
	//如果不是空表的话, 需要找到最后一个结点, 然后进行操作
	Node* tail = sl->head;
	while (tail->next != NULL) {
		//这里 tail->next != NULL  循环结束的时候, tmp是指向最后一个结点的结构体指针(也就是最后一个结点的首地址)
		tail = tail->next;
	}
	tail->next = node;
}


//尾删
void SinglgListPopBack(SinglgList* sl) {
	if (sl->head == NULL) {
		printf("链表为空! 删除失败!\n");
		return;
	}
	if (sl->head->next == NULL) {
		//如果只有一个结点的话, 直接给头指针设空即可
		sl->head = NULL;
		return;
	}
	//如果不为空的话, 就开始操作
	//尾删需要找到最后一个元素和他的前驱, 并对他的前驱进行操作
	Node* tail = sl->head;
	Node* prev = NULL;
	while (tail->next != NULL) {
		//前面已经知道这里循环结束时, tail 指向的是最后一个结点
		//所以 prev 就是 tail 的前驱 , 这一次循环体执行后循环结束
		prev = tail;
		tail = tail->next;
	}
		prev->next = NULL;
	free(tail);
}

//查找
Node* SinglgListFind(SinglgList* sl, DataType val) {
	//这里是根据数据查找, 返回结点的地址
	Node* ret = sl->head;
	if (ret == NULL) {
		printf("链表为空! 查找失败!\n");
	}
	while (ret != NULL) {
		if (ret->data == val) {
			return ret;
		}
		ret = ret->next;
	}
	return NULL;
}


//在pos 结点后查一个结点
void SinglgListInsertAfter(Node* pos, DataType data) {
	Node* newnode = CreatNode(data);
	if (pos == NULL) {
		return;
	}
	newnode->next = pos->next;
	pos->next = newnode;
}


//删除 pos 结点后的一个结点
void SinglgListEraseAfter(Node* pos) {
	if (pos == NULL) {
		return;
	}
	Node* tmp = pos->next;
	if (tmp != NULL) {
		//每次解引用都要检查指针是否为空, 如果对野指针解引用就是未定义行为
		pos->next = tmp->next;
		free(tmp);
	}
}


//销毁
void SinglgListDestory(SinglgList* sl) {
	if (sl->head == NULL) {
		//链表为空 无需销毁
		return;
	}
	Node* cur = sl->head;
	while (cur != NULL) {
		Node* tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	printf("销毁成功!\n");
}



int main() {
	SinglgList sl;
	SinglgListInit(&sl);

	SinglgListPushFront(&sl, 1);
	SinglgListPrint(&sl);
	SinglgListPushFront(&sl, 2);
	SinglgListPrint(&sl);
	SinglgListPushFront(&sl, 3);
	SinglgListPrint(&sl);


	SinglgListPopFront(&sl);
	SinglgListPrint(&sl);
	SinglgListPopFront(&sl);
	SinglgListPrint(&sl);
	SinglgListPopFront(&sl);
	SinglgListPrint(&sl);


	SinglgListPushBack(&sl, 1);
	SinglgListPrint(&sl);
	SinglgListPushBack(&sl, 2);
	SinglgListPrint(&sl);
	SinglgListPushBack(&sl, 3);
	SinglgListPrint(&sl);


	Node* pos = SinglgListFind(&sl, 2);
	SinglgListInsertAfter(pos, 100);
	SinglgListPrint(&sl);


	SinglgListEraseAfter(pos);
	SinglgListPrint(&sl);

	//SinglgListPopBack(&sl);
	//SinglgListPrint(&sl);
	//SinglgListPopBack(&sl);
	//SinglgListPrint(&sl);
	//SinglgListPopBack(&sl);
	//SinglgListPrint(&sl);


	//SinglgListDestory(&sl);

	system("pause");
	return 0;
}