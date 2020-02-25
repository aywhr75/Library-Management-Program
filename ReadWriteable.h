#ifndef  SDDS_RDWT_H
#define  SDDS_RDWT_H

using namespace std;
namespace sdds {

	class  ReadWriteable {

	public:
		virtual istream& read(istream& is = cin) = 0;
		virtual ostream& write(ostream& os = cout)const = 0;
	};
	istream& operator>> (istream& is, ReadWriteable& R);
	ostream& operator<< (ostream& os, const ReadWriteable& W);
}
#endif
