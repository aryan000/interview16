#include<iostream>
using namespace std;
#include<queue>
#include<climits>
typedef class BinaryTree btree;



class BinaryTree
{
	public : 
	int data;
	BinaryTree *left;
	BinaryTree *right;

	BinaryTree( int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}

	~BinaryTree()
	{
		if(left) delete left;
		if(right) delete right;
	}
};


btree * takeinput()
{
	int rootdata;
	cin>> rootdata;
	if(rootdata==-1)
		return NULL;
	btree *root = new btree(rootdata);
	queue<btree*> q;
	q.push(root);
	int input;
	while(!q.empty())
	{	
		btree *temp = q.front();
		q.pop();

		cin>> input;
		if(input!=-1)
		{
			btree *left = new btree(input);
			temp->left = left;
			q.push(left);
		}
		cin>> input;
		if(input!=-1)
		{
			btree *right = new btree(input);
			temp->right = right;
			q.push(right);
		}


	}


	return root;
}

vector<btree*> lca(btree*root , int element)
{
	vector<btree*> ans;
	if(root==NULL)
	{
		 return ans;
	}

	if(root->data==element)
	{
		ans.push_back(root);
		return ans;
	}

	vector<btree*> temp = lca(root->left,element);

	if(temp.size()!=0)
	{
		temp.push_back(root);
		return temp;
	}

	temp = lca(root->right,element);

	if(temp.size()!=0)
	{
		temp.push_back(root);

	}
	return temp;

}

// LCA using O(N) extra space and saving the path
btree * getLca(btree *root , int element1 , int element2 )
{
	if(root==NULL)
		return NULL;
	vector<btree*> path1 = lca(root,element1);
	vector<btree*> path2 = lca(root,element2);

	if(path1.size()==0 || path2.size()==0)
		return NULL;
	int i, j;
	 
	// for( i = 0;i<path1.size();i++)
	// 	cout<< path1[i]->data << " ";
	// cout<< endl;


	// for( i = 0;i<path2.size();i++)
	// 	cout<< path2[i]->data << " ";
	// cout<< endl;

	for(i= path1.size()-1,j = path2.size()-1 ;i>=0 && j>=0;i--,j--)
	{	
		// cout<< path1[i]->data << endl;
		// cout<< path2[j]->data << endl;
		if(path1[i]!=path2[j])
			break;
	}

	return path1[i+1];
	
}




int main()
{	
	int a , b;
	cout<<"Enter first and second node data : ";
	 cin>> a >> b;
	btree * root = takeinput();
	 
	 
	btree *temp = getLca(root,a,b);
	cout<< temp->data << endl;
	

}