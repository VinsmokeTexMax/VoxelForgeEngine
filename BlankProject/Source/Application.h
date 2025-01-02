#pragma once

#include "Platform/WIN32/IApplication.h"

class Application : public IApplication
{
	//Application

public:
	Application(); // Constructor
	~Application(); // Destructor

public:
	VOID Initialize(); // Initialize Application
	VOID Update(); // Game loop
};