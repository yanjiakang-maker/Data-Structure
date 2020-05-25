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

  //第一遍遍历, 获取结点个数
int getSize(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return getSize(root->left) + getSize(root->right) + 1;
}

//这里的索引idx不能传值, 要传指针
//因为如果传值的话, 在递归的过程中会产生元素覆盖的情况
int* preorderT(struct TreeNode* root, int* array, int* idx) {
    if (root == NULL)
        return 0;
    //当前节点
    array[*idx] = root->val;
    (*idx)++;
    //左子树
    preorderT(root->left, array, idx);
    //右子树
    preorderT(root->right, array, idx);
    return array;
}

//前序遍历
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* array = (int*)malloc(sizeof(int) * getSize(root));
    *returnSize = 0;
    array = preorderT(root, array, returnSize);
    return array;
}

int main() {

    return 0;
}

