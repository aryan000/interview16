#include<iostream>
using namespace std;

class ABC
{	
	public :
	int x ;

	ABC( int x)
	{
		cout<<"constructor is invoked"<< endl;
		this->x = x;

	}

	~ABC()
	{
		cout<<"Destructor is invoked " << endl;
	}
};



int main()
{
	cout<<"Static Allocation " << endl;
	ABC a(15);
	cout << " a data is :  " << a.x<<  endl;
	cout<<"Dynamic Allocation " << endl;
	ABC *b = new ABC(25);
	cout<< " b data is : " << b->x << endl;

	*b = a;
	ABC c = a;

	cout<<"Deleting Dynamic Allocation" << endl;
	cout<< " b data is : " << b->x << endl;

	cout<< " c data is : " << c.x << endl;
	delete b;

}