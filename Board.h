#pragma once
#ifndef BOARD_HPP_
#define BOARD_HPP_


#include "Status.h"
#include "Coordination.h"
#include "IllegalCoordinateException.cpp"


class Board {
private:
	Status** board;
	int sizeOfBoard;
	bool exists(const std::string& name);

public:
	Board();
	Board(int size);
	Board(const Board& newBorad);
	~Board();
	Board& operator=(const Board& newBorad);
	Board& operator= (const char newChar);
	Status& operator[] (const Coordination &newChar) const;
	friend ostream& operator<< (ostream& os, const Board& newBorad);
	friend istream& operator>> (istream& is, Board& newBorad);
	unsigned int size() const;
	int BoardSize() const;
	string draw(int pixels);
};

struct RedGreenBlue {
	uint8_t red, green, blue;
public:
	RedGreenBlue() {}
	RedGreenBlue(uint8_t red, uint8_t green, uint8_t blue) {
		this->red = red;
		this->green = green;
		this->blue = blue;
	}
};
#endif
