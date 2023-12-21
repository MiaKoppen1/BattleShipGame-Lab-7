#pragma once
#include <iostream>
#include "Battleship.h"
#include "Grid.h"
#include <Windows.h>
#include <cstdlib>
#include <ctime>


int main() // this is what is run everytime the program starts
	{
	char rerun; // declares a char variable called rerun

	do
		{
		srand(static_cast<unsigned>(time(NULL)));

		BattleShips human;
		BattleShips cpu;

		Boards humanBoard;
		Boards cpuBoard;
		
		human.ClearGrid();
		human.setShips(true);

		cpu.ClearGrid();
		cpu.setShips(false);

		int chosenColor;
		std::cout << "Choose a color for your board (0-255): ";
		std::cin >> chosenColor;

		humanBoard.setColor(chosenColor);
		cpuBoard.setColor(160); // Set a default color for the CPU board

		humanBoard.MakeBoards();
		cpuBoard.MakeBoards();

		std::cout << "Your Board: " << std::endl;
		humanBoard.PrintBoards(); // prints the new boards
		std::cout << "CPU's Board" << std::endl;
		cpuBoard.PrintBoards();

		int position1, position2;
		char which;
		int found = 0;
		int toGo = 10;

		int cpuFound = 0;
		int cpuToGet = 10;
		bool isTrue;
		bool isTrueCpu;

		char option;
		int cpuX, cpuY; 
		while (found < 10 || cpuFound < 10) // loops while found is less than 10.
			{
			std::cout << "Options:\n";
			std::cout << "1. Fire\n";
			std::cout << "2. View User's Ship Grid\n";
			std::cout << "3. Surrender\n";
			std::cout << "Choose an option: ";
			std::cin >> option;

			switch (option)
				{
			case '1': //fire
			cpuX = rand() % 10; // makes a random integer between 0 and 9
			cpuY = rand() % 10;

			if (cpu.Attack(cpuX, cpuY))
				{
				isTrueCpu = true;
				cpuFound++;
				cpuToGet--;
				std::cout << "The Computer has found one of your battleships at: " << "(" << cpuX << ", " << cpuY << ")" << std::endl;
				}
			else
				{
				isTrueCpu = false;
				std::cout << "The Computer did not find a battleship this time" << std::endl;
				}

				// Update boards and display
				cpuBoard.updateBoards(isTrueCpu, cpuX, cpuY);
				std::cout << "CPU's Board" << std::endl;
				cpuBoard.PrintBoards();
				break;

			case '2': // View User's Ship Grid
				std::cout << "Your Ship Grid: " << std::endl;
				human.ShowGrid();
				break;

			case '3': // Surrender
				std::cout << "You surrendered. Game Over!" << std::endl;
				// Handle game over logic, update wins and losses
				break;

			default:
				std::cout << "Invalid option. Try again." << std::endl;
				break;
				}

			// Check for game over
			if (found == 10 || cpuFound == 10)
				{
				// Handle game over logic, update wins and losses
				break;
				}
			else 
				{
				isTrueCpu = false;
				std::cout << "The Computer did not find a battleship this time" << std::endl;
				}
			if (cpu.Attack(cpuX, cpuY)) // checks the boolean output of the Attack function for the cpu
				{
				isTrueCpu = true; // sets isTrueCpu to true
				cpuFound++; // increments cpuFound
				cpuToGet--; // decrements cpuToGet
				std::cout << "The Computer has found one of your battleships at: " << "(" << cpuX << ", " << cpuY << ")" << std::endl; // outputs the position that the cpu found a battleship at.
				}
			else // anything else
				{
				isTrueCpu = false; // sets isTrueCpu to false
				std::cout << "The Computer did not find a battleship this time" << std::endl; // outputs that the cpu did not find a battleship this time.
				}

				position1 = 11; // sets position1 and position2 to 11
				position2 = 11; // so that the while loop will initiate below

			while (position1 > 9 || position2 > 9) // loops while position1 is more than 9 OR position 2  is more than 9.
				{
				if (cpuFound == 10 || found == 10)
					{
					break;
					}
					std::cout << "Please input the location on the grid you think a battleship is: "; // prompts the user to enter co-ordinates.
					
					std::cin >> position1 >> position2; // takes the keyboard input and stores it in position 

				while (std::cin.fail()) // this will inintiate if the user enters a non integer input.
					{
					std::cin.clear(); // clears the std::cin.
					std::cin.ignore(); // ignores so it does not go in to an infinite loop
					std::cout << "not int, try again: "; std::cin >> position1 >> position2; // re prompts the user to enter their input
					}
				}

			if (human.Attack(position1, position2)) // checks if the boolean value for the Attack function is true
				{
				isTrue = true; // sets isTrue to true
				found++; // increments found
				toGo--; // decrements toGo
				std::cout << "You have found: " << found << " battleships, you have: " << toGo << " to go" << std::endl; // alerts the user of how many battleships they have found, and how many more they need to get.
				}
			else // anything else
				{
				isTrue = false; // sets isTrue to false
				std::cout << "there is no ship at that position, keep trying" << std::endl; // alerts the user that there is no ship in that position
				}

			std::cout << "There are: " << human.numberOfShips() << " left" << std::endl; // tells the user how many more ships there is
			std::cout << "would you like to surrender (y/n)?: "; std::cin >> which; // asks the user if they want to surrender and stores the input into char.

			system("CLS"); // clears the console to eliminate clutter

			humanBoard.updateBoards(isTrue, position1, position2); // updates the boards
			cpuBoard.updateBoards(isTrueCpu, cpuX, cpuY);

			std::cout << "Your Board: " << std::endl;
			humanBoard.PrintBoards(); // prints the new boards
			std::cout << "CPU's Board" << std::endl;
			cpuBoard.PrintBoards();

			if (which == 'y') // checks if which is equal to y
				{
				break; // breaks from the loop
				}
			else if (found == 10 || cpuFound == 10)
				{
				break;
				}

			}

		// this code is run when the loop is exited.

		std::cout << "Game Over!" << std::endl;
		std::cout << "your grid: " << std::endl;
		std::cout << "The number 2 represents ships that have been hit" << std::endl;
		human.ShowGrid();
		std::cout << "----------------------------------------------------" << std::endl;
		std::cout << "CPU's Grid" << std::endl;
		cpu.ShowGrid();

		std::cout << "Would you like to rerun, or exit (r/e)? "; std::cin >> rerun;
		} while (rerun == 'r' || rerun == 'R');

	return 0;
}
