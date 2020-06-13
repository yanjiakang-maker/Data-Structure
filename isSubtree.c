#include<stdio.h>
#include<stdbool.h>


//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};



bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    //ͬʱΪ��˵���ṹ��ͬ
    if (p == NULL && q == NULL)
        return true;
    //��ͬʱΪ��˵���ṹ��ͬ
    if (p == NULL || q == NULL)
        return false;
    //��Ӧλ�õ�ֵ�Լ������Ƿ���ͬ
    return p->val == q->val
        && isSameTree(p->left, q->left)
        && isSameTree(p->right, q->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
    //�κ�������������
    if (t == NULL)
        return true;
    //�����������κηǿ���
    if (s == NULL)
        return false;
    if (isSameTree(s, t) == true)
        return true;
    //��������ֻҪ��һ����t�ṹ��ͬ����
    return isSubtree(s->left, t) || isSubtree(s->right, t);

}