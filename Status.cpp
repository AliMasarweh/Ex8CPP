#include "Status.h"

Status::Status() {
	this->status = '.';
}

Status::Status(const char status) {
	this->operator =(status);
}

Status::Status(const Status& newStatus) {
	this->status = newStatus.status;
}

Status::~Status() {}

char Status::getStatus() const{
	return this->status;
}

void Status::setStatus(const char newStatus) {
	this->status = newStatus;
}

Status& Status::operator= (const char newStatus){
	if (newStatus == '.' || newStatus == 'X' || newStatus == 'O') {
		setStatus(newStatus);
	}
	else
		throw IllegalCharException(newStatus);//An illegal char is sent
	return *this;
}


Status& Status::operator= (const Status& newStatus) {
	this->status = newStatus.status;
	return *this;
}

Status::operator char() const {
	return getStatus();
}

ostream& operator<< (ostream& os, const Status& newStatus) {
	return os << newStatus.status;
}

bool Status::operator != (char stat) {
	return (this->status != stat);
}

bool Status::operator == (char stat) {
	return (this->status == stat);
}
