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


//��ʼ��
void listInit(List* ls) {
	//Ҫ����һ��ͷ���, ��ʵ��ѭ���ṹ
	ls->header = (Node*)malloc(sizeof(Node));
	ls->header->next = ls->header;
	ls->header->prev = ls->header;
}


//�����½ڵ�
Node* listCreat(DataType data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = node->prev = NULL;
	return node;
}


//��ӡ
void listPrint(List* ls) {
	if (ls->header->next == ls->header) {
		//˵������Ϊ��
		printf("����Ϊ��, ��ӡʧ��!\n");
		return;
	}
	Node* cur = ls->header->next;
	while (cur != ls->header) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}


//ͷ��
void listPushFront(List* ls, DataType data) {
	Node* front = ls->header->next;
	Node* node = listCreat(data);

	node->next = front;
	front->prev = node;
	ls->header->next = node;
	node->prev = ls->header;
}


//ͷɾ
void listPopFront(List* ls) {
	if (ls->header->next == ls->header) {
		//����Ϊ��, �޷�ɾ��
		return;
	}
	Node* front = ls->header->next;
	Node* next = front->next;

	free(front);
	ls->header->next = next;
	next->prev = ls->header;

}


//β��
void listPushBack(List* ls, DataType data) {
	Node* node = listCreat(data);
	Node* last = ls->header->prev;

	last->next = node;
	node->prev = last;
	ls->header->prev = node;
	node->next = ls->header;
}


//βɾ
void listPopBack(List* ls) {
	//ע�ⲻ��ɾͷ���
	if (ls->header->next == ls->header) {
		//����Ϊ��, ����ɾͷ
		return;
	}
	Node* last = ls->header->prev;
	Node* cur = last->prev;

	free(last);
	cur->next = ls->header;
	ls->header->prev = cur;
}


//��posλ��ǰ�����һ�����
void listInsert(Node* pos, DataType data) {
	Node* node = listCreat(data);
	Node* prev = pos->prev;

	node->next = pos;
	pos->prev = node;
	prev->next = node;
	node->prev = prev;
}


//ɾ��posλ�õĽ��
void listErase(Node* pos) {
	if (pos->next == pos) {
		//˵��ֻ��ͷ���, ����ɾ��
		return;
	}

	Node* prev = pos->prev;
	Node* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}


//����
Node* listFind(List* ls, DataType data) {
	if (ls->header->next == ls->header) {
		//����Ϊ��, ����ʧ��
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


//����
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