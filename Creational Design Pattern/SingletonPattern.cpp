#include "stdafx.h"
#include "SingletonPattern.h"

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if (_instance == NULL)
			_instance = new Singleton;
		return _instance;
	}

	void DoSomething()
	{
		cout << "Working..." << endl;
	}

private:
	static Singleton* _instance;
	Singleton()
	{
		cout << "New instance created..." << endl;
	}
};

Singleton* Singleton::_instance = NULL;

void SingletonPattern::Execute()
{
	for (int i = 0; i < 100; i++) 
	{
		Singleton* instance = Singleton::GetInstance();
		instance->DoSomething();
	}
	return;
}
