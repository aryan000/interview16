#include<iostream>
using namespace std;
#include<queue>

class btree
{
	public : 
	int data;
	btree *left;
	btree *right;

	btree(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

btree *takeinput()
{
	int n ;
	cin>> n;
	if(n==-1)
		return NULL;
	btree *root = new btree(n);
	queue<btree*> q;
	q.push(root);
	while(!q.empty())
	{
		btree *first = q.front();
		q.pop();
		cin>> n;
		if(n!=-1)
		{
			btree *left = new btree(n);
			first->left = left;
			q.push(left);
		}
		cin>> n;
		if(n!=-1)
		{
			btree*right  = new btree(n);
			first->right = right;
			q.push(right);
		}
	}

	return root;
} 

int find_best_sum(btree *root , bool can_include = true)
{
	if(root==NULL)
		return 0;


	if(!can_include)
		return find_best_sum(root->left,true) + find_best_sum(root->right,true);

	else 
	{
		int ans1 = find_best_sum(root->left,true) + find_best_sum(root->right,true);
		int ans2 = root->data + find_best_sum(root->left,false) + find_best_sum(root->right,false);

		return max(ans2,ans1);

	}
}
int main()
{	
	btree *root = takeinput();
	cout<< find_best_sum(root) << endl;

}
