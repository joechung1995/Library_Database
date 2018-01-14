/*********************************************************************
** Author: Tso-Yi (Joe) Chung
** Date: Nov/24/2017
** Description: Header file for Album
*********************************************************************/
#ifndef ALBUM_HPP
#define ALBUM_HPP

#include "LibraryItem.hpp"

using namespace std;

class Album : public LibraryItem
{
	private:
		string artist;
	public:
		static const int CHECK_OUT_LENGTH = 14;

		Album(string idc, string t, string a);
		string getArtist();
		int getCheckOutLength();
};

#endif
