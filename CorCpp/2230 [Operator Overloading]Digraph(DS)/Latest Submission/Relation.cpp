#include "Relation.hpp"

Relation::Relation(BooleanMatrix const &m): mat(m){}
bool Relation::isReflexive() const{
	int columns = mat.getColums();
	int row = mat.getRow();
	for (int index = 1; index <= row; index++){
		if (mat.getElement(index, index) == 0) return false;
	}
	return true;
}
bool Relation::isIrreflexive() const{
	int columns = mat.getColums();
	int row = mat.getRow();
	for (int index = 1; index <= row; index++){
		if (mat.getElement(index, index) == 1) return false;
	}
	return true;
}
bool Relation::isSymmetric() const{
	int columns = mat.getColums();
	int row = mat.getRow();
	for (int i = 1; i <= row; i++){
		for (int j = 1; j <= columns; j++){
			if (i != j){
				if ( mat.getElement(i, j) != mat.getElement(j, i) ) return false;
			}
		}
	}
	return true;
}
bool Relation::isAsymmetric() const{
	int columns = mat.getColums();
	int row = mat.getRow();
	for (int i = 1; i <= row; i++){
		for (int j = 1; j <= columns; j++){
			if (i == j){
				if ( mat.getElement(i, j) == 1) return false;
			}
			else if (i != j){
				if ( mat.getElement(i, j) == 1 && mat.getElement(j, i) == 1) return false;
			}
		}
	}
	return true;
}
bool Relation::isAntisymmetric() const{
	int columns = mat.getColums();
	int row = mat.getRow();
	for (int i = 1; i <= row; i++){
		for (int j = 1; j <= columns; j++){
			if (i != j){
				if ( mat.getElement(i, j) == 1 && mat.getElement(j, i) == 1) return false;
			}
		}
	}
	return true;
}

bool Relation::isTransitive() const{
	int columns = mat.getColums();
	int row = mat.getRow();
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= columns; j++) {
			if (mat.getElement(i, j) == 1) {
				for (int k = 1; k <= row; k++) {
					if (mat.getElement(j, k) == 1 && mat.getElement(i, k) == 0) {
						return false;
					}
				}
			}
		}
	}
	return true;
}

BooleanMatrix Relation::getmatrix() const{
	return mat;
}