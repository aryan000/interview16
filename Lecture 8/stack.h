#include<iostream>
using namespace std;
#include<vector>

template <typename T>
class stack
{
	public : 
	vector<T>* arr;

	stack()
	{
		arr = new vector<int> ;
	}

	~stack()
	{
		delete arr;
	}


	void push(T data)
	{
		arr->push_back(data);
	}

	void pop()
	{
		if(arr->empty())
			cout<<" stack is empty.. cannot pop elements "<< endl;

	   else
	   {
	   	arr->pop_back();
	   }
	}

	T top()
	{
		if(arr->empty())
			{cout<< " stack is empty ... "; return 0;}

		return arr->at(arr->size()-1);
	}

	int size()
	{
		return arr->size();
	}

	bool isempty()
	{
		return arr->size()==0;
	}


};


