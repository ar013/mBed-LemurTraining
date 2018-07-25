#ifndef SETUP_H
#define SETUP_H

#define BAUDRATE 

// Define a few extra colors
#define PINK 0xCB3BBE
#define CYAN 0x37E6FB
#define YELLOW 0xF0ED31

#include "mbed.h"
#include "uLCD_4DGL.h"
#include "SDFileSystem.h"
#include "Speaker.h"
#include <cstdlib>

using namespace std;

extern uLCD_4DGL uLCD;        // LCD Screen
extern SDFileSystem sd;       // SD Card
extern Speaker speaker;        // Speaker
extern DigitalIn selectLeft;  // Pushbuttons
extern DigitalIn selectRight;
extern DigitalIn exitButton;
extern int xstart, ystart, row, col, rad, cx, cy, color;
extern int offset;
extern bool GETOUT;

// Global functions used for setup

void loadScreen( );                       // Loading Screen
void startupJingle( );                    // Play StartupJingle
void loadEmpty( );                        // Load "bins" for objects
int loadObjects( bool);                   // Load objects into specified bins
void endTraining();                       // Ends Lemur Training
void drawTriangle( int, int, float, int );  // Draw filled triangle
void drawStar( int, int, float, int);       // Draw star using two triangles

#endif
