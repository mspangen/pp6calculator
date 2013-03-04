#include "particle.hpp"

// Constructors

Particle::Particle (const double mass, const double px, const double py, const double pz)
{
	_invmass = invmass;
	_px = px;
	_py = py;
	_pz = pz;
	calcEnergy();
}

Particle::Particle (const double energy, const double px, const double py, const double pz)
{
	_energy = energy;
	_px = px;
	_py = py;
	_pz = pz;
	calcInvMass();
}

// Functions to get particle values

double Particle::getInvMass () const
{
	return _invmass;
}

double Particle::getEnergy () const
{
	return _energy;
}

double Particle::getPx () const
{
	return _px;
}

double Particle::getPy () const
{
	return _py;
}

double Particle::getPz () const
{
	return _pz;
}


// Private functions

void Particle::calcInvMass ()
{

}

void Particle::calcEnergy ()
{

}
