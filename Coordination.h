#pragma once
#ifndef Coordination_HPP_
#define Coordination_HPP_



class Coordination {
private:
	int x_Coordination, y_Coordination;

public:
	Coordination();
	Coordination(int xCoordination, int yCoordination);
	Coordination(unsigned int xCoordination, unsigned int yCoordination);
	~Coordination();
	Coordination& operator= (const Coordination& otherCoordination);
	int getXCoordination() const;
	int getYCoordination() const;
	void setXCoordination(int xCoordination);
	void setYCoordination(int yCoordination);
};
#endif