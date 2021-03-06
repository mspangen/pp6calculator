#include "pp6calculator.hpp"

int random100() { return (std::rand()%100); } // Function to generate random numbers in the range [0,100]

int main(int argc, char* argv[])
{

	//Check if help argument has been typed
	std::string arg;
	if (argc > 1) {
		for (int i=0; i<argc; ++i) {
			arg = argv[i];
			if (arg == "-h") {
				helptext();
				return 0;
			}
		}
	}


	// Display main menu
	// This gives access to the submenus for each week of the course.
	// It is placed in a while loop such that the program returns to
	// the main menu when exiting a sumbenu.

	std::string operation;
	bool showmenu = true;

	while (true) {

		if (showmenu) {
			std::cout << "==================================================\n";
			std::cout << "pp6calculator main menu\n";
			std::cout << "==================================================\n";
			std::cout << "1) Week 1\n";
			std::cout << "2) Week 2\n";
			std::cout << "3) Week 3\n";
			std::cout << "4) Week 4\n";
			std::cout << "q) Quit program\n";
			std::cout << "--------------------------------------------------\n";
		}

		showmenu = true;

		std::cout << "Choose option: ";
		std::cin >> operation; // Get operation from user

		if (operation == "1") {
			MenuWeek1();
		}

		else if (operation == "2") {
			MenuWeek2();
		}

		else if (operation == "3") {
			MenuWeek3();
		}

		else if (operation == "4") {
			MenuWeek4();
		}

		else if (operation == "q") {
			break;
		}

		else {
			std::cout << "No such option!" << std::endl;
			std::cout << "-----------------" << std::endl;
			showmenu = false;
		}

	}

	return 0;

}


//==================================
// Submenus
//==================================

