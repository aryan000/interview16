#include<vector>
#include<iostream>
using namespace std;

#define print(arr,n) for(int i = 0;i<n;i++) cout<< arr[i] << " "; cout << endl;
class Heap
{	
	public : 
	
	vector<int> array;
	int count ; 
	int size;
	int heap_type;

	Heap(vector<int> arr )
	{	//cout<<"here";
		array = arr;
		count = arr.size();
		size = arr.size();
		//cout<<"data inserted";
		build_heap();
	}

	int parent(int i )
	{
		if(i<=0 || i>=count)
			return -1;
		return (i-1)/2;
	}

	int leftchild(int i)
	{
		int left = 2*i +1;

		if(left>=count)
			return -1;
		return left;
	}

	int rightchild(int i )
	{
		int right = 2*i + 2;
		if(right>=count)
			return -1;
		return right;
	}

	void insert(int data)
	{
		array.push_back(data);
		count++;
		size++;
		build_heap();
	}

	int getmax()
	{
		if(count==0)
			return INT_MIN;

		return array[0];
	}


	void build_heap()
	{
		int n = count;
		// cout<< " build_heap " << n << endl; 
		for(int i = (n-1)/2 ; i>=0;i--)
			{heapify(i); 
				// cout<<"heapify " << i << " th node " ;
				// print(array,count);
			}

	}

	void swap(int *a , int *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}

	void heapify(int i )
	{
		// cout<< i << endl ;

	 int left = 2*i + 1;
	 int right = 2*i + 2;

	 

	 int gre = i;
	 if( left>-1 && left<count&& array[gre] < array[left])
	 	gre = left;

	 if(right>-1 && right<count && array[gre] < array[right])
	 	gre = right;

	 if(gre!=i)
	 {
	 	swap( &array[gre],&array[i]);
	 	 heapify(gre);

	 }
	}

	int remove()
	{
		if(count==0)
			return -1;

		int x = array[0];
		swap(&array[0],&array[count-1]);
		array.erase(array.begin()+count-1);
		count --;
		size--;
		heapify(0);
		return x;
	}

};