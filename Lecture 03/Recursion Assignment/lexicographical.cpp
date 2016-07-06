/*
Given a number n. Print all numbers from 1 to n in lexicographical order. i.e.
1,10,100,1000,101,102…..etc.
*/

#include<iostream>
using namespace std;

void printlexicographical(int n , int x)
{

	if(x>n) return;

	if(x<=n) 
		cout<< x << endl;

	for(int i =0;i<10;i++)
		printlexicographical(n,x*10+i);
}


void lexicographical(int n)
{

	for(int i =1;i<10;i++)
		printlexicographical(n,i);

}

int main()
{
	int n;
	cout<<"Enter the number : ";
	cin>> n;

	lexicographical(n);
}