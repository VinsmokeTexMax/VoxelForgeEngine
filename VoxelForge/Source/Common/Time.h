#pragma once

#include <string>

namespace Time
{
	std::wstring VOXELFORGE_API GetTime(BOOL stripped = false); //Get the current time

	std::wstring VOXELFORGE_API GetDate(BOOL stripped = false); //Get the current date

	std::wstring VOXELFORGE_API GetDateTime(BOOL stripped = false); //Get the current date and time
}