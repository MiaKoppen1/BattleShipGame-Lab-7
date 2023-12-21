#pragma once
#ifndef BATTLESHIP_H
#define BATTLESHIP_H

class BattleShips 
    {
    public:
    static const int maximumShips = 5;
    static const int rows = 10;
    static const int columns = 10;
    int matrix[rows][columns];
    BattleShips();
    void ClearGrid();
    void ShowGrid();
    int numberOfShips();
    void setShips(bool isPlayer);
    bool Attack(int _x, int _y);
    bool isValidPlacement(int xPos, int yPos, char direction);
    void placeShip(int xPos, int yPos, char direction);
    };

class Boards 
    {
    public:
    int color;
    void MakeBoards();
    void updateBoards(bool i, int x, int y);
    void PrintBoards();
    void setColor(int newColor); // New method to set the color
    static const int rows = 10;
    static const int columns = 10;
    char grid[rows][columns];
    };

#endif // BATTLESHIP_H

