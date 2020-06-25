#include<stdio.h>
#include<stdbool.h>


//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


//��ȡ���ĸ߶�
int getH(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    int l = getH(root->left);
    int r = getH(root->right);
    return l > r ? l + 1 : r + 1;
}

bool isBalanced(struct TreeNode* root) {
    //�������Ľ��,
    if (root == NULL)
        return true;
    int lh = getH(root->left);
    int rh = getH(root->right);
    //��֤��ǰ�������������߶�֮�����1, Ȼ�����������
    return abs(lh - rh) < 2
        && isBalanced(root->left)
        && isBalanced(root->right);
}