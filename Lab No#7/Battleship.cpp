#pragma once
#include "Battleship.h"
#include <iostream>
#include <ctime>
#include <cstdlib>



BattleShips::BattleShips()
    {
    ClearGrid();
    }

void Boards::setColor(int newColor) 
    {
    color = newColor;
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

void BattleShips::setShips(bool isPlayer) 
{
    int ships = 0;

    while (ships < maximumShips) 
        {
        int xPos, yPos;
        char direction;

        if (isPlayer) 
            {
            // For player, allow manual input for XY coordinate and direction
            std::cout << "Enter the position for your ship " << ships + 1 << " (x y): ";
            std::cin >> xPos >> yPos;

            std::cout << "Enter the direction for your ship (H for horizontal, V for vertical): ";
            std::cin >> direction;
            }
        else 
            {
            // For computer, generate random positions and directions
            xPos = rand() % 10;
            yPos = rand() % 10;
            direction = (rand() % 2 == 0) ? 'H' : 'V'; // Randomly choose horizontal or vertical
            }

        // Check if the ship can be placed at the chosen position and direction

        if (isValidPlacement(xPos, yPos, direction)) 
            {
            placeShip(xPos, yPos, direction);
            ships++;
            }
        else 
            {
            std::cout << "Invalid placement. Try again." << std::endl;
            }
        }
    }

bool BattleShips::isValidPlacement(int xPos, int yPos, char direction) 
{
    if (xPos < 0 || xPos >= rows || yPos < 0 || yPos >= columns) {
        return false;
    }

    // Check if the ship exceeds the grid boundaries in the chosen direction
    if ((direction == 'H' && yPos + maximumShips > columns) ||
        (direction == 'V' && xPos + maximumShips > rows)) 
        {
        return false;
        }

    // Check for collisions with existing ships
    for (int i = 0; i < maximumShips; ++i) 
        {
        if (direction == 'H' && matrix[xPos][yPos + i] == 1) 
            {
            return false; // Collision in the horizontal direction
            }
        if (direction == 'V' && matrix[xPos + i][yPos] == 1) 
            {
            return false; // Collision in the vertical direction
            }
        }

    // If all checks pass, the placement is valid
    return true;
    }
 

void BattleShips::placeShip(int xPos, int yPos, char direction) 
    {
    //Place the ship on the grid
        for (int i = 0; i < maximumShips; ++i) 
            {
            if (direction == 'H') 
                {
                matrix[xPos][yPos + i] = 1; // Place the ship horizontally
                }
            else if (direction == 'V') 
                {
                matrix[xPos + i][yPos] = 1; // Place the ship vertically
                }
            }
        matrix[xPos][yPos] = 1;
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
    std::cout << "  0 1 2 3 4 5 6 7 8 9" << std::endl;

    // Set color using ANSI escape codes
    std::cout << "\033[38;5;" << color << "m";

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

    // Reset color to default
    std::cout << "\033[0m";
}
    
   
        
