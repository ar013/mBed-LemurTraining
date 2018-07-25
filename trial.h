#ifndef TRIAL_H
#define TRIAL_H

#include "setup.h"

class Trial{

  public: //Member Functions

		int * initializeTraining( ); // mBed wont allow constructor to have same name as class for some reason... :(
    void startTrial( int * );         // Set-up trial, start timer, increment trial count
    void executeTrial( );       // Wait for pb, take appropriate action
    void endTrial( );           // wait for exitButton
    void dataLogger( );         // Prints Trial stats and saves to SDCARD

  private: // Data Members: TrialStats
    Timer trialTime;
		int trialNumber;
    int trialsCorrect;
    bool correctBin;    // true => left, false => right
    int leftObjects;
    int rightObjects;
    int goodLemur;
		float accuracy;

};
#endif
