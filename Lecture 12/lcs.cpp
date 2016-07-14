#include<iostream>
using namespace std;
#include<string.h>

// This is recursive solution and exponential 
int lcs(string s , string t  ,  int sindex , int tindex)
{
  if(s.empty() || t.empty() || sindex>=s.size() || tindex>=t.size())
  	return 0;

  if(s[sindex]==t[tindex])
  	{ 	
  		return 1 + lcs(s,t, sindex+1,tindex+1);
  	}

  return max(lcs(s,t, sindex+1,tindex), lcs(s,t ,sindex,tindex+1));
}

// Optimized O(n^2) solution 
int dplcs(string s , string t, string&ans,   int sindex, int tindex , int **output)
{
	 
	if(output[sindex][tindex]!=-1)
		return output[sindex][tindex];

	if(s.size()==0 || t.size()==0 || sindex>=s.size() || tindex>=t.size())
		{ 	
			output[sindex][tindex] = 0;
			return 0;
		}

	if(s[sindex]==t[tindex])
	{
		 ans += s[sindex];
		output[sindex][tindex] = 1 + dplcs(s,t,ans ,sindex+1,tindex+1,output);
		return output[sindex][tindex];
	}

	output[sindex][tindex] = max(dplcs(s,t,ans, sindex+1,tindex,output) , dplcs(s,t,ans, sindex,tindex+1,output));

	return output[sindex][tindex];



}

int main()
{
	string s , t;
	cin>> s >> t; 
	string ans;
	int row ;
	row =  s.size()+1;
	int col;
	col = t.size()+1;
	int **output = new int*[row+1];
	for(int i =0;i<=row ;i++)
	{
		output[i] = new int[col+1];	

	}

	for(int i =0;i<=row ; i++)
	{
		for(int j = 0;j<=col;j++)
		{	output[i][j] = -1;
		}
	}

	int len = dplcs(s,t,ans, 0,0 , output); 


	cout<< " THe lcs of the two string is :"<< ans << "  and length is : " << len << endl;

	
return 0;

}