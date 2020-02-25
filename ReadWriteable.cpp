/***********************************************************************
// Name            Date            Section         Student ID
// YoungA Lee    Nov 18, 2019        NDD            048417083
//
// OOP244 MS2
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "ReadWriteable.h"
using namespace std;

namespace sdds {
	istream& operator>> (istream& is, ReadWriteable& R){
		R.read(is);
		return is;
	}
	ostream& operator<< (ostream& os, const ReadWriteable& W){
		W.write(os);
		return os;
	}
}