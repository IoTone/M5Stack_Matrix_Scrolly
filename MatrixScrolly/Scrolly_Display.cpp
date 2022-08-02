
#include "Scrolly_Display.h"

Scrolly_Display::Scrolly_Display(int displayWidth, int displayHeight, short int ***&pixelBoard) {
  this->display_width = displayWidth;
  this->display_height = displayHeight;
  this->pixelBoard = pixelBoard;
  this->display = ma.make3DShortInt(3, displayWidth + 1, displayHeight + 1);
}

void Scrolly_Display::show(void) {
  for (int y = 0; y < this->display_height; y++) {
    for (int x = 0; x < this->display_width; x++) {
      M5.dis.drawpix(x, y, this->display[1][x][y] << 16 | this->display[0][x][y] << 8 | this->display[2][x][y]);
    }
  }
}

void Scrolly_Display::drawMessageBuffer(float fx) {
  if (fx < 0) return;
  int intOffsetX = (int) fx;
  float partialX = 1 - (fx - (int) fx);
  for (int y = 0; y < this->display_height; y++) {
    for (int x = 0; x <= this->display_width; x++) {
      this->display[0][x][y] = 0;
      this->display[1][x][y] = 0;
      this->display[2][x][y] = 0;
    }
  }
  for (int y = 0; y < this->display_height; y++) {
    for (int x = 0; x <= this->display_width; x++) {
      int posX = intOffsetX + x;
      this->drawAAPixel(partialX + x - 1, y, this->pixelBoard[0][posX][y], this->pixelBoard[1][posX][y], this->pixelBoard[2][posX][y]);
    }
  }
}

void Scrolly_Display::drawAAPixel(float x, float y, uint8_t rr, uint8_t gg, uint8_t bb) {
  x += 1;
  uint8_t iX = (uint8_t)x;
  uint8_t iY = (uint8_t)y;
  // Percentage
  float rightP = x - (int)x;
  float leftP = 1.0 - rightP;
  //int off2 = iX + 5 * iY;
  //int off1 = off2 - 1;
  // Left side
  if (x >= 1 && x < 6) {
    this->display[0][iX - 1][iY] += (int)(rr * leftP);
    this->display[1][iX - 1][iY] += (int)(gg * leftP);
    this->display[2][iX - 1][iY] += (int)(bb * leftP);
  }
  // Right side
  if (x > 0 && x < 5) {
    this->display[0][iX][iY] += (int)(rr * rightP);
    this->display[1][iX][iY] += (int)(gg * rightP);
    this->display[2][iX][iY] += (int)(bb * rightP);
  }
}
