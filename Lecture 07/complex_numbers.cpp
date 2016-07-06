#include<iostream>
using namespace std;

class complex
{
	public : 
	 float real , imaginary;

	 complex()
	 {
	 	real = 0;
	 	imaginary = 0.0;
	 }

	 complex(float real , float imaginary)
	 {
	 	this->real = real;
	 	this->imaginary = imaginary;

	 }

	 

	 complex operator + (complex const c2)
	 {
	 	complex temp;
	 	temp.real = real + c2.real;
	 	temp.imaginary = imaginary + c2.imaginary;
	 	return temp;
	 }
	 
};


int main()
{
	complex c1(12,13.0);
	complex c2;

	complex c3 =  c1 + c2;
	cout<< " complex 1 is " << c1.real  << " and " << c1.imaginary << "i" << endl;
	cout<< " complex 2 is " << c2.real  << " and " << c2.imaginary << "i" << endl;
	cout<< " complex 3 is " << c3.real  << " and " << c3.imaginary << "i" << endl;
}