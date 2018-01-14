/*********************************************************************
** Author: Tso-Yi (Joe) Chung
** Date: Nov/24/2017
** Description: class functions for LibraryItem.hpp
*********************************************************************/

#include "LibraryItem.hpp"

using namespace std;

LibraryItem::LibraryItem(string idc, string t)
	: idCode(idc), title(t), location(ON_SHELF), checkedOutBy(NULL),
	requestedBy(NULL), dateCheckedOut(0) {}

string LibraryItem::getIdCode() 
{
	return idCode;
}

string LibraryItem::getTitle() 
{
	return title;
}

Locale LibraryItem::getLocation() 
{
	return location;
}

void LibraryItem::setLocation(Locale l) 
{
	location = l;
}

Patron* LibraryItem::getCheckedOutBy() 
{
	return checkedOutBy;
}

void LibraryItem::setCheckedOutBy(Patron *p) 
{  
	checkedOutBy = p;
}

Patron* LibraryItem::getRequestedBy() 
{
	return requestedBy;
}

void LibraryItem::setRequestedBy(Patron *p) 
{
	requestedBy = p;
}

int LibraryItem::getDateCheckedOut() 
{
	return dateCheckedOut;
}

void LibraryItem::setDateCheckedOut(int date) 
{
	dateCheckedOut = date;
}
