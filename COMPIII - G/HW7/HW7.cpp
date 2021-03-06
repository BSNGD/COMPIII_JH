#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

//Javier Hernandez
//HW6 - Lab Sec 801
template<typename T>
	class MyComplex {
		private:
			T real;
			T imaginary;
		public:
			// constructors
			MyComplex();
			MyComplex(T& inputReal);
			MyComplex(T& inputReal, T& inputImaginary);
			
			// accessors and mutators
			void SetReal(T& inputReal);
			void SetImaginary(T& inputImaginary);
			MyComplex<T>* GetReal() const { return real; };
			MyComplex<T>* GetImaginary() const { return imaginary; };
			
			// friend in and out
			friend ostream& operator<<(ostream& out, const MyComplex<T>& comp);
			friend istream& operator>>(istream& in, const MyComplex<T>& comp);

			// + operator overloading
			MyComplex<T>& operator+(MyComplex<T>& comp);

			
			// - operator overloading
			MyComplex<T>& operator-(MyComplex<T>& comp);

					
			// * operator overloading
			MyComplex<T>& operator*(MyComplex const comp);

			
			// / functions
			MyComplex<T>& operator/(const MyComplex<T>& comp);
			
			//conjugate
			void SetConjugate() { real = real; imaginary = imaginary * -1; };
	};
	
template<typename T>MyComplex<T>& operator+(MyComplex<T>& comp, T& sumpart);
template<typename T>MyComplex<T>& operator+(T& sumpart, MyComplex<T>& comp);
			
template<typename T>MyComplex<T>& operator-(MyComplex<T>& comp, T& subpart);
template<typename T>MyComplex<T>& operator-(T& subpart, MyComplex<T>& comp);

template<typename T>MyComplex<T>& operator*(MyComplex<T>& comp, T& mulpart);
template<typename T>MyComplex<T>& operator*(T& mulpart, const MyComplex<T>& comp);
			
template<typename T>MyComplex<T>& operator/(const MyComplex<T>& comp, const T& denominator);



int main(){
	MyComplex <double>c1(2,3);
	MyComplex <double>c2(1.5,-4.01);
	MyComplex<int> c3(-2), c4(0,-5), c5;
	cout << "c1: " << c1 << endl;
	cout << "c2: " << c2 << endl;
	cout << "c3: " << c3 << endl;
	cout << "c4: " << c4 << endl;
	cout << "c5: " << c5 << endl;
	
	cout << "Using c5" << endl;
	cout << "Setting real to 1" << endl;
	c5.SetReal(1);
	cout << "Setting imaginary to 3" << endl;
	c5.SetImaginary(3);
	cout << "c5 real part is: " << c5.GetReal() << " and the imaginary part is: "<< c5.GetImaginary() << endl;
	cout << "c5: " << c5 << endl;

	
	cout << "using extraction operator to give new values to c5" << endl;
	for (int i = 0; i < 8; i++){	
		cin >> c5;
		cout << "c5 is now: " << c5 << endl;
	}
	
	MyComplex <double>operationTotal;
	cout << "Using c1 and c2" << endl;
	operationTotal = c1 + c2;
	cout << c1 << " + " << c2 << " = "  << operationTotal << endl;
	operationTotal = c1 - c2;
	cout << c1 << " - " << c2 << " = "  << operationTotal << endl;
	operationTotal = c1 * c2;
	cout << c1 << " * " << c2 << " = "  << operationTotal << endl;
	operationTotal = c1 / c2;
	cout << c1 << " / " << c2 << " = "  << operationTotal << endl;
	cout << "Setting c1 with its conjugate" << endl;
	c1.SetConjugate();
	cout << "c1 is now: " << c1 << endl;
	
	cout << "Using c2" << endl;
	operationTotal = c2 + 4.0;
	cout << c2 << " + 4 = "  << operationTotal << endl;	
	operationTotal = 4.0 + c2;
	cout << "4 + "  << c2 << " = " << operationTotal << endl;	
	operationTotal = c2 - 5.5;
	cout << c2 << " - 5.5 = "  << operationTotal << endl;	
	operationTotal = 5.5 + c2;
	cout << "5.5 - "  << c2 << " = " << operationTotal << endl;	
	operationTotal = c2 * 10;
	cout << c2 << " * 10 = "  << operationTotal << endl;	
	operationTotal = 10 * c2;
	cout << "10 * "  << c2 << " = " << operationTotal << endl;
	operationTotal = c2 / 9;
	cout << c2 << " / 9 = " << operationTotal << endl;
	
	return 0;
}

//Constructors
template<typename T>
MyComplex<T>::MyComplex(){
	real = 0;
	imaginary = 0;
}
template<typename T>
MyComplex<T>::MyComplex(T& inputReal){
	real = inputReal;
	imaginary = 0;
}
template<typename T>
MyComplex<T>::MyComplex(T& inputReal, T& inputImaginary){
	real = inputReal;
	imaginary = inputImaginary;
}
template<typename T>
void MyComplex<T>::SetReal(T& inputReal){
	real = inputReal;
}
//Accessors and Mutators
template<typename T>
void MyComplex<T>::SetImaginary(T& inputImaginary){
	imaginary = inputImaginary;
}

