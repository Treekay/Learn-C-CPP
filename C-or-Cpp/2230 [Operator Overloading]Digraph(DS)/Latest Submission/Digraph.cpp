#include "Digraph.hpp"

 int Digraph::getSetElePos(int poi){
	for (int index = 1; index <= set.getSize(); index++){
		if (set.get(index) == poi) return index;
	}
	return -1;
 }

Digraph::Digraph(BooleanMatrix const &m, Set const &s): Relation(m) , set(s){}; 

int Digraph::inDegree(int poi){
	int columns =getmatrix().getColums();
	int row = getmatrix().getRow();
	int index = getSetElePos(poi);
	int in_col = index;
	int num = 0;
	for (int i = 1; i <= row; i++){
		if (getmatrix().getElement(i, in_col) == 1) num++;
	}
	return num;
}
int Digraph::outDegree(int poi){
	int columns = getmatrix().getColums();
	int row = getmatrix().getRow();
	int index = getSetElePos(poi);
	int in_row = index;
	int num = 0;
	for (int i = 1; i <= columns; i++){
		if (getmatrix().getElement(in_row, i) == 1) num++;
	}
	return num;
}
    
Digraph Digraph::pathOfLength(int len){
	BooleanMatrix newmatrix(getmatrix());
	for (int index = 1; index < len; index++) {
		newmatrix = newmatrix.BooleanProduct(newmatrix);
	}
	Digraph out(newmatrix, set);
	return out;
}
    
    // Properties of Relations.    
bool Digraph::isReflexive() const{
	return Relation::isReflexive();
}
bool Digraph::isIrreflexive() const{
	return Relation::isIrreflexive();
}
bool Digraph::isSymmetric() const{
	return Relation::isSymmetric();
}
bool Digraph::isAsymmetric() const{
	return Relation::isAsymmetric();
}
bool Digraph::isAntisymmetric() const{
	return Relation::isAntisymmetric();
}

bool Digraph::isTransitive() const{
	return Relation::isTransitive();
}

BooleanMatrix Digraph::getBooleanMatrix() const{
	return Relation::getmatrix();
}