void MenuWeek1()
{

	std::string operation;
	std::vector<double> vars;
	int outcode; // Code to check for input errors

	std::cout << "==================================================\n";
	std::cout << "Week 1\n";
	std::cout << "==================================================\n";
	std::cout << "a) Addition\n";
	std::cout << "s) Subtraction\n";
	std::cout << "m) Multiplication\n";
	std::cout << "d) Divison\n";
	std::cout << "i)  Line intercept with x-axis\n";
	std::cout << "p)  Solve 2nd degree polynomium\n";
	std::cout << "v3) Size of 3-vector\n";
	std::cout << "v4) Size of 4-vector\n";
	std::cout << "im) Invariant mass of particle pair\n";
	std::cout << "q) Quit to main menu\n";
	std::cout << "--------------------------------------------------\n";

	while (true) {

		vars.clear();

		std::cout << "Choose option: ";
		std::cin >> operation; // Get operation from user

		//=====================================

		if (operation == "a") {
			std::cout << "Addition A+B. Enter as A,B:" << std::endl;
			outcode = get_user_input(2,vars);
			if (outcode != -1) {
				std::cout << vars.at(0) << " + " << vars.at(1) << " = " << Add(vars.at(0),vars.at(1)) << std::endl;
			}
		}

		//=====================================

		else if (operation == "s") {
			std::cout << "Subtraction A-B. Enter as A,B:" << std::endl;
			outcode = get_user_input(2,vars);
			if (outcode != -1) {
				std::cout << vars.at(0) << " - " << vars.at(1) << " = " << Subtract(vars.at(0),vars.at(1)) << std::endl;
			}
		}

		//=====================================

		else if (operation == "m") {
			std::cout << "Multiplication A*B. Enter as A,B:" << std::endl;
			outcode = get_user_input(2,vars);
			if (outcode != -1) {
				std::cout << vars.at(0) << " * " << vars.at(1) << " = " << Multiply(vars.at(0),vars.at(1)) << std::endl;
			}
		}

		//=====================================

		else if (operation == "d") {
			std::cout << "Division A/B. Enter as A,B:" << std::endl;
			outcode = get_user_input(2,vars);
			if (outcode != -1) {
				if (vars.at(1) == 0) {
					std::cout << "Division by zero!" << std::endl;
					input_error();
				} else {
					std::cout << vars.at(0) << " / " << vars.at(1) << " = " << Divide(vars.at(0),vars.at(1)) << std::endl;
				}
			}
		}

		//=====================================

		else if (operation == "i") {
			std::cout << "Intercept of line A*x+B with x-axis. Enter as A,B:" << std::endl;
			outcode = get_user_input(2,vars);
			if (outcode != -1) {
				std::cout << "Line " << vars.at(0) << "*x+" << vars.at(1) << " intercepts x-axis at x = " << Intercept(vars.at(0),vars.at(1)) << std::endl;
			}
		}

		//=====================================

		else if (operation == "p") {
			std::cout << "Solution to 2nd order polynomial A*x^2+B*x+C=0. Enter as A,B,C:" << std::endl;
			outcode = get_user_input(3,vars);
			if (outcode != -1) {
				std::vector<double> solutions;
				Poly2Solve(vars.at(0),vars.at(1),vars.at(2),solutions);
				std::cout << "Solution to 2nd degree polynomium " << vars.at(0) << "*x^2+" << vars.at(1) << "*x+" << vars.at(2) << "=0:" << std::endl;
				for (unsigned int i=0; i<solutions.size(); ++i)
				{
					std::cout << "x" << i << " = " << solutions.at(i) << std::endl;
				}
				if (solutions.size() == 0) {
					std::cout << "None" << std::endl;
				}
			}
		}

		//=====================================

		else if (operation == "v3") {
			std::cout << "Size of 3-vector (v1,v2,v3). Enter as v1,v2,v3:" << std::endl;
			outcode = get_user_input(3,vars);
			if (outcode != -1) {
				double result = Size3Vec(vars.at(0),vars.at(1),vars.at(2));
				std::cout << "Size of 3-vector (" << vars.at(0) << "," << vars.at(1) << "," << vars.at(2) << ") = " << result << std::endl;
			}
		}

		//=====================================

		else if (operation == "v4") {
			std::cout << "Size of 4-vector (v0,v1,v2,v3). Enter as v0,v1,v2,v3:" << std::endl;
			outcode = get_user_input(4,vars);
			if (outcode != -1) {
				double result = Size4Vec(vars.at(0),vars.at(1),vars.at(2),vars.at(3));
				if (result >= 0) {
					std::cout << "Size of 4-vector (" << vars.at(0) << "," << vars.at(1) << "," << vars.at(2) << "," << vars.at(3) << ") = " << result << std::endl;
				} else {
					std::cout << "Invalid entry. Negative sum of squares.\n";
				}
			}
		}

		//=====================================

		else if (operation == "im") {
			std::cout << "Invariant mass of particle pair. Enter as m1,m2,p1x,p1y,p1z,p2x,p2y,p2z:" << std::endl;
			outcode = get_user_input(8,vars);
			if (outcode != -1) {
				double result = InvMass(vars.at(0),vars.at(1),vars.at(2),vars.at(3),vars.at(4),vars.at(5),vars.at(6),vars.at(7));
				std::cout << "Invariant mass of particles M = " << result << std::endl;
			}
		}

		//=====================================

		else if (operation == "q") {
			break;
		}

		else {
			std::cout << "No such option!" << std::endl;
		}

		if (outcode == -1) {
			std::cout << "Error in input!" << std::endl;
		}

		std::cout << "-----------------" << std::endl;

	}

}


//================================================================


