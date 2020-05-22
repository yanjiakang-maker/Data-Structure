#include"heap.h"



void Swap(HPDataType* array, int left, int right) {
	HPDataType tmp = array[left];
	array[left] = array[right];
	array[right] = tmp;
}


//建堆
void heapCreat(Heap* hp, HPDataType* array, int size) {
	//先把信息填入堆中 (结构体)
	hp->array = (HPDataType*)malloc(sizeof(HPDataType) * size);
	memcpy(hp->array, array, sizeof(HPDataType) * size);
	hp->size = size;
	hp->capacity = size;

	//从第一个非叶子节点开始 做向下调整
	//第一个非叶子节点: (size - 2) / 2
	for (int parent = (size - 2) / 2; parent >= 0; parent--) {
		shiftDownL(hp->array, hp->size, parent);
	}
}


//小堆的向下调整
//parent : 当前需要调整的位置
void shiftDownL(HPDataType* array, int size, int parent) {

	//先确定左孩子位置
	int child = 2 * parent + 1;

	while (child < size) {
		//取左右孩子中, 较小的一个孩子
		if (child + 1 < size && array[child + 1] < array[child])
			child++;
		//比较孩子和父亲, 若孩子比父亲小, 交换
		if (array[child] < array[parent])
			Swap(array, child, parent);
		else {
			//若孩子大于等于父亲, 结束调整
			break;
		}
		//更新child和parent
		parent = child;
		child = 2 * parent + 1;
	}
}


//小堆向上调整
void shiftUpL(HPDataType* array, int child) {
	//先确定父节点位置
	int parent = (child - 1) / 2;
	while (child > 0) {
		if (array[child] < array[parent])
			Swap(array, child, parent);
		else {
			//结束调整
			break;
		}
		//更新child和parent
		child = parent;
		parent = (child - 1) / 2;
	}
}


//大堆的向下调整
//parent : 当前需要调整的位置
void shiftDownB(HPDataType* array, int size, int parent) {

	//先确定左孩子位置
	int child = 2 * parent + 1;

	while (child < size) {
		//取左右孩子中, 较大的一个孩子
		if (child + 1 < size && array[child + 1] > array[child])
			child++;
		//比较孩子和父亲, 若孩子比父亲大, 交换
		if (array[child] > array[parent])
			Swap(array, child, parent);
		else {
			//若孩子小于等于父亲, 结束调整
			break;
		}
		//更新child和parent
		parent = child;
		child = 2 * parent + 1;
	}
}


//大堆向上调整
void shiftUpB(HPDataType* array, int child) {
	//先确定父节点位置
	int parent = (child - 1) / 2;
	while (child > 0) {
		if (array[child] > array[parent])
			Swap(array, child, parent);
		else {
			//结束调整
			break;
		}
		//更新child和parent
		child = parent;
		parent = (child - 1) / 2;
	}
}


//插入操作
void heapPush(Heap* hp, HPDataType data) {
	//插入要检查容量
	if (hp->size == hp->capacity) {
		//扩容
		hp->capacity *= 2;
		hp->array = (HPDataType*) realloc(hp->array, sizeof(HPDataType) * hp->capacity);
	}

	//插入 : 尾插 + 向上调整
	hp->array[hp->size] = data;
	hp->size++;
	shiftUpL(hp->array, hp->size - 1);

}


//删除堆顶元素
void heapPop(Heap* hp) {

	if (hp->size > 0) {
		//删除 : 交换 -> 尾删 -> 根节点的向下调整
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
