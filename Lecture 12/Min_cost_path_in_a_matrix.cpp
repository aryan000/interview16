#include<iostream>
using namespace std;

int min_cost_path(int** cost, int n , int m , int i , int j )
{
	// Base Case 
	if(i==n-1 && j==m-1)
		return cost[i][j];

	if(i==n-1)
		return cost[i][j]+ min_cost_path(cost,n,m,i,j+1);
	if(j==m-1)
		return cost[i][j] + min_cost_path(cost,n,m,i+1,j);

	int ans1 = min_cost_path(cost,n,m,i,j+1);
	int ans2 = min_cost_path(cost,n,m,i+1,j);
	int ans3 = min_cost_path(cost,n,m,i+1,j+1);

	return cost[i][j] + min(ans1 , min(ans2,ans3));

} 


int min_cost_path(int **cost , int n , int m , int i , int j , int **output)
{	
	if(output[i][j]!=0)
		return output[i][j];

	if(i==n-1 && j==m-1)
		output[i][j] =  cost[i][j];

	else if(i==n-1)
		output[i][j] = cost[i][j]+ min_cost_path(cost,n,m,i,j+1);
	else if(j==m-1)
		output[i][j] =  cost[i][j] + min_cost_path(cost,n,m,i+1,j);
	else
	{
	int ans1 = min_cost_path(cost,n,m,i,j+1);
	int ans2 = min_cost_path(cost,n,m,i+1,j);
	int ans3 = min_cost_path(cost,n,m,i+1,j+1);

	output[i][j] =  cost[i][j] + min(ans1 , min(ans2,ans3));
    }

    return output[i][j];


}

int iterative_min_cost(int **cost , int n , int m)
{
	int **temp = new int*[n];
	for(int i =0;i<n;i++)
		temp[i] = new int[m];

	temp[0][0] = 0;

	// initialising column
	for(int i =1;i<=n;i++)
		temp[i][0] = cost[i][0] + temo[i-1][0];

	// initialising row

	for(int j =1;j<=m;j++)
		temp[0][j] = cost[0][j] + temp[0][j-1];

	for(int i =1;i<=m;i++)
		for(int j =1;j<=m;j++)
		{
			temp[i][j] = min(temp[i-1][j-1] , min(temp[i-1][j] , temp[i][j-1])) + cost[i][j];
		}

	return temp[n][m];
}

int main(int argc, char const *argv[])
{
	
	int n , m;
	cout<<"Enter rows and column : " ;
	cin>> n >> m;

	int **matrix = new int*[n];
	int **output = new int*[n];
	for(int i =0;i<n;i++)
		{matrix[i] = new int[m];
			output[i] = new int[m];
		}

	for(int i =0;i<n;i++)
		for(int j =0;j<n;j++)
			{cin>> matrix[i][j];
				output[i][j] = 0;
			}


	// cout<< min_cost_path(matrix,n,m,0,0,output);
			cout<< iterative_min_cost(matrix,n,m);
	return 0;
}