void MenuWeek2()
{
	std::string operation;
	std::vector<double> vars;
	int outcode; // Code to check for input errors

	std::cout << "==================================================\n";
	std::cout << "Week 2\n";
	std::cout << "==================================================\n";
	std::cout << "s) Sort numbers in descending order\n";
	std::cout << "d) Calculate standard deviation of numbers\n";
	std::cout << "e) Generate 100 energies and 3-momenta and output\n";
	std::cout << "   the mean energy and its standard deviation\n";
	std::cout << "m) Read file containing particle data, calculate\n";
	std::cout << "   invarant masses of all pairs of mu+,mu- from\n";
	std::cout << "   run4.dat and output the 10 largest values and\n";
	std::cout << "   the muons they were calculated from\n";
	std::cout << "q)  Quit to main menu\n";
	std::cout << "--------------------------------------------------\n";

	while (true) {

		vars.clear();

		std::cout << "Choose option: ";
		std::cin >> operation; // Get operation from user

		//=====================================

		if (operation == "s") {
			std::cout << "Sort array of numbers in descending order. Input as a[0],a[1],...:" << std::endl;
			outcode = get_user_input(-1,vars);
			if (outcode != -1) {
				BubbleSort(vars);
				std::cout << "Sorted array: " << vars[0];
				for (unsigned int i=1; i<vars.size(); ++i) {
					std::cout << "," << vars[i];
				}
				std::cout << std::endl;
			}
		}

		//=====================================

		else if (operation == "d") {
			std::cout << "Calculate standard deviation of array of numbers. Input as a[0],a[1],...:" << std::endl;
			outcode = get_user_input(-1,vars);
			if (outcode != -1) {
				std::cout << "sigma = " << StandardDeviation(vars) << std::endl;
			}
		}

		//=====================================

		else if (operation == "e") {
			std::cout << "Calculate N energies by generating random 3-momenta and masses. Then output <E> and sigma_E.\n";
			std::cout << "Input as N,p_min,p_max,m_min,m_max:" << std::endl;
			outcode = get_user_input(5,vars);
			if (outcode != -1) {
				std::vector<double> energies;
				GenerateEnergies((int)vars.at(0),vars.at(1),vars.at(2),vars.at(3),vars.at(4),energies);
				std::cout << "Mean: " << Mean(energies) << ", standard deviation: " << StandardDeviation(energies) << std::endl;
			}
		}

		//=====================================

		else if (operation == "m") {
			double mumass = 0.1056583715; // Mass of muon [GeV]
			std::string file;
			std::string tempstring; // String for reading in various strings from file
			std::cout << "Please state the relative location of the data file:" << std::endl;
			std::cin >> file;
			FileReader f(file);
			
			if (!f.isValid()) {
				std::cout << "File was not found!" << std::endl;
				continue;
			}

			std::vector<Particle> muvec_p; // Vector to contain mu+ particles
			std::vector<Particle> muvec_m; // Vector to contain mu- particles

			f.nextLine(); // Skip first line
			while (f.nextLine()) {
				tempstring = f.getFieldAsString(6); // Read data source
				if (tempstring == "run4.dat") {
					tempstring = f.getFieldAsString(2); // Read particle type
					if (tempstring == "mu+" || tempstring == "mu-") {
						Particle temp(mumass,f.getFieldAsDouble(3),f.getFieldAsDouble(4),f.getFieldAsDouble(5));

						if (tempstring == "mu+") {
							muvec_p.push_back(temp);
						}	else {
							muvec_m.push_back(temp);
						}

					}
				}
			}

			// Now we have all the mu+ and mu- particles in two vectors,
			// so we can calculate invariant masses of all combinations.

			std::vector<double> invmassvec;
			std::vector<std::pair<int,int> > eventvec; // Vector of mu+,mu- event pairs

			for (unsigned int i=0; i<muvec_p.size(); ++i) {
				for (unsigned int j=0; j<muvec_m.size(); ++j) {
					if (i>=j) {
						Particle mu_p = muvec_p.at(i);
						Particle mu_m = muvec_m.at(j);
						double im = InvMass(mu_p.getMass(),mu_m.getMass(),mu_p.getPx(),mu_p.getPy(),mu_p.getPz(),mu_m.getPx(),mu_m.getPy(),mu_m.getPz());
						invmassvec.push_back(im);
						eventvec.push_back(std::pair<int,int>(i,j));
					}
				}
			}

			std::vector<int> indexvec; // Vector to store indexes of the sorted values
			BubbleSortIndex(invmassvec,indexvec); // Sort the invariant masses in descending order and output index vector

			std::cout << "InvMass  mu+  mu-\n";
			for (int i=0; i<10; ++i) {
				printf("%8f %3d %3d\n",invmassvec.at(indexvec.at(i)),eventvec.at(indexvec.at(i)).first,eventvec.at(indexvec.at(i)).second);
			}

		}



		//=====================================

		else if (operation == "q") {
			break;
		}

		else {
			std::cout << "No such option!" << std::endl;
		}

		if (outcode == -1) {
			std::cout << "Error in input!" << std::endl;
		}

		std::cout << "-----------------" << std::endl;

	}

}


