/* Get all subsequence of an array */

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

vector<string> * getallsubsequence(string str, int n)
{
	vector<string> * output = new vector<string>;
	if(n==0)
	{
		output->push_back(" ");
		return output;

	}

	vector<string> * smalloutput = getallsubsequence(str,n-1);

	for(int i =0;i<smalloutput->size();i++)
	{
		output->push_back(smalloutput->at(i));
		output->push_back(smalloutput->at(i) + str[n-1]);
	}


	return output;

}


int main()
{
	string str;
	cout<<"Enter the string : ";
	cin>> str;

	vector<string> *allsubsequence = getallsubsequence(str,str.size());

	sort(allsubsequence->begin(),allsubsequence->end());
	cout<<"Number of substrings are : " << allsubsequence->size() << endl;
	for(int i =0;i<allsubsequence->size();i++)
	cout<<i+1 << " \t"<< allsubsequence->at(i) << endl;



	return 0;
}