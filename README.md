# mBed-LemurTraining
Simulate an expirement to assess whether or not Lemurs have the ability to percieve numbers. The original experiment was performed by Professor Elizabeth Brannon at Duke University. 
See here for more information: https://gpb.pbslearningmedia.org/resource/nvmm-math-numeracy/animals-numeracy/#.W1nXJBgnarw

### Experiment Process:
	At the start of the each trial, two 'bins' will be drawn on either side of the screen. Each bin will contain a psuedo-random number of objects, with a psuedo-random shape. Connected to the mBed are three momentary pushbuttons. The left and right pushbuttons correspond to the left and right bins, while the center pushbutton acts as the 'EXIT' button.

The lemur or other test subject will press the button corresponding to the bin with the fewest number of objects. After each trial, results will be printed to the screen indicating whether or not the choice was correct, the trial number, and the overall accuracy of the experiment. The proccess will then start over, and loop until the 'EXIT' button is pressed.

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
