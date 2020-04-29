/*
Group 4
Javier Hernandez
Eli Sears
Robert Lyle
Matthew Baresch
*/

#include <iostream>
#include <math.h>
#include <vector>
#include <limits>
using namespace std;

class ComplexNumber {
	public:
		ComplexNumber();
		ComplexNumber(double realNumber, double imagNumber);
		~ComplexNumber();
		void setRe(double inputReal);
		void setIm(double inputImag);
		double Re();
		double Im();
		friend ostream& operator<< (ostream&, ComplexNumber);
		ComplexNumber operator+(ComplexNumber rhs);
		ComplexNumber operator-(ComplexNumber rhs);
		ComplexNumber operator*(ComplexNumber rhs);
		ComplexNumber operator/(ComplexNumber rhs);
		void operator!(void){
			complex = complex * -1;
		};
	private:
		double real;
		double complex;
};


int main(){
	ComplexNumber c1, c2(1,2), c3(3,4), operTotal, hold;
	vector <ComplexNumber> test;
	//reserve number has to be set to XX or garbage will be push into vector

	cout << "Value of c1 (default constructor): \n";
	cout << c1.Re() << " " << c1.Im() << endl;
	cout << "Value of c2 (value constructor): \n";
	cout << c2.Re() << " " << c2.Im() << endl;
	cout << "Value of c3 (value constructor): \n";
	cout << c3;

	operTotal = c2 + c3;
	cout << "c2 + c3 == " << operTotal << endl;

	operTotal = c2 - c3;
	cout << "c2 - c3 == " << operTotal << endl;

	operTotal = c2 * c3;
	cout << "c2 * c3 == " << operTotal << endl;

	operTotal = c2 / c3;
	cout << "c2 / c3 == " << operTotal << endl;

	operTotal = (c2/c3) + (c2*c3);
	cout <<  "c2/c3 + c2*c3 == " << operTotal << endl;

	!c2;
	cout << "Conjugate of c2 == " << c2 << endl;

	cout << "Vector output using indexed for-loop: \n";
	for (int i = 0; i < 10; ++i){
		//creating a temp object to store into vector
		hold.setRe(i); hold.setIm(i*2);
		test.push_back(hold);
		cout << test.at(i);
	}

	vector <ComplexNumber>::iterator it;
	unsigned int i = 0;
	cout << "Vector output using iterator in for-loop: \n";

	for (auto it = test.begin(); it != test.end(); ++it, ++i){
		hold.setRe(i); hold.setIm(i*2);
		cout << *it;
	}

}


ComplexNumber::ComplexNumber(){
	real = 0;
	complex = 0;
}
ComplexNumber::ComplexNumber(double realNumber, double imagNumber){
	real = realNumber;
	complex = imagNumber;
}
void ComplexNumber::setRe(double inputReal){
	real = inputReal;
}
void ComplexNumber::setIm(double inputImag){
	complex = inputImag;
}
double ComplexNumber::Re(){
	return real;
}
double ComplexNumber::Im(){
	return complex;
}
ostream& operator<< (ostream& out, ComplexNumber comp) {
 if(comp.complex >= 0){
		cout << comp.real << "+" << comp.complex << "i" << endl;
	}
	else{
		cout << comp.real << comp.complex << "i" << endl;
	}
	return out;
}
ComplexNumber ComplexNumber::operator+(ComplexNumber rhs){
	ComplexNumber sumTotal;
	sumTotal.real = real + rhs.real;
	sumTotal.complex = complex + rhs.complex;
	return sumTotal;
}
ComplexNumber ComplexNumber::operator-(ComplexNumber rhs){
	ComplexNumber subTotal;
	subTotal.real = real - rhs.real;
	subTotal.complex = complex - rhs.complex;
	return subTotal;
}
ComplexNumber ComplexNumber::operator*(ComplexNumber rhs){
	ComplexNumber mulTotal;
	mulTotal.real = (real * rhs.real) + (complex * (rhs.complex * (-1)));
	mulTotal.complex = (real * rhs.complex) + (complex * rhs.real);
	return mulTotal;
}
ComplexNumber ComplexNumber::operator/(ComplexNumber rhs){
	ComplexNumber divTotal;
	if ((real == 0) && (rhs.real == 0) && (rhs.complex == 0)){
		divTotal.real = numeric_limits<double>::infinity();
		divTotal.complex = numeric_limits<double>::infinity();
		return divTotal;
	}
	else{
		divTotal.real = ((real * rhs.real) + ((complex * (rhs.complex * -1)) * -1)) / ((pow(rhs.real,2)) + (pow(rhs.complex,2)));
		divTotal.complex = ((real * (rhs.complex * -1)) + (complex * rhs.real)) / ((pow(rhs.real,2)) + (pow(rhs.complex,2)));
		return divTotal;
 }
}
ComplexNumber::~ComplexNumber(){
}
