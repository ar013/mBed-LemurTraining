# mBed-MissileCommandEmulator
Emulator for a spin-off of the classic arcade game "Missile Command" to be run on the ARM mBed platform

-------------
## File Guide:

	Emulator: 
	- main.cpp		=>	main C++ routines
	- setup.h/.cpp		=>	Trial Setup
	- trial.h/.cpp		=>	Trial routine
	
	mBed/Hardware Drivers:
	- mbed/		 	=>	mBed Drivers/Libraries
	- PinDetect/		=>	pushButton Driver
	- SDFileSystem/		=>	SD Card Reader/File System Libraries
	- 4DGL-uLCD-SE		=> 	4DGL uLCD Drivers
	- Speaker.h		=> 	Speaker Driver

### NOTE:
- All drivers/libraries are include in setup.h
