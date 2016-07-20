#include<iostream>
using namespace std;
#include<cstring>
#include<vector> 
/*
// recursive  solution with exponential time complexity
int edit_distance(string s , string t , int sindex , int tindex)
{
	// Base case ... used to insert

	if(s.size()==sindex)
	{
		return t.size()-tindex;
	}

	if(tindex==t.size())
	{
		return s.size()-sindex;
	}


	if(s[sindex]==t[tindex])
	{
		// no change
		return edit_distance(s,t,sindex+1,tindex+1);

	}

	int ans1 = edit_distance(s,t,sindex+1,tindex+1) ; // replace;
	int ans2 = edit_distance(s,t,sindex,tindex+1);  // insert in s
	int ans3 = edit_distance(s,t,sindex+1,tindex);  // delete from s

	return 1+ min(ans3,min(ans2,ans1));

}

//recursive solution with exponential time complexity
int edit_distance(char * s , char* t  )
{
	// Base case ... used to insert

	 if(s[0]=='\0')
	 	return strlen(t);
	 if(t[0]=='\0')
	 	return strlen(s);

	if(s[0]==t[0])
	{
		// no change
		return edit_distance(s+1,t+1);

	}

	int ans1 = edit_distance(s+1,t+1) ; // replace;
	int ans2 = edit_distance(s ,t+1);  // insert in s
	int ans3 = edit_distance(s+1,t);  // delete from s

	return 1 + min(ans3,min(ans2,ans1));

}

*/

// optimised dp solution 
int edit_distancedp(string s , string t , int sindex , int tindex , vector<vector<int> > dp)
{
	// Base case ... used to insert
	
	if( sindex == s.size())
	{	
		dp[sindex][tindex] =t.size()-tindex;
		return dp[sindex][tindex];
	}

	if(tindex==t.size())
	{	dp[sindex][tindex]=  s.size()-sindex;
		return dp[sindex][tindex];
	}

	if(dp[sindex][tindex]!=0)
		return dp[sindex][tindex];
	
	if(s[sindex]==t[tindex])
	{
		// no change
		dp[sindex][tindex] = edit_distancedp(s,t,sindex+1,tindex+1,dp);
		return dp[sindex][tindex];

	}

	int ans1 = edit_distancedp(s,t,sindex+1,tindex+1,dp) ; // replace;
	int ans2 = edit_distancedp(s,t,sindex,tindex+1,dp);  // insert in s
	int ans3 = edit_distancedp(s,t,sindex+1,tindex,dp);  // delete from s

	dp[sindex][tindex]= 1+ min(ans3,min(ans2,ans1));
	return dp[sindex][tindex];

}





int main()
{
	string s , t;
	cin>> s;
	cin>> t;
	vector<vector<int> > dp;
	for(int i =0;i<s.size()+1;i++)
	{ vector<int> temp;
		for(int j =0;j<t.size()+1;j++)
			temp.push_back(0);
		dp.push_back(temp);
	}
	// cout<<"Edit distance is : " << edit_distancedp(s,t,0,0,dp);
	cout<< edit_distancedp(s,t,0,0,dp) << endl;

}