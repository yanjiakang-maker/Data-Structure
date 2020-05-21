#include"heapsort.h"


void heapSort(int* array, int size) {
	//����
	for (int i = (size - 2) / 2; i >= 0; i--) {
		shiftDownB(array, size, i);
	}
	//���� : ʵ���Ͼ���ѭ��βɾ  (����, βɾ, ���µ���)
	int end = size;
	while (end > 1) {
		Swap(array, 0, end - 1);
		end--;
		shiftDownB(array, end, 0);
	}
}