#pragma once
#include<iostream>
#include "Animal.h"

class Goose : public Animal
{
public:
	Goose();  //ctor
	Goose(const std::string&, const Location&); //c-tor
	Goose(const std::string& name);
	void printDetails() override;
	char getInitial() override;
	void turnVertically()override;
	void turnHorizontally()override;
	void step()override;
	void move()override;
};

