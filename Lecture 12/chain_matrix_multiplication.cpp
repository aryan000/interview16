// Chain Matrix Multiplication 

#include<iostream>
using namespace std;
#include<vector>


int matrix_multiplication(vector<int> p , int i , int j )
{
	if(i==j)
		return 0;

	int count = INT_MAX;
	int temp ; 
	for(int k = i;k<j;k++)
	{	
		temp = matrix_multiplication(p,i,k) + matrix_multiplication(p,k+1,j) + p[i-1]*p[j]*p[k];

		count = min(count,temp);

	}

	return count;
}


int dp_matrix_multiplication(vector<int> p )
{ 

	int n = p.size();
	int dp[n][n];

	// defining dp as dp[i][j] indicated multiplication of matrix A[i]*a[i+1] *.....A[j] = A[i...j]

	// cost of multipling single matrix is : 0
	for(int i =1;i<n;i++)
		dp[i][i] = 0;

	 //cost of multipling matrix of length l
	 for(int l = 2; l<n;l++)
	 {
	 	for(int i = 1;i<=n-l+1;i++)
	 	{
	 		int j = i+l-1;
	 		dp[i][j] = INT_MAX;
	 		int cost;
	 		for(int k = i ; k<j;k++)
	 			{cost = dp[i][k] + dp[k+1][j] + p[i-1]*p[j]*p[k];

	 			//dp[i][j] = min(cost,dp[i][j]);
	 				if(dp[i][j]>cost)
	 					dp[i][j] = cost;
	 			}

	 	}
	 }
	
	return dp[1][n-1];

}

int main()
{
	int n;
	cin>>n;
	vector<int> p;
	int temp;
	for(int i =0;i<n;i++)
	{
		cin>> temp;
		p.push_back(temp);
	}

	// int ans = matrix_multiplication(p,1,p.size()-1);


	int ans = dp_matrix_multiplication(p);
	cout<< ans << endl;
}