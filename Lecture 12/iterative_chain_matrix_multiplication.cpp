#include<iostream>
using namespace std;
#include<vector>
#include<climits>

int iterative_chain_matrix_multiplication(vector<int> p)
{

	int n = p.size();
	int dp[n][n];
	//dp[i][j] represents cost of multiplying  matrices A[i]*A[i+1]*.......A[j] = A[i...j]

	// cost of multiplying single matrix is : 0
	for(int i =1;i<n;i++)
		dp[i][i] = 0;

	// cost of multiplying matrix of size l
	for(int l =2;l<n;l++)
	{
		for(int i = 1;i<=n-l+1;i++)
		{
			int j = i+l-1;
			dp[i][j]  = INT_MAX;
			int temp ;
			for(int k =i;k<j;k++)
			{	
				temp = dp[i][k] + dp[k+1][j] + p[i-1]*p[j]*p[k];

				if(temp<dp[i][j])
					dp[i][j] = temp;

			}
		}
	}


	return dp[1][n-1];
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

	cout<< iterative_chain_matrix_multiplication(p) << endl;


	return 0;
}