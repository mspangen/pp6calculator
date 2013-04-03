#include "particle.hpp"

// Constructors

Particle::Particle (const double mass, const double px, const double py, const double pz)
{
	m_mass = mass;
	m_pvec.setv1(px);
	m_pvec.setv2(py);
	m_pvec.setv3(pz);
	calcEnergy();
}

Particle::~Particle()
{
}

// Functions to get particle values

double Particle::getMass () const
{
	return m_mass;
}

double Particle::getEnergy () const
{
	return m_pvec.getv0();
}

double Particle::getPx () const
{
	return m_pvec.getv1();
}

double Particle::getPy () const
{
	return m_pvec.getv2();
}

double Particle::getPz () const
{
	return m_pvec.getv3();
}

void Particle::boost(const double beta, const double b1, const double b2, const double b3)
{
	m_pvec.boost(beta,b1,b2,b3);
}

// Private functions

void Particle::calcEnergy ()
{
	m_pvec.setv0( Square(m_pvec.getv1()) + Square(m_pvec.getv2()) + Square(m_pvec.getv3()) + Square(m_mass) );
}
