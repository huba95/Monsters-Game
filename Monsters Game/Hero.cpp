#include "Hero.h"



Hero::Hero()
{
	Name = "";
	RealLevel = 0;

}

Hero::Hero(std::string name, int faj)
{
	Name = name;
	RealLevel = 1;
	Cast = static_cast<species>(faj);
}


Hero::~Hero()
{
}
