#include<stdio.h>
#include<stdbool.h>


//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};



bool order(struct TreeNode* root, int key) {
    //�ߵ�Ҷ��, ������
    if (root == NULL)
        return true;
    
    //�ݹ�, ֻҪ��һ�����ֵ������key ���Ǽ�
    //ʵ�ʾ��Ǹ�ǰ�����
    return  root->val == key
        && order(root->left, key)
        && order(root->right, key);
}


bool isUnivalTree(struct TreeNode* root) {
    return order(root, root->val);
}