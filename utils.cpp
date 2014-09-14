/*
 * =====================================================================================
 *
 *       Filename:  utils.cpp
 *
 *    Description:  general utilities
 *
 *        Version:  1.0
 *        Created:  09/13/2014 11:31:37 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gabe Jespersen, gzackwebs@tfwno.gf
 *
 * =====================================================================================
 */

#include <vector>

#include "utils.h"

using namespace std;

bool isValid(vector <vector <char> > toCheck)
{
    unsigned int isLength = toCheck.at(0).size();
    for(unsigned int i = 1; i < toCheck.size(); i++) //checking from 1 because already
                                                     //checked 0, see: previous line
    {
        if(toCheck.at(i).size() != isLength)
            return false;
        for(int j = 0; j < isLength; j++)
        {
            if(toCheck.at(i).at(j)==255)
                return false;
        }
    }
    return true;
}

