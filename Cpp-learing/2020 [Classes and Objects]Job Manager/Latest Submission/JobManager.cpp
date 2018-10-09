#include "JobManager.h"
#include <iostream>
using namespace std;

JobManager* JobManager::instance = NULL;

JobManager* JobManager::getInstance(){
	if (JobManager::instance == NULL) {
		JobManager::instance = new JobManager();
		instance->jobFrontPointer = NULL;
	}
	return JobManager::instance;
} 
bool JobManager::deleteInstance(){
	if (JobManager::instance == NULL) return false;
	else {
		instance->clear();
		delete instance;
		JobManager::instance = NULL;
		return true;
	}
}
void JobManager::addJob(int priority){
	if (instance->jobFrontPointer == NULL) {
		instance->jobFrontPointer = new Job(priority);
	}
	else {
		Job* current;
		current = instance->jobFrontPointer;
		while (current-> getNext() != NULL) {
			current = current->getNext();
		}
		Job* poi;
		poi = new Job(priority);
		current->setNext(poi);
	}
}
void JobManager::finishOneJob(){
	if (instance->jobFrontPointer != NULL){
		Job* poi;
		poi = instance->jobFrontPointer->getNext();
		delete instance->jobFrontPointer;
		instance->jobFrontPointer = poi;
	}
}
void JobManager::sortJob(){
	Job* current1;
	Job* current2;
	current2 = instance->jobFrontPointer;
	int exid;
	int expri;
	int num = instance->getNumOfJob();
	for (current1 = instance->jobFrontPointer; current1 != NULL; current1 = current1->getNext()) {
		for (current2 = current1->getNext(); current2 != NULL; current2 = current2->getNext()){
			if (current1->getPriority() < current2->getPriority()) {
				expri = current1->getPriority();
				current1->setPriority(current2->getPriority());
				current2->setPriority(expri);
				exid = current1->getId();
				current1->setId(current2->getId());
				current2->setId(exid);
			}
			else if (current1->getPriority() == current2->getPriority()) {
				if (current1->getId() > current2->getId()){
					exid = current1->getId();
					current1->setId(current2->getId());
					current2->setId(exid);
				}
			}
		}
	}
}
void JobManager::printJob(){
	Job* current;
	if (instance->jobFrontPointer == NULL) {
		cout << "empty!"<< endl;
		return;
	}
	current = instance->jobFrontPointer;
	while (current != NULL){
		cout << current->toString();
		if (current->getNext() != NULL) cout << "->";
		current = current->getNext();
	}
	cout << endl;
}
int JobManager::getNumOfJob(){
	Job* current;
	int num = 0;
	if (instance == NULL) return num;
	current = instance->jobFrontPointer;
	while (current != NULL){
		current = current->getNext();
		num++;
	}
	return num;
}
void JobManager::clear(){
	Job* current = instance->jobFrontPointer;
	while (instance->jobFrontPointer != NULL){
		current = instance->jobFrontPointer;
		instance->jobFrontPointer = instance->jobFrontPointer->getNext();
		delete current;
	}
	instance->jobFrontPointer = NULL;
}
JobManager::~JobManager(){
	
}
JobManager::JobManager(){

}