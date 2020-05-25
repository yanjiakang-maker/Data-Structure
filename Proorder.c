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

  //��һ�����, ��ȡ������
int getSize(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return getSize(root->left) + getSize(root->right) + 1;
}

//���������idx���ܴ�ֵ, Ҫ��ָ��
//��Ϊ�����ֵ�Ļ�, �ڵݹ�Ĺ����л����Ԫ�ظ��ǵ����
int* preorderT(struct TreeNode* root, int* array, int* idx) {
    if (root == NULL)
        return 0;
    //��ǰ�ڵ�
    array[*idx] = root->val;
    (*idx)++;
    //������
    preorderT(root->left, array, idx);
    //������
    preorderT(root->right, array, idx);
    return array;
}

//ǰ�����
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* array = (int*)malloc(sizeof(int) * getSize(root));
    *returnSize = 0;
    array = preorderT(root, array, returnSize);
    return array;
}

int main() {

    return 0;
}

