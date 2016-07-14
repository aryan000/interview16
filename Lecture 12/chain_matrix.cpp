#include<iostream>
using namespace std;
#include<vector>

int chain_matrix(vector<int> p , int i , int j)
{
	if(i==j)
		return 0;
	int ans = INT_MAX;
	for(int k = i;k<j;k++)
	{
		int temp = chain_matrix(p,i,k) + chain_matrix(p,k+1,j) + p[i-1]*p[j]*p[k];

		ans = min(temp,ans);
	}

	return ans;
}


///Recursive DP chain matrix multiplication



int main()
{
	int n;
	cin>> n;
	cout<<"Enter the order of matrix : " ;
	vector<int> p;

	int temp;
	for(int i =0;i<n;i++)
	{
	cin>> temp;
	p.push_back(temp);
	}


	int ans = chain_matrix(p,1,p.size()-1);
	cout<< " Chain matrix multiplication using brute force is minimum order is : " << ans << endl;


}