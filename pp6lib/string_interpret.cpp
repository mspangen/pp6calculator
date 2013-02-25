
#include "string_interpret.hpp"

// Function to interpret input string. This splits comma separated string into input variables
void string_interpret (std::string input, std::vector<double>& variables)
{
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

}

