#include <iostream>
using namespace std;

void weightinput(int& Pounds, double& Ounces){
	
	while (true){
	
	cout << "Please enter the number of pounds" << endl;
	cin >> Pounds;

	cout << "Please enter the number of ounces" << endl;
	cin >> Ounces;

	
	if (cin.fail() || Ounces < 0 || Pounds < 0){
		cerr << "That's not a number greater than or equal to 0! Please try again..." << endl;
		cin.clear();
		
	}
	if (Ounces > 16){
		cerr << "That's not a number greater than or equal to 0, and less than 16! Please try again..." << endl;
	}
	}
}

int main(){
	int weightP;
	double weightO;
	
	weightinput(weightP, weightO);
	
	return 0;
}
