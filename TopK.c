#include"heap.h"

// TopK���� : �ҳ�N ������ ���/��С ��K��ֵ
// �����ֵ��С��
// ����Сֵ�����

//�������ֵΪ��
//���岽�� : ����һ��K��Ԫ�صĶ�
//          Ȼ��ӵ�i��Ԫ�ؿ�ʼһֱ���������� (i>k), 
//          �����i��Ԫ�ش��ڶѶ�Ԫ��, ɾ���Ѷ�Ԫ��(����,βɾ,���µ���) , �õ�i��Ԫ�����(β��,���ϵ���)


//��ӡ����k��ֵ
void TopK(int* array, int size, int k) {
	Heap hp;
	//����k��Ԫ�ص�С��
	heapCreat(&hp, array, k);

	for (int i = k; i < size; i++) {
		if (array[i] > getHeapTop(&hp)) {
			heapPop(&hp);
			heapPush(&hp, array[i]);
		}
	}

	heapPrint(&hp);
}



