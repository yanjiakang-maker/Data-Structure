#include<stdio.h>
#include<stdlib.h>


typedef int DataType;

typedef struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
}Node;

typedef struct List {
	Node* header;
}List;


//初始化
void listInit(List* ls) {
	//要创建一个头结点, 并实现循环结构
	ls->header = (Node*)malloc(sizeof(Node));
	ls->header->next = ls->header;
	ls->header->prev = ls->header;
}


//创建新节点
Node* listCreat(DataType data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = node->prev = NULL;
	return node;
}


//打印
void listPrint(List* ls) {
	if (ls->header->next == ls->header) {
		//说明链表为空
		printf("链表为空, 打印失败!\n");
		return;
	}
	Node* cur = ls->header->next;
	while (cur != ls->header) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}


//头插
void listPushFront(List* ls, DataType data) {
	Node* front = ls->header->next;
	Node* node = listCreat(data);

	node->next = front;
	front->prev = node;
	ls->header->next = node;
	node->prev = ls->header;
}


//头删
void listPopFront(List* ls) {
	if (ls->header->next == ls->header) {
		//链表为空, 无法删除
		return;
	}
	Node* front = ls->header->next;
	Node* next = front->next;

	free(front);
	ls->header->next = next;
	next->prev = ls->header;

}


//尾插
void listPushBack(List* ls, DataType data) {
	Node* node = listCreat(data);
	Node* last = ls->header->prev;

	last->next = node;
	node->prev = last;
	ls->header->prev = node;
	node->next = ls->header;
}


//尾删
void listPopBack(List* ls) {
	//注意不能删头结点
	if (ls->header->next == ls->header) {
		//链表为空, 不能删头
		return;
	}
	Node* last = ls->header->prev;
	Node* cur = last->prev;

	free(last);
	cur->next = ls->header;
	ls->header->prev = cur;
}


//在pos位置前面插入一个结点
void listInsert(Node* pos, DataType data) {
	Node* node = listCreat(data);
	Node* prev = pos->prev;

	node->next = pos;
	pos->prev = node;
	prev->next = node;
	node->prev = prev;
}


//删除pos位置的结点
void listErase(Node* pos) {
	if (pos->next == pos) {
		//说明只有头结点, 不能删除
		return;
	}

	Node* prev = pos->prev;
	Node* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}


//查找
Node* listFind(List* ls, DataType data) {
	if (ls->header->next == ls->header) {
		//链表为空, 查找失败
		return;
	}
	Node* cur = ls->header->next;
	while (cur != ls->header) {
		if (cur->data == data) {
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}


//销毁
void listDestory(List* ls) {
	Node* cur = ls->header->next;
	while (cur != ls->header) {
		Node* tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	free(ls->header);
	ls->header = NULL;
}



int main() {
	List ls;
	listInit(&ls);

	listPushFront(&ls, 1);
	listPushFront(&ls, 2);
	listPushFront(&ls, 3);
	listPushFront(&ls, 4);
	listPushFront(&ls, 5);
	listPrint(&ls);

	listPopFront(&ls);
	listPopFront(&ls);
	listPopFront(&ls);
	listPrint(&ls);

	listPushBack(&ls, 9);
	listPushBack(&ls, 8);
	listPushBack(&ls, 7);
	listPushBack(&ls, 6);
	listPrint(&ls);

	listPopBack(&ls);
	listPopBack(&ls);
	listPopBack(&ls);
	listPrint(&ls);


	Node* pos = listFind(&ls, 9);
	listInsert(pos, 6);
	listPrint(&ls);

	listErase(pos);
	listPrint(&ls);

	listDestory(&ls);

	system("pause");
	return 0;
}