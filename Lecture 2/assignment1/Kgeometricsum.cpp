/* Given k find the geometric Sum i.e. 1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) */

#include<iostream>
using namespace std;
#include<cmath>

float kgeometricsum(int k)
{
	if(k==0) return 1 ;
	float sum =  kgeometricsum(k-1); 
	// cout<< " sum is  : " << sum << endl;
	return  sum +  pow(0.5,k) ; 
}






int main()
{
	int k;
	cout<<"Enter the value of k : ";
	cin>> k;

	float ans = kgeometricsum(k);
	cout<<" ans is  :" << ans << endl;
}