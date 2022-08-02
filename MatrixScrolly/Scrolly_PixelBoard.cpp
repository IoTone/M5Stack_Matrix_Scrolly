
#include "M5Atom.h"
#include "Scrolly_MultiArrays.h"
#include "Scrolly_PixelBoard.h"

Scrolly_PixelBoard::Scrolly_PixelBoard(int pixelBoardWidth, int pixelBoardHeight, int pixelBoardChannels) {
  this->channels = pixelBoardChannels;
  this->width = pixelBoardWidth;
  this->height = pixelBoardHeight;
  this->pixelBoardBuffer = ma.make3DShortInt(this->channels, this->width, this->height);
}

void Scrolly_PixelBoard::clearPixelBoard(uint8_t r, uint8_t g, uint8_t b) {
  for (int y = 0; y < this->height; y++) {
    for (int x = 0; x < this->width; x++) {
      this->pixelBoardBuffer[0][x][y] = r;
      this->pixelBoardBuffer[1][x][y] = g;
      this->pixelBoardBuffer[2][x][y] = b;
    }
  }
}

// Also to add: User defined full color 8x8 graphics.
