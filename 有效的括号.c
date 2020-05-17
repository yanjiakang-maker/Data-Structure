#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef char DataType;

typedef struct Stack {
    DataType* arr;
    int size;
    int capacity;
}Stack;


//��ʼ��
void StackInit(Stack* st, int n) {
    //����һ��n��Ԫ�ص�ջ
    st->size = 0;
    st->capacity = n;
    st->arr = (DataType*)malloc(sizeof(DataType) * n);
}


//��ջ
void StackPush(Stack* st, DataType data) {
    //����ʱ�ȼ��ջ�Ƿ�����
    if (st->size >= st->capacity) {
        //����
        st->capacity += st->capacity;
        st->arr = (DataType*)realloc(st->arr, st->capacity * sizeof(DataType));
    }
    //β��
    st->arr[st->size] = data;
    st->size++;
}


//��ջ
void StackPop(Stack* st) {
    if (st->size == 0) {
        //��ջ, ɾ��ʧ��
        return;
    }
    //βɾ
    st->size--;
}


//�õ�ջ��Ԫ��
DataType getStackTop(Stack* st) {
    return st->arr[st->size - 1];
}


//�õ�ջ�Ĵ�С
int getStackSize(Stack* st) {
    return st->size;
}


//�п�
int StackEmpty(Stack* st) {
    if (st->size == 0) {
        return 1;
    }
    return 0;
}


//����
void StackDestory(Stack* st) {
    free(st->arr);
    st->arr = NULL;
    st->capacity = 0;
    st->size = 0;
}



bool isValid(char* s) {
    Stack st;
    StackInit(&st, 10);
    //����һ�����ŵ�ӳ��
    char map[3][2] = { {'(', ')'}, {'[', ']'}, {'{', '}'} };

    //�����ַ���
    while (*s != '\0') {
        //���ҵ�������, ����ջ��, ֱ�����ֵ�һ��������
        //flag  1��ʾ�ҵ���һ��������  0����û�ҵ�
        int falg = 0;
        for (int i = 0; i < 3; i++) {
            //ѭ����������
            if (*s == map[i][0]) {
                falg = 1;
                StackPush(&st, *s);
                s++;
                break;
            }
        }

        //�������ѭ��ֻ�е���һ�������ų��ֵ�ʱ��Ż����
        if (falg == 0) {
            //���ջ�Ƿ�Ϊ��
            if (StackEmpty(&st) == 1) {
                //ջΪ��˵��û���ҵ�������, ֱ�ӷ���false
                return false;
            }
            //ջ��Ϊ��, ��ʼ��������Ƿ�ƥ��
            for (int j = 0; j < 3; j++) {
                //ѭ����������
                if (*s == map[j][1]) {
                    //�ҵ������ź�, ȡ��ջ��Ԫ��, ����Ƿ�ƥ��
                    //ƥ�������, ��ƥ��ֱ�ӷ��� false
                    char top = getStackTop(&st);
                    if (top == map[j][0]) {
                        //����ƥ��, ��ջ������s
                        StackPop(&st);
                        s++;
                        break;
                    }
                    else
                        return false;
                }
            }
        }
    }
    if (StackEmpty(&st) == 1)
        return true;
    else
        return false;
}



int main() {

	system("pause");
	return 0;
}