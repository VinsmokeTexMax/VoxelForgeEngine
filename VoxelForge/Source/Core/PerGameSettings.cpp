#include "VoxelForge.h"

PerGameSettings* PerGameSettings::inst;



PerGameSettings::PerGameSettings()
{
	inst = this;

	wcscpy_s(inst->m_GameName, L"Undefined");
	wcscpy_s(inst->m_ShortName, L"Undefined");
	wcscpy_s(inst->m_BootTime, Time::GetDateTime(TRUE).c_str());

}

PerGameSettings::~PerGameSettings()
{
}
