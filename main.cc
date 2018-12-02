#include <iostream>
#include <sstream>
#include <string>
#include "game.h"

using namespace std;

int main (int argc, char *argv[]) {
  Game game; // call the game constructor(implementation still absent from the game class)
  int seed;
  for (int i = 1; i < argc; i = i + 1) {
     if (argv[i] = "-text") {
        // suggestion: add a boolean field in the game class to control whether the graphic are shown
     } else if (argv[i] = "-seed") {
        istringstream readStr{argv[i+1]}; // since argv[i+1] is a string
        readStr >> seed;
        i += 1;
        srand(seed);
     }  else if (argv[i] = "-scriptfile1") {
        game.setFilename1(argv[i+1]);
        i += 1;
     }  else if (argv[i] = "-scriptfile2") {
        game.setFilename2(argv[i+1]);
        i += 1;
     }  else if  (argv[i] = "-startLevel") {
        int level;
        istringstream readStr{arg[i+1]};
        readStr >> level;
        game.setLevel(level);
     }
  } 
}
