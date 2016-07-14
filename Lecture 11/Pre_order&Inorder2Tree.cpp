#include<iostream>
using namespace std;
#include<vector>
#include<queue>


class Tree
{
	public :
	int data;
	Tree*left;
	Tree*right;


	Tree(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

Tree * create(vector<int> pre_order , vector<int> inorder , int a , int b , int c , int d)
{
	// base case
	if(a>b)
		return NULL;

	if(a==b)
	{
		Tree *root = new Tree(pre_order[a]);
		return root;
	}

	Tree*root = new Tree(pre_order[a]);

	int i ,count=0;
	for(i=c;i<=d;i++)
		{
			if(pre_order[a]==inorder[i])
			break;
		count++;
	}

	root->left = create(pre_order,inorder,a+1,a+count,c,i-1);
	root->right = create(pre_order,inorder,a+count +1,b,i+1,d);	

	return root;
}
	

void print(Tree *root)
{
	if(root==NULL)
		return;

	queue<Tree*> q;
	q.push(root);
	int current_level = 1;
	int next_level = 0;

	while(!q.empty())
	{
		Tree*temp = q.front();
		q.pop();

		if(temp->left)
		{
			next_level++;
			q.push(temp->left);
		}
		if(temp->right)
		{
			next_level++;
			q.push(temp->right);
		}

		cout<< temp->data << " ";

		current_level--;
		if(current_level==0)
		{
			current_level = next_level;
			next_level = 0;
			cout<< endl;
		}
	}



	return;
}

int main()
{
	int n;
	cin>> n;
	vector<int> pre_order ;
	vector<int> inorder;

	int temp;
	for(int i=0;i<n;i++)
	{
		cin>> temp;
		pre_order.push_back(temp);

	}
	for(int i =0;i<n;i++)
	{
		cin>> temp;
		inorder.push_back(temp);
	}
	int a , b , c , d;
	Tree* root = create(pre_order,inorder,0,n-1,0,n-1);

	print(root);
}