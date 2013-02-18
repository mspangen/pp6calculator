#include <iostream>
#include <climits>
#include <cmath>
#include <vector>

#include "pp6calc.h" // Include header file to forward declare functions

int main()
{

	double a;
	double b;
	std::string operation;

	std::vector<std::string> valid_operations; // List of valid operations
	valid_operations.push_back("q");
	valid_operations.push_back("a");
	valid_operations.push_back("s");
	valid_operations.push_back("m");
	valid_operations.push_back("d");
	valid_operations.push_back("i");
	valid_operations.push_back("p");
	valid_operations.push_back("v3");
	valid_operations.push_back("v4");
	valid_operations.push_back("im");

	bool valid; // Boolean to check if operation choice is valid


	while (true)
	{

		valid = false;

		std::cout << "Choose operation [add (a), subtract (s), multiply (m), divide (d)]:\n";
		std::cin >> operation;

		for (unsigned int i=0; i<valid_operations.size(); ++i)
		{
			if (valid_operations.at(i) == operation) valid = true;
		}

		// Check if user entered quit command or if operation does not exist
		if (operation == "q") return 0;
		else if (!valid) {
			std::cout << "Error in operation choice!\n";
			input_error();
			continue;
		}

		std::cout << "Please enter number A:\n";
		std::cin >> a;
		std::cout << "Please enter number B:\n";	
		std::cin >> b;

		if (!std::cin)
		{
			std::cout << "Error in input! \n";
			input_error();
			continue;
		}

		if (operation == "a") {
			std::cout << "A+B = " << Add(a,b) << std::endl;
		} else if (operation == "s") {
			std::cout << " A-B = " << Subtract(a,b) << std::endl;
		} else if (operation == "m") {
			std::cout << "A*B = " << Multiply(a,b) << std::endl;
		} else if (operation == "d") { 
			if (b == 0) {
				std::cout << "Division by zero!\n";
				input_error();
				continue;
			}
			std::cout << "A/B = " << Divide(a,b) << std::endl;
		} else if (operation == "q") {
			break;
		}


	}

	return 0;

}




//==================================
// Functions for calculator
//==================================

//Function to call whenever an input exception is found
void input_error()
{
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}

//-------------------
// Math functions
//-------------------

double Add (double a, double b)
{
	return a+b;
}

double Subtract (double a, double b)
{
	return a-b;
}

double Multiply (double a, double b)
{
	return a*b;
}

double Divide (double a, double b)
{
	return a/b;
}

// Calculate the intercept of a line on the x-axis
double Intercept (double a, double b) //a*x+b
{
	
}

// Solve quadratic equation
double Poly2Solve (double a, double b, double c)
{

}

// Calculate length of 3-vector
double Vector3Length (double v1, double v2, double v3)
{

}

// Calculate length of 4-vector
double Vector4Length (double v1, double v2, double v3)
{

}

// Calculate invariant mass of particle
double InvMass (double m1, double m2, double angle)
{

}




//==================================
// Manual
//==================================

//Write manual text to be output when running program with --man

