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

  //��ȡ������
int getSize(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return getSize(root->left) + getSize(root->right) + 1;
}

//�������
int* postorderT(struct TreeNode* root, int* array, int* idx) {
    if (root == NULL)
        return 0;
    //������
    postorderT(root->left, array, idx);
    //������
    postorderT(root->right, array, idx);
    //���
    array[*idx] = root->val;
    (*idx)++;
    return array;
}


int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* array = (int*)malloc(sizeof(int) * getSize(root));
    *returnSize = 0;
    array = postorderT(root, array, returnSize);
    return array;
}