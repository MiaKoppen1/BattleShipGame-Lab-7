#pragma once
#include "Battleship.h"
#include <iostream>
#include <ctime>
#include <cstdlib>



BattleShips::BattleShips()
    {
    ClearGrid();
    }

void Boards::SetGridColor(int color)
{
    gridColor = color;
}
void BattleShips::ClearGrid() 
    {
    for (int y = 0; y < rows; y++) 
        {
        for (int x = 0; x < columns; x++) 
            {
            matrix[y][x] = 0;
            }
        }
    }

void BattleShips::ShowGrid() 
    {

    char coOrd = 'A'; // Initialize coOrd to 'A'
    std::cout << "   0 1 2 3 4 5 6 7 8 9" << std::endl;
    std::cout << "-----------------------" << std::endl;

    for (int x = 0; x < rows; x++) 
        {
        std::cout << coOrd << "| ";
        coOrd++;

        for (int y = 0; y < columns; y++)
            {
            std::cout << matrix[x][y] << " ";
            }
        std::cout << std::endl;
        }
    }

int BattleShips::numberOfShips()
    {
    int c = 0;
    for (int x = 0; x < rows; x++) 
        {
        for (int y = 0; y < columns; y++) 
            {
            if (matrix[x][y] == 1) 
                {
                c++;
                }
            }
        }
       return c;
    }

void BattleShips::setShips()    
    {
    int ships = 0;

    while (ships < maximumShips) 
        {
        int xPos = rand() % 10;
        int yPos = rand() % 10;

        if (matrix[xPos][yPos] != 1) 
            {
            ships++;
            matrix[xPos][yPos] = 1;
            }
        }
    }

bool BattleShips::Attack(int _x, int _y) 
    {
    if (matrix[_x][_y] == 1) 
        {
        matrix[_x][_y] = 2;
        return true;
        }
    else 
        {
        return false;
        }
    }

void Boards::MakeBoards() 
    {
    for (int x = 0; x < rows; x++) 
        {
        for (int y = 0; y < columns; y++) 
            {
            grid[x][y] = '-';
            }
        }
    }

void Boards::updateBoards(bool i, int x, int y) 
    {
    if (x >= 0 && x < rows && y >= 0 && y < columns)
        { // Check bounds to avoid array out-of-bounds access
        if (i) 
            {
            grid[x][y] = 'Y';
            }
        else 
            {
            grid[x][y] = 'N';
            }
        }
    }

void Boards::PrintBoards() 
    {
    int amt = 0;

    // Use ANSI escape codes for text color
    std::cout << "\033[" << gridColor << "m";  // Set text color

    std::cout << "  0 1 2 3 4 5 6 7 8 9" << std::endl;

    for (int x = 0; x < rows; x++) 
        {
        std::cout << amt << " ";
        amt++;

        for (int y = 0; y < columns; y++) 
         {
            std::cout << grid[x][y] << " ";
         }
        std::cout << std::endl;
        }

    // Reset text color to default
    std::cout << "\033[0m";
    }
