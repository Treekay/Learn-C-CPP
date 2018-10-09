#ifndef _RELATION_H
#define _RELATION_H

#include "ProductSet.hpp"
#include "BooleanMatrix.hpp"

class Relation {
private:
	BooleanMatrix mat;
public:
	Relation(BooleanMatrix const &m);
	bool isReflexive() const;
    bool isIrreflexive() const;
    bool isSymmetric() const;
    bool isAsymmetric() const;
    bool isAntisymmetric() const;
    BooleanMatrix getmatrix() const;
    
    bool isTransitive() const;
};

#endif