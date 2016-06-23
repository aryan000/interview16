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


vector<string> * getkeypad(int n )
{
	vector<string> * ans = new vector<string>;
	if(n==0)
	{
		ans->push_back("");
		return ans;
	}

	vector<string> *smallans = getkeypad(n/10);

	string lastdigitoption = getlastdigit(n%10);

   for(int i=0;i<smallans->size();i++)
   	for(int j =0;j<lastdigitoption.size();j++)
   	{
   		ans->push_back(smallans->at(i)+ lastdigitoption[j]);
   	}

   	return ans;

}


int main()
{

	int n;
	cout<<"Enter the number : ";
	cin>> n;

	vector<string> * ans = getkeypad(n);

	cout<<"Total possible numbers are : " << ans->size() << endl;
	for(int i =0;i<ans->size();i++)
		cout<< ans->at(i) << endl;

}