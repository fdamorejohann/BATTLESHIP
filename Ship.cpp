
#include "PointCollection.h"
#include <iostream>
#include "Ship.h"
#include "Point.h"

using namespace std;

int Ship :: shipsLeft = 4;

Ship :: Ship()
{}

void Ship :: enterShip(point originPoint, direction o, int l) 
{
  PointCollection * s = new PointCollection;
  PointCollection * q = new PointCollection;
  origin =  originPoint;
  orientation = o;
  length = l;
  points =  s;
  hits = q;
}

Ship::Ship(const Ship& s) 
{

}


void Ship :: setUp()
{
    hit = 0;
    int * z;
  z = new int;
  if (orientation ==  VERTICAL)
  {
    *z = origin.getY();
    for (int i = 0; i < length; i++)
    {
      origin.setY(*z);
      *z = origin.getY() + 1;
      points -> add(origin);

    }
  }
  if (orientation ==  HORIZONTAL)
  {
    *z = origin.getX();
    for (int i = 0; i < length; i++)
    {
      origin.setX(*z);
      *z = origin.getX() + 1;
      points -> add(origin);

    }
  }
  cout << endl;
}

bool Ship::shotFiredAtPoint(point p)
{
  for (int i = 0; i < length; i++)
  {
    if (p == points->get(i))
    {
      if(isHitAtPoint(p) == false)
      {
        hits -> add(p);
        hitCount();
        return true;
      }        
      else
        return false;
    }          
  }
  return false;
}

bool Ship::isHitAtPoint(point p)
{
  for (int i = 0; i < length; i++)
  {
    if (p.getX() ==  hits -> getpointX(i) && p.getY() == hits -> getpointY(i))
    {
      cout << "you already hit that point.\n";
      return true;
    }
  }
return false;
}



void Ship::hitCount()
{
  hit ++;
  if (isSunk())
  {
    cout << "YOU SANK A SHIP OF LENGTH " << length << ".\n";
    shipsLeft = shipsLeft - 1;
  }
}


const Ship& Ship::operator=(const Ship& s)
{
	return *this;
}


bool Ship::isSunk() 
{
	if (length == hit)
	  return true;
	 else 
	  return false;
}

bool Ship :: ifItCollides(point q, bool & collidesWith, direction horv, int pointlength)
{
  if (horv == HORIZONTAL)
  {
    for (int i = 0; i < pointlength; i++)
    {
      for (int l = 0; l < length; l++)
      {
        if (q.getX() + i == points -> getpointX(l) && q.getY()== points -> getpointY(l))
        return true;
      }
    }
    return false;
  }

  if (horv == VERTICAL)
  {
    for (int i = 0; i < pointlength; i++)
    {
      for (int l = 0; l < length; l++)
      {
        if (q.getX() == points -> getpointX(l) && q.getY() + i == points -> getpointY(l))
          return true;
      }
    }
    return false;
  }
  else 
    return false;
}

Ship :: ~Ship()
{
  delete points;
  delete hits;
}

int Ship :: getshipsLeft()
{
  return shipsLeft;
}


void Ship :: printLocations()
{
      for (int i = 0; i < length; i++)
    {

      cout << points -> getpointX(i) << points -> getpointY(i) << endl;
    }
  
}
