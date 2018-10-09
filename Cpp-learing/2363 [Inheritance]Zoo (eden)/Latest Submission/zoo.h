 #include <vector>
#include <string>
#include "animal.h"
using namespace std;

class Zoo{
public:
	Zoo();
	void addAnimal(Cat*);
	void addAnimal(Dog*);
	void deleteAnimalByName(string);
	void deleteAnimalByAge(int);
	int getCatCount();
	int getDogCount();
	void print();
	~Zoo();
private:
	vector <Cat> catcontain;
	vector <Dog> dogcontain;
};