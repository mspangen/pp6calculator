#include <iostream>
#include <string>
#include <vector>
#include <set>

#include "pp6calculator.hpp"
#include "pp6lib/pp6math.hpp"
#include "pp6lib/string_interpret.hpp"

int main(int argc, char* argv[])
{

	if (argc == 2 && argv[1] == "-h") {
		helptext();
		return 0;
	}

	std::string operation; // Variable to store operation chosen by user

	//Define set of available operations
	const int Noperations = 11;
	std::string valid_operations[Noperations] = {"q","a","s","m","d","i","p","v3","v4","im","sort"};
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
			std::vector<double> solutions;
			Poly2Solve(vars.at(0),vars.at(1),vars.at(2),solutions);
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
			double result = InvMass(vars.at(0),vars.at(1),vars.at(2),vars.at(3),vars.at(4));
			std::cout << "Invariant mass of particles M = " << result << std::endl;
		}

		else if (operation == "sort") {
			BubbleSort(vars);
			std::cout << "Sorted array: " << vars[0];
			for (int i=1; i<vars.size(); ++i) {
				std::cout << "," << vars[i];
			}
			std::cout << std::endl;
		}

		else if (operation == "q") {
			break;
		}

		std::cout << "=================" << std::endl;

	}

	return 0;

}


//=====================================
// Other functions
//=====================================

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
		prompt_text = "Invariant mass of particle pair. Enter as m1,m2,p1,p2,phi:";
		nvars = 5;
	} else if (operation == "sort") {
		prompt_text = "Sort array a[N] of numbers in descending order. Input as a0,a1,a2,...:";
		nvars = -1; // Set to -1 since we don't know the size of the array to sort
	}
	
	std::cout << prompt_text << std::endl;

	std::string input;
	std::cin >> input;

	if (!std::cin) { // Check for errors in input
		input_error();
	}
	else {
		string_interpret(input,variables);
	}

	if (variables.size() != nvars && nvars != -1) {
		variables.clear();
	}

	return variables;

}


//==================================
// Help text
//==================================

//Write help text to output when running program with -h
void helptext()
{
	std::cout << "========================\n";
	std::cout << "How to use this program \n";
	std::cout << "========================\n";
	std::cout << "Enter the operation that you want to perform when prompted.\n";
	std::cout << "   Available operations:\n";
	std::cout << "   (a)  Addition a+b,\n";
	std::cout << "   (s)  Subtraction a-b,\n";
	std::cout << "   (m)  Multiplication a*b,\n";
	std::cout << "   (d)  Division a/b,\n";
	std::cout << "   (i)  Find intercept of straight line a*x+b with x-axis,\n";
	std::cout << "   (p)  Solve 2nd degree polynomial a*x^2 + b*x + c = 0,\n";
	std::cout << "   (v3) Calculate size of 3-vector (a, b, c),\n";
	std::cout << "   (v4) Calculate size of 4-vector (a, b, c, d) assuming metric (1, -1, -1, -1),\n";
	std::cout << "   (im) Calculate invariant mass of particle pair using their momenta, masses and their mutual angle.\n";
}
