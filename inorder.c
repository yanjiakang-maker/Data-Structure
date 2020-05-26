#include<stdio.h>
#include<stdlib.h>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */

  //递归写法与前序大致一样, 只是改变访问顺序
  //获取结点个数
int getSize(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return getSize(root->left) + getSize(root->right) + 1;
}

//中序遍历
int* inorderT(struct TreeNode* root, int* array, int* idx) {
    if (root == NULL)
        return;
    //左子树
    inorderT(root->left, array, idx);
    //结点
    array[*idx] = root->val;
    (*idx)++;
    //右子树
    inorderT(root->right, array, idx);
    return array;
}


int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* array = (int*)malloc(sizeof(int) * getSize(root));
    *returnSize = 0;
    array = inorderT(root, array, returnSize);
    return array;
}