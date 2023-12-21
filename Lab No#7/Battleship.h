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
    void setShips();
    bool Attack(int _x, int _y);
    };

class Boards 
    {

    public:
    void SetGridColor(int color);
    void MakeBoards();
    void updateBoards(bool i, int x, int y);
    void PrintBoards();
    static const int rows = 10;
    static const int columns = 10;
    char grid[rows][columns];
    };

#endif // BATTLESHIP_H

