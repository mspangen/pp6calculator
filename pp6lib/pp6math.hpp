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
double InvMass (double m1, double m2, double p1x, double p1y, double p1z, double p2x, double p2y, double p2z);

// Sorting
template<class T>
void Swap (T& a, T& b);
void BubbleSort (std::vector<double>& a);
void BubbleSortIndex(std::vector<double> a, std::vector<int>& indexvec);

// Number generation
double RandomNumber (double min, double max);
void GenerateEnergies (int N, double p_min, double p_max, double m_min, double m_max, std::vector<double>& energies);

// Other functions
double Square (double a);
double Mean (std::vector<double> vars);
double StandardDeviation (std::vector<double> vars);
double Energy (double m, double px, double py, double pz);

#endif
