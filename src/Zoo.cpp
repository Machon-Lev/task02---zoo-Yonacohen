#include "Zoo.h"
#include <iostream>


Zoo::Zoo() {
	srand(time(NULL));
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 40; j++) {
			mapArr[i][j] = '-';
		}
}

void Zoo::print()
{
	for (int i = 0; i < Animal_vec.size(); i++) {
			std::cout << i << ")  ";
			this->Animal_vec[i]->printDetails();
		}
}

void Zoo::stop(int index)
{
	this->Animal_vec[index]->stop();
}
void Zoo::move(int index)
{
	this->Animal_vec[index]->move();
}
void Zoo::moveAll()
	{
	for (int i = 0; i < Animal_vec.size(); i++) {

		this->Animal_vec[i]->move();
	}

}
void Zoo::stopAll()
{
	for (int i = 0; i < Animal_vec.size(); i++) {

		this->Animal_vec[i]->stop();
	}

}
void Zoo::create(std::string type, std::string name)
{
	if (type == "Lion")
	{
		Animal* l1 = new Lion(name);
		this->Animal_vec.push_back(l1);
		mapArr[l1->getLocation().row][l1->getLocation().col] = l1->getInitial();
		

	}
	if (type == "Monkey")
	{
		Animal* m1 = new Monkey(name);
		this->Animal_vec.push_back(m1);
		mapArr[m1->getLocation().row][m1->getLocation().col] = m1->getInitial();
	}
	if (type == "Goose")
	{
		Animal* g1 = new Goose(name);
		this->Animal_vec.push_back(g1);
		mapArr[g1->getLocation().row][g1->getLocation().col] = g1->getInitial();
	}

}

void Zoo::del(int index)
{
	mapArr[Animal_vec[index]->getLocation().row][Animal_vec[index]->getLocation().col] = '-';
	Animal_vec.erase(Animal_vec.begin() + index);
	
}
void Zoo::delAll(std::string type)
{
	
		for (int i = 0; i < Animal_vec.size();)
		{
			if (Animal_vec[i]->getInitial() == type.front())
				del(i);
			else
				i++;

		}

}
void Zoo::help()
{
	std::cout << "              All option            " << std::endl;
	std::cout << "enter a command " << std::endl;
	std::cout << "create a new animal = press 1" << std::endl;
	std::cout << "stop the animal = press 2" << std::endl;
	std::cout << "move the animal= press 3" << std::endl;
	std::cout << "del animal= press 4" << std::endl;
	std::cout << "delete all animal same type = press 5" << std::endl;
	std::cout << "help = enter 6" << std::endl;
	std::cout << "print the map = press 7" << std::endl;
	std::cout << "print list of animal = press 8" << std::endl;
	std::cout << "move all animal = press 9" << std::endl;
	std::cout << "stop all animal = press a" << std::endl;
	std::cout << "next  = press ." << std::endl;
	std::cout << "exit = press 0" << std::endl;
}
void Zoo::printMap()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			std::cout << mapArr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
void Zoo::step()
{
	for (int i = 0; i < Animal_vec.size(); i++)
	{
		Animal_vec[i]->step();
	}
}
void Zoo::run()
{
	
	
		create("Lion", "simba_create");
		create("Goose", "Gosees_create");
		create("Monkey", "rafiki_create");
		create("Lion", "arie_create");
		create("Lion", "lavi_create");
		create("Monkey", "monk2_create");
		printMap();
		print();
	
		
		char num;
		help();
		std::cin >> num;
		std::string type;
		std::string name;
		int num_of_animal;
		
		while (num!='0')
		{ 
			
			switch (num)
			{
			case '1':
				std::cout << "enter type of animal:  " << std::endl;
				std::cin >> type;
				std::cout << "enter name of animal:  " << std::endl;
				std::cin >> name;
				create(type, name);

				break;

			case '2':

				std::cout << "enter num of animal:  " << std::endl;
				std::cin >> num_of_animal;
				stop(num_of_animal);
				break;
			case '3':
				std::cout << "enter num of animal:  " << std::endl;
				std::cin >> num_of_animal;
				move(num_of_animal);
				break;
			case '4':
				std::cout << "enter num of animal:  " << std::endl;
				std::cin >> num_of_animal;
				del(num_of_animal);
				break;
			case '5':
				std::cout << "enter type of animal:  " << std::endl;
				std::cin >> type;
				delAll(type);
				break;
			case '6':
				help();
				break;
			case '7':
				printMap();
				break;
			case '8':
				printMap();
				break;
			case '9':
				moveAll();
				break;
			case 'a':
				stopAll();
				break;
			case 46:
				step();
				break;


			default: break;

				
			}
			print();
			printMap();
			help();
			std::cin >> num;
		}
		return;



}



