/*
 * =====================================================================================
 *
 *       Filename:  puzzle.cpp
 *
 *    Description:  puzzle class
 *
 *        Version:  1.0
 *        Created:  09/13/2014 11:13:35 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gabe Jespersen, gzackwebs@tfwno.gf
 *
 * =====================================================================================
 */

#include <vector>
#include <cstdlib>
#include <iostream>

#include "puzzle.h"

using namespace std;

char puzzle::pos(short x, short y)
{
    if(x>width||y>height)
    {
        cout << "Error, invalid position \(" << x << "," << y << ")" << endl;
        exit(1);
    }
    return((board.at(y)).at(x));
}

void puzzle::init(short toWidth, short toHeight, vector <vector <char> > toSet)
{
    width = toWidth;
    height = toHeight;
    board = toSet;
    return;
}

vector <vector <char> > puzzle::getBoard()
{
    return board;
}

vector <int> puzzle::posPDir(int x, int y, int dir, int dist)
{
    dist--;
    vector<int> end;
    switch(dir)
    {
        case 1:
            end = {x,y-dist};
            break;
        case 2:
            end = {x,y+dist};
            break;
        case 3:
            end = {x-dist,y};
            break;
        case 4:
            end = {x+dist,y};
            break;
        case 5:
            end = {x+dist,y-dist};
            break;
        case 6:
            end = {x+dist,y+dist};
            break;
        case 7:
            end = {x-dist,y-dist};
            break;
        case 8:
            end = {x-dist,y+dist};
        default:
            break;
    }
    if(x<0||y<0||!end.size())
    {
        cout << "Error, position out of range or invalid dir, details:\n" <<
                "x:\n\tbefore: " << x << "\n\tafter: " << end.at(0) <<
                "y:\n\tbefore: " << y << "\n\tafter: " << end.at(1) <<
                "direction(see documentation for details): " << dir <<
                "distance: " << dist << "\n\n";
        exit(1);
    }
    return end;
}

char puzzle::charAt(int x, int y, int dir, int dist)
{
    vector <int> temp = posPDir(x,y,dir,dist);
    return(board.at(temp.at(1)).at(temp.at(0)));
}

short puzzle::getWidth()
{
    return width;
}

short puzzle::getHeight()
{
    return height;
}
