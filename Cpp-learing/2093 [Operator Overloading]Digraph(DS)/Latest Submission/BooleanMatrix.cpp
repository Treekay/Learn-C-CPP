#include "BooleanMatrix.hpp"

BooleanMatrix::BooleanMatrix(const BooleanMatrix & another) : Matrix(another.row, another.columns){
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= columns; j++) {
            matrix[ELEMENT_POS(i, j)] = another.matrix[ELEMENT_POS(i, j)];
        }
    }
}
BooleanMatrix::BooleanMatrix(int r, int c) : Matrix(r, c){}                       

bool BooleanMatrix::replace(matrix_element_type e, int r, int c) {
	 return Matrix::replace(e, r, c);
}

BooleanMatrix BooleanMatrix::operator&(const BooleanMatrix & another){
	BooleanMatrix newmatrix(another);
	for(int i = 1; i <= getRow(); i++){
		for (int j= 1; j <= getColums(); j++){
			newmatrix.matrix[ELEMENT_POS(i, j)] &= matrix[ELEMENT_POS(i, j)];
		}
	}
	return newmatrix;
}
BooleanMatrix BooleanMatrix::operator|(const BooleanMatrix & another){
	BooleanMatrix newmatrix(another);
	for(int i = 1; i <= getRow(); i++){
		for (int j= 1; j <= getColums(); j++){
			newmatrix.matrix[ELEMENT_POS(i, j)] |= matrix[ELEMENT_POS(i, j)];
		}
	}
	return newmatrix;
}
BooleanMatrix BooleanMatrix::BooleanProduct(const BooleanMatrix & another) const{
	BooleanMatrix newmatrix(getRow(),another.getColums());
	int columns = another.getColums();
	for(int i = 1; i <= getRow(); i++){
		for (int j= 1; j <= another.getColums(); j++){
			for (int k = 1; k <= getColums(); k++){
				if (getElement(i, k) & another.getElement(k, j) == 1) newmatrix.matrix[ELEMENT_POS(i, j)] = 1;
			}
		}
	}
	return newmatrix;
}