//================================================================


void MenuWeek3()
{

	std::string operation;
	std::vector<double> vars;
	int outcode = 0; // Code to check for input errors

	std::cout << "==================================================\n";
	std::cout << "Week 3\n";
	std::cout << "==================================================\n";
	std::cout << "bz) Boost 4-vector along z-axis\n";
	std::cout << "b)  Boost 4-vector along arbitrary direction\n";
	std::cout << "l)  Calculate length of 4-vector\n";
	std::cout << "q)  Quit to main menu\n";
	std::cout << "--------------------------------------------------\n";

	while (true) {

		vars.clear();

		std::cout << "Choose option: ";
		std::cin >> operation; // Get operation from user

		//=====================================

		if (operation == "bz") {

			std::cout << "Boost 4-vector along z-axis. Input as t,x,y,z,beta:" << std::endl;
			outcode = get_user_input(5,vars);
			if (outcode != -1 && (1-vars.at(4)*vars.at(4)) > 0) {
				FourVector vec(vars.at(0),vars.at(1),vars.at(2),vars.at(3));
				vec.boost_v3(vars.at(4));
				std::cout << "Boosted 4-vector: (" << vec.getv0() << "," << vec.getv1() << "," << vec.getv2() << "," << vec.getv3() << ")" << std::endl;
			} else {
					std::cout << "Invalid arguments!" << std::endl;
			}

		}

		//=====================================

		else if (operation == "b") {

			std::cout << "Boost 4-vector along arbitrary direction. bx,by,bz are boost components. They give the direction, not the size!\n";
			std::cout << "Input as t,x,y,z,beta,bx,by,bz:" << std::endl;
			outcode = get_user_input(8,vars);
			if (outcode != -1 && (1-vars.at(4)*vars.at(4)) > 0) {
				FourVector vec(vars.at(0),vars.at(1),vars.at(2),vars.at(3));
				vec.boost(vars.at(4),vars.at(5),vars.at(6),vars.at(7));
				std::cout << "Boosted 4-vector: (" << vec.getv0() << "," << vec.getv1() << "," << vec.getv2() << "," << vec.getv3() << ")" << std::endl;
			} else {
				std::cout << "Invalid arguments!" << std::endl;
			}

		}

		//=====================================

		else if (operation == "l") {
			
			std::cout << "Calculate length of 4-vector. Input as t,x,y,z:" << std::endl;
			outcode = get_user_input(4,vars);
			if (outcode != -1) {
				FourVector vec(vars.at(0),vars.at(1),vars.at(2),vars.at(3));
				std::cout << "Length = " << vec.length() << std::endl;
			}

		}

		//=====================================

		else if (operation == "q") {
			break;
		}

		else {
			std::cout << "No such option!" << std::endl;
		}

		if (outcode == -1) {
			std::cout << "Error in input!" << std::endl;
		}

		std::cout << "-----------------" << std::endl;

	}

}


//================================================================


