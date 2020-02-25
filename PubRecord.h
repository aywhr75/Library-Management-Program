#ifndef SDDS_PUBRECORD_H
#define SDDS_PUBRECORD_H

#include <iostream>
#include "ReadWriteable.h"
#include "Date.h"

using namespace std;

namespace sdds{
const int SDDS_CONSOLE = 1;
const int SDDS_FILE = 2;
const int SDDS_NAME_MAX_LEN = 40; 

class PubRecord : public ReadWriteable{
    char* pubName;
    int shelfnum;
    int media;
protected:
    void name(const char*); 
    char* name()const; 
    void shelfNo(int); 
public:
    PubRecord(); 
    PubRecord(const PubRecord&); 
    virtual ~PubRecord(); 
    PubRecord& operator=(const PubRecord&); 
    void mediaType(const int); 
    int mediaType()const; 
    int shelfNo() const; 
    istream& readShelfNo(istream& is = cin); 
    bool operator==(char)const; 
    bool operator==(const char*)const; 
    operator bool()const; 
    
    virtual void checkIn() = 0;
    virtual void checkOut() = 0;
    virtual char recID()const = 0;
};
}
#endif
