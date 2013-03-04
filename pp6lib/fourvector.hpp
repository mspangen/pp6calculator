#ifndef __FOURVECTOR_HPP__
#define __FOURVECTOR_HPP__

#include <cmath>
#include <iostream>

class FourVector {

public:

	FourVector() {m_t = 0; m_x = 0; m_y = 0; m_z = 0;};
	FourVector(const double t, const double x, const double y, const double z);
	~FourVector();

	double getT() const;
	double getX() const;
	double getY() const;
	double getZ() const;

	void setT(double t);
	void setX(double x);
	void setY(double y);
	void setZ(double z);

	void boost_z(const double beta);
	void boost(const double beta, const double bx_, const double by_, const double bz_);
	double length() const;
	void setElements(const double t, const double x, const double y, const double z);

	// Operators

	FourVector& operator+=(const FourVector& rhs);
	FourVector& operator-=(const FourVector& rhs);


private:

	double m_t;
	double m_x, m_y, m_z;
	double m_length;

	void calcLength();


};

	// Operators outside class!

FourVector operator+(const FourVector& lhs, const FourVector& rhs);

std::ostream& operator<<(std::ostream& stream, const FourVector& v);



#endif //__FOURVECTOR_HPP__



