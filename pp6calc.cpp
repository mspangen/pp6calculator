#include <iostream>

int main()
{

	double a;
	double b;
	double c;

	std::cout << "Please enter number A:\n";
	std::cin >> a;
	std::cout << "Please enter number B:\n";	
	std::cin >> b;

	c = a*b;

	std::cout << "A*B = " << c << std::endl;

	return 0;

}
