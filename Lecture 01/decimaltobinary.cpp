/* Decimal to binary */

#include<iostream>
using namespace std;


int decimaltobinary(int n)
{
	if(n==0||n==1) return n ;

	int ans = decimaltobinary(n/2);

	//cout<< ans << " and " << n << endl;
	return (ans*10 + n%2);
}



int main()
{
	int n;
	cout<<"Enter the decimal number : ";
	cin>> n;

	int ans = decimaltobinary(n);
	//cout<< ans ; 
	cout<<"REcursive Binary of the decimal " << n <<  " is : " << ans << endl;



}