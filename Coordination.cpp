#include "Coordination.h"

Coordination::Coordination() {
	this->x_Coordination = 0;
	this->y_Coordination = 0;
}

Coordination::Coordination(int xCoordination, int yCoordination) {
	this->x_Coordination = xCoordination;
	this->y_Coordination = yCoordination;
}

Coordination::Coordination(unsigned int xCoordination, unsigned int yCoordination) {
	this->x_Coordination = xCoordination;
	this->y_Coordination = yCoordination;
}

Coordination& Coordination::operator= (const Coordination& otherCoordination) {
	this->x_Coordination = otherCoordination.getXCoordination();
	this->y_Coordination = otherCoordination.getYCoordination();
	return *this;
}

Coordination::~Coordination() { }

int Coordination::getXCoordination() const {
	return this->x_Coordination;
}

int Coordination::getYCoordination() const {
	return this->y_Coordination;
}

void Coordination::setXCoordination(int xCoordination) {
	this->x_Coordination = xCoordination;
}

void Coordination::setYCoordination(int yCoordination) {
	this->y_Coordination = yCoordination;
}

