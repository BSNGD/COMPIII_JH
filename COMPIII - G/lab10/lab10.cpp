// Day 10: Mass class with exception handling
#include <iostream>
#include <string>
#include <limits>
#include <exception>      // std::exception

using namespace std;


const int IGNORE_SIZE = 256;
const double MAX_DOUBLE = std::numeric_limits<double>::max();

class input_exception : public std::exception{
	protected:
		string holdError;
	public:
		input_exception();
		input_exception(string _message) { holdError = _message; };
		const char* what() const throw() { return this->holdError.c_str(); };
};

/**
 *  Generic function to input a number, and check whether the number is within
 *  the specified bounds.
 *  If within bounds, return the input number.
 *  If not a number or not within bounds, should throw an input_error exception with the
 *  specified error message.
 */
template<typename T>
T checkInput(T lower, T upper, string message){
	T in;
	input_exception _error(message);
	try{
		if ( !(cin >> in) || (in < lower) || (in > upper) ) {
			throw _error;
		}
		else{
			return in;
		}
	}
	catch(exception& _error){
		cerr << _error.what() << endl;
		cin.clear();
		cin.ignore(IGNORE_SIZE, '\n');
		return checkInput(lower, upper, message);
	}
}

class Mass {
	public:
		void setMassAvoirdupoisPounds( double ap ) { drams = ap*dramsPerAvoirdupoisPound; }
		void setMassTroyPounds( double tp ) { drams = tp*dramsPerTroyPound; }
		void setMassMetricGrams( double mg ) { drams = mg/metricGramsPerDram; }
		double getMassAvoirdupoisPounds() { return drams/dramsPerAvoirdupoisPound; }
		double getMassTroyPounds() { return drams/dramsPerTroyPound; }
		double getMassMetricGrams() { return drams*metricGramsPerDram; }
	private:
		double drams;
		const int dramsPerAvoirdupoisPound = 256;
		const int dramsPerTroyPound = 96;
		const double metricGramsPerDram = 1.7718451953125;
};

int main()
{
	int choice;
	double inputMass;
	Mass m;
		
	do {
		do{
		    cout << "Please enter 1 to use Avoirdupois pounds, 2 to use Troy pounds, "
			     << "3 to use grams, or 0 to exit: ";
				 
			choice = checkInput(0, 3, "That's not a number between 0 and 3!");
			break;
			
		} while (true);
		
		switch ( choice ) {
			case 1:
				do {
				    cout << "Please enter a mass in Avoirdupois pounds: ";
				    
				    inputMass = checkInput(0.0, MAX_DOUBLE, "That's not a positive number!");
				    break;
					
		        } while (true);
				m.setMassAvoirdupoisPounds( inputMass );
				break;
				
			case 2:
				do {
				    cout << "Please enter a mass in Troy pounds: ";
				    
				    inputMass = checkInput(0.0, MAX_DOUBLE, "That's not a positive number!");
				    break;
			        
		        } while (true);
				m.setMassTroyPounds( inputMass );
				break;
				
			case 3:
				do {
				    cout << "Please enter a mass in grams: ";
				    
				    inputMass = checkInput(0.0, MAX_DOUBLE, "That's not a positive number!");
				    break;
 
		        } while (true);
				m.setMassMetricGrams( inputMass );
				break;
				
			default:
				cout << "Thanks for using the mass conversion program!\n";
				exit( 1 );
				
		} // end switch
		
		cout << "Mass in Avoirdupois pounds is " << m.getMassAvoirdupoisPounds() << endl;
		cout << "Mass in Troy pounds is " << m.getMassTroyPounds() << endl;
		cout << "Mass in grams is " << m.getMassMetricGrams() << endl << endl;
		
	} while (true);
	
	return 0;
}
