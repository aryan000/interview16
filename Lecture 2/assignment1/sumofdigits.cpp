#include<iostream>
using namespace std;

int sumofdigits(int n)
{
	int sum = 0;
	while(n)
	{
		sum += n%10;
		n/=10;
	}
	return sum;
}


int main()
{
	int n;
	cout<<"Enter the number : " ;
	cin>> n;

	int sum = sumofdigits(n);
	cout<<" the sum of the digits are a : " << sum << endl;

}