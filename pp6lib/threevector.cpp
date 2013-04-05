#include "threevector.hpp"

ThreeVector::ThreeVector (const double v1, const double v2, const double v3)
	: m_v1(v1), m_v2(v2), m_v3(v3)
{
	calcLength();
}

ThreeVector::~ThreeVector ()
{
}

double ThreeVector::getv1 () const
{
	return m_v1;
}

double ThreeVector::getv2 () const
{
	return m_v2;
}

double ThreeVector::getv3 () const
{
	return m_v3;
}

double ThreeVector::getLength () const
{
	return m_length;
}

void ThreeVector::setv1 (const double v1)
{
	m_v1 = v1;
	calcLength();
}

void ThreeVector::setv2 (const double v2)
{
	m_v2 = v2;
	calcLength();
}

void ThreeVector::setv3 (const double v3)
{
	m_v3 = v3;
	calcLength();
}

double ThreeVector::dot (const ThreeVector& V) 
{
	return m_v1*V.getv1() + m_v2*V.getv2() + m_v3*V.getv3();
}


// Operators

ThreeVector& ThreeVector::operator+=(const ThreeVector& rhs)
{
	m_v1 += rhs.getv1();
	m_v2 += rhs.getv2();
	m_v3 += rhs.getv3();
	return *this;
}

ThreeVector& ThreeVector::operator-=(const ThreeVector& rhs)
{
	m_v1 -= rhs.getv1();
	m_v2 -= rhs.getv2();
	m_v3 -= rhs.getv3();
	return *this;
}

ThreeVector& ThreeVector::operator=(const ThreeVector& rhs)
{
	if (&rhs != this) {
		m_v1 = rhs.getv1();
		m_v2 = rhs.getv2();
		m_v3 = rhs.getv3();
	} 
	return *this;
}


// Private functions

void ThreeVector::calcLength ()
{
	m_length = sqrt(m_v1*m_v1 + m_v2*m_v2 + m_v3*m_v3);
}


// Outside class. Should not be in class scope!

ThreeVector operator+(const ThreeVector& lhs, const ThreeVector& rhs)
{
	ThreeVector temp(lhs);
	temp += rhs;
	return temp;
}

ThreeVector operator-(const ThreeVector& lhs, const ThreeVector& rhs)
{
	ThreeVector temp(lhs);
	temp -= rhs;
	return temp;
}
