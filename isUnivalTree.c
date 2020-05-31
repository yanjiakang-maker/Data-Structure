#include<stdio.h>
#include<stdbool.h>


//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};



bool order(struct TreeNode* root, int key) {
    //走到叶子, 返回真
    if (root == NULL)
        return true;
    
    //递归, 只要有一个结点值不等于key 就是假
    //实际就是个前序遍历
    return  root->val == key
        && order(root->left, key)
        && order(root->right, key);
}


bool isUnivalTree(struct TreeNode* root) {
    return order(root, root->val);
}