#include <iostream>
using namespace std;

int main ()
{
	float loanMonths = 0;
	float interestRate = 0.001;
	float loanAmount = 0;
	float toPay = 0;
	float monthlyPayment = 0;
	float totalInterest = 0;
	
	cout << "Please enter the annual rate as a percentage (e.g. 15 for 15%) (enter 0 to quit)" << endl;
	cin >> interestRate;
	interestRate = interestRate / 100;
	
	if (interestRate <= 0.0001){
		return (0);
	}
	else
	{
		cout << "Please enter the amount you would like to receive:" << endl;
		cin >> loanAmount;
		
		cout << "Please enter the loan period:" << endl;
		cin >> loanMonths;
		
		toPay = loanAmount / (1 - (interestRate * (loanMonths / 12)));
		cout << "The total amount of your loan: $" << toPay << endl;
		
		monthlyPayment = toPay / loanMonths;
		cout << "Your monthly payment for " << loanMonths << " months will be $" << monthlyPayment << endl;
		
		return (0);
	}
}
