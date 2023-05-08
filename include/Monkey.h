#pragma once
#include<iostream>
#include "Animal.h"

class Monkey : public Animal
{
	int moneOfJumps,stepOfJump,dir;
public:
	Monkey();  //ctor
	Monkey(const std::string&, const Location&); //c-tor
	Monkey(const std::string& name);
	void printDetails() override;
	char getInitial() override;
	void turnVertically()override;
	void turnHorizontally()override;
	void step()override;
};
