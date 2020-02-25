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
#include "Book.h"
#include "Date.h"
#include "Utils.h"

using namespace std;

namespace sdds{
    Book::Book():PubRecord(){
        isbn = 0;
        id =0;
    }
    Book::Book(const Book& _book):PubRecord(_book){
        isbn = _book.isbn;
        id = 0;
    }
    Book& Book::operator=(const Book& _book){
        PubRecord::operator=(_book);
        isbn = _book.isbn;
        id = 0;
        return *this;
    }
    char Book::recID()const{
        return 'B';
    }
    int Book::memberId()const{
        return id;
    }
    void Book::checkIn(){
        if(id != 0){
            id = 0;
            cout << setw(41) << left << name() 
				<< isbn << "  " << shelfNo() << " checked in!" << endl;
        }
    }
    void Book::checkOut(){
        Date day;
        cout << "Enter Member id: ";
        readnum(id, MEMID_MAX, MEMID_MIN, "Invalid Member ID, Enter again: ");
        bool pass;
        do{
			cout << "Enter return date: ";
            pass = false;
            cin >> due;
            if(due.errCode()){
                cout << due.dateStatus() << '.' << endl;
                pass = true;
            }else if(due < day || cin.fail()){
                keyboardclear(cin);
				cout << "Please enter a future date." << endl;
                pass = true;
            }
            if(!pass && (due - day) > 30){  
                cout << "The return date must be earlier than 30 days away from day." << endl;
                pass = true;
            }
        }while(pass);
    }
    istream& Book::read(istream& is){
        char temp_name[SDDS_NAME_MAX_LEN + 1];
        if(mediaType() == SDDS_CONSOLE){
            id = 0;
            cout << "Book Name: ";
            readchar(temp_name, SDDS_NAME_MAX_LEN, "Book name too long, Enter again: ", is);
            name(temp_name);
            cout << "ISBN: ";
            readnum(isbn, ISBN_MAX, ISBN_MIN, "Invalid ISBN, Enter again: ", is);
            cout << "Shelf Number: ";
            readShelfNo(is);
            is.clear();
            is.ignore(200, '\n');
        }else if(mediaType() == SDDS_FILE){
            is.getline(temp_name, SDDS_NAME_MAX_LEN, '\t');
            name(temp_name);
            is >> isbn;
            readShelfNo(is);
            is >> id;
            if(id)
                is >> due;
            is.ignore();
        }
        return is;
    }
    ostream& Book::write(ostream& os)const{
        if(mediaType() == SDDS_CONSOLE){
            os.setf(ios::left, ios::adjustfield);
            os << setw(41) << name();
            os << isbn << "  " << shelfNo();
            if(id)
                os << " " << id << "   " << due;
        }else if(mediaType() == SDDS_FILE){
            os << recID() << name() << '\t' << isbn << '\t' << shelfNo() << '\t' << id;
            if(id)
                os << '\t' << due;
            os << endl;
        }
        return os;
    }

}
