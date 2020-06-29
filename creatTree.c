#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    struct Node* left;
    struct Node* right;
    char val;
}Node;


//给一个字符数组和索引
Node* CreatTree(char* str, int* idx)
{
    if (str[*idx] != '#')
    {
        Node* root = (Node*)malloc(sizeof(Node));
        root->val = str[*idx];
        (*idx)++;
        root->left = CreatTree(str, idx);
        (*idx)++;
        root->right = CreatTree(str, idx);
        return root;
    }
    else
        return NULL;
}


//中序遍历
void inorder(Node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%c ", root->val);
    inorder(root->right);
}


int main()
{
    char str[101] = { 0 };
    scanf("%s", str);
    int idx = 0;
    Node* root = CreatTree(str, &idx);
    inorder(root);
    printf("\n");
    return 0;
}



