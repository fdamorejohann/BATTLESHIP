//FINNEGAN DAMORE JOHANN
//BATTLESHIP, MAY 7TH, 2018

#include "PointCollection.h"
#include "Point.h"
#include "Ship.h"
#include "Board.h"
#include <iostream>
#include <stdio.h>      
#include <stdlib.h>    
#include <time.h>  
using namespace std;

void getValues(int &, int & , int &, direction &);
void setdata(int &, int &, int &, direction &, point p);

int main() {
  srand (time(NULL));
  
  int x;
  int y;
  int length;
  bool collidesWith;
  direction horv;
  bool usedLaser = false;
  bool usedLaserX = false;
  point * origins = new point[4];
  Ship * ship = new Ship[4];
  Board board;
  PointCollection * miss = new PointCollection;
  PointCollection * hit = new PointCollection;
  
  getValues(x, y, length, horv);
 
  for(int u = 0; u < 4; u++)
  {
    do
    {
      collidesWith = false;
      getValues(x, y, length, horv);
      origins[u].setX(x);
      origins[u].setY(y);
      
      for (int i = 0; i < 3; i ++)
      {
        if(ship[i].ifItCollides(origins[u], collidesWith, horv, length) == true)
          collidesWith = true;
      }
    }
    
    while (collidesWith == true);
    ship[u].enterShip(origins[u], horv, length);
    ship[u].setUp();
    
  }

  cout << ("CHOOSE A COORDINATE TO STIKE DOWN ENEMY SHIPS WITH THE  POWER OF THE NAVY\n");

  cout <<("\n CONTROLS:\n");

  cout<<("enter coordinates with space between (EX: 1 1) \n");
  cout<<("enter coordinate followed by three zeros to target entire row (EX: 1 000)\ncan be used once per game\n");

  cout << endl;
  collidesWith = false;
  do
  {
    board.createBoard(miss,  hit);
    cin >> x; cin >> y;
    origins = new point(x,y);
    if (x == 111 & y == 111)
    {
      cout << endl;
      for (int i = 0; i < 4; i++)
      {
        ship[i].printLocations();
        cout << endl;
      }
    }
    else if (x == 111 & y == 111)
    {
    for (int i = 1; i < 11; i ++)
    {
      
      delete []origins;
      for (int z = 1; z < 11; z++)
      {
       collidesWith = false;
       x = i; y = z;
       origins = new point(x,y); 
      for (int p = 0; p < 4; p++)
    {
      if (ship[p].shotFiredAtPoint(*origins) == true)
        collidesWith = true;
    }
      if (collidesWith == true)
      hit->add(*origins);
       
       else
       miss->add(*origins);
      }
   }
    }  
      else if (y == 000 && usedLaser == false)
      {
      for (int i = 1; i < 11; i++)
      {
        delete []origins;
        y = i;
        origins = new point(x,y);
        collidesWith = false;
      for (int p = 0; p < 4; p++)
    {
      if (ship[p].shotFiredAtPoint(*origins) == true)
        collidesWith = true;
    }
      if (collidesWith == true)
      hit->add(*origins);
       
       else
       miss->add(*origins);
      }
        usedLaser = true;
      }
      
      else if (x == 000 && usedLaserX == false)
      {
      for (int i = 1; i < 11; i++)
      {
        delete []origins;
        x = i;
        origins = new point(x,y);
        collidesWith = false;
      for (int p = 0; p < 4; p++)
    {
      if (ship[p].shotFiredAtPoint(*origins) == true)
        collidesWith = true;
    }
      if (collidesWith == true)
      hit->add(*origins);
       
       else
       miss->add(*origins);
      }
        usedLaserX = true;
      }
      
    else{
    cout << endl << endl;
    collidesWith = false;
    for(int i = 1; i < 5; i++)
    {
      if (ship[i- 1].shotFiredAtPoint(*origins) == true)
        collidesWith = true;
        else
        {
          collidesWith = false;
        }
    }
   
    if(collidesWith == true)
    {
      board.color(7,32,41,"HIT");
      cout << endl;
      hit->add(*origins);
    }  
    else
    {
      board.color(7,32,41,"MISS");
      cout << endl; 
      miss->add(*origins);
    }
    delete []origins;
  }
  }
  while (ship[0].getshipsLeft()!= 0);
  cout << "YOU WIN\n";
  board.createBoard(miss,  hit);
}




