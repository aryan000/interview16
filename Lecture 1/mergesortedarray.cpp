/* Merge two sorted array */

#include<iostream>
using namespace std;
#include<vector>

void merge(vector<int> *a , vector<int> b)
{	
	if(a->empty())
	{
		*a = b;
		return ;
	}
	if(b.empty())
		return ;

	vector<int> arr;
	std::vector<int> :: iterator it1 , it2;
	it1 = a->begin();
	it2 = b.begin();

	while(it1!=a->end()&& it2!=b.end())
	{
		if(*it1<*it2)
		{
			arr.push_back(*it1);
			it1++;
		}
		else
		{
			arr.push_back(*it2);
			it2++;
		}

	}

	while(it1!=a->end())
	{
		arr.push_back(*it1);
		it1++;
	}
	while(it2!=b.end())
	{
		arr.push_back(*it2);
		it2++;

	}

	a->clear();
	*a = arr;
	return ;
}



int main()
{
	vector<int> a , b;
	int n ,m;
	cout<<"Enter size of first array : " ;
	cin>> n;
	int temp;
	cout<<"Enter array elements :  " ;
	for(int i =0;i<n;i++)
	{
		cin>> temp;
		a.push_back(temp);
	}
	cout<<"Enter the size of second arary : ";
	cin>> m;

	cout<<"Enter array elements :  " ;
	for(int i =0;i<m;i++)
	{
		cin>> temp;
		b.push_back(temp);
	}

	merge(&a,b);
	for(int i =0;i<a.size();i++)
		cout<< a[i] <<  " ";

	
}