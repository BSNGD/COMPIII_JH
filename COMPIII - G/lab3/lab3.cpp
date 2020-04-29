///////////////////////////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;

class Mass {
public:
	void setMassAvoirdupoisPounds(double Amass);
	void setMassTroyPounds(double Bmass);
	void setMassMetricGrams(double Cmass);
	double getMassAvoirdupoisPounds();
	double getMassTroyPounds();
	double getMassMetricGrams();
private:
	double gramsMass;
	double avoirMass;
	double troyMass;
};

void clearBuffer();
int main()
{
	Mass Mass;
	double inputTroy;
	double inputAvoir;
	double inputGram;
	int userInput;

	do
	{
		cout << "Please enter 1 to use Avoirdupois pounds, 2 to use Troy pounds, 3 to use grams, or 0	to exit:";
		cin >> userInput;

		switch (userInput)
		{
		case 0:
		{
			cout << "Thanks for using the mass conversion program!" << endl;
			exit(1);
		}
		break;
		case 1:
		{
			cout << "Please enter a mass in Avoirdupois pounds: ";
			cin >> inputAvoir;
			Mass.setMassAvoirdupoisPounds(inputAvoir);
			cout << "Mass in " << Mass.getMassAvoirdupoisPounds() << " Avoirdupois Pounds" << endl;
			cout << "Mass in " << Mass.getMassTroyPounds() << " Troy Pounds" << endl;
			cout << "Mass in " << Mass.getMassMetricGrams() << "Grams" << endl;

		}
		break;
		case 2:
		{
			cout << "Please enter a mass in Troy pounds: ";
			cin >> inputTroy;
			Mass.setMassTroyPounds(inputTroy);
			cout << "Mass in " << Mass.getMassTroyPounds() << " Troy Pounds" << endl;
			cout << "Mass in " << Mass.getMassAvoirdupoisPounds() << " Avoirdupois Pounds" << endl;
			cout << "Mass in " << Mass.getMassMetricGrams() << "Grams" << endl;		
		}
		break;
		case 3:
		{
			cout << "Please enter a mass in grams: ";
			cin >> inputGram;
			Mass.setMassMetricGrams(inputGram);
			cout << "Mass in " << Mass.getMassMetricGrams() << "Grams" << endl;
			cout << "Mass in " << Mass.getMassAvoirdupoisPounds() << " Avoirdupois Pounds" << endl;
			cout << "Mass in " << Mass.getMassTroyPounds() << " Troy Pounds" << endl;
		}
		break;
		default:
		{
			cout << "Invalid input. Please enter a 1, 2, 3, or 0";
		}
		}
	} while (userInput < 0 || userInput > 3);

	return 0;
}

double Mass::getMassAvoirdupoisPounds()
{
	return avoirMass;
}

double Mass::getMassMetricGrams()
{
	return gramsMass;
}

double Mass::getMassTroyPounds()
{
	return troyMass;
}

void Mass::setMassAvoirdupoisPounds(double Amass)
{
	avoirMass = Amass;
	gramsMass = (Amass * 255.999) * 1.772;
	troyMass = (Amass * 255.999) / 96.0;
}

void Mass::setMassMetricGrams(double Cmass)
{
	gramsMass = Cmass;
	avoirMass = (Cmass / 1.7718451953) / 256.0;
	troyMass = (Cmass / 1.7718451953) / 96.0;
}

void Mass::setMassTroyPounds(double Bmass)
{
	troyMass = Bmass;
	avoirMass = (Bmass * 96.0) / 256.0;
	gramsMass = (Bmass * 96.0) * 1.772;
}
void clearBuffer()
{
	cin.clear();
	cin.ignore(10000, '\n');
}
