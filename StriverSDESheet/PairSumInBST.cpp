/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
vector<int> all;

void helper(BinaryTreeNode<int> *root)
{
    if(root==NULL)
        return;
    helper(root->left);
    all.push_back(root->data);
    helper(root->right);
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    all.clear();
    helper(root);
    
    int low = 0, high = all.size()-1;
    
    while(low < high)
    {
        if(all[low]+all[high] > k)
            high--;
        else if(all[low]+all[high] < k)
            low++;
        else
            return true;
    }
    
    return false;
}
