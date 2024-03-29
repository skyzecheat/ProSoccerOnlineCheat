#include <iostream> 
#include <vector> 
#include <format>
#include "Header.h" 
#include <TlHelp32.h>  
#include <stdlib.h>
#include <windows.h>
#include <filesystem>
#include <cstdlib>



DWORD ProcessIdAl(const char* UygulamaIsim) {

	DWORD ProcessId = 0;
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnap != INVALID_HANDLE_VALUE)
	{
		PROCESSENTRY32 ProcessEntry;
		ProcessEntry.dwSize = sizeof(ProcessEntry);

		if (Process32First(hSnap, &ProcessEntry)) {
			do
			{

				if (!_strcmpi((ProcessEntry.szExeFile), UygulamaIsim))
				{
					ProcessId = ProcessEntry.th32ProcessID;
					break;
				}
			} while (Process32Next(hSnap, &ProcessEntry));
		}
	}
	CloseHandle(hSnap);
	return ProcessId;
}




uintptr_t PointerZinciriOku(HANDLE hProc, DWORD64 ptr, std::vector<unsigned int> offsets)
{
	uintptr_t addr = ptr;
	for (unsigned int i = 0; i < offsets.size(); ++i)
	{

		bool Okundumu = ReadProcessMemory(hProc, (BYTE*)addr, &addr, sizeof(DWORD64), 0);
		addr += offsets[i];
	}
	return addr;
}



#ifdef _WIN64
static constexpr const auto PEB_OFFSET = 0x60;
#else
static constexpr const auto PEB_OFFSET = 0x30;
#endif



static constexpr const auto OyunIsim = "ProSoccerOnline-Win64-Shipping.exe";






BOOL CALLBACK CloseIDA(HWND hwnd, LPARAM lParam) {
	char windowtitle[256];

	GetWindowTextA(hwnd, windowtitle, sizeof(windowtitle));

	if (strstr(windowtitle, "IDA") != NULL) {
		DWORD ProcessId;

		GetWindowThreadProcessId(hwnd, &ProcessId);

		HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, ProcessId);
		if (hProcess != NULL) {
			TerminateProcess(hProcess, 0);
			CloseHandle(hProcess);
		}
		else {
			exit(1);
		}
	}
	return TRUE;
}







