 class Exp {
  private:
   static int exp;
  public:
   static int get_Exp(){
     return exp;
   }
   Exp(){
     exp++;
   }
   ~Exp(){
     exp--;
   }
   
 };
int Exp::exp = 0;
int get_Exp();