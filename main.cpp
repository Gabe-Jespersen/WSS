/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  main file of word search solver
 *
 *        Version:  1.0
 *        Created:  09/13/2014 11:12:21 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gabe Jespersen, gzackwebs@tfwno.gf
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <cstdlib>

#include "puzzle.h"
#include "utils.h"
#include "malgo.h"

using namespace std;

int main(int argc, char **argv)
{
    vector <vector <char> > board = {{ 't', 'e', 's', 'c'},
                                     { 't', 'i', 'n', 'l'},
                                     { 'g', 'i', 'o', 'n'},
                                     { 'q', 'g', 'w', 's'}};
    vector <vector <char> > words = {{ 'r', 'n', 'o', 'w'}};
    if(!isValid(board))
    {
        cout << "Input is not valid, see documentation\n\n";
        exit(1);
    }
    puzzle curPuzzle;
    curPuzzle.init(board.at(0).size(),board.size(),board);
    vector <vector <int> > solutions;
    solutions = solve(curPuzzle,words);
    cout << "Solutions, most likely fucked up:\n";
    for(int i = 0; i < solutions.size(); i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout << solutions.at(i).at(j) << endl;
        }
    }
    return 0;
}
