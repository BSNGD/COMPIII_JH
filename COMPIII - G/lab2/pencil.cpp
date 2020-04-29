#include <iostream>
using namespace std;

int main(){
	
	float costPencil;
	float yearsPurchase;
	float rateInflation;
	
	cout << "Enter cost of Pencil:" << endl;
	cin >> costPencil;
	
	cout << "Enter amount of years to buy Pencils:" << endl;
	cin >> yearsPurchase;
	
	cout << "Enter rate of inflation (percent) :"  << endl;
	cin >> rateInflation;
	rateInflation = rateInflation / 100;
	
	for (int i = 0; i < yearsPurchase; i++){
		cout.precision(4);
		cout << "For year: " << i << " - Pencil prices are: " << costPencil << endl;
		costPencil = (costPencil * rateInflation) + costPencil;
	}
	return 0;
}
