#ifndef VEHICLE_H
#define VEHICLE_H

#include <cmath>
#include <iostream>
using namespace std;
struct City {
    double x, y;          // position of the city
    std::string name;  // name of city
};

class Vehicle {
 public:
    explicit Vehicle(double _speed) : speed(_speed) {}
    virtual void doTravel(const City& src, const City& dest) = 0;
    double getSpeed() const {
        return speed;
    }
    virtual ~Vehicle() {}

 private:
    double speed;
};

class BicycleStrategy:public Vehicle {
public:
	BicycleStrategy(double _speed) : Vehicle(_speed) {}
	void doTravel(const City& src, const City& dest){
		double dis;
		dis = fabs(src.x - dest.x) + fabs(src.y - dest.y);
		double tim;
		tim = dis/getSpeed();
		cout <<"It takes "<< tim <<" hours to Travel from "
		<< src.name <<" to "<< dest.name<<" by Bicycle."<<endl;
	}
	~BicycleStrategy(){}
};

class TrainStrategy:public Vehicle {
public:
	TrainStrategy(double _speed): Vehicle(_speed) {}
	void doTravel(const City& src, const City& dest){
		double dis;
		dis = sqrt((src.x - dest.x)*(src.x - dest.x) + (src.y - dest.y)*(src.y - dest.y));
		double tim;
		tim = dis/getSpeed();
		cout <<"It takes "<< tim <<" hours to Travel from "
		<< src.name <<" to "<< dest.name<<" by Train."<<endl;
	}
	~TrainStrategy(){}
};

class AirplaneStrategy:public Vehicle {
public:
	AirplaneStrategy(double _speed): Vehicle(_speed) {}
	void doTravel(const City& src, const City& dest){
		double dis;
		dis = fabs(src.x - dest.x) > fabs(src.y - dest.y) ? fabs(src.x - dest.x) : fabs(src.y - dest.y);
		double tim;
		tim = dis/getSpeed();
		cout <<"It takes "<< tim <<" hours to Travel from "
		<< src.name <<" to "<< dest.name<<" by Airplane."<<endl;
	}
	~AirplaneStrategy(){}
};

#endif