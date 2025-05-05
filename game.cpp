#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

const int rows = 10;
const int cols = 20;

const char maze[rows][cols + 1] = {
    "********************",
    "*S                *",
    "* *****  ******** *",
    "* *   *  *        *",
    "* * * *  * ****** *",
    "* * * *  * *      *",
    "* *     ** ****** *",
    "* ********     G  *",
    "*                  *",
    "********************",
};

int playerX, playerY;
int goalX, goalY;

void gotoxy(int x, int y) {
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void displayMaze() {
    system("cls");
    for (int i = 0; i < rows; i++) {
        cout << maze[i] << endl;
    }

    // Print the player at their current position
    gotoxy(playerX, playerY);
    cout << "P";
}

void movePlayer(int dx, int dy) {
    char nextCell = maze[playerY + dy][playerX + dx];

    if (nextCell != '*' && nextCell != '-') {
        // Clear the current player position
        gotoxy(playerX, playerY);
        cout << " ";

        // Update player position
        playerX += dx;
        playerY += dy;

        // Display the player in the new position
        gotoxy(playerX, playerY);
        cout << "P";

        // Check if the player reached the goal
        if (playerX == goalX && playerY == goalY) {
            gotoxy(0, rows + 1); // Move cursor below the maze
            cout << "🎉 Congratulations! You reached the goal!\n";
            system("pause");
            exit(0);
        }
    }
}

int main() {
    // Find starting (S) and goal (G) positions
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (maze[i][j] == 'S') {
                playerX = j;
                playerY = i;
            } else if (maze[i][j] == 'G') {
                goalX = j;
                goalY = i;
            }
        }
    }

    displayMaze();

    while (true) {
        char move = _getch(); // Get the key pressed
        switch (move) {
            case 'w': movePlayer(0, -1); break;
            case 's': movePlayer(0, 1); break;
            case 'a': movePlayer(-1, 0); break;
            case 'd': movePlayer(1, 0); break;
            case 'q': exit(0); break;
        }
    }

    return 0;
}
