#ifndef Scrolly_Display_h
#define Scrolly_Display_h

#include "M5Atom.h"
#include "Scrolly_MultiArrays.h"
#include <stdlib.h>

class Scrolly_Display {
  public:
    Scrolly_Display(int displayWidth, int displayHeight, short int ***&pixelBoard);
    void show(void);
    short int ***display;
    int display_width;
    int display_height;
    short int ***pixelBoard;
    void drawMessageBuffer(float x);
    void drawAAPixel(float x, float y, uint8_t rr, uint8_t gg, uint8_t bb);

  private:
};

#endif
