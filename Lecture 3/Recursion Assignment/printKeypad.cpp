/* Using the phone keypad return all possible words that can be produced given input
digits. e.g. 23 > “ad, ae, af, bd, be, bf, cd, ce, cf” */

#include<iostream>
using namespace std;
#include<vector>
#include<string>


string getlastdigit( int n)
{
	string str;
	switch(n)
	{
		case 1 : str = ""; return str;
		case 2 : str = "abc"; return str;
		case 3 : str = "def"; return str;
		case 4 : str = "ghi"; return str;
		case 5 : str = "jkl"; return str;
		case 6 : str = "mno"; return str;
		case 7 : str = "pqrs"; return str;
		case 8 : str = "tuv"; return str;
		case 9 : str = "wxyz"; return str;

	}
}


void  getkeypad(int n , string ans )
{
	
	if(n==0)
	{
		 cout<< ans << endl;
		 return;
	}

	string lastdigitoption = getlastdigit(n%10);

	for(int i =0;i<lastdigitoption.size();i++)
		getkeypad(n/10,lastdigitoption[i]+ans);
	 
}


int main()
{

	int n;
	cout<<"Enter the number : ";
	cin>> n;

	getkeypad(n,"");

	
}