#include "fourvector.hpp"

struct FourVector {
	double t;
	double x;
	double y;
	double z;
};

FourVector* createFourVector()
{
	return new FourVector;
}

void destroyFourVector(FourVector *&v)
{
	if(v) {
		delete v;
		v = 0;
	}
}

double getFourVectorT(FourVector *v)
{
	return v->t;
}

double getFourVectorX(FourVector *v)
{
	return v->x;
}

double getFourVectorY(FourVector *v)
{
	return v->y;
}

double getFourVectorZ(FourVector *v)
{
	return v->z;
}

void setFourVectorElements(FourVector *v, double t, double x, double y, double z)
{
	if (v) {
		v->t = t;
		v->x = x;
		v->y = y;
		v->z = z;
	}
}

int boostZFourVector(FourVector *v, double beta)
{
	if (v && (1-beta*beta) > 0) {
		double gamma = 1/sqrt(1-beta*beta);
		v->t = gamma*( (v->t) - beta*(v->z) );
		v->z = gamma*( (v->z) - beta*(v->t) );
		return 0;
	} else {
		return -1;
	}
}

int boostFourVector(FourVector *v, double beta, double _bx, double _by, double _bz)
{
	if (v && (1-beta*beta) > 0) {
		double gamma = 1/sqrt(1-beta*beta);
		double length = sqrt(_bx*_bx+_by*_by+_bz*_bz);

		double bx = _bx/length*beta;
		double by = _by/length*beta;
		double bz = _bz/length*beta;

		v->t = gamma*( (v->t) - bx*(v->x) - by*(v->y) - bz*(v->z) );
		v->x = -gamma*bx*(v->t) + (1+(gamma-1)*bx*bx/(beta*beta))*(v->x) + (gamma-1)*bx*by/(beta*beta)*(v->y) + (gamma-1)*bx*bz/(beta*beta)*(v->z);
		v->y = -gamma*by*(v->t) + (gamma-1)*by*bx/(beta*beta)*(v->x) + (1+(gamma-1)*by*by/(beta*beta))*(v->y) + (gamma-1)*by*bz/(beta*beta)*(v->z);
		v->z = -gamma*bz*(v->t) + (gamma-1)*bz*bx/(beta*beta)*(v->x) + (gamma-1)*bz*by/(beta*beta)*(v->y) + (1+(gamma-1)*bz*bz/(beta*beta))*(v->z);
		return 0;

	} else {
		return -1;
	}
}

double lengthOfFourVector(FourVector *v)
{
	return sqrt( (v->t)*(v->t) - (v->x)*(v->x) - (v->y)*(v->y) - (v->z)*(v->z) );
}























