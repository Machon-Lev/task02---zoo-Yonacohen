#pragma once
#include<iostream>
#include "Animal.h"
#include"Location.h"
class Lion : public Animal
{

	

public:
	Lion();  //ctor
	Lion(const std::string&, const Location&); //c-tor
	Lion(const std::string&);
	void printDetails() override;
	char getInitial() override;
	void step() override;
	void turnHorizontally() override;
	void move()override;
};
