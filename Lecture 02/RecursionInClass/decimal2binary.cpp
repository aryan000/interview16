/* Decimal to Binary via recursion */


#include<iostream>
#include<cstdlib>
using namespace std;

int dec2bin(int n)
{
	
	if(n==0 || n==1) return n;
	int remainder = n%2;
	int majorpart = dec2bin(n/2);

	return majorpart*10 + remainder;
}

int main()
{
	int n ;
	cout<<"Enter the number : " ;
	cin>> n;

	cout<<"THe decimal to binary conversion using recursion is :  " << dec2bin(n) << endl;

	cout<<"The other way to convert decimal to binary is to use itoa in stdlib library "<< endl ;
	char ch[10] ;
	itoa(n,ch,2);
	cout<<"Ans using itoa is : " << ch << endl;


}