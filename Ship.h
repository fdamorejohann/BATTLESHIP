//
//  Ship.h
//  Battleship
//

#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include "Point.h"
#include "PointCollection.h"

enum direction { HORIZONTAL, VERTICAL};

class Ship
{
  private:
    int length;
    point origin;
    int hit;

  public:
    Ship();
    static int shipsLeft;
    static int getshipsLeft();
    PointCollection * points;
    PointCollection * hits;
    direction orientation;
    //constructors
    ~Ship();
    void enterShip(point originPoint, direction orientationDirection, int lengthValue);
    Ship(const Ship& s);
    
    void setUp();
    void printLocations();
    bool shotFiredAtPoint(point p);
    bool isHitAtPoint(point p);
    void hitCount();
    
    bool ifItCollides(point q, bool &, direction , int);
    
    const Ship& operator=(const Ship& s);

    bool isSunk();

};

#endif
