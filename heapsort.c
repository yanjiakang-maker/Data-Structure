#include"heapsort.h"


void heapSort(int* array, int size) {
	//建堆
	for (int i = (size - 2) / 2; i >= 0; i--) {
		shiftDownB(array, size, i);
	}
	//排序 : 实际上就是循环尾删  (交换, 尾删, 向下调整)
	int end = size;
	while (end > 1) {
		Swap(array, 0, end - 1);
		end--;
		shiftDownB(array, end, 0);
	}
}