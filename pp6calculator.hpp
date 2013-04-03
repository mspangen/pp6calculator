#ifndef _PP6CALC_HPP_
#define _PP6CALC_HPP_

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>
#include "filereader/FileReader.hpp"

void input_error();
int get_user_input(int nvars, std::vector<double>& variables);

void MenuWeek1();
void MenuWeek2();
void MenuWeek3();
void MenuWeek4();

void helptext();

// Struct to be used when reading in particle data from file
struct particle
{
	double mass;
	double px;
	double py;
	double pz;
};







#endif
