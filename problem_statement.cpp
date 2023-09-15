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

    void move(char instruction) {
        if (instruction == 'f') {
            if (dir == "N") y += 1;
            else if (dir == "S") y -= 1;
            else if (dir == "E") x += 1;
            else if (dir == "W") x -= 1;
            else if (dir == "Up") z += 1;
            else if (dir == "Down") z -= 1;
            
        } else if (instruction == 'b') {
            if (dir == "N") y -= 1;
            else if (dir == "S") y += 1;
            else if (dir == "E") x -= 1;
            else if (dir == "W") x += 1;
            else if (dir == "Up") z -= 1;
            else if (dir == "Down") z += 1;
        }
    }

    void turn(char instruction) {
        if (instruction == 'l') {
            dir = changingDir[dir][0];
        } else if (instruction == 'r') {
            dir = changingDir[dir][1];
        }
    }

    void angle(char instruction) {
        if (instruction == 'u') {
            if (dir == "N" || dir == "S") dir = "Up";
            else if (dir == "Up") dir = "S";
            else if (dir == "Down") dir = "N";
        
        } else if (instruction == 'd') {
            if (dir == "N" || dir == "S") dir = "Down";
            else if (dir == "Up") dir = "N";
            else if (dir == "Down") dir = "S";
        }
    }
    
};
int main(){

  return 0;
}
