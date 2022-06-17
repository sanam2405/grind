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

vector<int> leftView;

void rec(TreeNode<int>* root, int level)
{
    if(root==NULL)
        return;
    
    if(leftView.size()==level)
        leftView.push_back(root->data);
    
    rec(root->left,level+1);
    rec(root->right,level+1);
}
vector<int> getLeftView(TreeNode<int> *root)
{
        leftView.clear();
        rec(root,0);
        return leftView;
}
