#include <iostream>
#include <cstring>
#include "Utils.h"

using namespace std;

namespace sdds{
istream& readchar(char* str, int len, const char* errorCode, istream& is){

	bool ok = true;
	do {
		ok = false;
		is.getline(str, len + 1, '\n');
		if (is.fail()) {
			is.clear();
			is.ignore(500, '\n');
			cout << errorCode;
			ok = true;
		}
	} while (ok);
	return is;
}

void keyboardclear(istream& is) {
	if (is.fail()) {
		is.clear();
		is.ignore(1000, '\n');
	}
}
}
