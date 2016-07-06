/* Print all subset of an array */

#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>

void print( vector<int> ans)
{
	for(int i =0;i<ans.size();i++)
					cout<< ans[i] << " ";
				cout<< endl;
				
}

vector<vector<int> > getsubset(vector<int> v , int n)
{	
	vector<vector<int> > ans;

	if(n==1)
	{	
		vector<int> temp;
		temp.push_back(v[n-1]);
		 ans.push_back(temp);
		 return ans;
	}

	vector<vector<int> > smallans = getsubset(v,n-1);

	vector<int> temp;

	for(int i =0;i<smallans.size();i++)
	{
		 for(int j =0;j<smallans[i].size();j++)
		 	temp.push_back(smallans[i][j]);

		 ans.push_back(temp);
		 temp.push_back(v[n-1]);
		 ans.push_back(temp);
		 temp.clear();
		 
	}

			temp.clear();
		 temp.push_back(v[n-1]);
		 ans.push_back(temp);
		
	
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

	int k;
	cout<<"Enter the element k : ";
	cin>> k;
	vector< vector<int> > ans = getsubset(arr,arr.size());

	sort(ans.begin(),ans.end());
	int sum = 0 ;
	for(int i =0;i< ans.size();i++)
	{	sum = 0;
	    for(int j =0;j<ans[i].size();j++)
	    	sum += ans[i][j];
	    if(sum==k)
	    	print(ans[i]);
	}
}