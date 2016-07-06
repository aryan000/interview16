#include<iostream>
using namespace std;
#include<vector>

template <typename T>
class queue
{ public:
	vector<T>*arr;

	queue()
	{
	arr = new vector<T>;
	}

	~queue()
	{
	delete arr;
	}


	void enqueue(T data)
	{
		arr->push_back(data);
	}

	void dequeue()
	{	
		if(arr->size()==0)
		{
			cout<<"Queue is empty ... cannot Dequeue " ; return;
		}
		 
		  arr->erase(arr->begin());
	}

	T front()
	{
		if(arr->size()==0)
		{
			cout<<"Queue is empty  " ; throw "Queue Empty";
		}	
		return arr->at(0);
	}

	int size()
	{
		return arr->size() ;
	}

	bool isempty()
	{
		return arr->size()==0;
	}
};