#include"heap.h"

// TopK问题 : 找出N 个数中 最大/最小 的K个值
// 找最大值建小堆
// 找最小值建大堆

//以找最大值为例
//具体步骤 : 建立一个K个元素的堆
//          然后从第i个元素开始一直遍历到结束 (i>k), 
//          如果第i个元素大于堆顶元素, 删除堆顶元素(交换,尾删,向下调整) , 让第i个元素入堆(尾插,向上调整)


//打印最大的k个值
void TopK(int* array, int size, int k) {
	Heap hp;
	//创建k个元素的小堆
	heapCreat(&hp, array, k);

	for (int i = k; i < size; i++) {
		if (array[i] > getHeapTop(&hp)) {
			heapPop(&hp);
			heapPush(&hp, array[i]);
		}
	}

	heapPrint(&hp);
}



