#ifndef SDDS_MAGAZINE_H
#define SDDS_MAGAZINE_H

#include <iostream>
#include "PubRecord.h"

using namespace std;

namespace sdds{
const int MAX_NUM = 99;
const int MIN_NUM = 1;

class Magazine : public PubRecord{
    int volume;
    int issue;
public:
    Magazine();
    Magazine(Magazine&);
    Magazine& operator=(const Magazine&);
    char recID()const;
    void checkIn();
    void checkOut();
    istream& read(std::istream& is = cin);
    ostream& write(std::ostream& os = cout)const;
};
}
#endif
