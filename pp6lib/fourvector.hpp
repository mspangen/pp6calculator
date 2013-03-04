#ifndef __FOURVECTOR_HPP__
#define __FOURVECTOR_HPP__

#include <cmath>

class FourVector {

public:

	FourVector();
	FourVector(double t, double x, double y, double z);
	~FourVector();

	double getT() const;
	double getX() const;
	double getY() const;
	double getZ() const;

	void setT();
	void setX();
	void setY();
	void setZ();

	void boost_z(double beta);
	void boost(double beta, double bx_, double by_, double bz_);
	double length() const;
	void setElements(double t, double x, double y, double z);

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
