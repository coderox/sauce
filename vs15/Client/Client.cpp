// Client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "sauce/sauce.h"
#include "vs15/shared.h"

int main()
{
	sauce::Modules modules;
	modules.add<FrameworkModule>();
	sauce::shared_ptr<sauce::Injector> injector = modules.createInjector();
	auto aSingleton = injector->get<Singleton>();
	auto anotherSingleton = injector->get<Singleton>();
	
	return 0;
}