void MenuWeek4()
{

	std::string operation;
	std::vector<double> vars;
	int outcode = 0; // Code to check for input errors

	std::cout << "==================================================\n";
	std::cout << "Week 4\n";
	std::cout << "==================================================\n";
	std::cout << "r)  Read in data from PDG file\n";
	std::cout << "pi) Create and test a ParticleInfo class to read PDG file\n";
	std::cout << "al) Algorithm test manipulating a vector\n";
	std::cout << "m)  Produce ordered list of invariant masses formed\n";
	std::cout << "    between mu+mu- pairs in run4.dat using FileReader,\n";
	std::cout << "    ParticleInfo and Particle classes.\n";
	std::cout << "q)  Quit to main menu\n";
	std::cout << "--------------------------------------------------\n";

	while (true) {

		vars.clear();

		std::cout << "Choose option: ";
		std::cin >> operation; // Get operation from user

		//=====================================

		if (operation == "r") {

			std::cout << "Read in data rom PDG database. " << std::endl;
			std::cout << "Please state the relative location of the data file:" << std::endl;
			std::string file;
			std::cin >> file;
			FileReader f(file);
			
			if (!f.isValid()) {
				std::cout << "File was not found!" << std::endl;
				continue;
			}

			std::vector<std::string> ptype;
			std::vector<int> val1;
			std::vector<int> val2;
			std::vector<double> val3;

			while (f.nextLine()) {
				ptype.push_back(f.getField<std::string>(1));
				val1.push_back(f.getField<int>(2));
				val2.push_back(f.getField<int>(3));
				val3.push_back(f.getField<double>(4));
			}

			std::vector<std::string>::iterator iter0 = ptype.begin();
			std::vector<int>::iterator iter1 = val1.begin();
			std::vector<int>::iterator iter2 = val2.begin();
			std::vector<double>::iterator iter3 = val3.begin();

			for ( ; iter0 != ptype.end(); ++iter0) {
				std::cout << std::setw(10) << std::left  << *iter0
				          << std::setw(5)  << std::right << *iter1
									<< std::setw(4)  << std::right << *iter2
									<< std::setw(10) << std::right << *iter3 << std::endl;

				++iter1;
				++iter2;
				++iter3;
			}

		}

		//===================================

		else if (operation == "pi") {
			std::cout << "Create ParticleInfo class from file. " << std::endl;
			std::cout << "Please state the relative location of the data file:" << std::endl;
			std::string file;
			std::cin >> file;

			FileReader f(file);
			if (!f.isValid()) {
				std::cout << "File was not found!" << std::endl;
				continue;
			}

			ParticleInfo database(file);

			std::cout << "Testing the created ParticleInfo class:" << std::endl;
			std::cout << "name of pdgID 521: " << database.getName(521) << std::endl;
			std::cout << "pdgID of K+: " << database.getPDGCode(std::string("K+")) << std::endl;
			std::cout << "mass of electron in MeV: " << database.getMassMeV(11) << std::endl;
			std::cout << "mass of electron in GeV: " << database.getMassGeV(11) << std::endl;

		}

		//===================================

		else if (operation == "al") {
			std::cout << "Creating vector with 10 elements and filling it with random integers." << std::endl;
			std::vector<int> myvector (10);
			std::srand(unsigned(std::time(0))); // Create seed for random generation of numbers
			std::generate (myvector.begin(), myvector.end(), random100); // Fill vector with random numbers in the range [0,100]

			std::cout << "The vector contains the following numbers:" << std::endl;
			std::copy(myvector.begin(),myvector.end(),std::ostream_iterator<int>(std::cout,"\n")); // Output contents of vector to screen
			std::cout << "--------------------------------" << std::endl;

			// Output smallest and largest value in vector
			int minimum = *std::min_element(myvector.begin(),myvector.end());
			int maximum = *std::max_element(myvector.begin(),myvector.end());
			std::cout << "Smallest entry: " << minimum << ", largest entry: " << maximum << std::endl;
			std::cout << "--------------------------------" << std::endl;

			std::sort(myvector.begin(),myvector.end()); // Sort vector in ascending order
			std::cout << "Sorting vector entries in ascending order. The ording is now:" << std::endl;
			std::copy(myvector.begin(),myvector.end(),std::ostream_iterator<int>(std::cout,"\n")); // Output contents of vector to screen


		}

		//===================================


		else if (operation == "m") {

			std::cout << "Create ParticleInfo class from file. " << std::endl;
			std::cout << "Please enter the relative location of the PDG file:" << std::endl;
			std::string file;
			std::cin >> file;

			FileReader f(file);
			if (!f.isValid()) {
				std::cout << "File was not found!" << std::endl;
				continue;
			}

			ParticleInfo database(file);
			int pdgID = database.getPDGCode(std::string("mu+"));
			double mumass = database.getMassGeV(pdgID);
			
			std::cout << "mumass = " << mumass << std::endl;

			std::cout << "Please enter the relative location of the data file:" << std::endl;
			std::string datafile;
			std::cin >> datafile;

			FileReader f2(datafile);
			if (!f2.isValid()) {
				std::cout << "File was not found!" << std::endl;
				continue;
			}

			std::vector<Particle> mu_p; // Vector to contain mu+ particles
			std::vector<Particle> mu_m; // Vector to contain mu- particles

			std::string tempstring;

			f2.nextLine(); // Skip first line
			while (f2.nextLine()) {
				if (f2.getFieldAsString(6) == "run4.dat") {
					
					tempstring = f2.getFieldAsString(2); // Read particle type
					if (tempstring == "mu+") {
						mu_p.push_back(Particle(mumass,f2.getFieldAsDouble(3),f2.getFieldAsDouble(4),f2.getFieldAsDouble(5)));
					}
					else if (tempstring == "mu-") {
						mu_m.push_back(Particle(mumass,f2.getFieldAsDouble(3),f2.getFieldAsDouble(4),f2.getFieldAsDouble(5)));
					}

				}
			}

			// Now we have all the mu+ and mu- particles in two vectors,
			// so we can calculate invariant masses of all combinations.

			std::vector<massTuple> invmassvec;

			for (unsigned int i=0; i<mu_p.size(); ++i) {
				for (unsigned int j=0; j<mu_m.size(); ++j) {
					if (i>=j) {
						double im = InvMass(mu_p.at(i),mu_m.at(j));
						invmassvec.push_back(makeMassTuple(im,i,j));
					}
				}
			}

			std::sort(invmassvec.begin(),invmassvec.end(),compareMassTuple); // Sort the invariant masses in ascending order

			std::cout << "InvMass  mu+  mu-\n";
			std::vector<massTuple>::iterator it;
			for (it = invmassvec.begin(); it != invmassvec.end(); ++it) {
				printf("%8f %3d %3d\n",(*it).invMass,(*it).i_p,(*it).i_m);
			}

		}

		//===================================

		else if (operation == "q") {
			break;
		}

		else {
			std::cout << "No such option!" << std::endl;
		}

		if (outcode == -1) {
			std::cout << "Error in input!" << std::endl;
		}

		std::cout << "-----------------" << std::endl;

	}

}

//=====================================
// Other functions
//=====================================

// Function to call whenever an input error is found
void input_error()
{
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}


// Function to get user input
int get_user_input(int nvars, std::vector<double>& variables)
{
	std::string input;
	std::cin >> input;

	if (!std::cin) { // Check for errors in input
		input_error();
		return -1;
	}	else {
		string_interpret(input,variables);
	}

	if ( (variables.size() != (unsigned)nvars && nvars != -1) || variables.size() == 0) {
		variables.clear();
		return -1;
	}	else {
		return 0;
	}

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
	std::cout << "pp6calculator is a simple program for doing various kinds\n";
	std::cout << "of calculations."; 
	std::cout << "The program consists of a main menu which gives access to\n";
	std::cout << "a number of submenus. Both the main menu and submenus are\n";
	std::cout << "navigated by entering one or several symbols as described\n";
	std::cout << "in the respective menu.\n";
	std::cout << "The submenus contain options for mathematical operations\n";
	std::cout << "on input given by the user. All input variables are entered\n";
	std::cout << "in one line with each variable separated by a comma.\n";
}