//friend in and out
template<typename T>
ostream& operator<< (ostream& out, const MyComplex<T>& comp) {
	//if both are zero then return real = 0
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

template<class T>
istream& operator>> (istream& in, MyComplex<T>& comp) {
	string holdComplex;
	size_t pos = 0;
	size_t n;
	string helper;

	cout << "Enter the real and imaginary part: ex. 0-9i, 50, 6i " << endl;
	getline(in, holdComplex);
	// if i is not found results true
	if (holdComplex.find('i') == string::npos){
		comp.real = stod(holdComplex);
		comp.imaginary = 0;
	}
	else{
		if ((pos = holdComplex.find('+')) != string::npos){
		comp.real = stod(holdComplex.substr(0, pos));
		comp.imaginary = stod(holdComplex.substr(pos+1, string::npos));
		}
		else if((pos = holdComplex.find('-')) != string::npos){
			n = std::count(holdComplex.begin(), holdComplex.end(), '-');
			helper = holdComplex.substr(0,pos);
			if( n == 2){
				pos = holdComplex.find('-', pos + 1);
				comp.real = stod(holdComplex.substr(0, pos));
				holdComplex.erase(std::remove(holdComplex.begin(), holdComplex.end(), 'i'), holdComplex.end());
				comp.imaginary = stod(holdComplex.substr(pos, string::npos));
			}
			else if(n == 1 && !helper.empty()){
				comp.real = stod(holdComplex.substr(0, pos));
				holdComplex.erase(std::remove(holdComplex.begin(), holdComplex.end(), 'i'), holdComplex.end());
				comp.imaginary = stod(holdComplex.substr(pos, string::npos));
			}
			else if(helper.empty()){
				holdComplex.erase(std::remove(holdComplex.begin(), holdComplex.end(), 'i'), holdComplex.end());
				comp.real = 0;
				comp.imaginary = stod(holdComplex.substr(pos+1, string::npos));
				comp.imaginary = comp.imaginary *-1;
			}
		}
		else{
			holdComplex.erase(std::remove(holdComplex.begin(), holdComplex.end(), 'i'), holdComplex.end());
			comp.real = 0;
			comp.imaginary = stod(holdComplex);
		}
	}
	return in;
}



// + operator overloading
template<class T>
MyComplex<T> MyComplex<T>::operator+(const MyComplex<T>& comp){
	MyComplex sumTotal;
	sumTotal.real = real + comp.real;
	sumTotal.imaginary = imaginary + comp.imaginary;
	return sumTotal;
}
MyComplex operator+(MyComplex const comp, double const sumpart){
	MyComplex sumTotal;
	sumTotal.real = comp.real + sumpart;
	sumTotal.imaginary = comp.imaginary;
	return sumTotal;
}
MyComplex operator+(double const sumpart, MyComplex const comp){
	MyComplex sumTotal;
	sumTotal.real = sumpart + comp.real;
	sumTotal.imaginary = comp.imaginary;
	return sumTotal;
}

// - operator overloading
MyComplex MyComplex::operator-(MyComplex comp){
	MyComplex subTotal;
	subTotal.real = real - comp.real;
	subTotal.imaginary = imaginary - comp.imaginary;
	return subTotal;
}
MyComplex operator-(MyComplex const comp, double const subpart){
	MyComplex subTotal;
	subTotal.real = subpart - comp.real;
	subTotal.imaginary = comp.imaginary;
	return subTotal;
}
MyComplex operator-(double const subpart, MyComplex const comp){
	MyComplex subTotal;
	subTotal.real = comp.real - subpart;
	subTotal.imaginary = comp.imaginary;
	return subTotal;
}

// * operator overloading
MyComplex MyComplex::operator*(MyComplex comp){
	MyComplex mulTotal;
	mulTotal.real = (real * comp.real) + (imaginary * (comp.imaginary * (-1)));
	mulTotal.imaginary = (real * comp.imaginary) + (imaginary * comp.real);
	return mulTotal;
}
MyComplex operator*(MyComplex const comp, double const mulpart){
	MyComplex mulTotal;
	mulTotal.real = comp.real * mulpart;
	mulTotal.imaginary = comp.imaginary * mulpart;
	return mulTotal;
}
MyComplex operator*(double const mulpart, MyComplex const comp){
	MyComplex mulTotal;
	mulTotal.real = mulpart * comp.real;
	mulTotal.imaginary = mulpart * comp.imaginary;
	return mulTotal;
}

// / operator overloading
MyComplex MyComplex::operator/(MyComplex const comp){
	MyComplex divTotal;
	divTotal.real = ((real * comp.real) + ((imaginary * (comp.imaginary * -1)) * -1)) / ((pow(comp.real,2)) + (pow(comp.imaginary,2)));
	divTotal.imaginary = ((real * (comp.imaginary * -1)) + (imaginary * comp.real)) / ((pow(comp.real,2)) + (pow(comp.imaginary,2)));
	return divTotal;
}
MyComplex operator/(MyComplex const comp, double const denominator){
	MyComplex divTotal;
	divTotal.real = comp.real / denominator;
	divTotal.imaginary = comp.imaginary / denominator;
	return divTotal;
}

//conjugate
void MyComplex::SetConjugate(){
	real = real;
	imaginary = imaginary * -1;
}


		
		
		

