#ifndef MOABEATTORNEY_H
#define MOABEATTORNEY_H

#include "MOABE.h"

class MOABEAttorney
{
	friend class TimeManager;
	friend class FreezeTime;
	friend int CALLBACK WinMain(_In_ HINSTANCE hInstance, 
								_In_opt_ HINSTANCE hPrevInstance,  
								_In_ LPSTR lpCmdLine, 
								_In_ int nShowCmd);
	static const float GetTimeInSeconds() { return MOABE::GetTimeInSeconds(); };
	static void Run(HINSTANCE hInstance) { MOABE::Run(hInstance); };
};

#endif // MOABEATTORNEY_H
