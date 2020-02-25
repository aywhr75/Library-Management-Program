#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>
#include "PubRecord.h"

using namespace std;

namespace sdds {

	const int MEMID_MIN = 10000;
	const int MEMID_MAX = 99999;
	const long long int ISBN_MIN = 1000000000000;
	const long long int ISBN_MAX = 9999999999999;

class Book : public PubRecord{
    long long int isbn;
    int id;
    Date due;
    
public:
    Book();
    Book(const Book&);           
    Book& operator=(const Book&);
    char recID()const;
    int memberId()const;
    void checkIn();
    void checkOut();
    istream& read(std::istream& is =cin);
    ostream& write(std::ostream& os = cout)const;
};
}
#endif

