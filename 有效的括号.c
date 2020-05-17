#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef char DataType;

typedef struct Stack {
    DataType* arr;
    int size;
    int capacity;
}Stack;


//初始化
void StackInit(Stack* st, int n) {
    //创建一个n个元素的栈
    st->size = 0;
    st->capacity = n;
    st->arr = (DataType*)malloc(sizeof(DataType) * n);
}


//进栈
void StackPush(Stack* st, DataType data) {
    //插入时先检查栈是否已满
    if (st->size >= st->capacity) {
        //扩容
        st->capacity += st->capacity;
        st->arr = (DataType*)realloc(st->arr, st->capacity * sizeof(DataType));
    }
    //尾插
    st->arr[st->size] = data;
    st->size++;
}


//出栈
void StackPop(Stack* st) {
    if (st->size == 0) {
        //空栈, 删除失败
        return;
    }
    //尾删
    st->size--;
}


//得到栈顶元素
DataType getStackTop(Stack* st) {
    return st->arr[st->size - 1];
}


//得到栈的大小
int getStackSize(Stack* st) {
    return st->size;
}


//判空
int StackEmpty(Stack* st) {
    if (st->size == 0) {
        return 1;
    }
    return 0;
}


//销毁
void StackDestory(Stack* st) {
    free(st->arr);
    st->arr = NULL;
    st->capacity = 0;
    st->size = 0;
}



bool isValid(char* s) {
    Stack st;
    StackInit(&st, 10);
    //创建一个括号的映射
    char map[3][2] = { {'(', ')'}, {'[', ']'}, {'{', '}'} };

    //遍历字符串
    while (*s != '\0') {
        //先找到左括号, 放入栈中, 直到出现第一个右括号
        //flag  1表示找到了一个左括号  0代表没找到
        int falg = 0;
        for (int i = 0; i < 3; i++) {
            //循环找左括号
            if (*s == map[i][0]) {
                falg = 1;
                StackPush(&st, *s);
                s++;
                break;
            }
        }

        //下面这个循环只有当第一个右括号出现的时候才会进入
        if (falg == 0) {
            //检查栈是否为空
            if (StackEmpty(&st) == 1) {
                //栈为空说明没有找到左括号, 直接返回false
                return false;
            }
            //栈不为空, 开始检查括号是否匹配
            for (int j = 0; j < 3; j++) {
                //循环找右括号
                if (*s == map[j][1]) {
                    //找到右括号后, 取出栈顶元素, 检查是否匹配
                    //匹配则继续, 不匹配直接返回 false
                    char top = getStackTop(&st);
                    if (top == map[j][0]) {
                        //括号匹配, 出栈并更新s
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