/* find pairs and triplets of elements in array */

#include<iostream>
using namespace std;
#include<vector> 
#include<algorithm>
#include<utility>

vector<pair<int,int> > find(std::vector<int> v, int n ,  int k)
{
	sort(v.begin(),v.end());
	vector<pair<int,int> > arr;
	pair<int,int> temp;
 	int i=0,  sum;

	while(i<n)
	{ 
		sum = v[i]+ v[n-1];
		if(sum == k && i!=n-1)
			{ 
			  temp.first = v[i];
				temp.second = v[n-1];
				arr.push_back(temp);
				i++;n--;
			// arr.push_back(make_pair(arr[i],arr[n-1]));
		}

		else if(sum>k) n--;
		else i++;

	}
// cout<<"reacing here";
return arr;
}

vector<pair<int,int> > findpair( vector<int> v)
{
	vector< pair<int,int> > myarr;
	myarr = find(v,v.size(),0);
	return myarr;
} 

vector<pair<pair<int,int>,int> > findtripple( vector<int> v )
{
 vector<pair< pair<int,int>,int> > arr; 
 sort(v.begin(),v.end());

  vector< pair<int,int> > temp;
  pair< pair<int,int>,int>  tripple;
  int n = v.size() , var;
 for(int i =v.size()-1;i>=2;i--)
 {  

 	temp = find(v,i-1, v[i]*-1);

 	if(!temp.empty())
 	{   
 		for(int z = 0;z<temp.size();z++)
 		{ tripple.first = temp[z];
 		  tripple.second = v[i];
 		  arr.push_back(tripple);
 		}
 	}


 }

return arr;
}


int main()
{
	int n;
	cout<<"Enter the number of elements : ";
	cin>> n;

	std::vector<int> v;
	int temp;

	for(int i =0;i<n;i++)
	{
		cin>> temp;
		v.push_back(temp);

	}

	int k;
  // cout<<" Enter the sum to be found : ";
  // cin>> k;
   vector<pair<int,int> > arr;
   arr = findpair(v);

   for( int i =0;i<arr.size();i++)
   	cout<< arr[i].first << " and " << arr[i].second << endl;

   vector<pair<pair<int,int>,int> > tripple;
   tripple = findtripple(v);

   for( int i =0;i<tripple.size();i++)
   	cout<< tripple[i].first.first << " and " << tripple[i].first.second << " and " << tripple[i].second << endl;	

}