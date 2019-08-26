#pragma once
#include <string>

class Equipment
{
	std::string Name;
	std::string Details;
	int Level;
	int Type;

public:
	Equipment();
	Equipment(std::string name, std::string details, int level, int type);
	~Equipment();
};

