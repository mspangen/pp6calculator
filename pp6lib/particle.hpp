#ifndef __PARTICLE_H__
#define __PARTICLE_H__

#include "fourvector.hpp"

class Particle {

public:

	Particle ();
	Particle (const double mass, const double px, const double py, const double pz);
	~Particle ();

	double getMass () const;
	double getEnergy () const;
	double getPx () const;
	double getPy () const;
	double getPz () const;

	void boost(const double beta, const double b1, const double b2, const double b3);

private:

	FourVector m_pvec; // 4-momentum vector
	double m_mass;
	const std::string m_type;

	void calcEnergy ();

};

#endif
