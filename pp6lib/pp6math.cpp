
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

double InvMass (double m1, double m2, double p1x, double p1y, double p1z, double p2x, double p2y, double p2z)
{
	double E1 = Energy(m1,p1x,p1y,p1z);
	double E2 = Energy(m2,p2x,p2y,p2z);

	return sqrt( m1*m1 + m2*m2 + 2*(E1*E2 - p1x*p2x - p1y*p2y - p1z*p2z) );
}

double InvMass (const Particle& p1, const Particle& p2)
{
	double E1 = p1.getEnergy();
	double E2 = p2.getEnergy();
	ThreeVector psum = p1.getThreeMomentum()+p2.getThreeMomentum();

	return sqrt( Square(E1 + E2) - psum.dot(psum) );
}


//====================================
// Sorting
//====================================

template <class T>
void Swap(T& a, T& b)
{
	T temp = b;
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
				Swap<double>(a[i],a[i+1]);
			}
		}

		if (swapped == false) break;

	}

}

void BubbleSortIndex(std::vector<double> a, std::vector<int>& indexvec)
{
	std::vector<double> _a = a;
	int size = _a.size();

	indexvec.clear();
	for (int i=0; i<size; ++i) {
		indexvec.push_back(i);
	}

	bool swapped;

	if (size < 2) return;

	while(true) {
		swapped = false;

		for (int i=0; i<size-1; ++i) {
			if (_a[i+1] > _a[i]) {
				swapped = true;
				Swap<double>(_a[i],_a[i+1]);
				Swap<int>(indexvec[i],indexvec[i+1]);
			}
		}

		if (swapped == false) break;

	}



}

//====================================
// Number generation
//====================================

double RandomNumber(double min, double max)
{
	double r = (double)rand() / RAND_MAX;
	return min + r*(max-min);
}

void GenerateEnergies(int N, double p_min, double p_max, double m_min, double m_max, std::vector<double>& energies)
{
	double Nd = N;
	energies.clear();
	double px, py, pz;
	double p;
	double m;
	for (int i=0; i<Nd; ++i) {
		px = RandomNumber(p_min,p_max);
		py = RandomNumber(p_min,p_max);
		pz = RandomNumber(p_min,p_max);
		p = Size3Vec(px,py,pz);
		m = RandomNumber(m_min,m_max);
		energies.push_back(sqrt(Square(p)+Square(m)));
	}
}

//====================================
// Other functions
//====================================

double Square(double a)
{
	return a*a;
}

double Mean(std::vector<double> vars)
{
	double mean = 0;
	for (unsigned int i=0; i<vars.size(); ++i) {
		mean += vars.at(i);
	}

	return mean/vars.size();
}

double StandardDeviation(std::vector<double> vars)
{
	double stddev = 0;
	double mean = Mean(vars);
	for (unsigned int i=0; i<vars.size(); ++i) {
		stddev += Square(vars.at(i) - mean);
	}
	stddev = stddev/vars.size();
	
	return sqrt(stddev);
}

double Energy(double m, double px, double py, double pz) {
	return sqrt(px*px + py*py + pz*pz + m*m);
}
