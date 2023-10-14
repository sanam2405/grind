/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

int ans = -1;
int cnt = 0;
int K;
void helper(TreeNode<int>* root)
{
    if(root==NULL)
        return;
    helper(root->right);
    cnt++;
    if(cnt==K)
        ans = root->data;
    helper(root->left);
    
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    K=k;
    ans = -1;
    cnt = 0;
    helper(root);
    return ans;
}
