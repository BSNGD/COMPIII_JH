#include <iostream>
#include <iomanip>
#include <string>
#include <getopt.h>
#include <cmath>
using namespace std;

// HW 2
// Javier Hernandez - COMPIII
// Lab Sec 801

string rightCheck = "";
void triangle(int a, int b, int c);
void triangle(double d, double e, double f);

// template function to sort input from min to max
// this will allow to use sortsides when int or double
template < class length>
	void sortsides(length &sideA, length &sideB, length &sideC){
		if (sideA > sideC){
			swap(sideA, sideC);
		}
		if (sideB > sideC){
			swap(sideB, sideC);
		}
		if (sideA > sideB){
			swap(sideA, sideB);
		}
	}

int main(int argc, char **argv)
{
	int sideA = 0;
	int sideB = 0;
	int sideC = 0;
	// command operation flag for getopt to indicate -i or -d
	char comOper;

	while ((comOper = getopt(argc, argv, "i::d::")) != -1)
	{
		cerr << "Operator chosen: " << comOper << endl;

		//checking the correct amount of arguments and vaues when using -i or -d
		if(argc !=2 && argc != 5){
			cerr << "Three values are expected ex. HW2 -option value1 value2 value3" << endl;
			cerr << "Exiting...";
			exit(1);
		}

		switch (comOper){
			case 'i':{
				//if -i is found and argument count is correct then parse command line
				if((argc == 5) && (comOper == 'i')){
					//using stoi to change string to int
					sideA = stoi(argv[2]);
					sideB = stoi(argv[3]);
					sideC = stoi(argv[4]);

	   				triangle(sideA, sideB, sideC);
				}
				else if((argc == 2) && (comOper == 'i')){
					while (true){
						//taking lengths and flushing cin after three values
						cin >> sideA >> sideB >> sideC;
						cin.clear();
						cin.ignore(1000, '\n');

						triangle(sideA, sideB, sideC);
					}
				}
				break;
			}

			case 'd':{
				//creating double variables for this block only
				double sideA = 0, sideB = 0, sideC = 0;

				//if -d is found and argument count is correct then parse command line
				if((argc == 5) && (comOper == 'd')){
					//using stod to change string to double
					sideA = stod(argv[2]);
					sideB = stod(argv[3]);
					sideC = stod(argv[4]);

	   				triangle(sideA, sideB, sideC);
				}
				else if ((argc == 2) && (comOper == 'd')){
					while (true){
					 	//taking lengths and flushing cin after three values
						cin >> sideA >> sideB >> sideC;
						cin.clear();
						cin.ignore(1000, '\n');

						triangle(sideA, sideB, sideC);
					}
				}
				break;
			}

			case '?':{
				cerr << "Unknown option : " << argv [1] << endl;
				cerr << "Exiting program...";
				exit (1);
				break; //unnecesary?
			}
		}
	return 0;
	}

	// when the program is called with no arguments or options it will default to integers
	// optind points toward index of the next argv should be null if no arguments are given
	if (argv[optind] == nullptr){
		cerr << "No parameters chosen" << endl;
		cerr << "Defaulting to integers (-i) option" << endl;

		while (true){
			// taking inputs and clearing cin buffer
			cin >> sideA >> sideB >> sideC;
			cin.clear();
			cin.ignore(1000, '\n');

			triangle(sideA, sideB, sideC);
		}
	}

	// when the program is called with no -i or -d option and 3 values, comOper will be assigned -1
	if ((comOper == -1)){
		cerr << "Defaulting to integers (-i) option" << endl;

		if (argc != 4){
			cerr << "Three values are expected ex. HW2 1 2 3" << endl;
		}

		while (argc == 4){
	   		// argv start at 1 because no option was chosen
			sideA = stoi(argv[1]);
			sideB = stoi(argv[2]);
			sideC = stoi(argv[3]);

	   		triangle(sideA, sideB, sideC);
	   		return 0;
		}
	}
	return 0;
}

void triangle(int a, int b, int c){
	sortsides(a, b, c);
	// check for 0 or negatives values
	if (a <= 0 || b <= 0 || c <= 0){
		cout << "Non positive numbers or zeros are not allowed" << endl;
		cout << "Exiting...";
		exit(1);
	}
	else {

		// Checking for right triangle
		if ((a * a) + (b * b) == (c * c)){
			rightCheck = "Right ";
		}
		else{
			rightCheck = "";
		}

		// triangle inequality theorem
		if ((a + b) <= c){
			cout << a << " " << b << " " << c << " " << "Not a triangle" << endl;
		}
		// all sides are equal
		else if (a == b && b == c){
			cout << a << " " << b << " " << c << " " << "Equilateral triangle" << endl;
		}
		// two sides are equal
		else if (a == b || a == c || b == c){
				cout << a << " " << b << " " << c << " " << rightCheck << "Isosceles triangle" << endl;
		}
		// all sides are different sides
		else {
				cout << a << " " << b << " " << c << " " << rightCheck << "Scalene triangle" << endl;
		}
	}
}

void triangle(double d, double e, double f)
{
	const double EPSILON = 0.001;
	sortsides(d, e , f);
	// check for 0 or negatives values
	if (d <= 0 || e <= 0 || f <= 0){
		cout << "Non positive numbers or zeros are not allowed" << endl;
		cout << "Exiting...";
		exit(1);
	}
	else{
		//setting precision for cout
		cout << fixed << setprecision(5);

		// Checking for right triangle
		if ((d * d) + (e * e) == (f * f)){
			rightCheck = "Right ";
		}
		else{
			rightCheck = "";
		}

		// triangle inequality theorem
		if ((d + e) <= f){
			cout << d << " " << e << " " << f << " " << "Not a triangle" << endl;
		}
		// all sides are equal
		else if ((fabs(d - e) < EPSILON) && (fabs(e - f) < EPSILON) && (fabs(f - d) < EPSILON)){
			cout << d << " " << e << " " << f << " " << "Equilateral triangle" << endl;
		}
		// two sides are equal
		else if ((d == e && d != f) || (d == f && e != f)){
				cout << d << " " << e << " " << f << " " << rightCheck << "Isosceles triangle" << endl;
		}
		// all sides are different sides
		else {
				cout << d << " " << e << " " << f << " " << rightCheck << "Scalene triangle" << endl;
		}
	}
}

