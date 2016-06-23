/* Return all subsequences */

#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>


void print(string str , int n ,string ans)
{
   // Base Case 1
	if(n==0)
	{	
		cout<< ans<<endl;
		return;
	}

   print(str,n-1,ans);
   print(str,n-1,str[n-1]+ans);



}


int main()
{
	string str;
	cout<<"Enter the string : ";
	cin>> str;

	print(str ,str.size(),"");


}