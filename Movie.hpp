/*********************************************************************
** Author: Tso-Yi (Joe) Chung
** Date: Nov/24/2017
** Description: Header file for Movie
*********************************************************************/
#ifndef MOVIE_HPP
#define MOVIE_HPP

#include "LibraryItem.hpp"

using namespace std;

class Movie : public LibraryItem 
{
	private:
		string director;
	public:
		static const int CHECK_OUT_LENGTH = 7;

		Movie(string idc, string t, string d);
		string getDirector();
		int getCheckOutLength();
};

#endif
