/* Print all subsequences */


#include<iostream>
using namespace std;

void printallsubsequence(string str , int n , string out)
{ 

	// Base Case 
	if(n==0)
		{   cout<< out << endl;
			return ;
		}

	printallsubsequence(str.substr(0,n-1),n-1,out);
	printallsubsequence(str,n-1,str[n-1] + out);



}




int main()
{
	
	string str;
	cout<<"Enter the string : ";
	cin>> str;

	printallsubsequence(str,str.size(),"");
}