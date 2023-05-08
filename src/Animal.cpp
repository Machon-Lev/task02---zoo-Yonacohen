
#include"Animal.h"
#include <iostream>
	
 void Animal::printDetails() 
{
	 std::cout << "name:   " << this->name << ",    location:    " << this->loc.row << " , " << this->loc.col  ;
}
 Location Animal::getLocation() const
 {
	 return loc;
 }
 void Animal::stop()
 {
	 this->isMove = 0;	// 0 =stop
		
 }
 void Animal::move()
 {
	 this->isMove = 1;		// 1= move
 }
 void Animal::step()
 {
	
 }
 void Animal::turnVertically()
 {

 }