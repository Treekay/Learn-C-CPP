#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    int sex;
    string name;
public:
   Person (string _name, int _sex){
     sex = _sex;
     name = _name;
     cout << "Construct Person" << endl;
   }
   ~Person(){
     cout << "Destruct Person" << endl;
   }
   string getName(){
    return name;
   }
   int getSex(){
    return sex;
   }
 };
class Student:virtual public Person {
private:
    string sno;
public:
    Student(string _name, int _sex,string _sno): Person( _name, _sex){
      sno = _sno;
      cout << "Construct Student" << endl;
    }
    ~Student(){
      cout << "Destruct Student" << endl;
    }
    string getSno(){
      return sno;
    }
};
class Worker:virtual public Person {
private:
    string wno;
public:
    Worker(string _name, int _sex,string _wno): Person( _name, _sex) {
      wno = _wno;
      cout << "Construct Worker" << endl;
    }
    ~Worker(){
      cout << "Destruct Worker" << endl;
    }
    string getWno(){
      return wno;
    }
};
class InService:public Student,public Worker {
public:
    InService(string _name, int _sex, string _sno, string _wno):Person(_name, _sex),Student(_name, _sex,_sno), Worker(_name, _sex,_wno){
      cout << "Construct InService" << endl;
    }
    ~InService(){
      cout << "Destruct InService" << endl;
    }
};