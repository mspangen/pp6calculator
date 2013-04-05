#include "fourvector.hpp"

FourVector::FourVector(const double v0, const double v1, const double v2, const double v3)
: m_v0(v0)
{
	m_vec3.setv1(v1);
	m_vec3.setv2(v2);
	m_vec3.setv3(v3);
	calcLength();
}

FourVector::~FourVector()
{
}

double FourVector::getv0() const
{
	return m_v0;
}

double FourVector::getv1() const
{
	return m_vec3.getv1();
}

double FourVector::getv2() const
{
	return m_vec3.getv2();
}

double FourVector::getv3() const
{
	return m_vec3.getv3();
}

ThreeVector FourVector::getThreeVector() const
{
	return m_vec3;
}

void FourVector::setv0(double v0)
{
	m_v0 = v0;
	calcLength();
}

void FourVector::setv1(double v1)
{
	m_vec3.setv1(v1);
	calcLength();
}

void FourVector::setv2(double v2)
{
	m_vec3.setv2(v2);
	calcLength();
}

void FourVector::setv3(double v3)
{
	m_vec3.setv3(v3);
	calcLength();
}

void FourVector::boost_v3(const double beta)
{
	if ( (1-beta*beta) > 0 ) {
		double gamma = 1/sqrt(1-beta*beta);
		double v0 = m_v0;
		m_v0 = gamma*( m_v0 - beta*m_vec3.getv3() );
		m_vec3.setv3( gamma*( m_vec3.getv3() - beta*v0 ) );
	}
}

void FourVector::boost(const double beta, const double b1_, const double b2_, const double b3_)
{
	if ( (1-beta*beta) > 0 ) {

		double v0 = m_v0;
		double v1 = m_vec3.getv1();
		double v2 = m_vec3.getv2();
		double v3 = m_vec3.getv3();

		double gamma = 1/sqrt(1-beta*beta);
		double length = sqrt(b1_*b1_+b2_*b2_+b3_*b3_);

		double b1 = b1_/length*beta;
		double b2 = b2_/length*beta;
		double b3 = b3_/length*beta;

		m_v0 = gamma*( v0 - b1*v1 - b2*v2 - b3*v3 );
		m_vec3.setv1( -gamma*b1*v0 + (1+(gamma-1)*b1*b1/(beta*beta))*v1 + (gamma-1)*b1*b2/(beta*beta)*v2 + (gamma-1)*b1*b3/(beta*beta)*v3 );
		m_vec3.setv2( -gamma*b2*v0 + (gamma-1)*b2*b3/(beta*beta)*v1 + (1+(gamma-1)*b2*b2/(beta*beta))*v2 + (gamma-1)*b2*b3/(beta*beta)*v3 );
		m_vec3.setv3( -gamma*b3*v0 + (gamma-1)*b3*b1/(beta*beta)*v1 + (gamma-1)*b3*b2/(beta*beta)*v2 + (1+(gamma-1)*b3*b3/(beta*beta))*v3 );

	}
}

double FourVector::length() const
{
	return m_length;
}

void FourVector::setElements(const double v0, const double v1, const double v2, const double v3)
{
		m_v0 = v0;
		m_vec3.setv1(v1);
		m_vec3.setv2(v2);
		m_vec3.setv3(v3);
}

void FourVector::calcLength()
{
	m_length = sqrt( m_v0*m_v0 - m_vec3.dot(m_vec3) );
}

double FourVector::dot(const FourVector& V)
{
	return m_v0*V.getv0() - m_vec3.dot(V.getThreeVector());
}

// Operators

FourVector& FourVector::operator+=(const FourVector& rhs)
{
	m_v0 += rhs.m_v0;
	m_vec3.setv1(m_vec3.getv1() + rhs.m_vec3.getv1());
	m_vec3.setv2(m_vec3.getv2() + rhs.m_vec3.getv2());
	m_vec3.setv3(m_vec3.getv3() + rhs.m_vec3.getv3());
	return *this;
}

FourVector& FourVector::operator-=(const FourVector& rhs)
{
	m_v0 -= rhs.m_v0;
	m_vec3.setv1( m_vec3.getv1() - rhs.m_vec3.getv1() );
	m_vec3.setv2( m_vec3.getv2() - rhs.m_vec3.getv2() );
	m_vec3.setv3( m_vec3.getv3() - rhs.m_vec3.getv3() );
	return *this;
}

FourVector& FourVector::operator=(const FourVector& rhs)
{
	if (&rhs != this) {
		m_v0 = rhs.m_v0;
		m_vec3.setv1( rhs.m_vec3.getv1() );
		m_vec3.setv2( rhs.m_vec3.getv2() );
		m_vec3.setv3( rhs.m_vec3.getv3() );
	} 
	return *this;
}

// Outside class. Should not be in class scope!

FourVector operator+(const FourVector& lhs, const FourVector& rhs)
{
	FourVector temp(lhs);
	temp += rhs;
	return temp;
}

FourVector operator-(const FourVector& lhs, const FourVector& rhs)
{
	FourVector temp(lhs);
	temp -= rhs;
	return temp;
}

std::ostream& operator<<(std::ostream& stream, const FourVector& v)
{
	stream << "[";
	stream << v.getv0() << ", " << v.getv1() << ", ";
	stream << v.getv2() << ", " << v.getv3() << "]";
	return stream;
}

std::istream& operator>>(std::istream& stream, FourVector& v)
{
	double v0, v1, v2, v3;
	stream >> v0 >> v1 >> v2 >> v3;
	v.setv0(v0); v.setv1(v1); v.setv2(v2); v.setv3(v3);
	return stream;
}












