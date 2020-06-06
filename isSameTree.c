#include<stdio.h>
#include<stdbool.h>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};



bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    //同时为空说明结构相同
    if (p == NULL && q == NULL)
        return true;
    //不同时为空说明结构不同
    if (p == NULL || q == NULL)
        return false;
    //对应位置的值以及子树是否相同
    return p->val == q->val
        && isSameTree(p->left, q->left)
        && isSameTree(p->right, q->right);
}