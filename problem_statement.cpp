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

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    int getZ() {
        return z;
    }

    string getDirection() {
        return dir;
    }
    
};
int main(){
    Chandrayaan chandrayaan3;
    string commands = "frubl";
    for (char command : commands) {
        if (command == 'f' || command == 'b') chandrayaan3.move(command);
        else if (command == 'l' || command == 'r') chandrayaan3.turn(command);
        else if (command == 'u' || command == 'd') chandrayaan3.angle(command);
    }

    cout << "Final Position: (" << chandrayaan3.getX() << ", " << chandrayaan3.getY() << ", " << chandrayaan3.getZ() << ")\n";
    cout << "Final Direction: " << chandrayaan3.getDirection() << "\n";
    
    return 0;
}

// TO check the test cases for various angle:

// void runTests() {
//     Chandrayaan chandrayaan3;

//     // Test move
//     chandrayaan3.move('f');
//     if (chandrayaan3.getX() == 0 && chandrayaan3.getY() == 1 && chandrayaan3.getZ() == 0)
//         cout << "Move test passed\n";
//     else
//         cout << "Move test failed\n";

//     // Test turn
//     chandrayaan3.turn('r');
//     if (chandrayaan3.getDirection() == "E")
//         cout << "Turn test passed\n";
//     else
//         cout << "Turn test failed\n";

//     // Test angle
//     chandrayaan3.angle('u');
//     if (chandrayaan3.getDirection() == "Up")
//         cout << "Angle test passed\n";
//     else
//         cout << "Angle test failed\n";
// }

