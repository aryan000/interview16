#include<iostream>
using namespace std;
#include<vector>
#include<queue>

class BST
{
	public : 
	int data;
	BST*left;
	BST *right;

	 BST(int data)
	 {
	 	this->data = data;
	 	left = NULL;
	 	right = NULL;
	 }

	 ~BST()
	 {
	 	if(left)
	 		delete left;
	 	if(right)
	 		delete right;

	 }
	
};


BST * create_bst(vector<int> arr , int start , int end)
{
	if(start>end)
		return NULL;

	int mid = (start+end)/2;

	BST* root = new BST(arr[mid]);
	root->left = create_bst(arr,start,mid-1);
	root->right = create_bst(arr,mid+1,end);

	return root;
}

void print(BST *root)
{
	if(root==NULL)
		return;
	queue<BST*> q;

	q.push(root);
	int current_level = 1;
	int next_level = 0;

	while(!q.empty())
	{
		BST *temp = q.front();
		q.pop();
		cout<< temp->data << " ";

		if(temp->left)
			{q.push(temp->left); next_level++;}
		if(temp->right)
			{q.push(temp->right); next_level++;}

		current_level--;
		if(current_level==0)
		{
			current_level = next_level;
			next_level = 0;
			cout<< endl;
		}
	}

	cout<< endl;
}
int main()
{
	int n;
	cin>> n;
	vector<int> arr; int temp;
	for(int i =0;i<n;i++)
	{
		cin>> temp;
		arr.push_back(temp);
	}

	BST *root = create_bst(arr,0,arr.size()-1);
	print(root);
}