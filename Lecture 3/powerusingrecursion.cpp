/* Power using recursion */

#include<iostream>
using namespace std;


int pow(int a , int n)
{
	if(n==0)
	return 1;

	int smallpow = pow(a,n/2);

	if(n&1)// if power is odd
		return smallpow*smallpow*a;
	return smallpow*smallpow;
}




int main()
{
	int a , b;

	cout<<"Enter the number and the power respectively : " ;
	cin>> a >> b;


	int ans = pow(a,b);

	cout<<"The power of the number is : " << ans << endl;
}