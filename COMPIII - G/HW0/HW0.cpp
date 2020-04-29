#include <iostream>
using namespace std;

// HW 0
// Javier Hernandez
 
int main(int argc, char** argv)
{
    
	cout << "Hello, World" << endl;
 
 // loop to ccreate a numbered list
    for (int i = 0; i < argc; ++i)
        cout << i << "---" << argv[i] << "\n";
 
    return 0;
} 
