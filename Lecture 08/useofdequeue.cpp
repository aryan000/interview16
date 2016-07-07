#include<iostream>
using namespace std;
#include "dequeue.h"

int main()
{
	dequeue<int> d;

	d.push(10);
	d.print();
	d.push(20);
	d.print();
	d.eject();
	d.print();
	// d.inject(100);
	// d.print();
	// d.pop();
	// d.print();


}