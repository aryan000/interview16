/* Naive pattern searching algorithm */

#include<iostream>
using namespace std;
#include<stdio.h>

// Complexity of this solution is o(m*n) where m is size of first and n is size of second

bool check (string s , string t , int i )
{
	for(int j =0;j<t.size();j++)
		if(s[i+j]!=t[j])
			return false;

	return true;
}

void search_substring(string s , string t)
{	
	bool flag = false;

	for(int i =0;i<s.size()-t.size();i++)
	{
		if(s[i]==t[0])
			{ bool ans = check(s , t , i);
				if(ans)
					{cout<< "Pattern found at index :  " << i << endl;
				 	flag = true;
				 }

			}
	}

	if(flag==0)
		cout<<"Pattern not found : ";
}



int main()
{
	string s , t;
	 getline(cin,s);
	 getline(cin,t);


	search_substring(s,t);
}