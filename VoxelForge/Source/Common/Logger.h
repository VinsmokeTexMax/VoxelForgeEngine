#pragma once

#include <string>

class VOXELFORGE_API Logger
{
	// Setters and Getters
private:
	static Logger* inst;

public:
	static Logger* Instance() { return inst; };

	// Constructors and Destructors
public:
	Logger();
	~Logger();


	// Print the Log File
	static VOID PrintLog(const WCHAR* message, ...);
	static std::wstring LogDirectory();
	static std::wstring LogFile();

	static void PrintDebugSeparator(); // Print a line of "-" char's
	static BOOL IsMTailRunning(); // Check if MTail is running
	static VOID StartMTail(); // Start MTail

};
