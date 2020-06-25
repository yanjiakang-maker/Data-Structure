#include<stdio.h>
#include<stdbool.h>


//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


//获取结点的高度
int getH(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    int l = getH(root->left);
    int r = getH(root->right);
    return l > r ? l + 1 : r + 1;
}

bool isBalanced(struct TreeNode* root) {
    //遍历树的结点,
    if (root == NULL)
        return true;
    int lh = getH(root->left);
    int rh = getH(root->right);
    //保证当前结点的左右子树高度之差不大于1, 然后遍历整棵树
    return abs(lh - rh) < 2
        && isBalanced(root->left)
        && isBalanced(root->right);
}