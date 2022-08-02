#ifndef Scrolly_PixelBoard_h
#define Scrolly_PixelBoard_h

class Scrolly_PixelBoard {
  public:
    Scrolly_PixelBoard(int pixelBoardWidth, int pixelBoardHeight, int pixelBoardChannels);

    void clearPixelBoard(uint8_t r, uint8_t g, uint8_t b);
    int channels;
    int width;
    int height;
    short int ***pixelBoardBuffer;

    // Also to add: User defined full color 8x8 graphics.

  private:
};

#endif
