/*Given weights and values of n items,
we need put these items in a knapsack of capacity
 W to get the maximum total value in the knapsack.
*/


 #include<iostream>
 using namespace std;
#include<algorithm>


class item
{
	public : 
	int value , weight;

	item()
	{
		value =0;
		weight = 0;

	}
};

bool compare(const item&a , const item&b)
{
	double x = (double)a.value/a.weight;
	double y = (double)b.value/b.weight;

	return x>y?true:false;
}

 int main()
 {
 	int w;
 	cout<<"Enter the size of knapsack : ";
 	cin>> w;
 	cout<<"Enter number of items :";
 	int n;
 	cin>> n;

 	item arr[n];

 	for(int i =0;i<n;i++)
 	{
 		cin>> arr[i].value >> arr[i].weight;
 	}

 	sort(arr,arr+n,compare);

  	int capacity = 0;
  	int max_value = 0;
  	for(int i =0;i<n;i++)
  	{
  		if(capacity+arr[i].weight < w)
  		{
  			max_value += arr[i].value;
  			capacity += arr[i].weight;
  			continue;
  		}

  		else if(capacity<w)
  		{
  			int weight = arr[i].weight;
  			max_value += (w-capacity)*(arr[i].value/arr[i].weight);
  			break;
  		}

  		break;
  	}


  	cout<<"Maximum value that can be taken is : " << max_value << endl;
 }