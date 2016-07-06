#include<iostream>
#include<cstring>
using namespace std;
#include<conio.h>

bool findpath( int m , int n , int x , int y ,int *arr[] , bool **b)
{
	if(x<0 || x>=m || y<0 || y>=n || arr[x][y]==1 ||  b[x][y]==1)
		return false;

	if(arr[x][y]==2)
		return true;

	*(*(b+x)+y) = 1;

	if(findpath(m,n,x+1,y,arr,b))
		return true;
	
	if(findpath( m,n,x-1,y,arr,b))
		return true;
	
	if(findpath( m,n,x,y+1,arr,b))
		return true;
	
	if(findpath( m,n,x,y-1,arr,b))
		return true;


	return false;

}





int main()
{

	cout<<"Enter row and cloumn of the matrix : ";
	int m , n;
	cin>> m >> n;

	int **arr = new int*[m];
	for(int i =0;i<m;i++)
		arr[i] = new int[n];

	cout<<"Enter the matrix : ";

	for(int i =0;i<m;i++)
		for(int j =0;j<n;j++)
			cin>> arr[i][j];


for(int i =0;i<m;i++)
		{for(int j = 0 ; j<n; j++)
					cout<< arr[i][j] << " ";
		 cout<<endl;
		}

	bool **b = new bool*[m];
	for(int i =0;i<m;i++)
		b[i] = new bool[n];

	// memset(b,0,sizeof(b));

	for(int i =0;i<m;i++)
		{for(int j = 0 ; j<n; j++)
					b[i][j] = 0;
		
				cout<<endl;
		}

	bool ans = findpath( m,n,0,0,arr,b);

	if(ans)
		cout<<"The path exists : ";
	else 
		cout<<"The path does not exists";

	for(int i =0;i<n;i++)
		{for(int j = 0 ; j<m; j++)
					cout<< b[i][j] << " ";
		
				cout<<endl;
		}

}