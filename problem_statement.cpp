#include <bits/stdc++.h>
using namespace std;

class Chandrayaan {
private:
    int x, y, z;
    string dir;  // directions
    map<string, vector<string>> changingDir; 

public:
    Chandrayaan() : x(0), y(0), z(0), dir("N") {
        changingDir = {
            {"N", {"W", "E"}},
            {"S", {"E", "W"}},
            {"E", {"N", "S"}},
            {"W", {"S", "N"}},
            {"Up", {"Down", "Up"}},
            {"Down", {"Up", "Down"}}
        };
    }

   };
int main(){

  return 0;
}
