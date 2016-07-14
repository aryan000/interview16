#include<iostream>
using namespace std;
#include<string>


void print(string str, int left_bracket , int right_bracket , int n , int &count)
{
	if(left_bracket > n || right_bracket >n || right_bracket>left_bracket)
		return;

	if(left_bracket ==right_bracket && left_bracket==n)
		{ cout<< str << endl; count++; return;}

	print(str+'(',left_bracket+1,right_bracket,n,count);
	print(str+')',left_bracket,right_bracket+1,n,count);
}

int main()
{
	int n;
	cout<< " Enter the number : " ;
	cin>>n;
	string str;
	int count = 0;
	print(str,0,0,n,count);
	cout<< " total number of parenthesis is : " << count << endl;
}