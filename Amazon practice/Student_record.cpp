#include<bits/stdc++.h>
using namespace std;

class Student
{
	public : 
	string name;
	int a,b,c;
	int max_avg;

	void getdata()
	{
	cin>> name >> a>> b >> c ;
		max_avg = (a+b+c)/3;
	}

};

bool compare( const Student& s1, const Student &s2)
{
	return s1.max_avg>s2.max_avg?true:false;
};

int main()
{
	int t;
	cin>> t;
	while(t--)
	{
		int n;
		cin>> n;
		vector<Student> S(n);
		for(int i =0;i<n;i++)
		{	S[i].getdata();

		}

		sort(S.begin(),S.end(),compare);

		cout<< S[0].name << " " << S[0].max_avg << endl;
	}
}