#include<iostream>
using namespace std;

int main()
{
	int n , m;
	// cin>> n >> m ;
	string s, t;
	cin>> s >> t;
	n = s.size()+1;
	m = t.size()+1;
	// n++;
	// m++;
	int **arr = new int*[n+1];
	for(int i =0;i<=n;i++)
		arr[i] = new int[m+1];

	for(int i =0;i<=n;i++)
		for(int j =0;j<=m;j++)
			arr[i][j] = -1;

	for(int i =0;i<=n;i++)
		{for(int j =0;j<=m;j++)
					cout<< arr[i][j] <<  " ";
				cout<< endl;

		}
}