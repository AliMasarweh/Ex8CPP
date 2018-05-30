#pragma once
#ifndef STATUS_HPP_
#define STATUS_HPP_

#include <iostream>
#include "IllegalCharException.cpp"

using namespace std;

class Status {
private:
	char status;

public:
	Status();
	Status(char status);
	Status(const Status& status);
	~Status();
	char getStatus() const;
	void setStatus(char status);
	Status& operator= (const char status);
	Status& operator= (const Status& status);
	operator char() const;
	bool operator != (char stat);
	//bool operator != (Status stat);
	bool operator == (char stat);
	//bool operator == (Status stat);
	friend ostream& operator<< (ostream& os, const Status& status);
};

#endif