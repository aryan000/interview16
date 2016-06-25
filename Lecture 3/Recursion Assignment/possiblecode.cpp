/*
Assume that value of a=1, b=2, c=3, d=4, .... z=26. You are given a numeric string
S. Write a program to find and print list of all possible codes that can be generated
from the given string. E.g. 1123 aabc, kbc, alc, aaw, kw
*/



#include<iostream>
using namespace std;
#include<string>
#include<stdio.h>

void find(int n, string str )
{	
	if(n==0)
		{
			if(str.size()) cout<< str << endl;
			return;
		}
	if(n<0) return;

	char ch = char(n%10 +'a' -1);
	find(n/10,ch+str);

     
	char ch1 = char(n%100  + 'a' - 1);
	if(ch1>='a' && ch1<='z' && ch1!=ch)
	find(n/100, ch1+str);
	
}

int main()
{
	int n;

	cout<<"Enter the number : ";
	cin>>n;
	find(n,"");

}


