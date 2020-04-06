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
	//������
	sl->head = NULL;
}


//����һ���½��
Node* CreatNode(DataType data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}


//��ӡ�������е�ֵ
void SinglgListPrint(SinglgList* sl) {
	if (sl->head == NULL) {
		printf("����Ϊ������! ��ӡʧ��!\n");
		return;
	}
	Node* cur = sl->head;
	while (cur != NULL) {
		//���� cur != NULL ѭ������ʱ cur�Ѿ�ָ�������һ��������һ�����, Ҳ����NULL
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}


//ͷ��
void SinglgListPushFront(SinglgList* sl, DataType data) {
	Node* node = CreatNode(data);
	if (sl->head == NULL) {
		//��Ϊ������, ֱ�Ӱѽ�����ͷָ���
		sl->head = node;
		return;
	}
	//������ǿձ� �Ǿ͸���ô����ô��
	node->next = sl->head;
	sl->head = node;
}


//ͷɾ
void SinglgListPopFront(SinglgList* sl) {
	if (sl->head == NULL) {
		printf("����Ϊ��! ɾ��ʧ��!\n");
		return;
	}
	Node* cur = sl->head;
	sl->head = cur->next;
	free(cur);
}


//β��
void SinglgListPushBack(SinglgList* sl, DataType data) {
	Node* node = CreatNode(data);
	if (sl->head == NULL) {
		//����ǿձ�Ļ�, ֱ�Ӳ���ͷָ��󼴿�
		sl->head = node;
		return;
	}
	//������ǿձ�Ļ�, ��Ҫ�ҵ����һ�����, Ȼ����в���
	Node* tail = sl->head;
	while (tail->next != NULL) {
		//���� tail->next != NULL  ѭ��������ʱ��, tmp��ָ�����һ�����Ľṹ��ָ��(Ҳ�������һ�������׵�ַ)
		tail = tail->next;
	}
	tail->next = node;
}


//βɾ
void SinglgListPopBack(SinglgList* sl) {
	if (sl->head == NULL) {
		printf("����Ϊ��! ɾ��ʧ��!\n");
		return;
	}
	if (sl->head->next == NULL) {
		//���ֻ��һ�����Ļ�, ֱ�Ӹ�ͷָ����ռ���
		sl->head = NULL;
		return;
	}
	//�����Ϊ�յĻ�, �Ϳ�ʼ����
	//βɾ��Ҫ�ҵ����һ��Ԫ�غ�����ǰ��, ��������ǰ�����в���
	Node* tail = sl->head;
	Node* prev = NULL;
	while (tail->next != NULL) {
		//ǰ���Ѿ�֪������ѭ������ʱ, tail ָ��������һ�����
		//���� prev ���� tail ��ǰ�� , ��һ��ѭ����ִ�к�ѭ������
		prev = tail;
		tail = tail->next;
	}
		prev->next = NULL;
	free(tail);
}

//����
Node* SinglgListFind(SinglgList* sl, DataType val) {
	//�����Ǹ������ݲ���, ���ؽ��ĵ�ַ
	Node* ret = sl->head;
	if (ret == NULL) {
		printf("����Ϊ��! ����ʧ��!\n");
	}
	while (ret != NULL) {
		if (ret->data == val) {
			return ret;
		}
		ret = ret->next;
	}
	return NULL;
}


//��pos �����һ�����
void SinglgListInsertAfter(Node* pos, DataType data) {
	Node* newnode = CreatNode(data);
	if (pos == NULL) {
		return;
	}
	newnode->next = pos->next;
	pos->next = newnode;
}


//ɾ�� pos �����һ�����
void SinglgListEraseAfter(Node* pos) {
	if (pos == NULL) {
		return;
	}
	Node* tmp = pos->next;
	if (tmp != NULL) {
		//ÿ�ν����ö�Ҫ���ָ���Ƿ�Ϊ��, �����Ұָ������þ���δ������Ϊ
		pos->next = tmp->next;
		free(tmp);
	}
}


//����
void SinglgListDestory(SinglgList* sl) {
	if (sl->head == NULL) {
		//����Ϊ�� ��������
		return;
	}
	Node* cur = sl->head;
	while (cur != NULL) {
		Node* tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	printf("���ٳɹ�!\n");
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