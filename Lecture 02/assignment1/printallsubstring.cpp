/* Print all substrings of a string. */

#include<iostream>
using namespace std;
#include<string>


// Brute Force solution for printting all substring O(n^3)
void printall(string str)
{
  for(int i =0;i<str.size();i++)
   {
   for(int j = i;j<str.size();j++)
      {
      for(int k = i;k<=j;k++)
       cout<< str[k];

       cout<< endl;

       }
   }
	
}

int main()
{
	string str;
	cout<<"Enter the string : " ;
	cin>> str;

	printall(str);


}