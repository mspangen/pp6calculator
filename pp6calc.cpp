#include <iostream>
#include <sstream>
#include <climits>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

#include "pp6calc.h" // Include header file to forward declare functions

int main(int argc, char* argv[])
{

	if (argc == 1 && argv[1] == "-h") {
		helptext();
		return 0;
	}

	std::string operation; // Variable to store operation chosen by user

	//Define set of available operations
	const int Noperations = 10;
	std::string valid_operations[Noperations] = {"q","a","s","m","d","i","p","v3","v4","im"};
	std::set<std::string> valid_operations_set (valid_operations,valid_operations+Noperations); // Set of valid operations

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

		vars = get_user_input(operation); // Prompt user for numbers to process depending on operation chosen
		if (vars.size() == 0) { // If size is zero then there are errors in input
			std::cout << "Error in input!\n";
			continue;
		}

		// Calculate result depending on the operation chosen
		if (operation == "a") {
			std::cout << vars.at(0) << " + " << vars.at(1) << " = " << Add(vars.at(0),vars.at(1)) << std::endl;
		}
		
		else if (operation == "s") {
			std::cout << vars.at(0) << " - " << vars.at(1) << " = " << Subtract(vars.at(0),vars.at(1)) << std::endl;
		}
		
		else if (operation == "m") {
			std::cout << vars.at(0) << " * " << vars.at(1) << " = " << Multiply(vars.at(0),vars.at(1)) << std::endl;
		}
		
		else if (operation == "d") {
			if (vars.at(1) == 0) {
				std::cout << "Division by zero!\n";
				input_error();
				continue;
			}
			std::cout << vars.at(0) << " / " << vars.at(1) << " = " << Divide(vars.at(0),vars.at(1)) << std::endl;
		}
		
		else if (operation == "i") {
			std::cout << "Line " << vars.at(0) << "*x+" << vars.at(1) << " intercepts x-axis at x = " << Intercept(vars.at(0),vars.at(1)) << std::endl;
		}
		
		else if (operation == "p") {
			std::vector<double> solutions = Poly2Solve(vars.at(0),vars.at(1),vars.at(2));
			std::cout << "Solution to 2nd degree polynomium " << vars.at(0) << "*x^2+" << vars.at(1) << "*x+" << vars.at(2) << "=0:\n";
			for (unsigned int i=0; i<solutions.size(); ++i)
			{
				std::cout << "x" << i << " = " << solutions.at(i) << std::endl;
			}
			if (solutions.size() == 0) {
				std::cout << "None" << std::endl;
			}
		}
		
		else if (operation == "v3") {
			double result = Size3Vec(vars.at(0),vars.at(1),vars.at(2));
			std::cout << "Size of 3-vector (" << vars.at(0) << "," << vars.at(1) << "," << vars.at(2) << ") = " << result << "\n";
		}

		else if (operation == "v4") {
			double result = Size4Vec(vars.at(0),vars.at(1),vars.at(2),vars.at(3));
			if (result >= 0) {
				std::cout << "Size of 4-vector (" << vars.at(0) << "," << vars.at(1) << "," << vars.at(2) << "," << vars.at(3) << ") = " << result << "\n";
			} else {
				std::cout << "Invalid entry. Negative square of components\n";
			}
		}

		else if (operation == "im") {
		//	double result = InvariantMass(vars.at(0),vars.at(1),vars.at(2),vars.at(3),...);
		//	std::cout << "Invariant mass of particles M = " << result << std::endl;
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

// Function to call whenever an input exception is found
void input_error()
{
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}

// Function to get user input
std::vector<double> get_user_input(std::string operation)
{
	std::vector<double> variables;
	std::string prompt_text;
	int nvars;

	if (operation == "a") {
		prompt_text = "Addition A+B. Enter as A,B:";
		nvars = 2;
	} else if (operation == "s") {
		prompt_text = "Subtraction A-B. Enter as A,B:";
		nvars = 2;
	} else if (operation == "m") {
		prompt_text = "Multiplication A*B. Enter as A,B:";
		nvars = 2;
	} else if (operation == "d") {
		prompt_text = "Division A/B. Enter as A,B:";
		nvars = 2;
	} else if (operation == "i") {
		prompt_text = "Intersect of line A*x+B with x-axis. Enter as A,B:";
		nvars = 2;
	} else if (operation == "p") {
		prompt_text = "Solution to 2nd order polynomial A*x^2+B*x+C=0. Enter as A,B,C:";
		nvars = 3;
	} else if (operation == "v3") {
		prompt_text = "Size of 3-vector (v1,v2,v3). Enter as v1,v2,v3:";
		nvars = 3;
	} else if (operation == "v4") {
		prompt_text = "Size of 4-vector (v0,v1,v2,v3). Enter as v0,v1,v2,v3:";
		nvars = 4;
	} else if (operation == "im") {
		prompt_text = "Invariant mass of particle pair. Enter as E1,E2,"; // ???
		nvars = 4; // ???
	}
	
	std::cout << prompt_text << std::endl;

	std::string input;
	std::cin >> input;

	if (!std::cin) { // Check for errors in input
		input_error();
	}
	else {
		variables = interpret_input(input);
	}

	if (!(variables.size() == nvars)) {
		variables.clear();
	}

	return variables;

}

// Function to interpret input string
// This splits comma separated string into input variables
std::vector<double> interpret_input (std::string input)
{
	std::vector<double> variables; // Vector of variables to output
	size_t lastfound = -1;
	size_t found;
	std::string variable;
	double doublevar;
	std::string error_msg; // Error message if error found in variable

	while (true) {
		found = input.find(",",lastfound+1); // Position of comma in string
		if (found != std::string::npos) { // Check if a comma was found. If not, found==std::string::npos
			variable = input.substr(lastfound+1,found-(lastfound+1));
		} else {
			variable = input.substr(lastfound+1,input.length()-(lastfound+1));
		}

		lastfound = found; // Update position of last found comma

		// Check if the variable is a valid number
		if (variable.empty()) error_msg = "Empty variable!";
		else if (variable.find_first_not_of("0123456789.-") != std::string::npos) error_msg = "Invalid characters!";
		else if (std::count(variable.begin(), variable.end(),'.') > 1) error_msg = "Too many periods!";
		else if (variable.find_first_of("-",1) != std::string::npos) error_msg = "Minus sign inside number!";

		if (!error_msg.empty())	{ // If errors are found clear variable vector and exit loop
			variables.clear();
			std::cout << error_msg << std::endl;
			break;
		}

		std::stringstream convert(variable);
		convert >> doublevar; // Convert variable string to double

		variables.push_back(doublevar);

		if (found == std::string::npos) break;
	}

	return variables;

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
	std::cout << "Enter the operation that you want to perform when prompted.\n";
	std::cout << "   Available operations:\n";
	std::cout << "   (a)  Addition a+b, (s) Subtraction a-b, (m) Multiplication a*b, (d) Division a/b,\n";
	std::cout << "   (i)  Find intercept of straight line a*x+b with x-axis,\n";
	std::cout << "   (p)  Solve 2nd degree polynomial a*x^2 + b*x + c = 0,\n";
	std::cout << "   (v3) Calculate size of 3-vector (a, b, c),\n";
	std::cout << "   (v4) Calculate size of 4-vector (a, b, c, d) assuming metric (1, -1, -1, -1),\n";
	std::cout << "   (im) Calculate invariant mass of particle pair using their energies, momenta and masses.\n";
}
