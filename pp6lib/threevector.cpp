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



// Private functions

void ThreeVector::calcLength ()
{
	m_length = sqrt(m_v1*m_v1 + m_v2*m_v2 + m_v3*m_v3);
}


