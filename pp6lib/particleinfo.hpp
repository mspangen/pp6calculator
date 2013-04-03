#ifndef PARTICLEINFO_HPP
#define PARTICLEINFO_HPP

#include <string>
#include <map>

class ParticleInfo {

public:

	ParticleInfo ();
	ParticleInfo (std::string&);
	ParticleInfo (const ParticleInfo&);

	int getPDGCode (std::string& name);
	int getCharge (int pdgID);
	std::string getName (int pdgID);
	double getMassMeV (int pdgID);
	double getMassGeV (int pdgID);

	// Operators
	ParticleInfo& operator=(const ParticleInfo& rhs);


private:

	struct particle {
		std::string name;
		int charge;
		double mass;
	};

	std::map<int,particle> map_ID;

};


#endif