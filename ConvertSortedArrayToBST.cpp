#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

TreeNode<int>* constructBST(int left, int right, vector<int> &arr)
{

    if(left > right)
    return NULL;

    int mid = left+(right-left)/2;
    TreeNode<int>* currentRoot = new TreeNode<int> (arr[mid]);

    currentRoot->left = constructBST(left,mid-1,arr);
    currentRoot->right = constructBST(mid+1,right,arr);

    return currentRoot;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    TreeNode<int> *BSTRoot;

    BSTRoot = constructBST(0,n-1,arr);

    return BSTRoot;
}
