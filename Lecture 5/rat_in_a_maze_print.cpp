#include<iostream>
using namespace std;
#include<vector>
#include<cstring>
#include<utility>
#include<conio.h>

#define loop(arr,n,m) for(int i = 0 ; i<n;i++) { for (int j = 0 ; j< m ; j++) cout<< arr[i][j] << " "; cout << endl; }
#define set(arr,n,m) for(int i = 0 ; i<n;i++) { for (int j = 0 ; j< m ; j++) b[i][j] = 0; }


bool findpath(int**arr,int n , int m , int x , int y , bool**b , vector<pair<int,int> > &ans)
{

	if(x<0 || x>=n || y<0 || y>=m || arr[x][y]==1 || b[x][y]==1 )
		return false;

	*(*(b+x)+y) = 1; // b[x][y]

	// cout<< " value : " << x << " " << y << endl;
	// getch();

	ans.push_back(make_pair(x,y));
	
	if(arr[x][y]==2)
		return true;

	
	if(findpath(arr,n,m,x+1,y,b,ans))
		return true;

	if(findpath(arr,n,m,x-1,y,b,ans))
		return true;

	if(findpath(arr,n,m,x,y+1,b,ans))
		return true;
	
	if(findpath(arr,n,m,x,y-1,b,ans))
		return true;


	ans.pop_back();
	return false;


}

int main()
{
	int n , m;
	cout<<"Enter the row and column : ";
	cin>> n >> m ;

	int **arr = new int*[n];
	bool **b = new bool*[n];
	for(int i =0;i<n;i++)
	{
		arr[i] = new int[m];
		b[i] = new bool[m];
	}

	for(int i =0;i<n;i++)
		for(int j =0;j<m;j++)
			cin>> arr[i][j];

	// memset(b,0,sizeof(b));
		set(b,n,m);


	// loop(arr,n,m);
	// loop(b,n,m);
	vector<pair<int,int> > result ;
	bool ans =  findpath(arr,n,m,0,0,b,result);
	cout<<"here";
	if(ans)
	{
		cout<<"The path exists !!"<< endl;
		for(int i =0;i<result.size();i++)
			cout<< result[i].first << " "<< result[i].second << endl;
	}

	else cout<<"Path is not forund";

}