#include "stdafx.h"
#include "Prototype.h"

class Animal
{
protected:
	char _hairColor[10];
	int _hairLength, _tail, _weight, _height, _age;
	int _intelligence, _stubbornness, _agressiveness;

public:

	virtual Animal* Clone() = 0;

	int setHairLength(int length)
	{
		_hairLength = length;
	}

	void setHairColor(const char* color)
	{
		strcpy_s(_hairColor, color);
	}

	void setTail(int length)
	{
		_tail = length;
	}

	void setWeight(int kg)
	{
		_weight = kg;
	}

	void setHeight(int m)
	{
		_height = m;
	}

	void setAge(int age)
	{
		_age = age;
	}
};

class Sheep : public Animal
{
public:
	Sheep()
	{
		_hairLength = 5;
		_stubbornness = 3;
		_agressiveness = 2;
		_intelligence = 7;
	}

	// Inherited via Animal
	virtual Animal* Clone() override
	{
		return new Sheep(*this);
	}

	void Shearing()
	{
		_hairLength -= 2;
	}
};

class Cow : public Animal
{
public:
	Cow()
	{
		_stubbornness = 6;
		_agressiveness = 5;
		_intelligence = 8;
	}

	// Inherited via Animal
	virtual Animal* Clone() override
	{
		return new Cow(*this);;
	}
};

void Prototype::Execute()
{
	Sheep* s1 = new Sheep;
	s1->setHairColor("white");
	s1->setTail(1);
	s1->setWeight(2);
	s1->setHeight(3);
	s1->setAge(4);


	Cow* c1 = new Cow;
	c1->setHairColor("brown");
	c1->setTail(5);
	c1->setWeight(6);
	c1->setHeight(7);
	c1->setAge(8);

	Animal* farm[3];
	farm[0] = s1->Clone();
	farm[1] = c1->Clone();

	farm[1]->setWeight(11);

	s1->Shearing();
	farm[2] = s1->Clone();
}