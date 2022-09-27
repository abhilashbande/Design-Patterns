#include "stdafx.h"
#include "Builder.h"

// ******************************* Entree ******************************************
class Entree
{
protected:
	char m_entree[20];

public:
	const char* GetEntree()
	{
		return m_entree;
	}
};

class Burger : public Entree
{
public:
	Burger()
	{
		cout << "Grill burger patty, add tomotoes and place them in a bun" << endl;
		strcpy_s(m_entree, "HamBurger");
	}
};

class Hotdog : public Entree
{
public:
	Hotdog()
	{
		cout << "Cook sausage and place it in a bun" << endl;
		strcpy_s(m_entree, "Hotdog");
	}
};

// ******************************* Side ******************************************
class Side
{
protected:
	char m_side[20];

public:
	const char* GetSide()
	{
		return m_side;
	}
};

class Fries : public Side
{
public:
	Fries()
	{
		cout << "Fry and season potatoes" << endl;
		strcpy_s(m_side, "Fries");
	}
};

class Salad : public Side
{
public:
	Salad()
	{
		cout << "Toss greens and dressing together" << endl;
		strcpy_s(m_side, "Salad");
	}
};

// ******************************* Drink ******************************************
class Drink
{
protected:
	char m_drink[10];
public:
	Drink()
	{
		cout << "Fill cup with Coke" << endl;
		strcpy_s(m_drink, "Coke");
	}
	char* GetDrink()
	{
		return m_drink;
	}
};

// ******************************* Meal Combo ******************************************
class MealCombo
{
private:
	Entree* m_entree;
	Side* m_side;
	Drink* m_drink;
	char m_bag[50];

public:
	MealCombo(const char* type)
	{
		sprintf_s(m_bag, "%s meal combo:", type);
	}
	void setEntree(Entree* e)
	{
		m_entree = e;
	}
	void setSide(Side* s)
	{
		m_side = s;
	}
	void setDrink(Drink* d)
	{
		m_drink = d;
	}
	const char* openMealBag()
	{
		sprintf_s(m_bag, "%s %s, %s, %s", m_bag, m_entree->GetEntree(), m_side->GetSide(), m_drink->GetDrink());
		return m_bag;
	}
};

// ******************************* Meal Builder ******************************************
class MealBuilder
{
protected:
	MealCombo* m_meal;

public:
	virtual void CookEntree() {} ;
	virtual void CookSide() {};
	virtual void FillDrink() {};

	MealCombo* GetMeal()
	{
		return m_meal;
	}
};

// class for burger meal --> burger + fries + coke
class BurgerMeal : public MealBuilder
{
public:
	BurgerMeal()
	{
		m_meal = new MealCombo("Burger");
	}

	// Inherited via MealBuilder
	virtual void CookEntree() override
	{
		Burger* burger = new Burger;
		m_meal->setEntree(burger);
	}

	virtual void CookSide() override
	{
		Fries* fries = new Fries;
		m_meal->setSide(fries);
	}

	virtual void FillDrink() override
	{
		Drink* drink = new Drink;
		m_meal->setDrink(drink);
	}
};

// class for hotdog meal --> hotdog + salad + coke
class HotdogMeal : public MealBuilder
{
public:
	HotdogMeal()
	{
		m_meal = new MealCombo("Hotdog");
	}

	// Inherited via MealBuilder
	virtual void CookEntree() override
	{
		Hotdog* hotdog = new Hotdog;
		m_meal->setEntree(hotdog);
	}

	virtual void CookSide() override
	{
		Salad* salad = new Salad;
		m_meal->setSide(salad);
	}

	virtual void FillDrink() override
	{
		Drink* drink = new Drink;
		m_meal->setDrink(drink);
	}
};


void Builder::Execute()
{
	MealBuilder* cook = new MealBuilder;
	MealCombo* meal;

	int choice;

	while (1)
	{
		cout << "\n\nExecuting Builder Design Pattern" << endl;
		cout << "Select a meal: " << endl;
		cout << "1: Hamburger meal" << endl;
		cout << "2: Hotdog meal" << endl;
		cout << "Enter you choice :: ";
		cin >> choice;
		cout << endl;

		if (!choice)
			break;

		switch (choice)
		{
		case 1:
			cook = new BurgerMeal;
			break;

		case 2:
			cook = new HotdogMeal;
			break;
		default:
			cout << "Invalid choice. Try Again...";
			cook = NULL;
			continue;
		}

		if (cook) 
		{
			cook->CookEntree();
			cook->CookSide();
			cook->FillDrink();

			meal = cook->GetMeal();
			cout << meal->openMealBag() << endl;
		}
	}

	delete cook;
	return;
}
