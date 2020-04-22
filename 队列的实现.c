#include<stdio.h>
#include<stdlib.h>


typedef int DataType;

typedef struct QNode {
	DataType data;
	struct QNode* next;
}QNode;

typedef struct Queue {
	QNode* front;
	QNode* rear;
	int size;
}Queue;


//��ʼ��
void QueueInit(Queue* q) {
	q->front = q->rear = NULL;
	q->size = 0;
}


//�������
QNode* QNodeCreat(DataType data) {
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->data = data;
	node->next = NULL;
	return node;
}


//����(β��)
void QueuePush(Queue* q, DataType data) {
	QNode* node = QNodeCreat(data);
	//�����ǲ��ǿն���
	if (q->front == NULL) {
		q->front = q->rear = node;
	}
	else {
		q->rear->next = node;
		q->rear = node;
	}
	q->size++;
}


//����(ͷɾ)
void QueuePop(Queue* q) {
	if (q->front == NULL) {
		//����Ϊ��, ����ʧ��
		return;
	}

	QNode* next = q->front->next;
	free(q->front);
	q->front = next;

	//ɾ�����Ƿ�Ϊ�ձ�
	if (q->front == NULL) {
		q->rear = NULL;
	}
	q->size--;
}


//�õ�����Ԫ��
DataType getQueueFront(Queue* q) {
	return q->front->data;
}


//�õ���βԪ��
DataType getQueueBack(Queue* q) {
	return q->rear->data;
}


//�õ����г���
int getQueueSize(Queue* q) {
	return q->size;
}


//�п�
int QueueEmpty(Queue* q) {
	if (q->front == NULL) {
		return 1;
	}
	return 0;
}


//����
void QueueDertory(Queue* q) {
	QNode* cur = q->front;
	while (cur != NULL) {
		QNode* tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	q->front = q->rear = NULL;
	q->size = 0;
}


void queueprint(Queue* q) {
	QNode* cur = q->front;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}


int main() {
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	queueprint(&q);

	//QueuePop(&q);
	//QueuePop(&q);
	//QueuePop(&q);
	//queueprint(&q);

	if (QueueEmpty(&q) == 0) {
		printf("front : %d\n", getQueueFront(&q));
	}

	if (QueueEmpty(&q) == 0) {
		printf("rear : %d\n", getQueueBack(&q));
	}

	if (QueueEmpty(&q) == 0) {
		printf("size : %d\n", getQueueSize(&q));
	}

	QueueDertory(&q);


	system("pause");
	return 0;
}