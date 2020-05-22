#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int HPDataType;

typedef struct Heap {
	HPDataType* array;
	int size;
	int capacity;
}Heap;

void Swap(HPDataType* array, int left, int right);

void heapCreat(Heap* hp, HPDataType* array, int size);

void shiftDownL(HPDataType* array, int size, int parent);

void shiftUpL(HPDataType* array, int child);

void shiftDownB(HPDataType* array, int size, int parent);

void shiftUpB(HPDataType* array, int child);

void heapPush(Heap* hp, HPDataType data);

void heapPop(Heap* hp);

HPDataType getHeapTop(Heap* hp);

int heapEmpty(Heap* hp);

void heapPrint(Heap* hp);

void TopK(int* array, int size, int k);
void PrintTopK(int* a, int n, int k);