
#include "Scrolly_MultiArrays.h"

Scrolly_MultiArrays::Scrolly_MultiArrays() {
}

short int** Scrolly_MultiArrays::make2DShortInt(int dimensionX, int dimensionY) {
  short int* values = (short int *)calloc(dimensionX * dimensionY, sizeof(short int));
  short int** rows = (short int **)malloc(dimensionY * sizeof(short int*));
  for (int col = 0; col < dimensionY; ++col) {
    rows[col] = values + col * dimensionX;
  }
  for (int x = 0; x <  dimensionX; x++)
    for (int y = 0; y < dimensionY; y++)
      rows[x][y] = 0;
  return rows;
}

short int*** Scrolly_MultiArrays::make3DShortInt(int dimensionZ, int dimensionX, int dimensionY) {
  short int ***p;
  p = (short int ***) malloc(dimensionZ * sizeof(short int **));
  for (int i = 0; i < dimensionZ; i++) {
    p[i] = (short int **)malloc(dimensionX * sizeof(short int *));
    for (int j = 0; j < dimensionX; j++)
      p[i][j] = (short int *)malloc(dimensionY * sizeof(short int));
  }
  for (int z = 0; z < dimensionZ; z++)
    for (int y = 0; y < dimensionY; y++)
      for (int x = 0; x < dimensionX; x++)
        p[z][x][y] = 0;
  return p;
}

void Scrolly_MultiArrays::destroy2DIntArray(int** arr) {
  free(*arr);
  free(arr);
}

void Scrolly_MultiArrays::destroy3DIntArray(int*** arr) {
  free(**arr);
  free(*arr);
  free(arr);
}

Scrolly_MultiArrays ma;
