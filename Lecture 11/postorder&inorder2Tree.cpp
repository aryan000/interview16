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

Tree * create(vector<int> post_order , vector<int> inorder , int a , int b , int c , int d)
{
	// base case
	if(a>b)
		return NULL;

	if(a==b)
	{
		Tree *root = new Tree(post_order[b]);
		return root;
	}

	Tree*root = new Tree(post_order[b]);

	int i ,count=0;
	for(i=c;i<=d;i++)
		{
			if(post_order[b]==inorder[i])
			break;
			count++;
		
	}


	root->left = create(post_order,inorder,a,a+count-1,c,c+count-1);
	root->right = create(post_order,inorder,a+count,b-1,c+count+1,d);	

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
	vector<int> post_order ;
	vector<int> inorder;

	int temp;
	for(int i=0;i<n;i++)
	{
		cin>> temp;
		post_order.push_back(temp);

	}
	for(int i =0;i<n;i++)
	{
		cin>> temp;
		inorder.push_back(temp);
	}
	int a , b , c , d;
	Tree* root = create(post_order,inorder,0,n-1,0,n-1);

	print(root);
}