#ifndef __FOURVECTOR_HPP__
#define __FOURVECTOR_HPP__

#include <cmath>

struct FourVector;

FourVector* createFourVector ();

void destroyFourVector (FourVector *&v);

double getFourVectorT (FourVector *v);
double getFourVectorX (FourVector *v);
double getFourVectorY (FourVector *v);
double getFourVectorZ (FourVector *v);

void setFourVectorElements (FourVector *v, double v0, double v1, double v2, double v3);
int boostZFourVector (FourVector *v, double beta);
int boostFourVector (FourVector *v, double beta, double _bx, double _by, double _bz);
double lengthOfFourVector (FourVector *v);


#endif //__FOURVECTOR_HPP__
