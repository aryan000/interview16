#include<bits/stdc++.h>
using namespace std;
#define loop(i,n) for(int i =0;i<n;i++)
#include<conio.h>

void print(std::vector<vector<int> > v)
{
	int i , j ;
	loop(i,v.size())
	{ cout<< endl;
	 loop(j,v[0].size())
	 	cout<< v[i][j] << " ";
	 }
	 cout<< endl;
}

void print1(std::vector<vector<bool> > v)
{
	int i , j ;
	loop(i,v.size())
	{ cout<< endl;
	 loop(j,v[0].size())
	 	cout<< v[i][j] << " ";
	 }
	 cout<< endl;
}
void fn(vector<vector<int> > &arr, vector<vector<bool> > &visited , vector<vector<bool> > &set , int i , int j , int &count )
{
	cout<< " i is " << i << " j is " << j << endl;

	print1(visited);
	print(arr);
	getch();
	if(visited[i][j])
		return;
	 visited[i][j] = 1;
	// top
	if(!visited[i-1][j])
		fn(arr,visited,set,i-1,j,count);
	cout<<"top checked";
	// right
	visited[i-1][j] = 1;
	if(!visited[i][j+1])
		fn(arr,visited,set,i,j+1,count);
	cout<<"right checked";
	visited[i][j+1] = 1;
	// bottom
	if(!visited[i+1][j])
		fn(arr,visited,set,i+1,j,count);
	cout<<"bottom checked";
	visited[i+1][j] = 1;
	// left
	if(!visited[i][j-1])
		fn(arr,visited,set,i,j-1,count);
	visited[i][j-1] = 1;
	cout<<"left checked";
	int value = INT_MAX;
	if(set[i-1][j]) // top
		value = min(value,arr[i-1][j]);

	if(set[i][j-1])  //left
		value = min(value,arr[i][j-1]);

	if(set[i][j+1]) //right
		value = min(value,arr[i][j+1]);

	if(set[i+1][j]) // bottom
	 value = min(value , arr[i+1][j]);


	 if(value>arr[i][j])
	 {
	 	count += value - arr[i][j];
	 	arr[i][j] = value;

	 	if(!set[i-1][j])
	 		arr[i-1][j] = max(value,arr[i-1][j]);

	 	if(!set[i][j+1])
	 		arr[i][j+1] = max(value,arr[i][j+1]);

	 	if(!set[i+1][j])
	 		arr[i+1][j]  = max(value,arr[i+1][j]);

	 	if(!set[i][j-1])
	 		arr[i][j-1] = max(value,arr[i][j-1]);

	 }

	
	 set[i][j] = 1;

	 return ;
}


int main(int argc, char const *argv[])
{
	
	int t;
	cin>> t;
	while(t--)
	{
		int r , c;
		cin>> r >> c;

		vector<vector<int> > arr;
		vector<vector<bool> > visited ;
		vector<vector<bool> > set ;
		 int temp ,  i , j;
		loop(i,r)
		{	vector<int> smallans;
			std::vector<bool> v;
			loop(j,c)
			{
				cin>> temp;
				smallans.push_back(temp);
				v.push_back(0);
			}
			arr.push_back(smallans);
			visited.push_back(v);
			set.push_back(v);
		}
	
		loop(i,r)
			{
				loop(j,c)
				{
					if(i==0 || i==r-1 || j == 0 || j == c-1)
					{
						visited[i][j] = 1;
						set[i][j] = 1;
					}
				}
			}

			 
			int count = 0;
			fn(arr,visited,set,1,1,count);
			print(arr);
			cout << count << endl;
	}// end of while of t--
	return 0;
}