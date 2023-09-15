#include <bits/stdc++.h>
using namespace std;

class Chandrayaan {
private:
    struct Position {
        int x, y, z;
    };

    Position position;
    vector<string> directions;
    string currentDirection;

public:
    Chandrayaan() : position({0, 0, 0}), directions({"N", "E", "S", "W", "Up", "Down"}), currentDirection("N") {}

    void moveForward() {
        switch (currentDirection[0]) {
            case 'N':
                position.y++;
                break;
            case 'E':
                position.x++;
                break;
            case 'S':
                position.y--;
                break;
            case 'W':
                position.x--;
                break;
            case 'U':
                position.z++;
                break;
            case 'D':
                position.z--;
                break;
        }
    }

    void moveBackward() {
        switch (currentDirection[0]) {
            case 'N':
                position.y--;
                break;
            case 'E':
                position.x--;
                break;
            case 'S':
                position.y++;
                break;
            case 'W':
                position.x++;
                break;
            case 'U':
                position.z--;
                break;
            case 'D':
                position.z++;
                break;
        }
    }

    void turnLeft() {
        if (currentDirection == "N")  currentDirection = "W";
        else if (currentDirection == "E")  currentDirection = "N";
        else if (currentDirection == "S")  currentDirection = "E";
        else if (currentDirection == "W")  currentDirection = "S";
        else if (currentDirection == "Up")  currentDirection = "N";
        else if (currentDirection == "Down")  currentDirection = "N";
    }

    void turnRight() {
        if (currentDirection == "N") currentDirection = "E";
        else if (currentDirection == "E") currentDirection = "S";
        else if (currentDirection == "S") currentDirection = "W";
        else if (currentDirection == "W") currentDirection = "N";
        else if (currentDirection == "Up") currentDirection = "N";
        else if (currentDirection == "Down") currentDirection = "N";
    }

    void turnUp() {
        if (currentDirection != "Up" && currentDirection != "Down")
            currentDirection = "Up";
    }

    void turnDown() {
        if (currentDirection != "Up" && currentDirection != "Down")
            currentDirection = "Down";
    }

    void executeCommands(const vector<char>& commands) {
        for (char command : commands) {
            switch (command) {
                case 'f':
                    moveForward();
                    break;
                case 'b':
                    moveBackward();
                    break;
                case 'l':
                    turnLeft();
                    break;
                case 'r':
                    turnRight();
                    break;
                case 'u':
                    turnUp();
                    break;
                case 'd':
                    turnDown();
                    break;
                default:
                    // Invalid command, ignore it
                    break;
            }
            cout << '"' << command << "\" - (" << position.x << ", " << position.y << ", " << position.z << ") - " << currentDirection << endl;
        }
    }

    pair<Position, string> finalPosition() {
        return {position, currentDirection};
    }
};

int main() {
    Chandrayaan chandrayaan3;
    vector<char> commands = {'f', 'r', 'u', 'b', 'l'};
    
    cout << "Initial Direction: " << chandrayaan3.finalPosition().second << endl;

    chandrayaan3.executeCommands(commands);
    auto finalState = chandrayaan3.finalPosition();
    
    cout << "Final Position: (" << finalState.first.x << ", " << finalState.first.y << ", " << finalState.first.z << ")" << endl;
    cout << "Final Direction: " << finalState.second << endl;

    return 0;
}
