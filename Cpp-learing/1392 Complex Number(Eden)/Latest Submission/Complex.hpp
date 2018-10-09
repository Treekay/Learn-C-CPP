using namespace std;
class Complex {
  
    public :
    Complex(double ,double);
    Complex(){
         realPart = 0.0;
         imaginaryPart = 0.0;
       };
    void printComplex();
    void setComplexNumber( double, double );
    Complex add(const Complex &);
    Complex subtract(const Complex &);
  
    private :
    double realPart;
    double imaginaryPart;
    
 };