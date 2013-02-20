#ifndef _PP6CALC_H_
#define _PP6CALC_H_

void input_error();
std::vector<double> get_user_input(std::string);
std::vector<double> interpret_input(std::string);

double Add (double, double);
double Subtract (double, double);
double Multiply (double, double);
double Divide (double, double);
double Intercept (double, double);
std::vector<double> Poly2Solve (double, double, double);
double Size3Vec (double, double, double);
double Size4Vec (double, double, double, double);
double InvMass (double, double, double);

void helptext();

// Variable vector used by calculator
std::vector<double> vars;








#endif
