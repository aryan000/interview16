#include<bits/stdc++.h>
using namespace std;

class array
{
	public :
	int data;
	int frequency;

	array()
	{
		frequency = 0;
	}
	void setdata(int data)
	{
		this->data = data;
	}
	{
		this->data = data;
		frequency = 1;
	}

	void set(int frequency)
	{
		this->frequency = frequency;
	}

};


int main()
{
	int t;
	cin>> t;
	while(t--)
	{
		int n;
		cin>> n;
		array a[n];
		int temp;
		map<int,int> mark;
		for(int i =0;i<n;i++)
		{
			cin>> temp;
			if(mark.count(temp)==1)
			{
				
			}
		}
	}
}