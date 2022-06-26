/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int rec(TreeNode<int> *root, int &ans)
{
    if(root==NULL)
        return 0;
    int left = rec(root->left,ans);
    int right = rec(root->right,ans);
    ans = max(ans,left+right);
    return 1+max(left,right);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
	int ans;
    rec(root,ans);
    return ans;
}
