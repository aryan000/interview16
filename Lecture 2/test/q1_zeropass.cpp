/*
Question
1
You are given with a NxN matrix which contains only 0s and 1s. e.g.
1 0 1 1 0
0 1 1 1 0
1 1 1 1 1
1 0 1 1 1
1 1 1 1 1
Your job is to write a function which will set every row that contains a 0 to all 0s and set every
column that contains a 0 to all 0s. The output for the above input matrix will be:
0 0 0 0 0
0 0 0 0 0
0 0 1 1 0
0 0 0 0 0
0 0 1 1 0
Fucntion
Prototype:
Int[][] ZeroPass(int[][] inputMatrix)
*/

#include<iostream>
using namespace std;
#include<vector>
#include<cstdio>
#define print(arr,n) for(int i =0;i<n;i++) cout<< arr[i] << " "

vector<vector<int> > ZeroPass(vector<vector<int> > arr)
{
	int n = arr.size();
	int m = arr[0].size();

	bool row[n] = {0};
	bool column[m] = {0};
	// print(row,n);
	// print(column,n);

	for(int i =0;i<n;i++)
		{
			for(int j = 0;j<m;j++)
				{	
					if(arr[i][j]==0)
					{    
						row[i]=1;
						column[j]=1;
						
					}
			}
		}


	for(int i =0;i<n;i++)
		{if(row[i]==1)
				{
					for(int j =0;j<m;j++)
						arr[i][j] = 0;
				}
			
		}

	for(int i =0;i<n;i++)
		if(column[i]==1)
				for(int j =0;j<m;j++)
					arr[j][i] = 0;

return arr;
}

int main()
{
	int n,m;
	cout<<"Enter the row size of input matrix : ";
	cin>> n;
	cout<<"Enter the column size of input matrix : ";
	cin>> m;

	cout<<"Enter the matrix : \n" ;
	vector<vector<int> > arr;
	for(int i =0;i<n;i++)
	{	
		vector<int> row;
		int temp;
		for( int j =0;j<m;j++)
		{
			cin>> temp;
			row.push_back(temp);

		}
		arr.push_back(row);
	}

	arr = ZeroPass(arr);

	cout<<"The required matrix is : " << endl;
	for(int i =0;i<n;i++)
		{
			for(int z =0;z<m;z++)
				cout<< arr[i][z] << " ";
		cout<< endl;
		}

	return 0;

}