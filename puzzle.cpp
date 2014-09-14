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
    return(charAt(x,y,0,0));
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
    vector<int> end = {-1,-1};//default, signifies no valid point found
    char error = 255;

    //this is really, really shitty, and really slow
    if(x<=0&&(dir==3||dir==7||dir==8)) //all of these are checking for invalid positions
        return end;
    if(y<=0&&(dir==1||dir==5||dir==7))
        return end;
    if(x>=(width-1)&&(dir==4||dir==5||dir==6))
        return end;
    if(y>=(height-1)&&(dir==2||dir==6||dir==8))
        return end;


    dist--; //because math 'n shit
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
            break;

        default:
            break;
    }
    return end;
}

char puzzle::charAt(int x, int y, int dir, int dist)
{
    vector <int> temp = posPDir(x,y,dir,dist+1);
    if(temp.at(0) == -1)//invalid, no situation it would have -1 for x and something
        return(255);    //else for y, at least as far as I know
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
