/* Remove Duplicates from an array */
#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<int> removeduplicates(std::vector<int> v)
{
	vector<int> :: iterator it;
	 map<int,int> hash; int temp;
	for(it=v.begin(); it!=v.end(); it++)
	{
		temp = *it;
		if(hash.count(temp)>0)
		{
			cout<< " it " << temp << " exists " << endl;
			v.erase(it);
			it--;
		}

		else
			hash[temp] = 1;
			
	}

	return v;
}

int main()
{
	int n;
	cout<<"Enter the number of elements : ";
	cin>> n;
	int temp ;
	std::vector<int> v;
	while(n--)
	{
		cin>> temp;
		v.push_back(temp);
	}

	v = removeduplicates(v);

	for(int i =0;i<v.size();i++)
		cout<< v[i] << " ";



}