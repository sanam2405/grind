/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/

vector<vector<int>> ans;
vector<int> in;
vector<int> pre;
vector<int> post;

void Inorder(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        return;
    Inorder(root->left);
    in.push_back(root->data);
    Inorder(root->right);
}

void Preorder(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        return;
    pre.push_back(root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    post.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
            
        ans.clear();
        in.clear();
        pre.clear();
        post.clear();
    
        Inorder(root);
        Preorder(root);
        Postorder(root);
    
        ans.push_back(in);
        ans.push_back(pre);
        ans.push_back(post);
    
        return ans;
}
