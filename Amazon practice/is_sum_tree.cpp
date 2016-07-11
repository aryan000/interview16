/*  Tree node
struct Node
{
    int data;
    struct Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false

bool sumtree(struct Node*root , int &sum)
{
    if(root==NULL)
        {
            sum = 0;
            return true;
        }
    
    int ans =0;    
    if(root->left==NULL && root->right==NULL)
    {
        sum = root->data;
        return true;
    }
    bool left = sumtree(root->left,sum);
    ans +=sum;
    bool right = sumtree(root->right,sum);
    ans+= sum;
     
    
    if(root->data ==ans)
    {
        sum = 2*ans;
        return true;
    }
    else
    {
        sum = ans;
        return false;
    }
    
}
bool isSumTree(struct Node* root)
{
     // Your code here
     if(root==NULL)
        return 1;
        int sum=0;
    return sumtree(root,sum);
     
}