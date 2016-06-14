// Write an efficient algorithm that searches for a value in an n x m table (two-dimensional array). This table is sorted along the rows and columns — that is,

// Table[i][j] ≤ Table[i][j + 1], 
// Table[i][j] ≤ Table[i + 1][j]

#include<iostream>
using namespace std;
#include<vector>

bool findelement( vector<vector<int> > arr , int *a , int *b , int numbertobefound)
{

	int n = arr.size();
	int m = arr[0].size();
	// cout<< n << " " << m ;

	bool flag = false; int i = 0 , j = m-1;
	 while(  i<n && j>=0 )
	 { 
	 	if(arr[i][j]==numbertobefound) { *a = i; *b = j ; flag = true; break;}

	 	if(numbertobefound>arr[i][j]) i++;
	 	else j--;
	 }

	return flag;

}

int main()
{
	int n , m;
	cout<<"Enter the row and column of the 2D array : " ;
	cin>> n >> m;

	vector< vector<int> > arr;
	int temp;

	std::vector<int> v;
	cout<<" Enter 2d array elements " ;
	for(int i =0;i<n;i++)
		{   
			for(int j =0;j<m;j++)
				{
					cin>> temp;
					 v.push_back(temp);
		
				}
				arr.push_back(v);
				v.clear();
		}
	int i , j;	
	int numbertobefound;
	cout<<"Enter the number to be found : " ;
	cin>> numbertobefound;
	bool ans = findelement(arr , &i, &j , numbertobefound);
	if(ans)
	{
		cout<<" Element is found at : " << i <<" th row and " << j << " th column";
	}

	else 
		cout<<"Element not found";


return 0;
}