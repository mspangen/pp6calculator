#include <iostream>
#include <climits>
#include <cmath>
#include <string>
#include <vector>
#include <set>

#include "pp6calc.h" // Include header file to forward declare functions

int main(int argc, char* argv[])
{

	if (argc == 1 && argv[1] == "-h") {
		helptext();
		return 0;
	}

	// Variables used by calculator
	double a;
	double b;
	double c;

	std::string operation; // Temporary variable to store operation chosen by user

	//Define set of available operations
	const int Noperations = 10;
	std::string valid_operations[Noperations] = {"q","a","s","m","d","i","p","v3","v4","im"};
	std::set<std::string> valid_operations_set; // Set of valid operations
	for (int i=0; i<Noperations; ++i) valid_operations_set.insert(valid_operations[i]);


	while (true) // Loop over calculator menu until user quits with "q"
	{
		std::cout << "Choose operation:\n";
		std::cin >> operation; // Get operation from user

		if (!valid_operations_set.count(operation)) { // Check if user input is valid
			std::cout << "Error in operation choice!\n";
			input_error();
			continue;
		} else if (operation == "q") { // Check if user wants to quit
			return 0;
		}

		// Prompt user for numbers to process depending on operation chosen
		std::cout << "Enter number A:\n";
		std::cin >> a;
		std::cout << "Enter number B:\n";	
		std::cin >> b;
		if (operation == "p") {
			std::cout << "Enter number C:\n";
			std::cin >> c;
		}

		if (!std::cin) { // Check for errors in input
			std::cout << "Error in input! \n";
			input_error();
			continue;
		}

		// Calculate result depending on the operation chosen
		if (operation == "a") {
			std::cout << "A+B = " << Add(a,b) << std::endl;
		}
		else if (operation == "s") {
			std::cout << " A-B = " << Subtract(a,b) << std::endl;
		}
		else if (operation == "m") {
			std::cout << "A*B = " << Multiply(a,b) << std::endl;
		}
		else if (operation == "d") { 
			if (b == 0) {
				std::cout << "Division by zero!\n";
				input_error();
				continue;
			}
			std::cout << "A/B = " << Divide(a,b) << std::endl;
		}
		else if (operation == "i") {
			std::cout << "Line intercepts x-axis at x = " << Intercept(a,b) << std::endl;
		}
		else if (operation == "p") {
			std::vector<double> solutions = Poly2Solve(a,b,c);
			std::cout << "Solution to 2nd degree polynomial:\n";
			for (unsigned int i=0; i<solutions.size(); ++i)
			{
				std::cout << "x" << i << " = " << solutions.at(i) << std::endl;
			}
			if (solutions.size() == 0) {
				std::cout << "None" << std::endl;
			}
		}
		else if (operation == "q") {
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

double Intercept (double a, double b)
{
	return -b/a;
}

std::vector<double> Poly2Solve (double a, double b, double c)
{
	std::vector<double> solutions;
	double d = b*b - 4*a*c; // Discriminant

	if (a == 0 && b != 0) {
		solutions.push_back(-c/b);
	}	else if (d > 0 && a != 0) {
		solutions.push_back( (-b + sqrt(d))/(2*a) );
		solutions.push_back( (-b - sqrt(d))/(2*a) );
	} else if (d == 0 && a != 0) {
		solutions.push_back(-b/(2*a));
	}

	return solutions;

}

double Size3Vec (double v1, double v2, double v3) // Size of 3-vector
{
	return sqrt(v1*v1 + v2*v2 + v3*v3);
}

double Size4Vec(double v0, double v1, double v2, double v3) // Size of 4-vector
{
	double square = v0*v0 - v1*v1 - v2*v2 - v3*v3; // We assume metric (+1,-1,-1,-1)

	if (square >= 0) {
		return sqrt(square);
	}	else {
		return -1;
	}
}



/*
// Calculate the intercept of a line on the x-axis
double Intercept (double a, double b) //a*x+b
{
	return 0;
}

// Solve quadratic equation
double Poly2Solve (double a, double b, double c)
{
	return 0;
}

// Calculate length of 3-vector
double Vector3Length (double v1, double v2, double v3)
{
	return 0;
}

// Calculate length of 4-vector
double Vector4Length (double v1, double v2, double v3)
{
	return 0;
}

// Calculate invariant mass of particle
double InvMass (double m1, double m2, double angle)
{
	return 0;
}

*/


//==================================
// Help text
//==================================

//Write help text to be output when running program with -h
void helptext()
{
	std::cout << "========================\n";
	std::cout << "How to use this program \n";
	std::cout << "========================\n";
	std::cout << "1) Enter the operation that you want to perform when prompted.\n";
	std::cout << "   Available operations:\n";
	std::cout << "   (a) Addition a+b, (s) Subtraction a-b, (m) Multiplication a*b, (d) Division a/b,\n";
	std::cout << "   (i) Find intercept of straight line ax+b with x-axis,\n";
	std::cout << "   (p) Solve 2nd degree polynomial ax^2 + bx + c = 0,\n";
	std::cout << "   (v3) Calculate size of 3-vector (a, b, c),\n";
	std::cout << "   (v4) Calculate size of 4-vector (a, b, c, d) assuming metric (1, -1, -1, -1),\n";
	std::cout << "   (im) Calculate invariant mass of particle pair.\n";
}
