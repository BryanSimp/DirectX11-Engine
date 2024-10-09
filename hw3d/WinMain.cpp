#include "App.h"

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR	  lpCmdLine,
	_In_ int		  nCmdShow )
{
	try
	{
		return App{}.Go();
	}
	catch (const ChiliException& e)
	{
		MessageBox(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION | MB_TASKMODAL);
	}
	catch (const std::exception& e)
	{
		MessageBox(nullptr, e.what(), "Standard Exception", MB_OK | MB_ICONEXCLAMATION | MB_TASKMODAL);
	}
	catch (...)
	{
		MessageBox(nullptr, "No details available", "Unknown Exception", MB_OK | MB_ICONEXCLAMATION | MB_TASKMODAL);
	}
	return -1;
}