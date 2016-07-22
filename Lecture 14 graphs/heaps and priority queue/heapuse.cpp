#include<iostream>
using namespace std;
#include "Heap.h"
#include<vector>


int main()
{
	vector<int> arr;
	int n;
	cin>> n;
	int temp;
	for(int i =0;i<n;i++)
	{
		cin>> temp;
		arr.push_back(temp);
	}

	// cout<<"inserted";
	Heap h(arr);

	char ch  = 'y';
	while(ch!='q')
	{
		cout<< "1 to insert \n2: to getmax : \n 3 to remove q to exit :";
		cin >> ch;

		if(ch=='1')
		{	int data;
			cout<< "Enter data to be inserted : ";
			cin>> data;
			h.insert(data);

		}

		else if(ch=='2')
		{
			int x = h.getmax();
			if(x==-1)
				cout<<"heap empty";
			else cout<<"maximum element is : " << x << endl;
		}

		else if(ch=='3')
		{
			int x = h.remove();
			if(x==-1)
				cout<<"heap empty";

			else cout<<"ELement remove is :  " << x << endl;
		}

		else
		 break;
	} 

}
