#include "VoxelForge.h"
#include <ctime>
#include <sstream>
#include <iomanip>

//Get time in format 00:00:00
//Stripped = 000000

std::wstring Time::GetTime(BOOL stripped)
{
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);
	std::wstringstream wss;
	wss << std::put_time(&ltm, L"%T");

	std::wstring timeString = wss.str();
	

	if (stripped)
	{
		std::wstring chars = L":";
		for (WCHAR c : chars)
		{
			timeString.erase(std::remove(timeString.begin(), timeString.end(), c), timeString.end());
		}
	}
	return timeString;
}


std::wstring Time::GetDate(BOOL stripped)
{
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);
	std::wstringstream wss;
	wss << std::put_time(&ltm, L"%d/%m/%y");

	std::wstring timeString = wss.str();


	if (stripped)
	{
		std::wstring chars = L"/";
		for (WCHAR c : chars)
		{
			timeString.erase(std::remove(timeString.begin(), timeString.end(), c), timeString.end());
		}
	}
	return timeString;
}

std::wstring Time::GetDateTime(BOOL stripped)
{
	std::wstring timeString = GetDate(stripped) + L" " + GetTime(stripped);

	if (stripped)
	{
		std::wstring chars = L" ";
		for (WCHAR c : chars)
		{
			timeString.erase(std::remove(timeString.begin(), timeString.end(), c), timeString.end());
		}
	}
	return timeString;
}