#include<iostream>
using namespace std;
#include<queue> 

typedef class BinaryTree btree;

class BinaryTree
{
public : 
 int data;
 BinaryTree *left;
 BinaryTree *right;

  BinaryTree( int data)
  { this->data = data;
  	 left = NULL;
  	 right  = NULL;

  }

  ~BinaryTree()
  {
  	if(left)
  		delete left;
  	if(right)
  		delete right;
  }
};


btree *takeinput()
{
	int n;
	cin>> n;
	if(n==-1)
		return NULL;

	btree *root = new btree(n);
	queue<btree*> q;
	q.push(root);
	while(!q.empty())
	{
		int temp;
		btree *first = q.front();
		q.pop();
		cin>> temp;

		if(temp!=-1)
		{
			btree *left = new btree(temp);
			first->left = left;
			q.push(left);
		}

		cin>> temp;
		if(temp!=-1)
		{
			btree *right = new btree(temp);
			first->right = right;
			q.push(right);
		}
	}


	return root;
}

void print(vector<int> v)
{
	for(int i = v.size()-1;i>=0;i--)
		cout<< v[i] << " ";
	cout<< endl;
}

vector<vector<int> > path_sum_root_to_leaf(btree *root , int k )
{
	if(root==NULL)
	{
		vector<vector<int> > ans;
		return ans;
	}

	vector<vector<int> > left = path_sum_root_to_leaf(root->left , k-root->data);
	 vector<vector<int> >right = path_sum_root_to_leaf(root->right , k-root->data);
 	
 	vector<vector<int> > ans;

 	vector<int> tmep;
 	 if(root->data ==k)
 	 {
 	 	 	tmep.push_back(root->data);

 	 	ans.push_back(tmep);
 	 	return ans;
 	 }

 	 if(left.size())
 	 { for(int i = 0 ; i<left.size();i++)
 	 	 {left[i].push_back(root->data);
 	 	 	ans.push_back(left[i]);
 	 	 }


 	 }
 	  
 	 if(right.size() )
 	 {
 	 	for(int i =0;i<right.size();i++)
 	 		{right[i].push_back(root->data);
 	 			ans.push_back(right[i]);
 	 		}
 	 }
 	 return ans;



	



}

int main()
{	
	int k ;
	cin>> k;
	btree *root = takeinput();

	// cout<<"receiving input";?
	vector<vector<int> > ans = path_sum_root_to_leaf(root,k);

	if(ans.size()==0)
		cout<<"-1\n";

	else
	{
		for(int i =0;i<ans.size();i++)
			print(ans[i]);
	}
}