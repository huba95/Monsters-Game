#include <iostream>
#include <fstream>
#include <string>
#include "Hero.h"

void Introduction();

int main()
{
	Hero Player;
	std::string GamerName;
	int specie;
	std::cout << "Add meg a Neved!" << std::endl << "Erre a nevre fog a jatek menteni vagy ez alapjan tolti be a mentesed." << std::endl;
	std::cout << "Nev: ";
	std::cin >> GamerName;

	int game{ 1 };
	while (game = 1)
	{
		//TODO: Game menu
		//TODO: Loading game here

		Introduction();
		std::cin >> specie;

	}
	std::getchar();
	return 0;
}

void Introduction()
{
	std::string introlines;
	std::ifstream intro;
	intro.open("start\\kezdoszoveg.txt");
	if (intro.is_open())
	{
		while (!intro.eof())
		{
			std::getline(intro, introlines);
			std::cout << introlines<<std::endl;
		}
	}
	else
	{
		std::cout << "Intro can`t load";
	}
}