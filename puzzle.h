/*
 * =====================================================================================
 *
 *       Filename:  puzzle.h
 *
 *    Description:  puzzle.cpp header file
 *
 *        Version:  1.0
 *        Created:  09/13/2014 11:15:45 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gabe Jespersen, gzackwebs@tfwno.gf
 *
 * =====================================================================================
 */

#include <vector>

#ifndef PUZZLE_H
#define PUZZLE_H

class puzzle
{
    private:
        short width;
        short height;
        std::vector <std::vector <char> > board; //counted from top left, array of L>R strings
    public:
        char pos(short,short);
        void init(short,short,std::vector <std::vector <char> >);
        std::vector <std::vector <char> > getBoard();
        std::vector <int> posPDir(int,int,int,int);
        char charAt(int,int,int,int);
        short getWidth();
        short getHeight();
};

#endif
