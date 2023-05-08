#include "Lion.h"

Lion::Lion() {}
Lion::Lion(const std::string& name, const Location& loc)
{
	

	this->name = name;
	this->loc = loc;
	Horizontally = 0;
	isMove = rand() % 2;
}
Lion::Lion(const std::string& name)
{

	
	this->name = name;
	this->loc.row = rand() % 20;
	this->loc.col = rand() % 40;
	Horizontally = 0;
	isMove = rand() % 2;
}
void Lion::printDetails()
{
	Animal::printDetails();
	std::cout << "   type : Lion  "<<std::endl;
}
char Lion::getInitial()
{
	return'L';
}

void Lion::turnHorizontally()
{

	
	if (this->Horizontally == 0)
		Horizontally = 1;     //move right
	else
		Horizontally = 0;		//move left
}
void Lion::step()
{
	if (this->isMove == 1)		
	{
		if (Horizontally == 0)
		{
			this->loc.col -= 2;
			if (loc.col < 0)
			{
				loc.col *= -1;
				turnHorizontally();
			}
		}
		else {
			if(loc.col<=37)
				this->loc.col += 2;
			else if (loc.col == 38)
			{
				loc.col = 38;
				turnHorizontally();
			}
			else if (loc.col == 39) 
			{
				loc.col = 37;
				turnHorizontally();
			}		
		}
	}
}
void Lion::move()
{
	if (this->isMove==0)
	Animal::move();
	this->Horizontally = rand() % 2;
}