int main() {

	//SUPER BASIC ANTI-DEBUGGER
	EnumWindows(CloseIDA, 0);




	//MAIN

	system("Color 0B");
	std::cout << "tappinforward.cc V3.0\n" << std::endl;
	Sleep(500);
	std::cout << "skyze\n" << std::endl;
	Sleep(500);


	std::cout << "[R] FOV\n" << std::endl;
	std::cout << "[X] DRONE CAMERA\n" << std::endl;
	std::cout << "[Q] STAMINA\n" << std::endl;
	std::cout << "[F] KICK POWER\n" << std::endl;
	std::cout << "[H] SPEED HACK\n" << std::endl;
	std::cout << "[V] DRIBBLING FACTOR\n" << std::endl;
	std::cout << "[L] ADD POSITION\n" << std::endl;
	std::cout << "[Z] BUG BALL\n" << std::endl;
	std::cout << "FOV VALUE : \n" << std::endl;

	float IstedigimizFov;
	std::cin >> IstedigimizFov;

	std::cout << "KICK POWER VALUE : \n" << std::endl;

	float IstedigimizKickPower;
	std::cin >> IstedigimizKickPower;

	std::cout << "SPEED HACK VALUE : \n" << std::endl;

	float IstedigimizSpeed;
	std::cin >> IstedigimizSpeed;

	std::cout << "DRIBBLING FACTOR VALUE : \n" << std::endl;

	float IstedigimizDribbling;
	std::cin >> IstedigimizDribbling;

	std::cout << "DRONE CAMERA VALUE : \n" << std::endl;

	float IstedigimizDrone;
	std::cin >> IstedigimizDrone;

	while (true) {



		//FOV

		if (GetAsyncKeyState('R') & 0x8000) {

			DWORD ProcessID = ProcessIdAl("ProSoccerOnline-Win64-Shipping.exe");

			

			if (!ProcessID) {
				std::cout << "pID = NULL"  "\n";
				return 0;
			}


			HANDLE OyunHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessID);


			if (!OyunHandle) {
				std::cout << "GAME HANDLE = NULL"  "\n";
				return 0;
			}


			DWORD Size = 0;
			PROCESS_BASIC_INFORMATION pbi;
			auto result = NtQueryInformationProc(OyunHandle, ProcessBasicInformation, &pbi, sizeof(PROCESS_BASIC_INFORMATION), &Size);
			PPEB PEB = pbi.PebBaseAddress;
			DWORD64 HedefAdress = ((DWORD64)PEB + 0x10);
			DWORD64 BaseAdress;
			ReadProcessMemory(OyunHandle, (void*)(HedefAdress), &BaseAdress, sizeof(DWORD64), 0);

			DWORD64 BaseAdress2 = (DWORD64)(GetModuleHandle("Console Application.exe"));


			if (!BaseAdress) {
				std::cout << "BASEADRESS = NULL"  "\n";
				return 0;
			}

			uintptr_t EnAltAdresFov = (uintptr_t)BaseAdress + 0x0460FF70;


			auto SonucAdresFov = PointerZinciriOku(OyunHandle, EnAltAdresFov, { 0x30 , 0x260 , 0x558 , 0x1F8 });
			float Fov = 0;
			ReadProcessMemory(OyunHandle, (void*)SonucAdresFov, &Fov, sizeof(float), 0);

			WriteProcessMemory(OyunHandle, (void*)SonucAdresFov, &IstedigimizFov, sizeof(float), 0);


		}





		//STAMINA

		if (GetAsyncKeyState('Q') & 0x8000) {

			DWORD ProcessID = ProcessIdAl("ProSoccerOnline-Win64-Shipping.exe");

			if (!ProcessID) {
				std::cout << "pID = NULL"  "\n";
				return 0;
			}


			HANDLE OyunHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessID);


			if (!OyunHandle) {
				std::cout << "GAME HANDLE = NULL"  "\n";
				return 0;
			}


			DWORD Size = 0;
			PROCESS_BASIC_INFORMATION pbi;
			auto result = NtQueryInformationProc(OyunHandle, ProcessBasicInformation, &pbi, sizeof(PROCESS_BASIC_INFORMATION), &Size);
			PPEB PEB = pbi.PebBaseAddress;
			DWORD64 HedefAdress = ((DWORD64)PEB + 0x10);
			DWORD64 BaseAdress;
			ReadProcessMemory(OyunHandle, (void*)(HedefAdress), &BaseAdress, sizeof(DWORD64), 0);



			DWORD64 BaseAdress2 = (DWORD64)(GetModuleHandle("Console Application.exe"));


			if (!BaseAdress) {
				std::cout << "BASEADRESS = NULL"  "\n";
				return 0;
			}

			uintptr_t EnAltAdresStamina = (uintptr_t)BaseAdress + 0x0461AF18;



			auto SonucAdresStamina = PointerZinciriOku(OyunHandle, EnAltAdresStamina, { 0x0 , 0x20 , 0x528 , 0x430 , 0x120 , 0x18 , 0x5B4 });
			float Stamina = 0;
			float IstedigimizStamina = 1;
			ReadProcessMemory(OyunHandle, (void*)SonucAdresStamina, &Stamina, sizeof(float), 0);



			WriteProcessMemory(OyunHandle, (void*)SonucAdresStamina, &IstedigimizStamina, sizeof(float), 0);

		}



		//KICKPOWER


		if (GetAsyncKeyState('F') & 0x8000) {

			DWORD ProcessID = ProcessIdAl("ProSoccerOnline-Win64-Shipping.exe");



			if (!ProcessID) {
				std::cout << "pID = NULL"  "\n";
				return 0;
			}


			HANDLE OyunHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessID);


			if (!OyunHandle) {
				std::cout << "GAME HANDLE = NULL"  "\n";
				return 0;
			}


			DWORD Size = 0;
			PROCESS_BASIC_INFORMATION pbi;
			auto result = NtQueryInformationProc(OyunHandle, ProcessBasicInformation, &pbi, sizeof(PROCESS_BASIC_INFORMATION), &Size);
			PPEB PEB = pbi.PebBaseAddress;
			DWORD64 HedefAdress = ((DWORD64)PEB + 0x10);
			DWORD64 BaseAdress;
			ReadProcessMemory(OyunHandle, (void*)(HedefAdress), &BaseAdress, sizeof(DWORD64), 0);

			DWORD64 BaseAdress2 = (DWORD64)(GetModuleHandle("Console Application.exe"));


			if (!BaseAdress) {
				std::cout << "BASEADRESS = NULL"  "\n";
				return 0;
			}

			uintptr_t EnAltAdresFov = (uintptr_t)BaseAdress + 0x046249E0;


			auto SonucAdresFov = PointerZinciriOku(OyunHandle, EnAltAdresFov, { 0x50 , 0x80 , 0x30 , 0x610 });
			float Fov = 0;
			ReadProcessMemory(OyunHandle, (void*)SonucAdresFov, &Fov, sizeof(float), 0);



			WriteProcessMemory(OyunHandle, (void*)SonucAdresFov, &IstedigimizKickPower, sizeof(float), 0);

		}







		// SPEEDHACK



		if (GetAsyncKeyState('H') & 0x8000) {

			DWORD ProcessID = ProcessIdAl("ProSoccerOnline-Win64-Shipping.exe");



			if (!ProcessID) {
				std::cout << "pID = NULL"  "\n";
				return 0;
			}


			HANDLE OyunHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessID);


			if (!OyunHandle) {
				std::cout << "GAME HANDLE = NULL"  "\n";
				return 0;
			}


			DWORD Size = 0;
			PROCESS_BASIC_INFORMATION pbi;
			auto result = NtQueryInformationProc(OyunHandle, ProcessBasicInformation, &pbi, sizeof(PROCESS_BASIC_INFORMATION), &Size);
			PPEB PEB = pbi.PebBaseAddress;
			DWORD64 HedefAdress = ((DWORD64)PEB + 0x10);
			DWORD64 BaseAdress;
			ReadProcessMemory(OyunHandle, (void*)(HedefAdress), &BaseAdress, sizeof(DWORD64), 0);

			DWORD64 BaseAdress2 = (DWORD64)(GetModuleHandle("Console Application.exe"));


			if (!BaseAdress) {
				std::cout << "BASEADRESS = NULL"  "\n";
				return 0;
			}

			uintptr_t EnAltAdresFov = (uintptr_t)BaseAdress + 0x0460FF70;


			auto SonucAdresFov = PointerZinciriOku(OyunHandle, EnAltAdresFov, { 0x30 , 0x5C8 , 0x528 , 0x58 , 0x20 , 0x98 });
			float Fov = 0;
			ReadProcessMemory(OyunHandle, (void*)SonucAdresFov, &Fov, sizeof(float), 0);



			WriteProcessMemory(OyunHandle, (void*)SonucAdresFov, &IstedigimizSpeed, sizeof(float), 0);

		}









		//DRIBBLING FACTOR




		if (GetAsyncKeyState('V') & 0x8000) {

			DWORD ProcessID = ProcessIdAl("ProSoccerOnline-Win64-Shipping.exe");



			if (!ProcessID) {
				std::cout << "pID = NULL"  "\n";
				return 0;
			}


			HANDLE OyunHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessID);


			if (!OyunHandle) {
				std::cout << "GAME HANDLE = NULL"  "\n";
				return 0;
			}


			DWORD Size = 0;
			PROCESS_BASIC_INFORMATION pbi;
			auto result = NtQueryInformationProc(OyunHandle, ProcessBasicInformation, &pbi, sizeof(PROCESS_BASIC_INFORMATION), &Size);
			PPEB PEB = pbi.PebBaseAddress;
			DWORD64 HedefAdress = ((DWORD64)PEB + 0x10);
			DWORD64 BaseAdress;
			ReadProcessMemory(OyunHandle, (void*)(HedefAdress), &BaseAdress, sizeof(DWORD64), 0);

			DWORD64 BaseAdress2 = (DWORD64)(GetModuleHandle("Console Application.exe"));


			if (!BaseAdress) {
				std::cout << "BASEADRESS = NULL"  "\n";
				return 0;
			}

			uintptr_t EnAltAdresFov = (uintptr_t)BaseAdress + 0x0460FF70;


			auto SonucAdresFov = PointerZinciriOku(OyunHandle, EnAltAdresFov, { 0x30 , 0x580 , 0x20 , 0x98 });
			float Fov = 0;
			ReadProcessMemory(OyunHandle, (void*)SonucAdresFov, &Fov, sizeof(float), 0);



			WriteProcessMemory(OyunHandle, (void*)SonucAdresFov, &IstedigimizDribbling, sizeof(float), 0);

		}









		// DRONE CAMERA




		if (GetAsyncKeyState('X') & 0x8000) {

			DWORD ProcessID = ProcessIdAl("ProSoccerOnline-Win64-Shipping.exe");



			if (!ProcessID) {
				std::cout << "pID = NULL"  "\n";
				return 0;
			}


			HANDLE OyunHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessID);


			if (!OyunHandle) {
				std::cout << "GAME HANDLE = NULL"  "\n";
				return 0;
			}


			DWORD Size = 0;
			PROCESS_BASIC_INFORMATION pbi;
			auto result = NtQueryInformationProc(OyunHandle, ProcessBasicInformation, &pbi, sizeof(PROCESS_BASIC_INFORMATION), &Size);
			PPEB PEB = pbi.PebBaseAddress;
			DWORD64 HedefAdress = ((DWORD64)PEB + 0x10);
			DWORD64 BaseAdress;
			ReadProcessMemory(OyunHandle, (void*)(HedefAdress), &BaseAdress, sizeof(DWORD64), 0);

			DWORD64 BaseAdress2 = (DWORD64)(GetModuleHandle("Console Application.exe"));


			if (!BaseAdress) {
				std::cout << "BASEADRESS = NULL"  "\n";
				return 0;
			}

			uintptr_t EnAltAdresFov = (uintptr_t)BaseAdress + 0x0461AF18;


			auto SonucAdresFov = PointerZinciriOku(OyunHandle, EnAltAdresFov, { 0x0 , 0x20 , 0x558 , 0x11C });
			float Fov = 0;
			ReadProcessMemory(OyunHandle, (void*)SonucAdresFov, &Fov, sizeof(float), 0);



			WriteProcessMemory(OyunHandle, (void*)SonucAdresFov, &IstedigimizDrone, sizeof(float), 0);

		}






		//ADD POSITION




		if (GetAsyncKeyState('L') & 0x8000) {

			DWORD ProcessID = ProcessIdAl("ProSoccerOnline-Win64-Shipping.exe");

			if (!ProcessID) {
				std::cout << "pID = NULL"  "\n";
				return 0;
			}


			HANDLE OyunHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessID);


			if (!OyunHandle) {
				std::cout << "GAME HANDLE = NULL"  "\n";
				return 0;
			}


			DWORD Size = 0;
			PROCESS_BASIC_INFORMATION pbi;
			auto result = NtQueryInformationProc(OyunHandle, ProcessBasicInformation, &pbi, sizeof(PROCESS_BASIC_INFORMATION), &Size);
			PPEB PEB = pbi.PebBaseAddress;
			DWORD64 HedefAdress = ((DWORD64)PEB + 0x10);
			DWORD64 BaseAdress;
			ReadProcessMemory(OyunHandle, (void*)(HedefAdress), &BaseAdress, sizeof(DWORD64), 0);



			DWORD64 BaseAdress2 = (DWORD64)(GetModuleHandle("Console Application.exe"));


			if (!BaseAdress) {
				std::cout << "BASEADRESS = NULL"  "\n";
				return 0;
			}

			uintptr_t EnAltAdresStamina = (uintptr_t)BaseAdress + 0x0421CC50;



			auto SonucAdresStamina = PointerZinciriOku(OyunHandle, EnAltAdresStamina, { 0x0 , 0x120 , 0x32C });
			float Stamina = 0;
			float IstedigimizStamina = Stamina + 1;
			ReadProcessMemory(OyunHandle, (void*)SonucAdresStamina, &Stamina, sizeof(float), 0);



			WriteProcessMemory(OyunHandle, (void*)SonucAdresStamina, &IstedigimizStamina, sizeof(float), 0);

		}





		//BUG BALL



		if (GetAsyncKeyState('Z') & 0x8000) {

			DWORD ProcessID = ProcessIdAl("ProSoccerOnline-Win64-Shipping.exe");

			if (!ProcessID) {
				std::cout << "pID = NULL"  "\n";
				return 0;
			}


			HANDLE OyunHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessID);


			if (!OyunHandle) {
				std::cout << "GAME HANDLE = NULL"  "\n";
				return 0;
			}


			DWORD Size = 0;
			PROCESS_BASIC_INFORMATION pbi;
			auto result = NtQueryInformationProc(OyunHandle, ProcessBasicInformation, &pbi, sizeof(PROCESS_BASIC_INFORMATION), &Size);
			PPEB PEB = pbi.PebBaseAddress;
			DWORD64 HedefAdress = ((DWORD64)PEB + 0x10);
			DWORD64 BaseAdress;
			ReadProcessMemory(OyunHandle, (void*)(HedefAdress), &BaseAdress, sizeof(DWORD64), 0);



			DWORD64 BaseAdress2 = (DWORD64)(GetModuleHandle("Console Application.exe"));


			if (!BaseAdress) {
				std::cout << "BASEADRESS = NULL"  "\n";
				return 0;
			}

			uintptr_t EnAltAdresStamina = (uintptr_t)BaseAdress + 0x046249E0;



			auto SonucAdresStamina = PointerZinciriOku(OyunHandle, EnAltAdresStamina, { 0x50 , 0x80 , 0x30 , 0x610 });
			float Stamina = 0;
			float IstedigimizStamina = 9999999999999;
			ReadProcessMemory(OyunHandle, (void*)SonucAdresStamina, &Stamina, sizeof(float), 0);



			WriteProcessMemory(OyunHandle, (void*)SonucAdresStamina, &IstedigimizStamina, sizeof(float), 0);

		}



	}





	return 0;
}


//R = FOV
//Q = STAMINA
//F = SHOOT POWER
//H = SPEED HACK
//V = DRIBBLING FACTOR
//X = DRONE CAMERA
//L = ADD POSITION
//Z = BUG BALL

//github.com/skyzecheat
//skyzecheat
