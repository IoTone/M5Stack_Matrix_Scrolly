#include "M5Atom.h"
#include "Scrolly.h"

Scrolly::Scrolly(int displayWidth, int displayHeight, int pixelBoardWidth, int pixelBoardHeight, int pixelBoardChannels) {

  this->pixelBoard = new Scrolly_PixelBoard(pixelBoardWidth, pixelBoardHeight, pixelBoardChannels);
  this->display = new Scrolly_Display(displayWidth, displayHeight, this->pixelBoard->pixelBoardBuffer);

  this->cursorX = 0;
  this->currentDisplayX = 0;
  this->displayAA = true;
  this->stepX = 1;
  this->displayDelay = 15;
  this->fontCount = 255;
  this->fontCount = findChar(8);
  this->setColor(255, 255, 255);
}

void Scrolly::print(const char * format, ...) {
  char charBuffer[256];
  va_list args;
  va_start(args, format);
  vsnprintf_(charBuffer, 255, format, args);
  this->printChars(charBuffer, 255);
  va_end(args);
}

void Scrolly::printChars(char *buffer, uint8_t length) {
  uint8_t i = 0;
  while (buffer[i] != 0) {
    this->printChar(buffer[i]);
    buffer++;
  }
}

void Scrolly::setColor(uint8_t r, uint8_t g, uint8_t b) {
  this->fontColor.r = r;
  this->fontColor.g = g;
  this->fontColor.b = b;
}

int Scrolly::findChar(char ascii) {
  for (int charIndex = 0; charIndex < this->fontCount; charIndex++) {
    if (font[charIndex][5] == ascii) return charIndex;
  }
  return this->findChar(32); // Return index for the space.
}

void Scrolly::printChar(char c) {
  if (c > 96) c -= 32;
  int charIndex = findChar(c);
  int charWidth = font[charIndex][6];
  for (int y = 0; y < this->pixelBoard->height; y++) {
    for (int x = charWidth; x >= 0 ; x--) {
      if (font[charIndex][y] & bits[charWidth - x]) {
        this->pixelBoard->pixelBoardBuffer[0][x + this->cursorX][y] = this->fontColor.r;
        this->pixelBoard->pixelBoardBuffer[1][x + this->cursorX][y] = this->fontColor.g;
        this->pixelBoard->pixelBoardBuffer[2][x + this->cursorX][y] = this->fontColor.b;
      }
    }
  }
  this->cursorX += charWidth;
}

void Scrolly::update() {
  if (this->displayAA) {
    this->stepX = 0.1;
  } else {
    this->currentDisplayX = (int)this->currentDisplayX;
    this->stepX = 1;
  }
  this->currentDisplayX += this->stepX;
  if (currentDisplayX > (this->cursorX + 5)) currentDisplayX = 0;
}

void Scrolly::show() {
  this->display->drawMessageBuffer(currentDisplayX);
  this->display->show();
  delay(this->displayDelay * (this->displayAA ? 1 : 10));
}

void Scrolly::clear() {
  this->pixelBoard->clearPixelBoard(0, 0, 0);
  this->currentDisplayX = 0;
  this->cursorX = 0;
}

void Scrolly::smoothScroll(bool on) {
  this->displayAA = on;
}

bool Scrolly::getSmoothScroll() {
  return this->displayAA;
}

void Scrolly::scrollDelay(int d){
  this->displayDelay = d;
}

int Scrolly::getScrollDelay(){
  return this->displayDelay;
}
