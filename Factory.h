#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "Product.h"
using namespace std;

class IMilitaryEquipmentFactory;

class RuMilitaryEquipmentFactory;
class UsMilitaryEquipmentFactory;


class IMilitaryEquipmentFactory
{
public:
	virtual ITank* createTank() = 0;
	virtual ITroopCarrier* createTroopCarrier() = 0;
	virtual IRobot* createRobot() = 0;
	virtual IHowitzer* createHowitzer() = 0;
	virtual IFighter* createFighter() = 0;
};

class RuMilitaryEquipmentFactory : public IMilitaryEquipmentFactory
{
private:
	RuTank t;
	RuTroopCarrier c;
	RuRobot r;
	RuHowitzer h;
	RuFighter f;
public:
	RuMilitaryEquipmentFactory(string);
	ITank* createTank() override;
	ITroopCarrier* createTroopCarrier() override;
	IRobot* createRobot() override;
	IHowitzer* createHowitzer() override;
	IFighter* createFighter() override;
};