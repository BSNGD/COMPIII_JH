#include <iostream>
#include <string>

using namespace std;

// HW 1
// Javier Hernandez - COMPIII

void triangle(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0) { // check for 0 or negatives values
        cout << "Non positive numbers or zeros are not allowed" << endl;
        cout << "Last value must be larger or equal to the previous values";
        exit(1);
    }
    else {
        if ((a + b) <= c || (b + c) <= a || (a + c) <= b) { // triangle inequality theorem
            cout << a << " " << b << " " << c << " " << "Not a triangle" << endl;
        }
        else if (a == b && b == c) { // all sides are equal
            cout << a << " " << b << " " << c << " " << "Equilateral triangle" << endl;
        }
        else if (a == b || a == c || b == c) { // two sides are equal
            if ((a * a) + (b * b) == (c * c)) { // check for right triangle
                cout << a << " " << b << " " << c << " " << "Right Isosceles triangle" << endl;
            }
            else {
                cout << a << " " << b << " " << c << " " << "Isosceles triangle" << endl;
            }
        }
        else if (a != b || a != c || b != c) { // all sides are different sides
            if ((a * a) + (b * b) == (c * c)) { // check for right triangle
                cout << a << " " << b << " " << c << " " << "Right Scalene triangle" << endl;
            }
            else {
                cout << a << " " << b << " " << c << " " << "Scalene triangle" << endl;
            }
        }
    }
}

int main(int argc, char** argv)
{
    int sideA = 0;
    int sideB = 0;
    int sideC = 0;
	
	if (argc <= 1) {
		while(true){
	    cin >> sideA >> sideB >> sideC;

        //sorting from min to max
        if (sideA > sideC) {
            swap(sideA, sideC);
        }
        if (sideB > sideC) {
            swap(sideB, sideC);
        }
        if (sideA > sideB) {
            swap(sideA, sideB);
        }
        triangle(sideA, sideB, sideC);
		}
	}
    else if (argc == 4) {
		sideA = stoi(argv[1]);
		sideB = stoi(argv[2]);
		sideC = stoi(argv[3]);

        //sorting from min to max
        if (sideA > sideC) {
            swap(sideA, sideC);
        }
        if (sideB > sideC) {
            swap(sideB, sideC);
        }
        if (sideA > sideB) {
            swap(sideA, sideB);
        }
        triangle(sideA, sideB, sideC);
        return 0;
    	}
    else {
        cerr << "Error - not suitable integers to form a triangle";
        exit(1);
	}
	
	return 0;
}
