#include "stdafx.h"
#include "AbstractFactory.h"

// ***************************** Door Objects **********************************

class Door
{
public:
	Door() 
	{
	}

	virtual void Open() = 0;
};

class PetrolCarDoor : public Door
{
public:
	PetrolCarDoor()
	{
		cout << "Making a door for a petrol car." << endl;
	}
	void Open()
	{
		cout << "Door opening sound : click" << endl;
	}
};

class ElectricCarDoor : public Door
{
public:
	ElectricCarDoor()
	{
		cout << "Making a door for an electric car" << endl;
	}
	void Open()
	{
		cout << "Door opening sound : shhhhh" << endl;
	}
};

// ***************************** Engine objects **********************************

class Engine
{
protected:
	char _sound[15];
public:
	Engine()
	{
		strcpy_s(_sound, "");
	}
	virtual void Run() = 0;
};

class PetrolCarEngine : public Engine
{
public:
	PetrolCarEngine()
	{
		strcpy_s(_sound, "vroom");
		cout << "Making a petrol engine." << endl;
	}
	void Run()
	{
		cout << "Engine sound : " <<  _sound << endl;
	}
};

class ElectricCarEngine : public Engine
{
public:
	ElectricCarEngine()
	{
		strcpy_s(_sound, "SHHHH");
		cout << "Making an electric engine." << endl;
	}
	void Run()
	{
		cout << "Engine sound : " << _sound << endl;
	}
};


// ***************************** Factories **********************************

class CarFactory
{
public:
	virtual Door* BuildDoor() = 0;
	virtual Engine* BuildEngine() = 0;
};

class PetrolCarFactory : public CarFactory
{
public:
	// Inherited via CarFactory
	virtual Door* BuildDoor() override
	{
		return new PetrolCarDoor;
	}

	virtual Engine* BuildEngine() override
	{
		return new PetrolCarEngine;
	}
};

class ElectricCarFactory : public CarFactory
{
public:
	// Inherited via CarFactory
	virtual Door* BuildDoor() override
	{
		return new ElectricCarDoor;
	}

	virtual Engine* BuildEngine() override
	{
		return new ElectricCarEngine;
	}
};


// Driver function
void AbstractFactory::Execute()
{
	CarFactory* newCar;

	int choice;

	while (1)
	{
		cout << "/n/nExecuting Abstract Factory Design Pattern" << endl;
		cout << "Select a car type: " << endl;
		cout << "1: Petrol" << endl;
		cout << "2: Electric" << endl;
		cout << "Enter you choice :: ";
		cin >> choice;
		cout << endl;

		if (!choice)
			break;

		switch (choice)
		{
		case 1:
			newCar = new PetrolCarFactory;
			break;

		case 2:
			newCar = new ElectricCarFactory;
			break;
		default:
			cout << "Invalid choice. Try Again...";
			newCar = NULL;
			continue;
		}

		if (newCar)
		{
			Door* newDoor = newCar->BuildDoor();
			Engine* newEngine = newCar->BuildEngine();

			// lets test it
			newDoor->Open();
			newEngine->Run();
		}
	}
	return;
}
