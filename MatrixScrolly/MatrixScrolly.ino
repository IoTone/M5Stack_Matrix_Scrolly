#include "M5Atom.h"
#include "Scrolly.h"

Scrolly s(5, 5, 100, 5, 3); // displWidth, displHeight, buffWidth, buffHeight, BuffCols
float x = 0;

void setup() {
  M5.begin(true, true, true);
  s.setColor(128, 128, 255);
  s.print(" TEST %i", 123);
  s.setColor(255, 0, 255);
  s.print(" ");
  s.print("A");
  s.setColor(255, 0, 0);
  s.print("B");
  s.setColor(0, 255, 0);
  s.print("C");
  s.setColor(0, 0, 255);
  s.print("D");
}

void loop() {
  M5.update();
  if (M5.Btn.wasPressed()) {
    s.smoothScroll(!s.getSmoothScroll());
  }
  s.update();
  s.show();
}
