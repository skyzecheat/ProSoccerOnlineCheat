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



int main() {


	//ASCII

	system("Color 0E");

	std::cout << "  OOO   H   H  IIIII  OOO" << std::endl;
	std::cout << " O   O  H   H    I   O   O" << std::endl;
	std::cout << " O   O  HHHHH    I   O   O" << std::endl;
	std::cout << " O   O  H   H    I   O   O" << std::endl;
	std::cout << "  OOO   H   H  IIIII  OOO\n" << std::endl;

	Sleep(1000);

	system("Color 04");

	std::cout << "  h  h   ooo   ooo   k   k" << std::endl;
	std::cout << "  h  h  o   o o   o  k  k" << std::endl;
	std::cout << "  hhhh  o   o o   o  kk" << std::endl;
	std::cout << "  h  h  o   o o   o  k  k" << std::endl;
	std::cout << "  h  h   ooo   ooo   k   k\n" << std::endl;

	Sleep(1000);

	system("cls");

	Sleep(1000);

	system("Color 03");

	std::cout << "  FFFF  U   U  CCCC  K   K" << std::endl;
	std::cout << "  F     U   U  C     K  K" << std::endl;
	std::cout << "  FFF   U   U  C     KK" << std::endl;
	std::cout << "  F     U   U  C     K  K" << std::endl;
	std::cout << "  F      UUU    CCCC  K   K\n" << std::endl;

	Sleep(1000);

	system("Color 01");

	std::cout << "Y     Y OOO   U   U" << std::endl;
	std::cout << "  Y  Y O   O  U   U" << std::endl;
	std::cout << "   Y   O   O  U   U" << std::endl;
	std::cout << "   Y   O   O  U   U" << std::endl;
	std::cout << "   Y    OOO    UUU\n" << std::endl;

	Sleep(1000);

	system("Color 05");

	std::cout << " BBBBB  RRRR    Y   Y  L      OOO   SSSS" << std::endl;
	std::cout << " B    B R   R    Y Y   L     O   O  S    " << std::endl;
	std::cout << " BBBBB  RRRR      Y    L     O   O  SSSS " << std::endl;
	std::cout << " B    B R   R     Y    L     O   O     S " << std::endl;
	std::cout << " BBBBB  R   R     Y    LLLLL  OOO   SSSS" << std::endl;

	Sleep(1000);

	system("cls");

	Sleep(1000);





	//MAIN

	system("Color 0E");
	std::cout << "ohiohook\n" << std::endl;
	Sleep(500);
	std::cout << "skyze x taskmanager\n" << std::endl;
	Sleep(500);

	std::cout << "[R] FOV\n" << std::endl;
	std::cout << "[X] DRONE CAMERA\n" << std::endl;
	std::cout << "[Q] STAMINA\n" << std::endl;
	std::cout << "[H] SPEED HACK\n" << std::endl;
	std::cout << "[F] MAGIC HANDS\n" << std::endl;
	std::cout << "[Z] BUG BALL\n" << std::endl;
	std::cout << "[V] DRIBBLING FACTOR\n" << std::endl;
	std::cout << "[L] ADD POSITION\n" << std::endl;

	std::cout << "FOV VALUE : \n" << std::endl;

	float IstedigimizFov;
	std::cin >> IstedigimizFov;

	std::cout << "SPEED HACK VALUE : \n" << std::endl;

	float IstedigimizSpeed;
	std::cin >> IstedigimizSpeed;

	std::cout << "MAGIC HANDS VALUE : \n" << std::endl;

	float IstedigimizKickPower;
	std::cin >> IstedigimizKickPower;

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

			uintptr_t EnAltAdresFov = (uintptr_t)BaseAdress + 0x04611F80;


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

			uintptr_t EnAltAdresStamina = (uintptr_t)BaseAdress + 0x0461CF28;



			auto SonucAdresStamina = PointerZinciriOku(OyunHandle, EnAltAdresStamina, { 0x0 , 0xA0 , 0x578 , 0xA0 , 0x50 , 0x6C8 });
			float Stamina = 0;
			float IstedigimizStamina = 1;
			ReadProcessMemory(OyunHandle, (void*)SonucAdresStamina, &Stamina, sizeof(float), 0);



			WriteProcessMemory(OyunHandle, (void*)SonucAdresStamina, &IstedigimizStamina, sizeof(float), 0);

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

			uintptr_t EnAltAdresFov = (uintptr_t)BaseAdress + 0x04611F80;


			auto SonucAdresFov = PointerZinciriOku(OyunHandle, EnAltAdresFov, { 0x30 , 0x5C8 , 0xF8 , 0x20 , 0x98 });
			float Fov = 0;
			ReadProcessMemory(OyunHandle, (void*)SonucAdresFov, &Fov, sizeof(float), 0);



			WriteProcessMemory(OyunHandle, (void*)SonucAdresFov, &IstedigimizSpeed, sizeof(float), 0);

		}





		//MAGIC HANDS
		


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

			uintptr_t EnAltAdresFov = (uintptr_t)BaseAdress + 0x04611F80;


			auto SonucAdresFov = PointerZinciriOku(OyunHandle, EnAltAdresFov, { 0x30 , 0x50 , 0x610 });
			float Fov = 0;
			ReadProcessMemory(OyunHandle, (void*)SonucAdresFov, &Fov, sizeof(float), 0);



			WriteProcessMemory(OyunHandle, (void*)SonucAdresFov, &IstedigimizKickPower, sizeof(float), 0);

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

			uintptr_t EnAltAdresStamina = (uintptr_t)BaseAdress + 0x04611F80;



			auto SonucAdresStamina = PointerZinciriOku(OyunHandle, EnAltAdresStamina, { 0x30 , 0x50 , 0x610 });
			float Stamina = 0;
			float IstedigimizStamina = 9999999999999;
			ReadProcessMemory(OyunHandle, (void*)SonucAdresStamina, &Stamina, sizeof(float), 0);



			WriteProcessMemory(OyunHandle, (void*)SonucAdresStamina, &IstedigimizStamina, sizeof(float), 0);

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

			uintptr_t EnAltAdresFov = (uintptr_t)BaseAdress + 0x04611F80;


			auto SonucAdresFov = PointerZinciriOku(OyunHandle, EnAltAdresFov, { 0x30 , 0x130 , 0x20 , 0x98 });
			float Fov = 0;
			ReadProcessMemory(OyunHandle, (void*)SonucAdresFov, &Fov, sizeof(float), 0);



			WriteProcessMemory(OyunHandle, (void*)SonucAdresFov, &IstedigimizDribbling, sizeof(float), 0);

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

			uintptr_t EnAltAdresStamina = (uintptr_t)BaseAdress + 0x041C9A00;



			auto SonucAdresStamina = PointerZinciriOku(OyunHandle, EnAltAdresStamina, { 0x0 , 0x120 , 0x32C });
			float Stamina = 0;
			float IstedigimizStamina = Stamina + 1;
			ReadProcessMemory(OyunHandle, (void*)SonucAdresStamina, &Stamina, sizeof(float), 0);



			WriteProcessMemory(OyunHandle, (void*)SonucAdresStamina, &IstedigimizStamina, sizeof(float), 0);

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

			uintptr_t EnAltAdresFov = (uintptr_t)BaseAdress + 0x0461CF28;


			auto SonucAdresFov = PointerZinciriOku(OyunHandle, EnAltAdresFov, { 0x0 , 0xA0 , 0x558 , 0x11C });
			float Fov = 0;
			ReadProcessMemory(OyunHandle, (void*)SonucAdresFov, &Fov, sizeof(float), 0);



			WriteProcessMemory(OyunHandle, (void*)SonucAdresFov, &IstedigimizDrone, sizeof(float), 0);

		}



	}




	return 0;
}


//R = FOV
//Q = STAMINA
//F = MAGIC HANDS
//H = SPEED HACK
//V = DRIBBLING FACTOR
//X = DRONE CAMERA
//L = ADD POSITION
//Z = BUG BALL

//github.com/skyzecheat
//skyzecheat
