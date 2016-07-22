/*
Consider the following 6 activities.
     start[]  =  {1, 3, 0, 5, 8, 5};
     finish[] =  {2, 4, 6, 7, 9, 9};
The maximum set of activities that can be executed
by a single person is {0, 1, 3, 4}

 */

 #include<iostream>
 using namespace std;
#include<algorithm>

class train
{
	public : 
	int start;
	int finish;

	train()
	{
		start = 0;
		finish = 0;
	}
};


bool compare (const train&s1 , const train&s2)
{
	if(s1.finish< s2.finish)
		return true;
	return false;

}


int num_of_activity( train s[] , int n)
{	

	int end_time = 0;
	int count = 0;

	for(int i =0;i<n;i++)
	{
		if(s[i].start >= end_time)
		{
			count++;
			end_time = s[i].finish;
		}

	}


	return count;

}


 int main()
 {
 	int n;
 	cin>>n;

 	train s[n];

 	for(int i =0;i<n;i++)
 		cin>> s[i].start;

	for(int i =0;i<n;i++)
 		cin>> s[i].finish;

 	sort(s,s+n,compare);

 	cout<< " Number of activities than can be performed are : " << num_of_activity(s,n) << endl;




 }
