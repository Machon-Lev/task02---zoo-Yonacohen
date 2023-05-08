#include "Goose.h"

Goose::Goose() {}
Goose::Goose(const std::string& name, const Location& loc) {
	//and(time(NULL));
	isMove = rand() % 2;
	Horizontally = rand() % 2;
	Vertically = rand() % 2;
	this->name = name;
	this->loc = loc;
}
Goose::Goose(const std::string& name)
{
	//and(time(NULL));
	this->name = name;
	this->loc.row = rand() % 20;
	this->loc.col = rand() % 40;
	Horizontally = 0;
	isMove = rand() % 2;
}
void Goose::printDetails()
{
	Animal::printDetails();
	std::cout << "    type : Goose    " << std::endl;
}
char Goose::getInitial()
{
	return'G';
}

void Goose::turnVertically()
{

	if (this->Vertically == 0)   //0 = down
		this->Vertically = 1;     //1 = up
	else
		Vertically = 0;
}
void Goose::turnHorizontally()
{
	if (this->Horizontally == 0)   // move left 
		this->Horizontally = 1;		//move right
	else
		Horizontally = 0;
}
void Goose::step()
{
	Horizontally = rand() % 2;  //0-????-1 ????
	Vertically = rand() % 2;	//?????-1 ????-0
	if (this->isMove == 1)
	{
		if (this->Horizontally == 1)
		{
			loc.col += 1;
			if (loc.col == 39) 
			{
				turnHorizontally();
			}
			if (loc.col == 40)
			{
				loc.col = 38;
			}
			
		}
		if (this->Horizontally == 0)
		{
			loc.col -= 1;
			if (loc.col < 0)
				loc.col *= -1;
		}
		if (this->Vertically == 1)
		{
			loc.row -= 1;
			if (loc.row < 0)
				loc.row *= -1;

		}
		if (this->Vertically == 0)
		{
			loc.row += 1;
			if (loc.row == 20)
			{
				turnVertically();
				loc.row = 18;
			}
			if (loc.row == 19 )
				turnVertically();
			
			
		}

	}

}
void Goose::move() 
{
	if (this->isMove == 0)
	Animal::move();
	this->Horizontally = rand() % 2;
	this->Vertically == rand() % 2;
}