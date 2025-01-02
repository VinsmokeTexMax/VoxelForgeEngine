#pragma once

#define ENTRYAPP(x) IApplication* EntryApplication() { return new x; }

class VOXELFORGE_API IApplication
{
	//Application

public:
	IApplication(); // Constructor
	virtual ~IApplication() {}; // Destructor

public:
	virtual VOID Initialize() = 0; // Initialize Application
	virtual VOID Update() = 0; // Game loop
};

IApplication* EntryApplication(); // Entry Point