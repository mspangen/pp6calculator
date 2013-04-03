#ifndef __THREEVECTOR_HPP__
#define __THREEVECTOR_HPP__

#include <cmath>

class ThreeVector {

public:

	ThreeVector () {m_v1 = 0; m_v2 = 0; m_v3 = 0;};
	ThreeVector (const double v1, const double v2, const double v3);
	~ThreeVector ();

	double getv1 () const;
	double getv2 () const;
	double getv3 () const;
	double getLength () const;

	void setv1 (const double v1);
	void setv2 (const double v2);
	void setv3 (const double v3);

private:

	double m_v1, m_v2, m_v3;
	double m_length;

	void calcLength ();



};

#endif