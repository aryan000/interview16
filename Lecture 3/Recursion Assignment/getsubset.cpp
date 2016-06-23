/* Print all subset of an array */

#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>


vector<string > getsubset(vector<int> v , int n)
{
	vector<string > ans;

	if(n==0)
	{
		 ans.push_back("");
		 return ans;
	}

	vector<string> smallans = getsubset(v,n-1);

	for(int i =0;i<smallans.size();i++)
	{
		ans.push_back(smallans[i]);

		ans.push_back( smallans[i] + char(v[n-1] +'0') );
	}



	return ans;


}


int main()
{
	int n;
	cout<<"Enter the number of array : ";
	cin>> n;

	vector<int> arr;
	int temp;

	for(int i =0;i<n;i++)
	{
	cin>> temp;
	arr.push_back(temp);
	}

	vector<string > ans = getsubset(arr,arr.size());

	sort(ans.begin(),ans.end());
	for(int i =0;i< ans.size();i++)
	{
	   cout<< ans[i] << endl;
	}
}