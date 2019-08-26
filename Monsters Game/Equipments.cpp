#include "Equipments.h"



Equipment::Equipment()
{
	Name = "";
	Details = "";
	Level = 0;
	Type = 0;
}

Equipment::Equipment(std::string name, std::string details, int level, int type)
{
	Name = name;
	Details = details;
	Level = level;
	Type = type;
}


Equipment::~Equipment()
{
}
