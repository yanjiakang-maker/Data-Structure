#include<stdio.h>
#include<stdlib.h>

 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };


   //��һ��д��
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



   //�ڶ���д��
 //�Ѷ����������� �� ������ ������ ������
 //��� = ���������нϴ����� + 1
int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    //���������
    int llen = maxDepth(root->left);
    //���������
    int rlen = maxDepth(root->right);
    //���ض�������� + 1
    return llen > rlen ? llen + 1 : rlen + 1;
}






