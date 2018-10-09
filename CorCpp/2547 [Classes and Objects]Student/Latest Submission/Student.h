#include "Person.h"
#include "Date.h"
#include <string>

class Student : public Person {
private:
	Date graduateDate;
public:
	Student(string _name, int _age, Date _date) : Person(_name, _age){
		set(_date);
	}
	void set(Date d){
		graduateDate.setYear(d.getYear());
		graduateDate.setMonth(d.getMonth());
		graduateDate.setDay(d.getDay());
	}
  	void sayHi() const{
  		Person::sayHi();
  		Date today(2017,5,7);
  		if (graduateDate > today) cout << "I will graduate on "<< graduateDate.getYear() << '-' << graduateDate.getMonth() << '-' << graduateDate.getDay() << '.';
  		else if (graduateDate == today) cout << "I graduated today!";
  		else if (graduateDate < today) cout << "I have graduated on "<< graduateDate.getYear() << '-' << graduateDate.getMonth() << '-' << graduateDate.getDay() << '.';
  		cout <<endl;
  	}
  	void set(int age){
  		Person::set(age);
  	}
  	void set(string name){
  		Person::set(name);
  	}
};