#include<iostream>
using namespace std;

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


int long_palin(string str)
{
	int n = str.size();

	int dp[n+1][n+1];
	// Base case
	for(int i =0;i<=n;i++)
		dp[i][i] = 1;


	// dp[i][j] states i se leke j tak longest palindromic subsequence
	for(int j =1;j<=n;j++)
	{
 			if(str[j-1]==str[j])
 				dp[j][j-1] = 1;

 			else dp[j][j-1] = 0;
	}

	for(int i =0;i<=n;i++)
	{
		for(int j =2;j<=n;j++)
		{
			if(str[i]==str[j])
				dp[i][j] = 
		}
	}

}

int main()
{
	string str;
	cin >> str; 

	cout<< length_longest_palin(str,0,str.size()-1);
}