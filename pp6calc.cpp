#include <iostream>

int main()
{

	double a;
	double b;
	double c;
	std::string operation;

	std::cout << "Choose operation [add (a), subtract (s), multiply (m), divide (d)]:\n";
	std::cin >> operation;

	std::cout << "Please enter number A:\n";
	std::cin >> a;
	std::cout << "Please enter number B:\n";	
	std::cin >> b;

	if (!std::cin)
	{
		std::cout << "Error in input! \n";
		return 0;
	}

	if (operation == "a") {
		std::cout << "A+B = " << a+b << std::endl;
	} else if (operation == "s") {
		std::cout << " A-B = " << a-b << std::endl;
	} else if (operation == "m") {
		std::cout << "A*B = " << a*b << std::endl;
	} else if (operation == "d") { 
		if (b == 0) {
			std::cout << "Division by zero!\n";
			return 0;
		}
		std::cout << "A/B = " << a/b << std::endl;
	}

	return 0;

}
