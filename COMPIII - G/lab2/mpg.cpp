#include <iostream>

using namespace std;

const float LITERS_GALLONS = 3.785;
void mpg(float gas, float distance){

	float totalMpg = distance/gas;
	cout << "Your MPG is: " << totalMpg << endl;
}
int main(){
	float liters = 0;
	float miles = 0;
	float gallons = 0;
	
	while(true){
		cout << "Enter the amount of gas in liters: ";
		cin >> liters;
		
		cout << endl;
		cout << "Enter miles driven: ";
		cin >> miles;

		gallons = liters/LITERS_GALLONS;
		mpg(gallons,miles);
		
	}
	return 0;
}
