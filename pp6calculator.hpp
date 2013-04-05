#ifndef _PP6CALC_HPP_
#define _PP6CALC_HPP_

#include <iostream>
#include <iterator>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "filereader/FileReader.hpp"
#include "pp6lib/pp6math.hpp"
#include "pp6lib/string_interpret.hpp"
#include "pp6lib/fourvector.hpp"
#include "pp6lib/particle.hpp"
#include "pp6lib/particleinfo.hpp"

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

//--------------------

struct massTuple
{
	double invMass;
	int i_p; // index of mu+
	int i_m; // index of mu-
};

massTuple makeMassTuple (double m, int ip, int im)
{
	massTuple tuple;
	tuple.invMass = m;
	tuple.i_p = ip;
	tuple.i_m = im;
	return tuple;
}

bool compareMassTuple (massTuple a, massTuple b)
{
	return a.invMass > b.invMass;
}

#endif
