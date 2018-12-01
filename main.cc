#include <iostream>
#include <string>
#include "grid.h"
#include "cell.h"

using namespace std;

int main () {
  string s;
  Grid g;

  // Command interpreter
  while (cin >> s) {
    if (s == "new") {
        int i;
        cin >> i;
        g.init(i);
    }
    else if (s == "init") {
        int x, y;
        cin >> x;
        cin >> y;
        while (x != -1 && y != -1) {
            g.turnOn(y, x);
            cin >> x;
            cin >> y;
        }
    }
    else if (s == "step") {
        g.tick();
    }
    else if (s == "steps") {
        int steps;
        cin >> steps;
        for (int i = 0; i < steps; ++i) {
            g.tick();
        }
    }
    else if (s == "print") {
        cout << g;
    }
  }
}
