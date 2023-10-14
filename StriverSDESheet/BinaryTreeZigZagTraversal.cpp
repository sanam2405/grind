/*************************************************************

    Following is the Binary Tree node structure

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

*************************************************************/
#include<bits/stdc++.h>
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
            vector<int> ans;
            if(root==NULL)
                return ans;
            queue<BinaryTreeNode<int>*> q;
            q.push(root);
            
            int parity = 0;
            while(!q.empty())
            {
                int size = q.size();
                vector<int> currentLevel;
                while(size--)
                {
                    BinaryTreeNode<int>* current = q.front();
                    q.pop();
                    currentLevel.push_back(current->data);
                    if(current->left)
                        q.push(current->left);
                    if(current->right)
                        q.push(current->right);
                }
                
                if(parity&1)
                    reverse(currentLevel.begin(),currentLevel.end());
                for(int i = 0; i < currentLevel.size(); i++)
                    ans.push_back(currentLevel[i]);
                parity++;
            }
    
            return ans;
}
