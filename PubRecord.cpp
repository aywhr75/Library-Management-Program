/***********************************************************************
// Name            Date            Section         Student ID
// YoungA Lee    Dec 7, 2019        NDD            048417083
//
// OOP244 MS4
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "PubRecord.h"
#include "Utils.h"

using namespace std;

namespace sdds{
    void PubRecord::name(const char* _name){ 
        if(pubName != nullptr)
            delete [] pubName;
        if(_name == nullptr)
            pubName = nullptr;
        else{
            pubName = new char[strlen(_name) + 1];
            strcpy(pubName, _name);
        }
    }
    char* PubRecord::name()const{ 
        return pubName;
    }
        
    PubRecord::PubRecord(){ 
        pubName = nullptr;
        shelfnum = 0;
        media = SDDS_CONSOLE;
    }
    PubRecord::PubRecord(const PubRecord& pub){ 
        if(pub.pubName == nullptr)
            pubName = nullptr;
        else{
            pubName = new char[strlen(pub.pubName) + 1];
            strcpy(pubName, pub.pubName);
        }
        shelfnum = pub.shelfnum;
        media = pub.media;
    }
    PubRecord::~PubRecord(){
        if(pubName != nullptr)
            delete [] pubName;
    }
    PubRecord& PubRecord::operator=(const PubRecord& pub){ 
        if(pubName != nullptr)
            delete [] pubName;
        if(pub.pubName == nullptr)
            pubName = nullptr;
        else{
            int length = static_cast<int>(strlen(pub.pubName));
            pubName = new char[length + 1];
            strcpy(pubName, pub.pubName);
        }
        shelfnum = pub.shelfnum;
        media = pub.media;

        return *this;
    }
    void PubRecord::mediaType(const int _media){ 
        if(this != nullptr)
            media = _media;
    }
    int PubRecord::mediaType()const{ 
        return media;
    }
    int PubRecord::shelfNo() const{ 
        return shelfnum;
    }
    istream& PubRecord::readShelfNo(istream& is){ 
        int temp = 0;
        bool check;
        do{
            check = false;
            is >> temp;
            if(is.fail()){
                keyboardclear();
                cout << "Invalid Shelf Number, Enter again: ";
                check = true;
            }else if(temp < 100 || temp > 999){
                cout << "Invalid Shelf Number, Enter again: ";
                check = true;
            }
        }while(check);
        shelfnum = temp;
        return is;
    }
    bool PubRecord::operator==(char _recID)const{ 
     if(recID() == _recID)
         return true;
    else
        return false;
    }
    bool PubRecord::operator==(const char* _name)const{ 
        return strstr(pubName, _name);
    }
    PubRecord::operator bool()const{
        return pubName;
    }
    void PubRecord::shelfNo(int value){
        shelfnum = value;
    }
}
