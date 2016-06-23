/*
Suppose you have a string made up of only
the letters 'a' and 'b'. Write a recursive
function that checks if the string was
generated using the following rules:
a) the string begins with an 'a'
b) each 'a' is followed by nothing or an 'a' or
"bb"
c) each "bb" is followed by nothing or an 'a’
*/

#include<iostream>
using namespace std;

bool ischeck( char* str)
{

	if(str==0) return true;
	if(str[0]=='a' && str!=0) 
		{
			if(str[1]==0)
				return true;
			else if(str[1]=='a')
				return ischeck(str+1);
			else if(str[1]=='b' && str[2]=='b')
				return ischeck(str+3);
		}

	return false;


}


int main()
{
	char str[10];
	cout<<"Enter the string : " ;
	cin>> str;

	bool ans = ischeck(str);

	if(ans) 
		cout<<"The String follow the rules";
	else
		cout<<"The String does not follow the rules";


}