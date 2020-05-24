#include"heap.h"
#include"heapsort.h"

void test() {

	int array[11] = { 100, 50, 30, 20, 25, 18, 10, 5, 15, 21, 23 };
	Heap hp;
	heapCreat(&hp, array, 11);
	heapPrint(&hp);
	heapPush(&hp, 40);
	heapPrint(&hp);
}

void test2() {
	int array[11] = { 18, 10, 5, 15, 21, 23, 100, 50, 30, 20, 25 };
	Heap hp;
	heapCreat(&hp, array, 11);
	heapPrint(&hp);
	heapPop(&hp);
	heapPrint(&hp);
	heapPop(&hp);
	heapPrint(&hp);
	heapPop(&hp);
	heapPrint(&hp);
	heapPush(&hp, 1);
	heapPrint(&hp);

	heapPop(&hp);
	heapPrint(&hp);
	heapPop(&hp);
	heapPrint(&hp);
	heapPush(&hp, 200);
	heapPrint(&hp);

	heapPop(&hp);
	heapPrint(&hp);

}


void test3() {
	int array[11] = { 100, 50, 30, 20, 25, 18, 10, 5, 15, 21, 23 };
	Heap hp;
	heapCreat(&hp, array, 11);
	heapPrint(&hp);
	while (heapEmpty(&hp) != 1) {
		printf("%d\n", getHeapTop(&hp));
		heapPop(&hp);
	}
}


void testsort() {
	int array[] = { 30, 45, 15, 35, 36, 18,45, 45, 53, 72, 48, 93 };
	int size = sizeof(array) / sizeof(array[0]);
	heapSort(array, size);

	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}


void testTopK() {
	int array[12] = { 12, 18, 50, 5, 77, 80, 1, 100, 0, 45, 200, 500 };
	TopK(array, 12, 5);
}



int main() {
	//test();
	//test2();
	//test3();
	//testsort();
	testTopK();
	return 0;
}