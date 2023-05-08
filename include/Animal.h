#pragma once
#include<iostream>
#include "Location.h"

class Animal {
protected:
	std::string name;
	Location loc;
	bool isMove, Vertically, Horizontally;
public:

	virtual void printDetails();
	virtual char getInitial() =0    ;
	Location getLocation() const;
	virtual void step();
	void stop();
	virtual void move();
	
	virtual void turnVertically()  ;
	virtual void turnHorizontally() =0 ;
}; 

