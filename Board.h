#include "PointCollection.h"
#include "Point.h"
#include "Ship.h"
#include <iostream>

using namespace std;
class Board
{
  
  public:
  Board() {}
  void createBoard(PointCollection* miss, PointCollection * hit)
  {
    string tile = " ~";
    for (int i = 10; i > 0; i --)
    {
      cout << "         ";
      if (i != 10)
      cout << " ";
      cout << i << "  ";
      for (int p = 1; p < 11; p++ )
      {
        tile = "  ~";
        water.setY(i);
        water.setX(p);
        for (int z = 0; z < miss->getSize(); z++)
        {
          if (water == miss->get(z))
          tile = "x";
        }
        for (int z = 0; z < hit->getSize(); z++)
        {
          if (water == hit->get(z))
          tile = "o";
        }
        if (tile == "  ~")
          color(3,36,0,tile); cout << " ";
        if (tile == "o")
        {
          color(5,33,0," o"); cout << " ";
        }
        if (tile == "x")
        {
          color(3,31,0," ~"); cout << " ";
        }
      }
      cout << endl << endl;
    }
    cout << "    ";color(0,33,0,"X"); cout <<"     0    1   2   3   4   5   6   7   8   9   10" << endl;
    cout << endl  << endl <<"          "; color(0,33,0,"Y"); cout << "                  ";
  }
  point water;
  
  void color(int f,int fg,int bg,string text)// f is for format
  {
    string fs = ""; //fs for format string
    string fgs = "";// fgs for foreground string
    string bgs = "";//bgs for background string

  switch(f)
  {
    case 0: fs = "0;";break;
    case 1: fs = "1;";break;
    case 2: fs = "2;";break;
    case 3: fs = "3;";break;
    case 4: fs = "4;";break;
    case 5: fs = "5;";break;
    case 6: fs = "6;";break;
    case 7: fs = "7;";break;
    case 8: fs = "8;";break;
    case 9: fs = "9;";break;
  }
  
  switch(fg)
  {
    case 0: fgs = "";break;
    case 30: fgs = "30";break;
    case 31: fgs = "31";break;
    case 32: fgs = "32";break;
    case 33: fgs = "33";break;
    case 34: fgs = "34";break;
    case 35: fgs = "35";break;
    case 36: fgs = "36";break;
    case 37: fgs = "37";break;
  }

  if(bg == 0)
  {
    cout << "\033[" << fs << fgs << "m" << text << "\033[m";
  }
  else
  {
    
    switch(bg)
    {
      case 40: bgs = "40";break;
      case 41: bgs = "41";break;
      case 42: bgs = "42";break;
      case 43: bgs = "43";break;
      case 44: bgs = "44";break;
      case 45: bgs = "45";break;
      case 46: bgs = "46";break;
      case 47: bgs = "47";break;
    }
      
    cout << "\033[" << fs << fgs << ";" << bgs << "m" << text << "\033[m";
  }
}
  
};
