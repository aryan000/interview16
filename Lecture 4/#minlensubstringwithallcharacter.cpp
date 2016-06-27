/*
Given two strings S  and T. Write a function that returns the minimum length substring in S which contains all characters in T. 

Example: 
S: “this is a test string” 
T: “tist” 
Output String: “t stri” 
*/

#include<iostream>
using namespace std;
#include<map>
#include<string>


void find(string s , string t)
{

	map<char,int> required ;
	for(int i =0;i<t.size();i++)
	{
		if(required.count(t[i])==1)
			required[t[i]] +=1;

		else required[t[i]] = 1;
	}

	int startindex = 0 , endindex = 0 , tempstart = 0 , tempend = 0 , maxsize = 0 , tempsize = 0;

	for(int i =0;i<s;i++)
	{
		
	}
}

int main()
{	
	string s , t;
	cout<<"Enter the string 1st : ";
	cin>> s;

	cout<<"Enter the other string : ";
	cin>> t;

	find(s,t);


	return 0;

}