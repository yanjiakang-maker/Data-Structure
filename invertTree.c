#include<stdio.h>


//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


void reverseT(struct TreeNode* root) {
    if (root == NULL)
        return;
    //叶子节点就不用翻转了
    if (root->left == NULL && root->right == NULL)
        return;
    //翻转当前节点的左右孩子
    struct TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    //继续向下走递归翻转子树
    reverseT(root->left);
    reverseT(root->right);
}


struct TreeNode* invertTree(struct TreeNode* root) {
    reverseT(root);
    return root;
}