#include "Factory.h"

RuMilitaryEquipmentFactory::RuMilitaryEquipmentFactory(string file)
{

	MilitaryEquipment* rt = &t;
	MilitaryEquipment* rtc = &c;
	MilitaryEquipment* rr = &r;
	MilitaryEquipment* rh = &h;
	MilitaryEquipment* rf = &f;
	float power,
		range,
		combat_weight,
		caliber;
	size_t crew, year, amount;
	string type_of_weapon, movement;
	std::ifstream fin(file);
	if (!fin)
	{
		std::cout << "could not open " << file << std::endl;
		std::cin.ignore();
		return;
	}
	for (size_t i = 0; i < amm_of_ME; i++)
	{
		fin >> power >> range >> combat_weight >> caliber >> crew >> year >> amount;
		getline(fin, type_of_weapon);
		type_of_weapon.erase(type_of_weapon.begin());
		getline(fin, movement);
		rt->Initialize(power, range, combat_weight, caliber, crew, year, amount, type_of_weapon, movement);
		
		fin >> power >> range >> combat_weight >> caliber >> crew >> year >> amount;
		getline(fin, type_of_weapon);
		type_of_weapon.erase(type_of_weapon.begin());
		getline(fin, movement);
		rtc->Initialize(power, range, combat_weight, caliber, crew, year, amount, type_of_weapon, movement);
		
		fin >> power >> range >> combat_weight >> caliber >> crew >> year >> amount;
		getline(fin, type_of_weapon);
		type_of_weapon.erase(type_of_weapon.begin());
		getline(fin, movement);
		rr->Initialize(power, range, combat_weight, caliber, crew, year, amount, type_of_weapon, movement);
		
		fin >> power >> range >> combat_weight >> caliber >> crew >> year >> amount;
		getline(fin, type_of_weapon);
		type_of_weapon.erase(type_of_weapon.begin());
		getline(fin, movement);
		rh->Initialize(power, range, combat_weight, caliber, crew, year, amount, type_of_weapon, movement);
		
		fin >> power >> range >> combat_weight >> caliber >> crew >> year >> amount;
		getline(fin, type_of_weapon);
		type_of_weapon.erase(type_of_weapon.begin());
		getline(fin, movement);
		rf->Initialize(power, range, combat_weight, caliber, crew, year, amount, type_of_weapon, movement);
	}
	fin.close();
}

ITank* RuMilitaryEquipmentFactory::createTank()
{
	return new RuTank(&t);
}
ITroopCarrier* RuMilitaryEquipmentFactory::createTroopCarrier()
{
	return new RuTroopCarrier(&c);
}
IRobot* RuMilitaryEquipmentFactory::createRobot()
{
	return new RuRobot(&r);
}
IHowitzer* RuMilitaryEquipmentFactory::createHowitzer()
{
	return new RuHowitzer(&h);
}
IFighter* RuMilitaryEquipmentFactory::createFighter()
{
	return new RuFighter(&f);
}


