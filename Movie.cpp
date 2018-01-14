/*********************************************************************
** Author: Tso-Yi (Joe) Chung
** Date: Nov/24/2017
** Description: class functions for Movie.hpp
*********************************************************************/
#include "Movie.hpp"

using namespace std;

Movie::Movie(string idc, string t, string d) : LibraryItem(idc, t), director(d) {}

string Movie::getDirector() 
{
	return director;
}

int Movie::getCheckOutLength() 
{
	return CHECK_OUT_LENGTH;
}

