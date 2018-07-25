#include "setup.h"

void loadScreen( ) { // Display loading screen, play startup jingle
  uLCD.cls();
  uLCD.locate(4,5);
  uLCD.puts("LOADING");
  uLCD.locate(4,6);
  uLCD.puts("TRAINING");
  uLCD.locate(4,7);
  uLCD.puts("SYSTEM...");
  //wait(2); // Make jingle 2 seconds, put here to replace statement
  //uLCD.cls();
}

void startupJingle( ) {
  // Shave and a Haircut:
  // Notes: C5-G4-G4-A4-G4-REST-B4-C5 Played @ 240 BPM => 0.25s/beat
	float v = 0.05;

  speaker.PlayNote( 523.25 , 0.25, v);  // C5
  speaker.PlayNote( 392.00 , 0.115, v); // G4
  wait(0.02);
  speaker.PlayNote( 392.00 , 0.115, v); // G4
  speaker.PlayNote( 440.00 , 0.25, v);  // A4
  speaker.PlayNote( 392.00 , 0.25, v);  // G4
  wait(0.25);                              // Rest
  speaker.PlayNote( 493.88 , 0.25, v);  // B4
  speaker.PlayNote( 523.25 , 0.25, v);  // C5
}

void loadEmpty( ) {
  uLCD.cls();
  uLCD.rectangle(3,4,63,124, WHITE);
  uLCD.rectangle(65,4,125,124, WHITE);
}

int loadObjects(bool left) {
  int object, shape;
    // Set starting position from bin (left/right)
  if(left) { xstart = 13; ystart = 14; } // Set starting position to (13, 14)
    else { xstart = 75; ystart = 14; } // Set offset to (75,14)

  cx = xstart; cy = ystart;

  for(object = 0; object < (rand() % 15 +1); object++) {   // Draw objects

    do {
      row = rand() % 6; col = rand() % 2; // Randomly determine box
      cx = xstart + col*offset; // Shift coordinates to center of box
      cy = ystart + row*offset;
    } while(uLCD.read_pixel(cx,cy) != BLACK);

    rad = rand() % 6 + 3; // Use rand to give random Radius (3-8)
    // Random colors (RED, GREEN, BLUE, WHITE, PINK, CYAN, YELLOW)
    color = rand() % 7;

    switch(color) {
      case 0: color = RED; break;
      case 1: color = GREEN; break;
      case 2: color = BLUE; break;
      case 3: color = WHITE; break;
      case 4: color = PINK; break;
      case 5: color = CYAN; break;
      case 6: color = YELLOW; break;
    }

		shape = rand() % 3;
		switch(shape) {
			case 0: uLCD.filled_circle(cx, cy, rad, color); break;
			case 1: drawTriangle(cx, cy, rad, color); break;
			case 2: drawStar(cx, cy, rad, color);
		}

  }
  return object;
}

void endTraining( ) {
  uLCD.cls();
  uLCD.locate(4,7);
	uLCD.puts("GOODBYE!");
}

void drawTriangle(int x0, int y0, float r, int c ) {
	float r1;
  while(r > 0){
		r1 = ceil(0.5*r);
    uLCD.triangle(x0, (y0-r), (x0+r1), (y0+r1), (x0-r1), (y0+r1), c);
		uLCD.pixel(x0-r1, y0+r1, c);
    r--;
  }
	uLCD.pixel(x0, y0, c);
}

void drawStar(int x0, int y0, float r, int c) { // NEEDS FIXING
	float r1 = ceil(0.5*r);
	int x1 = x0-r1;
	int x2 = x0+r1;
	int y1 = y0+r1;
	int y2 = y0-r1;

	uLCD.line(x0, y0+r, x0, y0-r, c);
	uLCD.line(x0-r, y0,x0+r, y0, c);
	uLCD.line(x1, y2, x2, y1, c);
	uLCD.line(x2, y2, x1, y1, c);
	uLCD.pixel(x1, y1-1, c); uLCD.pixel(x2, y1-1, c); // Fix bottom 2 pixels
}
