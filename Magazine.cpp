/***********************************************************************
// Name            Date            Section         Student ID
// YoungA Lee    Dec 7, 2019        NDD            048417083
//
// OOP244 MS4
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include "Magazine.h"
#include "Utils.h"

using namespace std;

namespace sdds{
Magazine::Magazine(): PubRecord(){
    volume = 0;
    issue = 0;
}
Magazine::Magazine(Magazine& _magaz): PubRecord(_magaz){
    volume = _magaz.volume;
    issue = _magaz.issue;
}
Magazine& Magazine::operator=(const Magazine& _magaz){
    PubRecord::operator=(_magaz);
    volume = _magaz.volume;
    issue = _magaz.issue;
    return *this;
}
char Magazine::recID()const{
    return 'M';
}
void Magazine::checkIn(){
    cout << "Magazines cannot be checked in or out!" << endl;
}
void Magazine::checkOut(){
    cout << "Magazines cannot be checked in or out!" << endl;
}
istream& Magazine::read(istream& is){
    char temp_name[SDDS_NAME_MAX_LEN + 1];
    if(mediaType() == SDDS_CONSOLE){
        cout << "Magazine Name: ";
        readchar(temp_name, SDDS_NAME_MAX_LEN, "Magazine name too long, Enter again: ", is);
        name(temp_name);
        cout << "Volume: ";
        readnum(volume, MAX_NUM, MIN_NUM, "Invalid Volume number, Enter again: ", is);
        cout << "Issue: ";
        readnum(issue, MAX_NUM, MIN_NUM, "Invalid Issue number, Enter again: ", is);
        cout << "Shelf Number: ";
        readShelfNo(is);
        is.clear();
        is.ignore(200, '\n');
    }else if(mediaType() == SDDS_FILE){
        is.getline(temp_name, SDDS_NAME_MAX_LEN, '\t');
        name(temp_name);
        is >> volume >> issue;
        readShelfNo(is);
        is.ignore();
    }
    return is;
}
ostream& Magazine::write(ostream& os)const{
    if(mediaType() == SDDS_CONSOLE){
        //os.setf(ios::left);
        os << setw(41) << left << name();
        os.unsetf(ios::left);
        os << "       " << setw(2) << setfill('0') << right << volume << '('
        << setw(2) << setfill('0') << right << issue << ")" << "  " << shelfNo() << setfill(' '); 
    }else if(mediaType() == SDDS_FILE){
        os << recID() << name() << '\t' << volume << '\t' << issue
        << '\t' << shelfNo() << endl;
    }
    return os;
}
}
