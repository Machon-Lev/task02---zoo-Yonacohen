#include "Monkey.h"
Monkey::Monkey() {}
Monkey::Monkey(const std::string& name, const Location& loc) {

	this->name = name;
	this->loc = loc;
	isMove = rand() % 2;
	Horizontally = rand() % 2;
	Vertically = rand() % 2;
	moneOfJumps = 0;
	stepOfJump = 1 + rand() % 2;
	dir = rand() % 2;
	std::cout << "stepOfJump   :    " << stepOfJump << ",  ";
	

}
Monkey::Monkey(const std::string& name)
{
	this->name = name;
	this->loc.row = rand() % 20;
	this->loc.col = rand() % 40;
	Horizontally = 0;
	Vertically = rand() % 2;
	moneOfJumps = 0;
	stepOfJump = 1 + rand() % 2;
	dir = rand() % 2;
	isMove = rand() % 2;

}
void Monkey::printDetails()
{
	Animal::printDetails();
	std::cout << "    type : Monkey  " << std::endl;
}
char Monkey::getInitial()
{
	return'M';
}
void Monkey::turnVertically()
{
	if (this->Vertically == 0)   //0 = down
		this->Vertically = 1;     //1 = up
	else
		Vertically = 0;
}
void Monkey::turnHorizontally()
{
	if (this->Horizontally == 0)   // move left 
		this->Horizontally = 1;		//move right
	else
		Horizontally = 0;
}
void Monkey::step()
{
	if (moneOfJumps == 5)
	{
		stepOfJump = 1 + rand() % 2;
		moneOfJumps = 0;
	}
	if (this->isMove == 1)
	{
		if (loc.col == 39)
			turnHorizontally();
		if (loc.row == 19)
			turnVertically();
		{

			if (dir == 0)

			{
				if (Horizontally == 0)  //check if monkey go left(0) or right(1)
				{

					this->loc.col -= stepOfJump;
					if (loc.col < 0)
						this->loc.col *= -1;
				}
				if (Horizontally == 1)

				{

					this->loc.col += stepOfJump;
					if (loc.col > 39)
					{
						if (loc.col == 40)
							loc.col -= 2;
						if (loc.col == 41)
							loc.col -= 3;
					}

				}
			}
			else if (dir == 1)
			{
				//std::cout << " up - down:   ";
				if (Vertically == 0)       ///check if monkey go down(0) or up(1) 
				{
					//std::cout << " down   ";
					loc.row += stepOfJump;
					if (loc.row > 19)
					{
						if (loc.row == 20)
							loc.row = 18;
						if (loc.row == 21)
							loc.row = 17;
					}
					if (loc.row < 0)
						loc.row *= -1;
				}
				if (Vertically == 1)
				{
					//std::cout << " up   ";
					this->loc.col -= stepOfJump;
					if (loc.row < 0)
						this->loc.row *= -1;

				}

			}
			else std::cout << "dir=  " << dir;
		}


		moneOfJumps += 1;
	}
}
