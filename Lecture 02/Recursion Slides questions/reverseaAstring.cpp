/* Reverse a string using recursion */

#include<iostream>
using namespace std;

string Reverse(string str , int start , int end)
{

	if(start>=end)
		return str;

	char ch ;
	ch  = str[start] ;
	str[start]  = str[end];
	str[end] = ch;

	return Reverse(str,start+1,end-1);


}



int main()
{
	string str;
	cout<<"Enter the string : " ;
	cin>> str;

	cout<< " the reverse of the string is : " << Reverse(str,0,str.size()-1) << endl;


}