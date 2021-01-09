#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "Product.h"
#include "Factory.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	MilitaryEquipment* rt;
	MilitaryEquipment* rtc;
	MilitaryEquipment* rr;
	MilitaryEquipment* rh;
	MilitaryEquipment* rf;
	IMilitaryEquipmentFactory* Factory;
	Factory = new RuMilitaryEquipmentFactory("RuMilitary.txt");
	rt = Factory->createTank();
	rtc = Factory->createTroopCarrier();
	rr = Factory->createRobot();
	rh = Factory->createHowitzer();
	rf = Factory->createFighter();
	
	if (Factory) delete Factory;
}