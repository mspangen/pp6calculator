#include <iostream>
#include <climits>

void input_error()
{
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}

int main()
{

	double a;
	double b;
	double c;
	std::string operation;

	while (true)
	{

		std::cout << "Choose operation [add (a), subtract (s), multiply (m), divide (d)]:\n";
		std::cin >> operation;

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
			std::cout << "A+B = " << a+b << std::endl;
		} else if (operation == "s") {
			std::cout << " A-B = " << a-b << std::endl;
		} else if (operation == "m") {
			std::cout << "A*B = " << a*b << std::endl;
		} else if (operation == "d") { 
			if (b == 0) {
				std::cout << "Division by zero!\n";
				input_error();
				continue;
			}
			std::cout << "A/B = " << a/b << std::endl;
		} else if (operation == "q") {
			break;
		}
		else {
			std::cout << "Error in operation choice!\n";
			input_error();
			continue;
		}

	}

	return 0;

}
