#include "fourvector.hpp"

FourVector::FourVector(const double t, const double x, const double y, const double z)
: m_t(t), m_x(x), m_y(y), m_z(z)
{
}

FourVector::~FourVector()
{
}

double FourVector::getT() const
{
	return m_t;
}

double FourVector::getX() const
{
	return m_x;
}

double FourVector::getY() const
{
	return m_y;
}

double FourVector::getZ() const
{
	return m_z;
}

void FourVector::boost_z(const double beta)
{
	if ( (1-beta*beta) > 0 ) {
		double gamma = 1/sqrt(1-beta*beta);
		double t_0 = m_t;
		m_t = gamma*( (m_t) - beta*(m_z) );
		m_z = gamma*( (m_z) - beta*(t_0) );
	}
}

void FourVector::boost(const double beta, const double bx_, const double by_, const double bz_)
{
	if ( (1-beta*beta) > 0 ) {

		double t_0 = m_t;
		double x_0 = m_x;
		double y_0 = m_y;
		double z_0 = m_z;

		double gamma = 1/sqrt(1-beta*beta);
		double length = sqrt(bx_*bx_+by_*by_+bz_*bz_);

		double bx = bx_/length*beta;
		double by = by_/length*beta;
		double bz = bz_/length*beta;

		m_t = gamma*( t_0 - bx*x_0 - by*y_0 - bz*z_0 );
		m_x = -gamma*bx*t_0 + (1+(gamma-1)*bx*bx/(beta*beta))*x_0 + (gamma-1)*bx*by/(beta*beta)*y_0 + (gamma-1)*bx*bz/(beta*beta)*z_0;
		m_y = -gamma*by*t_0 + (gamma-1)*by*bx/(beta*beta)*x_0 + (1+(gamma-1)*by*by/(beta*beta))*y_0 + (gamma-1)*by*bz/(beta*beta)*z_0;
		m_z = -gamma*bz*t_0 + (gamma-1)*bz*bx/(beta*beta)*x_0 + (gamma-1)*bz*by/(beta*beta)*y_0 + (1+(gamma-1)*bz*bz/(beta*beta))*z_0;

	}
}

double FourVector::length() const
{
	return sqrt( m_t*m_t - m_x*m_x - m_y*m_y - m_z*m_z );
}

void FourVector::setElements(const double t, const double x, const double y, const double z)
{
		m_t = t;
		m_x = x;
		m_y = y;
		m_z = z;
}





















