#include<bits/stdc++.h>
using namespace std;

int key(char ch)
{
	if(ch>='a' && ch<='c')
		return 2;
	if(ch>='d' && ch<='f')
		return 3;
	if(ch>='g' && ch<='i')
	return 4;
	if(ch>='j' && ch<='l')
	return 5;
	if(ch>='m' && ch<='o')
	return 6;
	if(ch>='p' && ch<='s')
	return 7;
	if(ch>='t' && ch<='v')
	return 8;
	if(ch>='w' && ch<='z')
	return 9;
}

int main()
{
 int t;
 cin>> t;
 while(t--)
 {
 	string str;
 	cin>> str;
 	for(int i =0;i<str.size();i++)
 	{
 	cout<< key(str[i]) ;

 	}
 	cout<< endl;
 }
	
}