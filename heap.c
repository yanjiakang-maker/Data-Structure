#include"heap.h"



void Swap(HPDataType* array, int left, int right) {
	HPDataType tmp = array[left];
	array[left] = array[right];
	array[right] = tmp;
}


//����
void heapCreat(Heap* hp, HPDataType* array, int size) {
	//�Ȱ���Ϣ������� (�ṹ��)
	hp->array = (HPDataType*)malloc(sizeof(HPDataType) * size);
	memcpy(hp->array, array, sizeof(HPDataType) * size);
	hp->size = size;
	hp->capacity = size;

	//�ӵ�һ����Ҷ�ӽڵ㿪ʼ �����µ���
	//��һ����Ҷ�ӽڵ�: (size - 2) / 2
	for (int parent = (size - 2) / 2; parent >= 0; parent--) {
		shiftDownL(hp->array, hp->size, parent);
	}
}


//С�ѵ����µ���
//parent : ��ǰ��Ҫ������λ��
void shiftDownL(HPDataType* array, int size, int parent) {

	//��ȷ������λ��
	int child = 2 * parent + 1;

	while (child < size) {
		//ȡ���Һ�����, ��С��һ������
		if (child + 1 < size && array[child + 1] < array[child])
			child++;
		//�ȽϺ��Ӻ͸���, �����ӱȸ���С, ����
		if (array[child] < array[parent])
			Swap(array, child, parent);
		else {
			//�����Ӵ��ڵ��ڸ���, ��������
			break;
		}
		//����child��parent
		parent = child;
		child = 2 * parent + 1;
	}
}


//С�����ϵ���
void shiftUpL(HPDataType* array, int child) {
	//��ȷ�����ڵ�λ��
	int parent = (child - 1) / 2;
	while (child > 0) {
		if (array[child] < array[parent])
			Swap(array, child, parent);
		else {
			//��������
			break;
		}
		//����child��parent
		child = parent;
		parent = (child - 1) / 2;
	}
}


//��ѵ����µ���
//parent : ��ǰ��Ҫ������λ��
void shiftDownB(HPDataType* array, int size, int parent) {

	//��ȷ������λ��
	int child = 2 * parent + 1;

	while (child < size) {
		//ȡ���Һ�����, �ϴ��һ������
		if (child + 1 < size && array[child + 1] > array[child])
			child++;
		//�ȽϺ��Ӻ͸���, �����ӱȸ��״�, ����
		if (array[child] > array[parent])
			Swap(array, child, parent);
		else {
			//������С�ڵ��ڸ���, ��������
			break;
		}
		//����child��parent
		parent = child;
		child = 2 * parent + 1;
	}
}


//������ϵ���
void shiftUpB(HPDataType* array, int child) {
	//��ȷ�����ڵ�λ��
	int parent = (child - 1) / 2;
	while (child > 0) {
		if (array[child] > array[parent])
			Swap(array, child, parent);
		else {
			//��������
			break;
		}
		//����child��parent
		child = parent;
		parent = (child - 1) / 2;
	}
}


//�������
void heapPush(Heap* hp, HPDataType data) {
	//����Ҫ�������
	if (hp->size == hp->capacity) {
		//����
		hp->capacity *= 2;
		hp->array = (HPDataType*) realloc(hp->array, sizeof(HPDataType) * hp->capacity);
	}

	//���� : β�� + ���ϵ���
	hp->array[hp->size] = data;
	hp->size++;
	shiftUpL(hp->array, hp->size - 1);

}


//ɾ���Ѷ�Ԫ��
void heapPop(Heap* hp) {

	if (hp->size > 0) {
		//ɾ�� : ���� -> βɾ -> ���ڵ�����µ���
		Swap(hp->array, 0, hp->size - 1);
		hp->size--;
		shiftDownL(hp->array, hp->size, 0);
	}
}


HPDataType getHeapTop(Heap* hp) {
	return hp->array[0];
}


int heapEmpty(Heap* hp) {
	if (hp->size == 0)
		return 1;
	return 0;
}


void heapPrint(Heap* hp) {
	for (int i = 0; i < hp->size; i++) {
		printf("%d ", hp->array[i]);
	}
	printf("\n");
}