void getValues(int &x, int & y, int & length, direction & horv)
{
  int z; int p; int q;
  p = 10;
  q = 10;
  z = rand() % 2 + 1;
  length = rand() % 4 + 2;
  if (z == 2)
  {
    horv = HORIZONTAL;
    q = 10 - length;
  }
  if ( z == 1)
  {
    horv = VERTICAL;
    p = 10 - length;
  }
  x = rand() % q + 1;
  y = rand() % p + 1;
}


/* CHOOSE A COORDINATE TO STIKE DOWN THE SOVIET SCUM WITH THE COMBINED FIERY WRATH OF THE US NAVY AND AIRFORCE
         10    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          9    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          8    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          7    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          6    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          5    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          4    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          3    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          2    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          1    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

    X     0    1   2   3   4   5   6   7   8   9   10


          Y                   1 4


MISS
         10    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          9    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          8    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          7    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          6    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          5    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          4    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          3    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          2    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          1    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

    X     0    1   2   3   4   5   6   7   8   9   10


          Y                   5 6


MISS
         10    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          9    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          8    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          7    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          6    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          5    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          4    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          3    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          2    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          1    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

    X     0    1   2   3   4   5   6   7   8   9   10


          Y                   10 3


HIT
         10    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          9    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          8    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          7    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          6    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          5    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          4    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          3    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          2    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          1    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

    X     0    1   2   3   4   5   6   7   8   9   10


          Y                   10 4


HIT
         10    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          9    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          8    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          7    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          6    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          5    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          4    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          3    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          2    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          1    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

    X     0    1   2   3   4   5   6   7   8   9   10


          Y                   10 6


HIT
         10    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          9    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          8    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          7    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          6    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          5    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          4    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          3    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          2    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          1    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

    X     0    1   2   3   4   5   6   7   8   9   10


          Y                   10 5


YOU SANK A SHIP OF LENGTH 4.
HIT
         10    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          9    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          8    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          7    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          6    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          5    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          4    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          3    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          2    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          1    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

    X     0    1   2   3   4   5   6   7   8   9   10


          Y                   10 4


you already hit that point.
MISS
         10    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          9    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          8    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          7    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          6    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          5    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          4    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          3    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          2    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          1    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

    X     0    1   2   3   4   5   6   7   8   9   10


          Y                   8 4


HIT
         10    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          9    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          8    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          7    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          6    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          5    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          4    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          3    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          2    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          1    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

    X     0    1   2   3   4   5   6   7   8   9   10


          Y                   8 6


HIT
         10    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          9    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          8    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          7    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          6    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          5    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          4    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          3    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          2    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          1    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

    X     0    1   2   3   4   5   6   7   8   9   10


          Y                   8 10


MISS
         10    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          9    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          8    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          7    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          6    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          5    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          4    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          3    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          2    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          1    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

    X     0    1   2   3   4   5   6   7   8   9   10


          Y                   9 8


MISS
         10    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          9    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          8    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          7    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          6    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          5    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          4    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          3    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          2    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          1    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

    X     0    1   2   3   4   5   6   7   8   9   10


          Y                   5 3


MISS
         10    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          9    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          8    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          7    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          6    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          5    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          4    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          3    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          2    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          1    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

    X     0    1   2   3   4   5   6   7   8   9   10


          Y                   8 5


YOU SANK A SHIP OF LENGTH 3.
HIT
         10    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          9    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          8    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          7    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          6    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          5    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          4    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          3    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          2    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          1    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

    X     0    1   2   3   4   5   6   7   8   9   10


          Y                   4 5


HIT
         10    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          9    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          8    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          7    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          6    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          5    ~   ~   ~   o   ~   ~   ~   o   ~   o 

          4    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          3    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          2    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          1    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

    X     0    1   2   3   4   5   6   7   8   9   10


          Y                   4 3


MISS
         10    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          9    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          8    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          7    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          6    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          5    ~   ~   ~   o   ~   ~   ~   o   ~   o 

          4    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          3    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          2    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          1    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

    X     0    1   2   3   4   5   6   7   8   9   10


          Y                   4 2


MISS
         10    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          9    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          8    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          7    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          6    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          5    ~   ~   ~   o   ~   ~   ~   o   ~   o 

          4    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          3    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          2    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          1    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

    X     0    1   2   3   4   5   6   7   8   9   10


          Y                   4 6


MISS
         10    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          9    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          8    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          7    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          6    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          5    ~   ~   ~   o   ~   ~   ~   o   ~   o 

          4    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          3    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          2    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          1    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

    X     0    1   2   3   4   5   6   7   8   9   10


          Y                   4 4


MISS
         10    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          9    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          8    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          7    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          6    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          5    ~   ~   ~   o   ~   ~   ~   o   ~   o 

          4    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          3    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          2    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          1    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

    X     0    1   2   3   4   5   6   7   8   9   10


          Y                   5 4


MISS
         10    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          9    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          8    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          7    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          6    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          5    ~   ~   ~   o   ~   ~   ~   o   ~   o 

          4    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          3    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          2    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          1    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

    X     0    1   2   3   4   5   6   7   8   9   10


          Y                   5 5


HIT
         10    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          9    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          8    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          7    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          6    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          5    ~   ~   ~   o   o   ~   ~   o   ~   o 

          4    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          3    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          2    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          1    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

    X     0    1   2   3   4   5   6   7   8   9   10


          Y                   6 5


HIT
         10    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          9    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          8    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          7    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          6    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          5    ~   ~   ~   o   o   o   ~   o   ~   o 

          4    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          3    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          2    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          1    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

    X     0    1   2   3   4   5   6   7   8   9   10


          Y                   7 5


YOU SANK A SHIP OF LENGTH 4.
HIT
         10    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          9    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          8    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          7    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          6    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          5    ~   ~   ~   o   o   o   o   o   ~   o 

          4    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          3    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          2    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          1    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

    X     0    1   2   3   4   5   6   7   8   9   10


          Y                   1 10


MISS
         10    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          9    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          8    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          7    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          6    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          5    ~   ~   ~   o   o   o   o   o   ~   o 

          4    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          3    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          2    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          1    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

    X     0    1   2   3   4   5   6   7   8   9   10


          Y                   1 5


HIT
         10    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          9    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          8    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          7    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          6    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          5    o   ~   ~   o   o   o   o   o   ~   o 

          4    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          3    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          2    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          1    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

    X     0    1   2   3   4   5   6   7   8   9   10


          Y                   1 6


HIT
         10    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          9    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          8    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          7    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          6    o   ~   ~   ~   ~   ~   ~   o   ~   o 

          5    o   ~   ~   o   o   o   o   o   ~   o 

          4    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          3    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          2    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          1    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

    X     0    1   2   3   4   5   6   7   8   9   10


          Y                   1 7


HIT
         10    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          9    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          8    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          7    o   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          6    o   ~   ~   ~   ~   ~   ~   o   ~   o 

          5    o   ~   ~   o   o   o   o   o   ~   o 

          4    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          3    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          2    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          1    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

    X     0    1   2   3   4   5   6   7   8   9   10


          Y                   1 9


HIT
         10    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          9    o   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          8    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          7    o   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          6    o   ~   ~   ~   ~   ~   ~   o   ~   o 

          5    o   ~   ~   o   o   o   o   o   ~   o 

          4    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          3    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          2    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          1    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

    X     0    1   2   3   4   5   6   7   8   9   10


          Y                   1 8


YOU SANK A SHIP OF LENGTH 5.
HIT
YOU WIN
         10    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          9    o   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          8    o   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          7    o   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          6    o   ~   ~   ~   ~   ~   ~   o   ~   o 

          5    o   ~   ~   o   o   o   o   o   ~   o 

          4    ~   ~   ~   ~   ~   ~   ~   o   ~   o 

          3    ~   ~   ~   ~   ~   ~   ~   ~   ~   o 

          2    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

          1    ~   ~   ~   ~   ~   ~   ~   ~   ~   ~ 

    X     0    1   2   3   4   5   6   7   8   9   10


          Y       
  */
