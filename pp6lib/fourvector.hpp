#ifndef __FOURVECTOR_HPP__
#define __FOURVECTOR_HPP__

#include <cmath>
#include <iostream>
#include "threevector.hpp"

class FourVector {

public:

	FourVector () {m_v0 = 0; m_vec3.setv1(0); m_vec3.setv2(0); m_vec3.setv3(0);};
	FourVector (const double v0, const double v1, const double v2, const double v3);
	~FourVector ();

	double getv0 () const;
	double getv1 () const;
	double getv2 () const;
	double getv3 () const;
	ThreeVector getThreeVector () const;

	void setv0 (double v0);
	void setv1 (double v1);
	void setv2 (double v2);
	void setv3 (double v3);

	void boost_v3 (const double beta);
	void boost (const double beta, const double b1_, const double b2_, const double b3_);
	double length () const;
	void setElements (const double v0, const double v1, const double v2, const double v3);

	double dot (const FourVector& V);

	// Operators

	FourVector& operator+=(const FourVector& rhs);
	FourVector& operator-=(const FourVector& rhs);
	FourVector& operator=(const FourVector& rhs);

private:

	ThreeVector m_vec3;
	double m_v0;
	double m_length;

	void calcLength();

};

// Operators outside class!

FourVector operator+(const FourVector& lhs, const FourVector& rhs);
FourVector operator-(const FourVector& lhs, const FourVector& rhs);

std::ostream& operator<<(std::ostream& stream, const FourVector& v);



#endif //__FOURVECTOR_HPP__



