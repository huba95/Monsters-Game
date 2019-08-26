#pragma once
#include <string>
#include "Equipments.h"

class Hero
{
	enum species {
		Human,
		Warrior,
		Elf,
		Magician,
		Physicist
	};
	std::string Name;
	int RealLevel;
	species Cast;

	Equipment Sword;
	Equipment Hat;
	Equipment Boots;
	Equipment Armor;


public:
	
	Hero();
	Hero(std::string name, int faj);

	void ChangeSword(Equipment newSword);
	void ChangeHat(Equipment newHat);
	void ChangeBoots(Equipment newBoots);
	void ChangeArmor(Equipment newArmor);

	~Hero();
};

//TODO: open speieces descrition
//TodO: Own class for spieces
//TODO: savegame, loadgame

