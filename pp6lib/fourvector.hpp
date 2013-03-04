#ifndef __FOURVECTOR_HPP__
#define __FOURVECTOR_HPP__

#include <cmath>

class FourVector {

public:

	FourVector() {m_t = 0; m_x = 0; m_y = 0; m_z = 0;};
	FourVector(const double t, const double x, const double y, const double z);
	~FourVector();

	double getT() const;
	double getX() const;
	double getY() const;
	double getZ() const;

	void setT();
	void setX();
	void setY();
	void setZ();

	void boost_z(const double beta);
	void boost(const double beta, const double bx_, const double by_, const double bz_);
	double length() const;
	void setElements(const double t, const double x, const double y, const double z);

private:

	double m_t;
	double m_x, m_y, m_z;


};










/*
FourVector* createFourVector ();

void destroyFourVector (FourVector *&v);

double getFourVectorT (FourVector *v);
double getFourVectorX (FourVector *v);
double getFourVectorY (FourVector *v);
double getFourVectorZ (FourVector *v);

void setFourVectorElements (FourVector *v, double v0, double v1, double v2, double v3);
int boostZFourVector (FourVector *v, double beta);
int boostFourVector (FourVector *v, double beta, double _bx, double _by, double _bz);
double lengthOfFourVector (FourVector *v);
*/

#endif //__FOURVECTOR_HPP__
