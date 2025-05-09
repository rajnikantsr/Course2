#include <iostream>
#include <conio.h>  // For _kbhit() and _getch()
#include <windows.h>
#include <ctime>

using namespace std;

#define MAX_LENGTH 1000  // Defines max length of snake

// Directions
const char DIR_UP = 'U';
const char DIR_DOWN = 'D';
const char DIR_LEFT = 'L';
const char DIR_RIGHT = 'R';

// Width and Height of Console
int consoleWidth = 40, consoleHeight = 20; // Fixed screen size

struct Point {
    int xCoord, yCoord;
    Point() : xCoord(0), yCoord(0) {}
    Point(int x, int y) : xCoord(x), yCoord(y) {}
};

class Snake {
    int length;
    char direction;
public:
    Point body[MAX_LENGTH];

    Snake(int x, int y) {
        length = 1;
        body[0] = Point(x, y);
        direction = DIR_RIGHT;
    }

    int getLength() {
        return length;
    }

    void changeDirection(char newDirection) {
        if ((newDirection == DIR_UP && direction != DIR_DOWN) ||
            (newDirection == DIR_DOWN && direction != DIR_UP) ||
            (newDirection == DIR_LEFT && direction != DIR_RIGHT) ||
            (newDirection == DIR_RIGHT && direction != DIR_LEFT)) {
            direction = newDirection;
        }
    }

    bool move(Point food) {
        for (int i = length - 1; i > 0; i--) {
            body[i] = body[i - 1];
        }

        switch (direction) {
            case DIR_UP:    body[0].yCoord--; break;
            case DIR_DOWN:  body[0].yCoord++; break;
            case DIR_RIGHT: body[0].xCoord++; break;
            case DIR_LEFT:  body[0].xCoord--; break;
        }

        // Check if snake bites itself
        for (int i = 1; i < length; i++) {
            if (body[0].xCoord == body[i].xCoord && body[0].yCoord == body[i].yCoord) {
                return false;
            }
        }

        // Check if snake hits the wall
        if (body[0].xCoord < 0 || body[0].xCoord >= consoleWidth ||
            body[0].yCoord < 0 || body[0].yCoord >= consoleHeight) {
            return false;
        }

        // Snake eats food
        if (food.xCoord == body[0].xCoord && food.yCoord == body[0].yCoord) {
            body[length] = body[length - 1];
            length++;
        }

        return true;
    }
};

class Board {
    Snake* snake;
    Point food;
    int score;

    const char SNAKE_BODY = 'o';
    const char FOOD = '*';

public:
    Board() {
        spawnFood();
        snake = new Snake(consoleWidth / 2, consoleHeight / 2);
        score = 0;
    }

    ~Board() {
        delete snake;
    }

    int getScore() {
        return score;
    }

    void spawnFood() {
        int x = rand() % consoleWidth;
        int y = rand() % consoleHeight;
        food = Point(x, y);
    }

    void gotoxy(int x, int y) {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

    void draw() {
        system("cls"); // Clear screen

        // Draw top border
        for (int i = 0; i < consoleWidth + 2; i++) cout << "#";
        cout << endl;

        for (int y = 0; y < consoleHeight; y++) {
            cout << "#";  // Left border
            for (int x = 0; x < consoleWidth; x++) {
                bool printed = false;
                
                // Draw snake
                for (int i = 0; i < snake->getLength(); i++) {
                    if (snake->body[i].xCoord == x && snake->body[i].yCoord == y) {
                        cout << SNAKE_BODY;
                        printed = true;
                        break;
                    }
                }

                // Draw food
                if (!printed && food.xCoord == x && food.yCoord == y) {
                    cout << FOOD;
                    printed = true;
                }

                if (!printed) cout << " ";
            }
            cout << "#" << endl;  // Right border
        }

        // Draw bottom border
        for (int i = 0; i < consoleWidth + 2; i++) cout << "#";
        cout << endl;

        // Display Score
        cout << "Current Score: " << score << endl;
        cout << "Press 'q' to quit" << endl;
    }

    bool update() {
        bool isAlive = snake->move(food);
        if (!isAlive) return false;

        if (food.xCoord == snake->body[0].xCoord && food.yCoord == snake->body[0].yCoord) {
            score++;
            spawnFood();
        }

        return true;
    }

    void getInput() {
        if (_kbhit()) {
            int key = _getch();
            if (key == 'w' || key == 'W') snake->changeDirection(DIR_UP);
            else if (key == 'a' || key == 'A') snake->changeDirection(DIR_LEFT);
            else if (key == 's' || key == 'S') snake->changeDirection(DIR_DOWN);
            else if (key == 'd' || key == 'D') snake->changeDirection(DIR_RIGHT);
            else if (key == 'q' || key == 'Q') exit(0);
        }
    }
};

int main() {
    srand(time(0));
    Board* board = new Board();

    while (board->update()) {
        board->getInput();
        board->draw();
        Sleep(150);
    }

    cout << "GAME OVER" << endl;
    cout << "Final Score: " << board->getScore() << endl;

    delete board;
    return 0;
}
