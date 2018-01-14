/*********************************************************************
** Author: Tso-Yi (Joe) Chung
** Date: Oct/27/2017
** Description: class functions for Album.hpp
*********************************************************************/
#include "Album.hpp"

using namespace std;

Album::Album(std::string idc, std::string t, std::string a) : LibraryItem(idc, t), artist(a) {}

string Album::getArtist() 
{
	return artist;
}

int Album::getCheckOutLength() 
{
	return CHECK_OUT_LENGTH;
}
