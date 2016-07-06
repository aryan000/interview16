#include<iostream>
using namespace std;

// used for printing the sudoku
#define print(arr,x) for(int i =0;i<x;i++) { for(int j =0;j<x;j++) cout<< arr[i][j] << " ";  cout<< endl;}

//  row and column of sudoku
#define N 9

#define unused 0





bool isSafe(int arr[N][N] , int row, int column , int num)
{
	// checking column
	for(int i =0;i<N;i++)
		if(arr[i][column]==num)
			return false;

	// checking row
	for(int i =0;i<N;i++)
		if(arr[row][i]==num)
			return false;


	// checking smaller 3*3 matrix
		int startrow = row - row%3;
		int startcolumn = column - column%3;

		for(int i =0;i<3;i++)
			for(int j =0;j<3;j++)
			{
				if(arr[i+startrow][j+startcolumn]==num)
					return false;
			}


	return true;

}

bool isSudokuComplete(int arr[N][N] , int &row, int &column)
{	
	
	for(row =0;row<N;row++)
		for( column =0;column <N;column++)
			if(arr[row][column]==unused)
				return false;

	return true;
}

bool solvesudoku(int arr[N][N])
{
	int row , column;
	if(isSudokuComplete(arr ,row,column ))
		return true;



	for(int i =1;i<=9;i++)
	{
		if(isSafe(arr,row,column,i)) // setting the cell to value
			{ arr[row][column] = i;

			if(solvesudoku(arr))  // recursing to check further values
				return true;

			else arr[row][column] = unused;  // backtracking and unsetting the cell 
		 	}
		
	}

// arr cannot be completed 
return false;
}



int main()
{
	
	int arr[N][N] = { {0, 7, 0, 0, 0, 2, 5, 3, 6},
                      {0, 0, 4, 0, 0, 0, 2, 0, 0},
                      {0, 0, 0, 3, 0, 0, 0, 0, 0},
                      {0, 0, 1, 0, 8, 3, 0, 4, 0},
                      {0, 2, 3, 7, 4, 1, 6, 8, 0},
                      {0, 4, 0, 6, 2, 0, 7, 0, 0},
                      {0, 0, 0, 0, 0, 5, 0, 0, 0},
                      {0, 0, 2, 0, 0, 0, 3, 0, 0},
                      {4, 5, 9, 2, 0, 0, 0, 6, 0},
                  };

     print(arr,N);


  bool ans = solvesudoku(arr);
  cout<<endl;

  if(ans)
  	{
  		cout<<"THe solved sudoku is : "<< endl;
  		print(arr,N);
  	}

  else cout<<"Cannot be solved";



}