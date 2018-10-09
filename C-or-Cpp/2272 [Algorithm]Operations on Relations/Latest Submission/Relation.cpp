 #include "Relation.hpp"

Relation::Relation(BooleanMatrix const &mat) : matrix(mat){}

BooleanMatrix Relation::getBooleanMatrix() const{
	return matrix;
}

// Operations on Relations
Relation Relation::complementary() const{
	BooleanMatrix newmatrix(getBooleanMatrix());
	int columns = matrix.getColums();
	int row = matrix.getRow();
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= columns; j++){
			if (newmatrix.getElement(i, j) == 1) newmatrix.replace(0, i, j);
			else newmatrix.replace(1, i, j);
		}
	}
	Relation out(newmatrix);
	return out;
}
Relation Relation::inverse() const{
	/*BooleanMatrix newmatrix();
	int columns = matrix.getColums();
	int row = matrix.getRow();
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= columns; j++){
			if (newmatrix.getElement(i, j) == 1) newmatrix.replace(0, i, j);
			else newmatrix.replace(1, i, j);	
		}
	}*/
	Relation out(getBooleanMatrix().transpose());
	return out;
}
Relation Relation::operator&(const Relation &another){
	Relation out(matrix & another.matrix);
	return out;
}
Relation Relation::operator|(const Relation &another){
	Relation out(matrix | another.matrix);
	return out;
}