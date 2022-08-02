#ifndef Scrolly_Arrays_h
#define Scrolly_Arrays_h

#include <stdlib.h>

class Scrolly_MultiArrays {
  public:
    Scrolly_MultiArrays();
    void destroy2DIntArray(int** arr);
    void destroy3DIntArray(int*** arr);
    short int** make2DShortInt(int dimensionX, int dimensionY);
    short int*** make3DShortInt(int dimensionZ, int dimensionX, int dimensionY);

  private:
};

extern Scrolly_MultiArrays ma;
#endif
