#include "stdafx.h"
#include "FactoryMethod.h"

class Toy
{
protected:
	char m_name[6];
	double m_price;

public:
	Toy(const char* name, double price)
	{
		strcpy_s(m_name, name);
		m_price = price;
	}

	virtual void PrepareParts() = 0;
	virtual void AssembleParts() = 0;
	virtual void ApplyLabel() = 0;
	virtual void ShowProduct() = 0;
};

class Bike : public Toy
{
public:

	Bike() : Toy("Bike", 44000)
	{

	}

	// Inherited via Toy
	virtual void PrepareParts() override
	{
		cout << "Preparing for new Bike" << endl;
	}
	virtual void AssembleParts() override
	{
		cout << "Assembling Bike parts..." << endl;
	}
	virtual void ApplyLabel() override
	{
		cout << "Applying Bike label..." << endl;
	}
	virtual void ShowProduct() override
	{
		cout << "Name : " << m_name << "\t\tPrice : " << m_price << endl;
	}
};

class Car : public Toy
{
public:

	Car() : Toy("Car", 222000)
	{

	}

	// Inherited via Toy
	virtual void PrepareParts() override
	{
		cout << "Preparing for new Car" << endl;
	}
	virtual void AssembleParts() override
	{
		cout << "Assembling Car parts..." << endl;
	}
	virtual void ApplyLabel() override
	{
		cout << "Applying Car label..." << endl;
	}
	virtual void ShowProduct() override
	{
		cout << "Name : " << m_name << "\t\tPrice : " << m_price << endl;
	}
};

class ToyFactory
{
public:
	static Toy* CreateToy(int type)
	{
		Toy* toy = nullptr;

		switch (type)
		{
		case 1:
			toy = new Car;
			break;
		case 2:
			toy = new Bike;
			break;
		default:
			cout << "*** Invalid Selection. Please try again..." << endl;
			return nullptr;
		}

		toy->PrepareParts();
		toy->AssembleParts();
		toy->ApplyLabel();

		return toy;

	}
};

// ***************************** Driver function **********************************
void FactoryMethod::Execute()
{
	int type = 0;

	while (1)
	{
		cout << "\n1. Car\n2. Bike\n0. Exit" << endl;
		cout << "Enter your choice :: ";
		cin >> type;

		if (type == 0)
			break;

		Toy* t = ToyFactory::CreateToy(type);

		if (t)
		{
			t->ShowProduct();
			delete t;
			t = NULL;
		}
	}

	return;
}
