#include<stdio.h>
#include<stdlib.h>

 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };


   //第一种写法
 int Max(int a, int b) {
     if (a > b)
         return a;
     else
         return b;
 }

 int getH(struct TreeNode* root) {
     if (root == NULL)
         return 0;
         int maxH = Max(getH(root->left), getH(root->right));
     return  maxH + 1;
 }

 int maxDepth(struct TreeNode* root){
     return getH(root);
 }



   //第二种写法
 //把二叉树看成是 根 左子树 右子树 三部分
 //深度 = 左右子树中较大的深度 + 1
int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    //左子树深度
    int llen = maxDepth(root->left);
    //右子树深度
    int rlen = maxDepth(root->right);
    //返回二叉树深度 + 1
    return llen > rlen ? llen + 1 : rlen + 1;
}






