#pragma once
#include<vector>
#include "Animal.h"
#include "Lion.h"
#include "Location.h"
#include"Monkey.h"
#include "Goose.h"
class Zoo
{
private:
	std::vector<Animal*> Animal_vec;
	char mapArr[20][40] ;
	void printMap();
public:
	Zoo();//ctor
	void print();
	void stop(int);
	void move(int);
	void create(std::string type, std::string name );
	void del(int);
	void delAll(std::string type);
	void help();
	void step();
	void moveAll();
	void stopAll();
	
	void run();
};

