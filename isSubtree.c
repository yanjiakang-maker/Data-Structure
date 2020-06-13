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

bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
    //任何树都包含空树
    if (t == NULL)
        return true;
    //空树不包含任何非空树
    if (s == NULL)
        return false;
    if (isSameTree(s, t) == true)
        return true;
    //左右子树只要有一个与t结构相同即可
    return isSubtree(s->left, t) || isSubtree(s->right, t);

}