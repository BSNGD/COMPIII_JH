#include <iostream>
using namespace std;

int main(){
	const float TOTALPURCHASE = 1000;
	const float INTRATE = 0.18;
	float monthlyRate = INTRATE/12;
	const float MONTHLYPAYMENT = 50;
	float interestMonth = 0;
	float amountLeft = 0;
	float totalDebt = TOTALPURCHASE;
	float interestPaid = 0;
	int monthCount = 0;
	
	while (totalDebt > 0){
		interestMonth = totalDebt * monthlyRate;
		cout << "Monthly interest to pay is: " << interestMonth << endl;
		
		if (totalDebt >= MONTHLYPAYMENT){
			amountLeft = MONTHLYPAYMENT - interestMonth;
		}
		else{
			amountLeft = totalDebt;
		}
		totalDebt = totalDebt - amountLeft;
		
		interestPaid = interestPaid + interestMonth;
		monthCount++;
	}
	
	cout << "Stereo cost: " << TOTALPURCHASE << endl;
	cout << "Interest paid over " << monthCount << " months will be: " << interestPaid << endl;
	return 0;
}
