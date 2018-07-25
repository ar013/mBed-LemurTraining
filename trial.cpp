#include "trial.h"

	void Trial::initializeTraining( ) {
		trialTime.reset();
		trialNumber = 0;
		trialsCorrect = 0;
		accuracy = 0.0;

    FILE *results = fopen("/sd/LAB03/LemurResults.txt", "a");
    if(results == NULL) { uLCD.cls(); uLCD.printf("SD CARD ERROR"); wait(1);}
    fprintf(results, "   LEMUR TRAINING RESULTS:   ");
    fclose(results);

		return &trialNumber;
	}

  void Trial::startTrial( int *tNum) {    // Begin trial, timer, wait for exit
    *tNum++;
    ::loadEmpty();

    do{ // Make sure bins are uneven
      leftObjects = ::loadObjects(1);
      rightObjects = ::loadObjects(0);
    } while(leftObjects == rightObjects);

    if(leftObjects < rightObjects) { correctBin = true; } // Set correctBin
      else { correctBin = false; }

    trialTime.start(); // start timer
  }

  void Trial::executeTrial( ) {
    while(true) {
      if (!selectLeft) {
        if(correctBin) { goodLemur = true; }
          else { goodLemur = false; }
        break;
      } else if (!selectRight) {
        if(!correctBin) { goodLemur = true; }
				  else { goodLemur = false; }
        break;
      } else if(!exitButton){ GETOUT = true; break; } // Exit Testing
        }
    }

  void Trial::endTrial( ) {
    trialTime.stop();
    uLCD.cls();
  }

  void Trial::dataLogger( int * tNum) { // Prints trial data to LCD and writes to SD card
    uLCD.locate(1,3);
		// Correct/Incorrect, update correct
		if(goodLemur){ uLCD.puts("Correct!!!"); trialsCorrect++; }
			else { uLCD.puts("Incorrect"); }

		// Update Accuracy
		accuracy = (float(trialsCorrect))/(float(trialNumber));

		// Print TrialStats to LCD
		uLCD.locate(1,4); uLCD.printf("Left Bin: %d", leftObjects);
		uLCD.locate(1,5); uLCD.printf("Right Bin: %d", rightObjects);
		uLCD.locate(1,6); uLCD.printf("Trial Number: %d", (*tNum));
		uLCD.locate(1,7); uLCD.printf("Accuracy: %.2f", accuracy);
		uLCD.locate(1,8); uLCD.printf("Delay (ms): %d", trialTime.read_ms());

		trialTime.reset(); // Reset Timer

		wait(1.5); // Delay for time to read

		// Write to SD
    FILE *results = fopen("/sd/LAB03/LemurResults.txt", "a");
    if(results == NULL) { uLCD.cls(); uLCD.printf("SD CARD ERROR"); }

    if(goodLemur) { fprintf(results, "Correct!!!"); }
      else { fprintf(results, "Incorrect"); }

    fprintf(results, "Left Bin: %d\n", leftObjects);
    fprintf(results, "Right Bin: %d\n", rightObjects);
    fprintf(results, "TrialNumber: %d\n", (*tNum));
    fprintf(results, "Accuracy: %.2f\n", accuracy);
    fprintf(results, "Delay (ms): %d\n", trialTime.read_ms());

    fclose(results);

  }

// After each individual round (trial), stop, read, and reset timer,
// call dataLogger.
// Loop until exitButton
