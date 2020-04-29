#include <iostream>
#include <math.h>
using namespace std;

class MyComplex {
	private:
		double real;
		double imaginary;
	public:
		MyComplex();
		MyComplex(double inputReal);
		MyComplex(double inputReal, double inputImaginary);
		~MyComplex();
		void SetReal(double inputReal);
		void SetImaginary(double inputImaginary);
		double GetReal();
		double GetImaginary();
		friend ostream& operator<< (ostream&, MyComplex);
};

MyComplex::MyComplex(){
	real = 0;
	imaginary = 0;
}
MyComplex::MyComplex(double inputReal){
	real = inputReal;
	imaginary = 0;
}
MyComplex::MyComplex(double inputReal, double inputImaginary){
	real = inputReal;
	imaginary = inputImaginary;
}
void MyComplex::SetReal(double inputReal){
	real = inputReal;
}
void MyComplex::SetImaginary(double inputImaginary){
	imaginary = inputImaginary;
}
double MyComplex::GetReal(){
	return real;
}
double MyComplex::GetImaginary(){
	return imaginary;
}
ostream& operator<< (ostream& out, MyComplex comp) {
	if (comp.imaginary >= 0){
		cout << comp.real << "+" << comp.imaginary << "i" << endl;
	}
	else{
		cout << comp.real << comp.imaginary << "i" << endl;
	}
	return out;
}
MyComplex::~MyComplex(){
}

int main(){
	MyComplex c1(2,3), c2(1,-4), c3(-2), c4(0,5), c5;
	cout << "c1: " << c1;
	cout << "c2: " << c2;
	cout << "c3: " << c3;
	cout << "c4: " << c4;
	cout << "c5: " << c5;
	
	cout << "Using c5" << endl;
	c5.SetReal(1);
	cout << "Setting real part to 1 gives: " << c5.GetReal() << endl;
	c5.SetImaginary(3);
	cout << "Setting imaginary part to 3i gives: " << c5.GetImaginary() << endl;
	cout << "c5 is now: " << c5;
	return 0;
}


		
		
		

