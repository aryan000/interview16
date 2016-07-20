#include<iostream>
using namespace std;
#define loop(x,n) for(int x = 0;x<n;x++)


int small(int a , int b , int c)
{
	return min(a,min(b,c));
}

int edit_distance_dp(string s , string t)
{	
	// base case 
		int m = s.size();
		int n = t.size();
	int dp[m+1][n+1]  ;
		// dp[i][j] is defined as 0 to i and 0 to j  tak me edit distance kya hai
	int i , j;
	
	for(int i =0;i<=m ; i++)
	{
		for(int j =0;j<=n;j++)
		{		
			if(i==0)
				dp[i][j] = j; // insert j element
			else if(j==0)
				dp[i][j] = i; // insert i element

			else if(s[i-1]==t[j-1])
				{  dp[i][j] = dp[i-1][j-1]; }
			else 
				dp[i][j] = 1 + small(dp[i-1][j-1],dp[i][j-1],dp[i-1][j]);
		}
	}

	
	 
	return dp[m][n];
}



int main()
{
	string s , t;
	cin>> s >> t;

	cout<< edit_distance_dp(s,t) << endl;
}