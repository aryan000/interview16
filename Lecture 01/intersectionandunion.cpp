/* Given two arrays return their intersection and
all */

#include<iostream>
using namespace std;
#include<map>
#include<vector>

vector<int> findall( vector<int> a , vector<int> b)
{
	map<int,int> hash;

	for(int i=0;i<a.size();i++)
	{
		if(hash.count(a[i])>0) 
			continue;
		else
			hash[a[i]] = 1;

	}

	for(int i =0;i<b.size();i++)
	{
		if(hash.count(b[i])>0) 
			continue;
		else
			hash[b[i]] = 1;

	}
	a.clear();
	map<int,int> :: iterator it;
	int var;
	for(it=hash.begin(); it!=hash.end();it++)
	{    
		a.push_back(it->first);
	}
	// cout<<"returning";
	return a;

}

vector<int> findintersection( vector<int> a , vector<int> b)
{
	map<int,int> hash;
	std::vector<int> v ;

	 v = a.size()<b.size()?a:b;
	for(int i=0;i<v.size();i++)
	{
		if(hash.count(v[i]>0)) 
			 hash[v[i]] +=1;
		else
			hash[v[i]] = 1;

	}

	v.clear();
	vector<int> x = v==a?b:a;
	for(int i =0;i<x.size();i++)
	{
		if(hash.count(x[i])>0) 
			 { 
			 		 
			 		v.push_back(x[i]);
			 		hash[x[i]] -=1;
			 		if(hash.count(x[i]) ==0)
			 				hash.erase(x[i]);

			 	
			 }

	}

	// cout<<"returning from b";
	return v;

}

int main()
{
	int n , m;
	vector<int> arr1 , arr2;
	cout<<"Enter the size of first matrix : ";
	cin>> n;
	int temp;
	for(int i =0;i<n;i++)
	{
		cin>> temp;
		arr1.push_back(temp);
	}
	cout<<"Enter the size of second matrix : ";
	cin>> m;
	for( int i =0;i<m;i++)
	{
		cin>> temp;
		arr2.push_back(temp);
	}

	vector<int> all , intersection;
	all  = findall(arr1, arr2);
	intersection = findintersection(arr1,arr2);

	cout<<"The all of the array is : " ;
	for( int i =0;i<all.size();i++)
		cout<< all[i] << " ";

	cout<<"\nThe intersection of the array is : " ;
	for(int i =0;i<intersection.size();i++)
		cout<< intersection[i] <<  " ";


	return 0;
}