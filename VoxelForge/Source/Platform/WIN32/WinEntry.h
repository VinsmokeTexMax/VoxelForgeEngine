#include "VoxelForge.h"

#include "IApplication.h"

extern IApplication* EntryApplication();

INT CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{

	auto EntryApp = EntryApplication();

	PerGameSettings GameSettings;
	
	EntryApp->SetupPerGameSettings();

	Logger logger;
	EntryApp->Initialize();



	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else 
		{
			EntryApp->Update();
		}
	}

	return 0;

}