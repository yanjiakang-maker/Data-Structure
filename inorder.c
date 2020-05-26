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

  //�ݹ�д����ǰ�����һ��, ֻ�Ǹı����˳��
  //��ȡ������
int getSize(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return getSize(root->left) + getSize(root->right) + 1;
}

//�������
int* inorderT(struct TreeNode* root, int* array, int* idx) {
    if (root == NULL)
        return;
    //������
    inorderT(root->left, array, idx);
    //���
    array[*idx] = root->val;
    (*idx)++;
    //������
    inorderT(root->right, array, idx);
    return array;
}


int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* array = (int*)malloc(sizeof(int) * getSize(root));
    *returnSize = 0;
    array = inorderT(root, array, returnSize);
    return array;
}