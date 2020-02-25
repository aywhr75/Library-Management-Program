#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include<iostream>

#define MAX_MENU_ITEMS 20

using namespace std;

namespace sdds {
	class Menu; 
	class MenuItem {
		char* desc;
		friend class Menu;
		MenuItem(); 
		MenuItem(const char*);
		~MenuItem();
		operator bool();
		operator const char* (); 
		ostream& display(ostream& os = cout);
	};
	class Menu {
		MenuItem title;
		MenuItem* list[MAX_MENU_ITEMS]; 
		int num = 0;

	public:
		Menu();
		Menu(const char*);
		~Menu();
		ostream& getTitle(ostream& os = cout)const;
		ostream& display(ostream& os = cout)const;
		Menu& operator << (const char*);
		unsigned int getSelection() const;
		unsigned int operator~() const;
		operator int() { return num; };
		operator unsigned int() { return num; };
		operator bool();
		const char* operator[](const int i)const;

	};
	std::ostream& operator<<(std::ostream&, Menu& m);
}

#endif
