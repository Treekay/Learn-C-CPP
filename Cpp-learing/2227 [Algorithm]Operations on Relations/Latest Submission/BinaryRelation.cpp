#include "BinaryRelation.hpp"

int BinaryRelation::getSetElePos(int poi){
		for (int index = 1; index <= set.getSize(); index++){
		if (set.get(index) == poi) return index;
	}
	return -1;
}
BinaryRelation::BinaryRelation(BooleanMatrix const &m, Set const &s): Relation(m), set(s){}
int BinaryRelation::inDegree(int poi){
	int columns =getBooleanMatrix().getColums();
	int row = getBooleanMatrix().getRow();
	int index = getSetElePos(poi);
	int in_col = index;
	int num = 0;
	for (int i = 1; i <= row; i++){
		if (getBooleanMatrix().getElement(i, in_col) == 1) num++;
	}
	return num;
}
int BinaryRelation::outDegree(int poi){
	int columns = getBooleanMatrix().getColums();
	int row = getBooleanMatrix().getRow();
	int index = getSetElePos(poi);
	int in_row = index;
	int num = 0;
	for (int i = 1; i <= columns; i++){
		if (getBooleanMatrix().getElement(in_row, i) == 1) num++;
	}
	return num;
}

BinaryRelation BinaryRelation::pathOfLength(int len){
	BooleanMatrix newmatrix(getBooleanMatrix());
	for (int index = 1; index < len; index++) {
		newmatrix = newmatrix.BooleanProduct(newmatrix);
	}
	BinaryRelation out(newmatrix, set);
	return out;
}

// Properties of Relations.    
bool BinaryRelation::isReflexive() const{
	int columns = matrix.getColums();
	int row = matrix.getRow();
	for (int index = 1; index <= row; index++){
		if (matrix.getElement(index, index) == 0) return false;
	}
	return true;
}
bool BinaryRelation::isIrreflexive() const{
	int columns = matrix.getColums();
	int row = matrix.getRow();
	for (int index = 1; index <= row; index++){
		if (matrix.getElement(index, index) == 1) return false;
	}
	return true;
}
bool BinaryRelation::isSymmetric() const{
	int columns = matrix.getColums();
	int row = matrix.getRow();
	for (int i = 1; i <= row; i++){
		for (int j = 1; j <= columns; j++){
			if (i != j){
				if ( matrix.getElement(i, j) != matrix.getElement(j, i) ) return false;
			}
		}
	}
	return true;
}
bool BinaryRelation::isAsymmetric() const{
	int columns = matrix.getColums();
	int row = matrix.getRow();
	for (int i = 1; i <= row; i++){
		for (int j = 1; j <= columns; j++){
			if (i == j){
				if ( matrix.getElement(i, j) == 1) return false;
			}
			else if (i != j){
				if ( matrix.getElement(i, j) == 1 && matrix.getElement(j, i) == 1) return false;
			}
		}
	}
	return true;
}
bool BinaryRelation::isAntisymmetric() const{
	int columns = matrix.getColums();
	int row = matrix.getRow();
	for (int i = 1; i <= row; i++){
		for (int j = 1; j <= columns; j++){
			if (i != j){
				if ( matrix.getElement(i, j) == 1 && matrix.getElement(j, i) == 1) return false;
			}
		}
	}
	return true;
}
bool BinaryRelation::isTransitive() const{
	int columns = matrix.getColums();
	int row = matrix.getRow();
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= columns; j++) {
			if (matrix.getElement(i, j) == 1) {
				for (int k = 1; k <= row; k++) {
					if (matrix.getElement(j, k) == 1 && matrix.getElement(i, k) == 0) {
						return false;
					}
				}
			}
		}
	}
	return true;
}

bool BinaryRelation::isEquivalence() const{
	if (isTransitive() && isReflexive() && isSymmetric()) return true;
	else return false;
}

BinaryRelation BinaryRelation::composition(const BinaryRelation &another){
	BooleanMatrix newmatrix(matrix.BooleanProduct(another.matrix));
	Set newset;
	Set poi(another.set);
	for (int i = 1; i <= set.getSize();i++) {
		if (outDegree(set.get(i))) newset.append(set.get(i));
	}
	for (int i = 1; i <= poi.getSize();i++) {
		if (inDegree(poi.get(i))) newset.append(poi.get(i));
	}
	BinaryRelation out(newmatrix, newset);
	return out;
}

BinaryRelation BinaryRelation::reflexiveClosure() const{
	int columns = matrix.getColums();
	int row = matrix.getRow();
	BooleanMatrix newmatrix(getBooleanMatrix());
	for (int i =1; i <= row; i++){
		newmatrix.replace(1, i, i);
	}
	BinaryRelation out(newmatrix, set);
	return out;
}
BinaryRelation BinaryRelation::symmetricClosure() const{
	int columns = matrix.getColums();
	int row = matrix.getRow();
	BooleanMatrix newmatrix(getBooleanMatrix());
	for (int i =1; i <= row; i++){
		for (int j = 1; j <= columns; j++) {
			if (i != j) {
				if (newmatrix.getElement(i, j) == 1) newmatrix.replace(1, j, i);
			}
		}
	}
	BinaryRelation out(newmatrix, set);
	return out;
}
BinaryRelation BinaryRelation::transitiveClosure() const{
	int columns = matrix.getColums();
	int row = matrix.getRow();
	BooleanMatrix newmatrix(getBooleanMatrix());
	for (int k = 1; k <= columns; k++) {
		for (int i = 1; i <= columns; i++) {
			for (int j = 1; j <= columns; j++) {
				if (newmatrix.getElement(i, j) == 1 ||(newmatrix.getElement(k, j) == 1&& newmatrix.getElement(i, k) == 1)) {
					newmatrix.replace(1, i ,j);
				}
			}
		}
	}
	BinaryRelation out(newmatrix, set);
	return out;
}