/*
 * =====================================================================================
 *
 *       Filename:  malgo.h
 *
 *    Description:  header file for malgo.cpp
 *
 *        Version:  1.0
 *        Created:  09/13/2014 03:21:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gabe Jespersen, gzackwebs@tfwno.gf
 *
 * =====================================================================================
 */

#include <vector>

#include "puzzle.h"

#ifndef MALGO_H
#define MALGO_H

std::vector< std::vector <int> > solve(puzzle,std::vector< std::vector <char> >);

#endif
