#include <iostream>
using namespace std;

class Rational{
	private:
		long numerator;
		long denominator;
	public:
		Rational();
		Rational(long newNumerator);
		Rational(long newNumerator, long newDenominator);
		void gcd(long& number1, long& number2);
		
		//friend operators
		friend ostream& operator << (ostream&, Rational const rationalNumber);
		//friend istream& operator >> (istream&, Rational &rationalNumber);
		
		//operator overloading
		Rational operator+(const Rational rationalNumber);
		Rational operator-(const Rational rationalNumber);
		Rational operator*(const Rational rationalNumber);
		Rational operator/(const Rational rationalNumber);
};

int main(){
	Rational r1 (-10,-2), r2 (6,12), r3 (6,-20), r4 (0), r5 (-0,12);
	cout << "r1 = " << r1 << endl;
	cout << "r2 = " << r2 << endl;
	cout << "r3 = " << r3 << endl;
	cout << "r4 = " << r4 << endl;
	cout << "r5 = " << r5 << endl;

	
	Rational operationTotal;
	cout << "operationTotal = " << operationTotal << endl;
	cout << r1 << " + " << r2 << " = ";
	operationTotal = r1 + r2;
	cout << operationTotal << endl;
	cout << r1 << " - " << r3 << " = ";
	operationTotal = r1 - r3;
	cout << operationTotal << endl;
	cout << r1 << " * " << r2 << " = ";
	operationTotal = r1 * r2;
	cout << operationTotal << endl;
	cout << r1 << " / " << r3 << " = ";
	operationTotal = r1 / r3;
	cout << operationTotal << endl;
	cout << r3 << " / " << r1 << " = ";
	operationTotal = r3 / r1;
	cout << operationTotal << endl;
	cout << r4 << " * " << r1 << " = ";
	operationTotal = r4 * r1;
	cout << operationTotal << endl;
	cout << r5 << " + " << r1 << " = ";
	operationTotal = r5 + r1;
	cout << operationTotal << endl;
	
	return 0;
}

//GCD
void Rational::gcd(long& number1, long& number2){
long gcd;
// if the numerator is negative turning numerator positive and returning negative GCD back
	if (number1 < 0){
		number1 = -1 * number1;
		for (int i = 1; i <= number1 && i <= number2; i++) {
			if (number1 % i == 0 && number2 % i == 0){
				gcd = i;
	    	}
		}
    number1 = -1 * (number1 / gcd);
    number2 = number2 / gcd;
	}
	else{
		for (int i = 1; i <= number1 && i <= number2; i++) {
			if (number1 % i == 0 && number2 % i == 0){
				gcd = i;
		    }
		}
	    number1 = number1 / gcd;
	    number2 = number2 / gcd;
	}
}

//Constructors
Rational::Rational(){
	numerator = 1;
	denominator = 1;
}
Rational::Rational(long newNumerator){
	denominator = 1;
	numerator = newNumerator;
	
}
Rational::Rational(long newNumerator, long newDenominator){
	try{
		if (newDenominator < 0 && newNumerator < 0){
			numerator = newNumerator;
			denominator = newDenominator * -1;
		}
		else if (newDenominator < 0){
			numerator = newNumerator * -1;
			denominator = newDenominator * -1;
		}		
		else if(newDenominator == 0){
			throw newDenominator;
		}
		else {
			numerator = newNumerator;
			denominator = newDenominator;
		}
	}
	catch (long newDenominator){
		cerr << "Exception caught - Invalid denominator at constructor" << endl
			 << "Giving rational number default values of 1/1" << endl;
		numerator = 1;
		denominator = 1;
	}
}

//friend operators
ostream& operator<< (ostream& out, Rational const rationalNumber){
	out << rationalNumber.numerator << "/" << rationalNumber.denominator;
	return out;
}
/*istream& operator>> (istream& in, Rational rationalNumber){
	
}*/

//operator overloading
Rational Rational::operator+(const Rational rationalNumber){
	Rational sumhelper;
	sumhelper.numerator = (numerator * rationalNumber.denominator) + (denominator * rationalNumber.numerator);
	sumhelper.denominator = (denominator * rationalNumber.denominator);
	gcd(sumhelper.numerator, sumhelper.denominator);
	return sumhelper;
}
Rational Rational::operator-(const Rational rationalNumber){
	Rational subhelper;
	subhelper.numerator = (numerator * rationalNumber.denominator) - (denominator * rationalNumber.numerator);
	subhelper.denominator = (denominator * rationalNumber.denominator);
	gcd(subhelper.numerator, subhelper.denominator);
	return subhelper;
}
Rational Rational::operator*(const Rational rationalNumber){
	Rational mulhelper;
	mulhelper.numerator = (numerator * rationalNumber.numerator);
	mulhelper.denominator = (denominator * rationalNumber.denominator);
	try{
		if (mulhelper.numerator == 0){
			throw mulhelper;
		}
		else{
			gcd(mulhelper.numerator, mulhelper.denominator);
			}
		}
	catch (Rational mulhelper){
		cerr << "0 found at results. Setting results to: ";
		mulhelper.numerator = 1;
		mulhelper.denominator = 1;
		return mulhelper;
	}
	return mulhelper;
}
Rational Rational::operator/(const Rational rationalNumber){
	Rational divhelper;
	// if other rational is negative then make results numerator negative
	if (rationalNumber.numerator < 0){
		divhelper.numerator = -1 * (numerator * rationalNumber.denominator);
		divhelper.denominator = (denominator * rationalNumber.numerator);
	}
	// else rational number is positive then results are positive
	else{
		divhelper.numerator = (numerator * rationalNumber.denominator);
		divhelper.denominator = (denominator * rationalNumber.numerator);
	}
	// if results denominator is negative turn it positive
	if (divhelper.denominator < 0){
		divhelper.denominator = -1 * divhelper.denominator;
	}
	try{
		if(divhelper.numerator == 0 || divhelper.denominator == 0){
			throw divhelper;
		}
		else{
			gcd(divhelper.numerator, divhelper.denominator);
		}
	}
	catch (Rational divhelper){
		cerr << "0 found at results. Setting results to: ";
		divhelper.numerator = 1;
		divhelper.denominator = 1;
		return divhelper;
	}
	return divhelper;
}

