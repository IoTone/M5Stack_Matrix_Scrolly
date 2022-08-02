#ifndef Scrolly_h
#define Scrolly_h

#include "M5Atom.h"
//#include "Scrolly_Font.h"
#include "Scrolly_FontNarrow.h"

#include "Scrolly_printf.h"
#include "Scrolly_Display.h"
#include "Scrolly_PixelBoard.h"
#include "Scrolly_MultiArrays.h"

struct FontColor {
  uint8_t r;
  uint8_t g;
  uint8_t b;
};

class Scrolly {
  public:
    Scrolly(int displayWidth, int displayHeight, int pixelBoardWidth, int pixelBoardHeight, int pixelBoardChannels);

    Scrolly_Display *display;
    Scrolly_PixelBoard *pixelBoard;

    uint8_t bits[8] = {1, 2, 4, 8, 16, 32, 64, 128};
    int cursorX;

    float currentDisplayX;
    boolean displayAA;
    float stepX;
    int displayDelay;

    uint8_t fontCount;
    FontColor fontColor;

    void printChar(char c);
    void setColor(uint8_t r, uint8_t g, uint8_t b);

    void print(const char * format, ...);

    void show(void);
    void update(void);
    void clear(void);

    void smoothScroll(bool on);
    bool getSmoothScroll();
    void scrollDelay(int d);
    int getScrollDelay();

  private:
    void printChars(char * buffer, uint8_t length);
    int findChar(char ascii);
};

#endif
