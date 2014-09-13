/*
 * =====================================================================================
 *
 *       Filename:  malgo.cpp
 *
 *    Description:  main algorithm, solves the word search
 *
 *        Version:  1.0
 *        Created:  09/13/2014 03:20:44 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gabe Jespersen, gzackwebs@tfwno.gf
 *
 * =====================================================================================
 */

#include <vector>

#include "puzzle.h"
#include "malgo.h"

using namespace std;

vector <vector <int> > solve(puzzle toSolve, vector < vector <char> > words)
{
    int dir = 0;
    bool temp = false;
    vector< vector<int> > solutions;
    vector<int> temp1;

    //here's where shit hits the fan, this is highly open to change
    
    for(int x = 0; x < toSolve.getWidth() + 1; x++)
    {
        for(int y = 0; y < toSolve.getHeight() + 1; y++)
        {
            for(int word = 0; word < words.size(); word++)
            {
                if(words.at(word).at(0) == toSolve.pos(x,y))
                {
                    dir = 0;

                    for(int dirs = 1; dirs < 9; dirs++)
                    {
                        if(words.at(word).at(1) == toSolve.charAt(x,y,1,1))
                            dir = 1;
                        else if(words.at(word).at(1) == toSolve.charAt(x,y,2,1))
                            dir = 2;
                        else if(words.at(word).at(1) == toSolve.charAt(x,y,3,1))
                            dir = 3;
                        else if(words.at(word).at(1) == toSolve.charAt(x,y,4,1))
                            dir = 4;
                        else if(words.at(word).at(1) == toSolve.charAt(x,y,5,1))
                            dir = 5;
                        else if(words.at(word).at(1) == toSolve.charAt(x,y,6,1))
                            dir = 6;
                        else if(words.at(word).at(1) == toSolve.charAt(x,y,7,1))
                            dir = 7;
                        else if(words.at(word).at(1) == toSolve.charAt(x,y,8,1))
                            dir = 8;

                        if(dirs != 0)
                        {
                            for(int i = 2; i < words.at(word).size(); i++)
                            {
                                if(toSolve.charAt(x,y,dir,i) != words.at(word).at(i))
                                {
                                    temp = false;
                                    break;
                                }
                                if(temp)
                                {
                                    //shitty solution
                                    solutions.push_back(vector<int>());
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return(solutions);
}
