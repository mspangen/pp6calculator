#ifndef __PARTICLE_H__
#define __PARTICLE_H__

//#include "threevector.hpp"
#include "fourvector.hpp"

class Particle {

public:

	Particle ();
	Particle (const double invmass, const double px, const double py, const double pz);
	Particle (const double energy, const double px, const double py, const double pz);
	~Particle ();


	double getInvMass () const;
	double getEnergy () const;
	double getPx () const;
	double getPy () const;
	double getPz () const;



private:

	FourVector _mp_vec; //Need somehow to redefine member variables to contain mass, momentum and energy
	const std::string type;
	
	double _invmass;
	double _energy;
	double _px, _py, _pz;

	void calcInvMass ();
	void calcEnergy ();

}














#endif
