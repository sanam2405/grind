/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
            vector<int> ans;
            if(root==NULL)
                return ans;
            queue<BinaryTreeNode<int>*> q;
    
            q.push(root);
            
            while(!q.empty())
            {
                int size = q.size();
                while(size--)
                {
                    BinaryTreeNode<int>* current = q.front();
                    q.pop();
                    ans.push_back(current->val);
                    if(current->left)
                        q.push(current->left);
                    if(current->right)
                        q.push(current->right);
                }
            }
    
            return ans;
}
