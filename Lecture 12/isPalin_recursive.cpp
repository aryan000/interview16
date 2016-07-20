#include<iostream>
using namespace std;

bool isPalin(string str , int start , int end)
{
	// Base case
	if(start>end)
		return false;

	if(start==end)
		return true;
	if(start+1==end && str[start]==str[end])
		return true;

	if(str[start]==str[end])
		return isPalin(str,start+1,end-1);

	else return false;
}

int main()
{
	string str;
	cin>> str;
	bool ans = isPalin(str,0,str.size()-1);

	if(ans) cout<<"true" << endl;
	else 
		cout<< "false" << endl;
}