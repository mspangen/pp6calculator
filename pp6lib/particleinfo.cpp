#include "particleinfo.hpp"
#include "../filereader/filereader.hpp"
#include <iostream>

ParticleInfo::ParticleInfo ()
{
}

ParticleInfo::ParticleInfo (std::string& file)
{
	FileReader f(file);
	if(!f.isValid()) {
		throw "File not found!";
	}

	particle p;
	while (f.nextLine()) {
		p.name = f.getField<std::string>(1);
		p.charge = f.getField<int>(3);
		p.mass = f.getField<double>(4);

		map_ID.insert(std::make_pair(f.getField<int>(2),p));
	}

}


int ParticleInfo::getPDGCode (std::string& name)
{
	std::map<int,particle>::iterator it;
	for (it = map_ID.begin(); it != map_ID.end(); ++it) {
		if ((it->second).name == name) {
			return it->first;
		}
	}
	//If not found
	std::cout << "Particle not found!" << std::endl;
	return 0;
}


std::string ParticleInfo::getName (int pdgID)
{
	return map_ID[pdgID].name;
}

int ParticleInfo::getCharge (int pdgID)
{
	return map_ID[pdgID].charge;
}

double ParticleInfo::getMassMeV (int pdgID)
{
	return map_ID[pdgID].mass;
}

double ParticleInfo::getMassGeV (int pdgID)
{
	return map_ID[pdgID].mass/1000.;
}


// Operators

ParticleInfo& ParticleInfo::operator=(const ParticleInfo& rhs)
{
	if (&rhs != this) {
		map_ID = rhs.map_ID;
	} 
	return *this;
}
