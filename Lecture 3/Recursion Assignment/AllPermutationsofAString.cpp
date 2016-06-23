/* Return all permutation of a string */

#include<iostream>
using namespace std;
#include<string>
#include<vector>

void swap( char *a , char*b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void printpermutation(string str , int index)
{

	if(index==str.size()-1)
		cout<< str<< endl;

	for(int i =index;i<str.size();i++)
	{	
		swap(str[i],str[index]);
		printpermutation(str,index+1);
		swap(str[i],str[index]); // Recursion with backstring

	}
}



int main()
{
	string str;
	cout<<"Enter the string";
	cin>> str;

	// vector<string> * ans = getpermutation(str);

	// for(int i = 0;i<ans->size();i++)
		// cout<< ans->at(i) << endl;

	printpermutation(str,0);



}