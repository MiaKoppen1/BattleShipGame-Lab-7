#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <string>

class Ship {
protected:
    std::string name;
    int size;
    char symbol;

public:
    Ship(const std::string& shipName, int shipSize, char shipSymbol);

    std::string getName() const;
    int getSize() const;
    char getSymbol() const;
};

class Carrier : public Ship {
public:
    Carrier();
};

class Battleship : public Ship {
public:
    Battleship();
};

class Cruiser : public Ship {
public:
    Cruiser();
};

class Submarine : public Ship {
public:
    Submarine();
};

class Destroyer : public Ship {
public:
    Destroyer();
};

class Ships {
private:
    Carrier carrier;
    Battleship battleship;
    Cruiser cruiser;
    Submarine submarine;
    Destroyer destroyer;

public:
    Ships();

    const Carrier& getCarrier() const;
    const Battleship& getBattleship() const;
    const Cruiser& getCruiser() const;
    const Submarine& getSubmarine() const;
    const Destroyer& getDestroyer() const;
};

class BattleshipGrid {
private:
    static const int rows = 10;
    static const int columns = 10;
    char grid[rows][columns];
    std::string gridColor;
    Ships ships;

public:
    BattleshipGrid();

    void setGridColor(const std::string& color);
    void displayGrid();
};

#endif // GRID_H
