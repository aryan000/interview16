/* Node structure
struct Node
{
    int data;
    struct Node* left, *right;
}; */

/* Given two trees, should return true if they are
   mirror of each other. */
int areMirror(Node* a, Node* b)
{
   // Your code here
   if(a==NULL && b==NULL)
   return 1;
   
   if(!(a&&b))
   return false;
   
   if(a->data==b->data)
   {
       return areMirror(a->left,b->right) && areMirror(a->right,b->left);
   }
   else return false;
}
