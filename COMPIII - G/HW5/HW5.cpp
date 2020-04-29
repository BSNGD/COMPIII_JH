#include <iostream>
#include <math.h>
#include <string>
using namespace std;

//Javier Hernandez
//HW4 - Lab Sec 801

class MyComplex {
	private:
		double real;
		double imaginary;
	public:
		//constructors
		MyComplex();
		MyComplex(double inputReal);
		MyComplex(double inputReal, double inputImaginary);
		
		//accessors and mutators
		void SetReal(double inputReal);
		void SetImaginary(double inputImaginary);
		const double GetReal();
		const double GetImaginary();
		
		//friend in and out
		friend ostream& operator<< (ostream&, const MyComplex comp);
		friend istream& operator>> (istream&, MyComplex &comp);
		
		//operators overloading
		MyComplex operator+(MyComplex comp);
		MyComplex operator-(MyComplex comp);
		MyComplex operator*(MyComplex comp);
		
		
		//conjugate
		void SetConjugate();
		

};

int main(){
	MyComplex c1(2,3), c2(1,-4), c3(-2), c4(0,-5), c5;
	cout << "c1: " << c1 << endl;
	cout << "c2: " << c2 << endl;
	cout << "c3: " << c3 << endl;
	cout << "c4: " << c4 << endl;
	
	cout << "Using c5" << endl;
	cout << "Setting real to 1" << endl;
	c5.SetReal(1);
	cout << "Setting imaginary to 3" << endl;
	c5.SetImaginary(3);
	cout << "c5 real part is: " << c5.GetReal() << " and the imaginary part is: "<< c5.GetImaginary() << endl;
	cout << "c5: " << c5 << endl;

	
	cout << "using extraction operator to give new values to c5" << endl;
	cin >> c5;
	cout << "c5 is now: " << c5 << endl;
	cout << "Using c1 and c2" << endl;
	MyComplex operationTotal;
	operationTotal = c1 + c2;
	cout << "c1 + c2 = " << operationTotal << endl;
	operationTotal = c1 - c2;
	cout << "c1 - c2 = " << operationTotal << endl;
	operationTotal = c1 * c2;
	cout << "c1 * c2 = " << operationTotal << endl;
	cout << "Setting c1 with conjugate: ";
	c1.SetConjugate();
	cout << c1 << endl;
	
	return 0;
}

//Constructors
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
//Accessors and Mutators
void MyComplex::SetImaginary(double inputImaginary){
	imaginary = inputImaginary;
}
const double MyComplex::GetReal(){
	return real;
}
const double MyComplex::GetImaginary(){
	return imaginary;
}
//friend in and out
ostream& operator<< (ostream& out, const MyComplex comp) {	
	if (comp.real == 0 && comp.imaginary == 0){
		cout << comp.real;
	}
	else if(comp.real == 0 && comp.imaginary !=0){
		cout << comp.imaginary << "i";
	}
	else if(comp.real !=0 && comp.imaginary == 0){
		cout << comp.real;
	}
	else if(comp.imaginary > 0){
		cout << comp.real << "+" << comp.imaginary << "i";
	}
	else{
		cout << comp.real << comp.imaginary << "i";
	}
	return out;
}
istream& operator>> (istream& in, MyComplex &comp) {
	string holdComplex;
	unsigned delimiterOne = holdComplex.find("+");
	unsigned delimiterTwo = holdComplex.find("-");
	double holdReal;
	double holdImaginary;

	cout << "Enter a new value for complex number. ex. 5+19i, 0-2i, 10i, etc." << endl;
	getline(cin, holdComplex);
	holdReal = stod(holdComplex.substr(0, delimiterOne));
	holdImaginary = stod(holdComplex.substr(delimiterOne));
 cout << holdReal << " and " << holdImaginary << endl;
		return in;
}

//operators overloading
MyComplex MyComplex::operator+(MyComplex comp){
	MyComplex sumTotal;
	sumTotal.real = real + comp.real;
	sumTotal.imaginary = imaginary + comp.imaginary;
	return sumTotal;
}
MyComplex MyComplex::operator-(MyComplex comp){
	MyComplex subTotal;
	subTotal.real = real - comp.real;
	subTotal.imaginary = imaginary - comp.imaginary;
	return subTotal;
}
MyComplex MyComplex::operator*(MyComplex comp){
	MyComplex mulTotal;
	mulTotal.real = (real * comp.real) + (imaginary * (comp.imaginary * (-1)));
	mulTotal.imaginary = (real * comp.imaginary) + (imaginary * comp.real);
	return mulTotal;
}

//conjugate
void MyComplex::SetConjugate(){
	real = real;
	imaginary = imaginary * -1;
}


		
		
		

