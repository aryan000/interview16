#include<iostream>
using namespace std;

#define set(arr,n) for(int i =0;i<n;i++){for(int j = 0;j<n;j++) arr[i][j] = 0; }
#define print(arr,n) for(int i =0;i<n;i++){for(int j = 0;j<n;j++) cout<< arr[i][j] << " "; cout<< endl; }

// brute force solution 
int length_longest_palin(string str , int i , int j )
{	
	// Base case 

	if(i>j)
		return 0;
	if(i==j)
		return 1;

	if(str[i]==str[j])
		return 2 + length_longest_palin(str,i+1,j-1);

	return max(length_longest_palin(str,i,j-1) , length_longest_palin(str,i+1,j));

}

// optimized solution using dp
int long_palin(string str)
{
	int n = str.size();

	int dp[n][n];
	set(dp,n);
	// Base case ... longest palindrom of length 1
	
	for(int i =0;i<n;i++)
		{dp[i][i] = 1;}


	for(int i =0;i<n-1;i++)
	{
		if(str[i] == str[i+1])
			dp[i][i+1] = 2;

		else dp[i][i+1] = 1;
	}
	// print(dp,n);
	// dp[i][j] represents i se leke j tak ka longest subsequence

	for(int l =2;l<n;l++)
	{	 int i = l;
		for(int j=0;j<n-i;j++)
		{	

			if(str[j]==str[j+i])
				dp[j][j+i] = dp[j+1][j+i-1] + 2;

			else
				dp[j][j+i] = max(dp[j][j+i-1],dp[j+1][j+i]);

		 // cout<< " filling " << j << " and " << j+i << " value " << dp[j][j+i] << endl;
		}
	}

	// print(dp,n);




	return dp[0][n-1];

}

int main()
{
	string str;
	cin >> str; 

	// cout<< length_longest_palin(str,0,str.size()-1);
	cout<< long_palin(str) << endl;
}