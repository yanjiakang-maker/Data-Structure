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
    //Ҷ�ӽڵ�Ͳ��÷�ת��
    if (root->left == NULL && root->right == NULL)
        return;
    //��ת��ǰ�ڵ�����Һ���
    struct TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    //���������ߵݹ鷭ת����
    reverseT(root->left);
    reverseT(root->right);
}


struct TreeNode* invertTree(struct TreeNode* root) {
    reverseT(root);
    return root;
}