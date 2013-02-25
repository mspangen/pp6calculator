#ifndef __PP6MATH_HPP__
#define __PP6MATH_HPP__

#include <vector>
#include <cmath>

// Arithmetic
double Add (double a, double b);
double Subtract (double a, double b);
double Multiply (double a, double b);
double Divide (double a, double b);

// Solve equations, find sizes etc.
double Intercept (double a, double b);
void Poly2Solve (double a, double b, double c, std::vector<double>& results);
double Size3Vec (double v1, double v2, double v3);
double Size4Vec (double v0, double v1, double v2, double v3);
double InvMass (double m1, double m2, double p1, double p2, double phi_deg);

// Sorting
void Swap(double& a, double& b);
void BubbleSort(std::vector<double>& a);

#endif
