
#include "pp6math.hpp"

//====================================
// Arithmetic
//====================================

double Add (double a, double b)
{
	return a+b;
}

double Subtract (double a, double b)
{
	return a-b;
}

double Multiply (double a, double b)
{
	return a*b;
}

double Divide (double a, double b)
{
	return a/b;
}

//====================================
// Solve equations, find sizes etc.
//====================================

double Intercept (double a, double b)
{
	return -b/a;
}

void Poly2Solve (double a, double b, double c, std::vector<double>& solutions)
{
	double d = b*b - 4*a*c; // Discriminant

	if (a == 0 && b != 0) {
		solutions.push_back(-c/b);
	}	else if (d > 0 && a != 0) {
		solutions.push_back( (-b + sqrt(d))/(2*a) );
		solutions.push_back( (-b - sqrt(d))/(2*a) );
	} else if (d == 0 && a != 0) {
		solutions.push_back(-b/(2*a));
	}

}

double Size3Vec (double v1, double v2, double v3) // Size of 3-vector
{
	return sqrt(v1*v1 + v2*v2 + v3*v3);
}

double Size4Vec(double v0, double v1, double v2, double v3) // Size of 4-vector
{
	double square = v0*v0 - v1*v1 - v2*v2 - v3*v3; // We assume metric (+1,-1,-1,-1)

	if (square >= 0) {
		return sqrt(square);
	}	else {
		return -1;
	}
}

double InvMass (double m1, double m2, double p1, double p2, double phi_deg)
{
	double E1 = sqrt(p1*p1 + m1*m1);
	double E2 = sqrt(p2*p2 + m2*m2);
	double pi = 3.14159265358979323846;
	double phi_rad = phi_deg/180*pi;
	return sqrt( m1*m1 + m2*m2 + 2*(E1*E2 - p1*p2*cos(phi_rad)) ); 
}


//====================================
// Sorting
//====================================

void Swap(double& a, double& b)
{
	double temp = b;
	b = a;
	a = temp;
}

void BubbleSort(std::vector<double>& a)
{
	int size = a.size();
	bool swapped;

	if (size < 2) return;

	while(true) {
		swapped = false;

		for (int i=0; i<size-1; ++i) {
			if (a[i+1] > a[i]) {
				swapped = true;
				Swap(a[i],a[i+1]);
			}
		}

		if (swapped == false) break;

	}

}
