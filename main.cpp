// Andres Rodriguez II
// GTID: 903126687 arodriguez79@gatech.edu
// ECE 2036 Section A Lab 03
// Date Completed: 02.14.18

#include "setup.h"
#include "trial.h"

uLCD_4DGL uLCD(p28, p27, p29);
SDFileSystem sd(p5, p6, p7, p8, "sd");
Speaker speaker(p21);
DigitalIn selectLeft(p17);
DigitalIn selectRight(p18);
DigitalIn exitButton(p16);

int xstart, ystart, row, col, rad, cx, cy, color;
int offset = 20;
bool GETOUT = false;
int *numTrial = NULL;

int main() {
  Trial training;
	uLCD.baudrate(BAUD_3000000);

  // Phase 2: Set-up trial (pushbuttons)
  selectLeft.mode(PullUp);
  selectRight.mode(PullUp);
  exitButton.mode(PullUp);

  srand(time(0)); // Seed pseudo-random set

  // Phase 1: Set-up
  ::loadScreen(); ::startupJingle();
  numTrial = training.initializeTraining( );
  while(!GETOUT) {
    training.startTrial( numTrial );       // Begin
    training.executeTrial( );     // Execute
    training.endTrial( );         // End
        if(!GETOUT) { training.dataLogger( numTrial ); } // Phase 3: Data Logging
  }

    ::endTraining( ); // Exit Training System
}
