#include <iostream>
#include <string>
#include "grid.h"
#include "cell.h"

using namespace std;

int main (int argc, char *argv[]) {
  int seed;
  for (int i = 1; i < argc; i = i + 1) {
     if (argv[0] = "-text") {
        // suggestion: probably add a field in the game class to control whether the graphic are shown
     } else if (argv[0] = "-seed") {
        seed = argv[i];
        i += 1;
        // suggestion: probably need to modify a random number 
     }
  } 
}
