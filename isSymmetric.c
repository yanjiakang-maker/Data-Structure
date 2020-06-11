#include<stdio.h>
#include<stdbool.h>


//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


bool isSy(struct TreeNode* p, struct TreeNode* q) {
    //同时为空说明结构相同
    if (p == NULL && q == NULL)
        return true;
    //不同时为空说明结构不同
    if (p == NULL || q == NULL)
        return false;
    //对应位置的值以及子树是否相同
    return p->val == q->val
        && isSy(p->left, q->right)
        && isSy(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
        return true;
    return isSy(root->left, root->right);
    //直接给根也是可以的
    // return isSy(root, root);
}