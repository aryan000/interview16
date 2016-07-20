#include<iostream>
using namespace std;
#define loop(x,n) for(x=0;x<n;x++)

int lcs(string s , string t)
{
	if(s.size()==0 || t.size()==0)
		return 0;

	int m = s.size();
	int n = t.size();

	int dp[m+1][n+1];

	// dp[i][j] means lcs between starting i charachers of s and starting j characters of t

	int i , j;
	 

	for( i =0;i<=m;i++)
		for( j =0;j<=n;j++)
			 {		
			 	if(i==0 || j==0)
			 		dp[i][j] = 0; 

			 	else if(s[i-1] == t[j-1])
			 		dp[i][j] = 1+ dp[i-1][j-1];

			 	else
			 		dp[i][j] =  max(dp[i][j-1],dp[i-1][j]);

			 }


	/*loop(i,m)
	{
		loop(j,n)
		 cout<< dp[i][j] << " ";
		 cout<< endl;
	} 
	*/
return dp[m][n] ;

}

int main()
{
	string s , t;

	cin>> s >> t;

	cout<< lcs(s,t) << endl;
}