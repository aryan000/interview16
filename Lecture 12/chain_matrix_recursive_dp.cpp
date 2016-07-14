#include<iostream>
using namespace std;
#include<vector>


int recursive_chain_matrix(vector<int> p , int i , int j , int**output)
{
	if(output[i][j]!=0)
		return output[i][j];

	if(i==j)
	{
		return 0;
	}

	int ans = INT_MAX;
	int temp;
	for(int k = i;k<j;k++)
	{	
		temp = recursive_chain_matrix(p,i,k,output) + recursive_chain_matrix(p,k+1,j,output) + p[i-1]*p[j]*p[k];
		if(ans>temp)
			ans = temp;

	}
	output[i][j] = ans;

	return ans;




}


int main()
{
	int n;
	cin>> n;
	vector<int> p;
	int temp;

	for(int i =0;i<n;i++)
	{
		cin>> temp;
		p.push_back(temp);
	}

	int **output  = new int*[n];
	for(int i =0;i<n;i++)
	{
		output[i] = new int[n];
		for(int j =0;j<n;j++)
			output[i][j] = 0;
	}

	int ans = recursive_chain_matrix(p,1,p.size()-1,output);

	cout<< " Required answer is : " << ans << endl;
}