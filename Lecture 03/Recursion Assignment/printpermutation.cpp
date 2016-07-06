#include<iostream>
using namespace std;
#include<vector>
#include<string>

void swap( char *a , char*b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

vector<string> * printpermutation(string str , int index)
{
	vector<string> * ans = new vector<string>;
	if(index==str.size()-1)
		{
			// cout<< str<< endl;
			ans->push_back(str);
			return ans;
		}

		vector<string> *smallans = new vector<string>;

	for(int i =index;i<str.size();i++)
	{	
		swap(str[i],str[index]);
		smallans =  printpermutation(str,index+1);
		ans->push_back(smallans->at(0));
		swap(str[i],str[index]); // Recursion with backstring

	}

	delete smallans;


return ans;
}



int main()
{
	string str;
	cout<<"Enter the string : ";
	cin>> str;

	vector<string> *ans = printpermutation(str,str.size());

	for(int i =0;i<ans->size();i++)
		cout<< ans->at(i) << endl;
}