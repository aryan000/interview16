/* find duplicates in the range  , only one number is duplicate */

#include<iostream>
using namespace std;
#include<vector>

int findduplicate1(vector<int> v)
{
	int n = v.size();
  int sum = n*(n-1)/2;
  int sum2 = 0;
  for(int i =0;i<n;i++)
  	sum2 += v[i];

   return sum2-sum;


}

int findduplicate2(std::vector<int> v)
{
	int ans1  =0;
	int n = v.size();

	for(int i =1;i<n;i++)
		ans1 = ans1^i;

	for(int i =0;i<n;i++)
		ans1 = ans1 ^ v[i];


	return ans1;

}
int main()
{
	
	int n;
	cout<<"Enter the range of number :";
	cin>> n;

	vector<int> arr; int temp;
	for(int i =0;i<n;i++)
	{
		cin>> temp;
		arr.push_back(temp);
	}


	int ans = findduplicate1(arr);
	cout<<"the duplicate number using sum method is  : " << ans << endl;
	ans = findduplicate2(arr);
	cout<<"the duplicate number using xor method is  : " << ans << endl;

}