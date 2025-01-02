#include "VoxelForge.h"
#include <fstream>
#include <ShlObj.h> 
#include <TlHelp32.h>

Logger* Logger::inst;

Logger::Logger()
{
	inst = this;
}

Logger::~Logger()
{
}

VOID Logger::PrintLog(const WCHAR* message, ...)
{
	WCHAR buffer[4096];
	va_list args;

	va_start(args, message);
	vswprintf_s(buffer, message, args);
	va_end(args);

	OutputDebugString(buffer);

	std::wfstream outfile;
  
	outfile.open(std::wstring(LogDirectory() + L"/" + LogFile()), std::ios_base::app);
	
	if (outfile.is_open())
	{
		std::wstring s = buffer;
		outfile <<L"[" << Time::GetDateTime() << L"] " << s;
		outfile.close();
		OutputDebugString(s.c_str());
	}
	else
	{
		MessageBox(NULL, L"Unable to open log file...", L"Log Error", MB_OK);
	}
}

std::wstring Logger::LogDirectory()
{
	WCHAR PATH[1024];
	PWSTR AppDataLocal;
	SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, nullptr, &AppDataLocal);
	wcscpy_s(PATH, AppDataLocal);
	wcscat_s(PATH, L"\\");
	wcscat_s(PATH, PerGameSettings::GameName());
	CreateDirectory(PATH, NULL);
	wcscat_s(PATH, L"\\Log");
	CreateDirectory(PATH, NULL);
	return PATH;
}

std::wstring Logger::LogFile()
{
	WCHAR FILE[1024];
	wcscpy_s(FILE, PerGameSettings::GameName());
	wcscat_s(FILE, PerGameSettings::BootTime());
	wcscat_s(FILE, L".log");
	return FILE;
}

VOID Logger::PrintDebugSeparator()
{
	std::wstring s = L"\n------------------------------------------------------------------------------------\n\n";

#ifdef _DEBUG
	std::wfstream outfile;
	outfile.open(std::wstring(LogDirectory() + L"/" + LogFile()), std::ios_base::app);

	if (outfile.is_open()) {
		outfile << s;
		outfile.close();
	}
	else {
		MessageBox(NULL, L"Unable to open log file...", L"Log Error", MB_OK);
	}
#endif
}

BOOL Logger::IsMTailRunning()
{
	bool exists = false;
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (Process32First(snapshot, &entry))
	{
		while (Process32Next(snapshot, &entry))
		{
			if (wcscmp(entry.szExeFile, L"MTail.exe") == 0)
			{
				exists = true;
			}
		}
	}

	CloseHandle(snapshot);
	return exists;
}

VOID Logger::StartMTail()
{
	if (IsMTailRunning())
	{
		Logger::PrintLog(L"--MTail failed to start - Already Running\n");
		return;
	}

	Logger::PrintLog(L"--Starting MTail\n");
	WCHAR path[MAX_PATH] = { 0 };
	GetCurrentDirectory(MAX_PATH, path);
	std::wstring url = path + std::wstring(L"/mTAIL.exe");
	std::wstring params = L" \"" + LogDirectory() + L"/" + LogFile() + L"\" /start";
	ShellExecute(0, NULL, url.c_str(), params.c_str(), NULL, SW_SHOWDEFAULT);
}