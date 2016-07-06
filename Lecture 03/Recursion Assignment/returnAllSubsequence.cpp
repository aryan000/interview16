/* Return all subsequences */

#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>


vector<string> * findallsubsequence(string str , int n )
{
	vector<string> * ans = new vector<string>;
	if(n==0)
	{	
		ans->push_back("");
		return ans;

	}

	vector<string> * smallans = findallsubsequence(str,n-1);

	for(int i =0;i<smallans->size();i++)
	{
		ans->push_back(smallans->at(i));
		ans->push_back(smallans->at(i) + str[n-1]);
	}

	return ans;


}


int main()
{
	string str;
	cout<<"Enter the string : ";
	cin>> str;

	vector<string> * ans = findallsubsequence(str ,str.size());
	cout<<"The number of subsquences is : " << ans->size();

	sort(ans->begin(),ans->end());
	for(int i = 0;i<ans->size();i++)
	{  cout<< ans->at(i) << endl;		
	}

}