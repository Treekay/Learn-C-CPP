#include "Job.h"
#include <sstream>
#include <iostream>
using namespace std;
int Job::number = 0;
Job::Job(int priority){
	setId(number++);
	setPriority(priority);
	nextJob = NULL;
}
void Job::setId(int id){
	this->id = id;
}
int Job::getId() const{
	return id;
}
void Job::setPriority(int priority){
	this->priority = priority;
}
int Job::getPriority() const{
	return priority;
}
void Job::setNext(Job *job){
	this->nextJob = job; 
}
Job * Job::getNext() const{
	return nextJob;
}
string Job::toString(){
	string str;
	str +='[';

	stringstream ss1;
	string _id;
	ss1 << id;
	ss1 >> _id;
	str += _id;

	str += ':';

	stringstream ss2;
	string _priority;
	ss2 << priority;
	ss2 >> _priority;
	str += _priority;

	str += ']';
	return str;
}