#include<stdio.h>
#include<stdbool.h>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};



bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    //ͬʱΪ��˵���ṹ��ͬ
    if (p == NULL && q == NULL)
        return true;
    //��ͬʱΪ��˵���ṹ��ͬ
    if (p == NULL || q == NULL)
        return false;
    //��Ӧλ�õ�ֵ�Լ������Ƿ���ͬ
    return p->val == q->val
        && isSameTree(p->left, q->left)
        && isSameTree(p->right, q->right);
}