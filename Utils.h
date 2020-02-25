#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

#include <iostream>

using namespace std;

namespace sdds{
istream& readchar(char* str, int maxLen, const char* errorCode, istream& is = cin);
void keyboardclear(istream& is = cin);
template <typename T>
istream& readnum(T& number, T max, T min, const char* errorCode, istream& is = cin){
    T temp;
    bool pass;
    do{
        pass = false;
        is >> temp;
        if(temp < min || temp > max || is.fail()){
            keyboardclear(is);
            cout << errorCode;
            pass = true;
        }
    }while(pass);
    number = temp;
    is.clear();
    is.ignore(200, '\n');
    return is;
}
}
#endif
