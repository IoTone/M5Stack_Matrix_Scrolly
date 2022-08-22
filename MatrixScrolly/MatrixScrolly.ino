#include "M5Atom.h"
#include "Scrolly.h"

#define MAX_MESSAGES        9
Scrolly s(5, 5, 100, 5, 3); // displWidth, displHeight, buffWidth, buffHeight, BuffCols
float x = 0;
int idx = 0;

char * messages[MAX_MESSAGES] = {
  "Camp Synthesis",
  "DJ Dreams Coming True",
  "The Bar Is Open",
  "The Bar Is Closed",
  "SUSHI BAR 6-8",
  "SOBA BAR 6-8",
  "SAKE BAR 6-9",
  "Burning Man 2022",
  "Last Year Was Better"
};

FontColor colors[MAX_MESSAGES] = {
  { .r = 128, .g = 128, .b = 255 },
  { .r = 255, .g = 0, .b = 255 },
  { .r = 255, .g = 0, .b = 0 },
  { .r = 0, .g = 255, .b = 0 },
  { .r = 0, .g = 0, .b = 255 },
  { .r = 128, .g = 128, .b = 255 },
  { .r = 128, .g = 128, .b = 128 },
  { .r = 100, .g = 100, .b = 255 },
  { .r = 200, .g = 200, .b = 0 }
};

void setup() {
  M5.begin(true, true, true);
  /*s.setColor(128, 128, 255);
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
  */
  s.setColor(colors[idx].r, colors[idx].g, colors[idx].b);
  s.print("%s", messages[idx]);
}

void loop() {
  M5.update();
  if (M5.Btn.wasPressed()) {
    s.smoothScroll(!s.getSmoothScroll());
  }
  if (M5.Btn.wasReleased()) {
    idx++;
    if (idx >= MAX_MESSAGES) {
      idx = 0;
    }
    s.clear();
    s.setColor(colors[idx].r, colors[idx].g, colors[idx].b);
    s.print("%s", messages[idx]);
  }
  s.update();
  s.show();
}
