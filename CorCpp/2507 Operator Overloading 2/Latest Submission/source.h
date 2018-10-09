#include <iostream>
using namespace std;
class Calculator{
public:
  Calculator(int _value){
    value = _value;
  	}
  Calculator& operator++ (){
    ++value;
    if (value < 0 || value > 99) value = 0;
    cout << "counter = " << value << endl;
    return *this;
  	}
  Calculator& operator-- (){
    --value;
    if (value < 0 || value > 99) value = 0;
    cout << "counter = " << value << endl;
    return *this;
  	}
private:
  int value;
};