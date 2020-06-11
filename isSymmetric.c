#include<stdio.h>
#include<stdbool.h>


//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


bool isSy(struct TreeNode* p, struct TreeNode* q) {
    //ͬʱΪ��˵���ṹ��ͬ
    if (p == NULL && q == NULL)
        return true;
    //��ͬʱΪ��˵���ṹ��ͬ
    if (p == NULL || q == NULL)
        return false;
    //��Ӧλ�õ�ֵ�Լ������Ƿ���ͬ
    return p->val == q->val
        && isSy(p->left, q->right)
        && isSy(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
        return true;
    return isSy(root->left, root->right);
    //ֱ�Ӹ���Ҳ�ǿ��Ե�
    // return isSy(root, root);
}