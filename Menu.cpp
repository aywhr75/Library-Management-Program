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
#include <iomanip>
#include "Menu.h"

namespace sdds {

	MenuItem::MenuItem() {
		desc = nullptr;
	}
	MenuItem::MenuItem(const char* _desc) {
		desc = new char[strlen(_desc) + 1];
		strncpy(desc, _desc, strlen(_desc));
		desc[strlen(_desc)] = '\0';
	}
	//Deallocating MenuItem Object
	MenuItem::~MenuItem() {
		if (desc != nullptr) {
			delete[] desc;
			desc = nullptr;
		}
	}
	MenuItem::operator bool() {
		if (desc == nullptr)
			return true;
		else
			return false;
	}
	MenuItem::operator const char* () {
		return desc;
	}
	ostream& MenuItem::display(ostream & os) {
		os << desc;
		return os;
	}
	Menu::Menu() {
		title.desc = nullptr;
		for (int i = 0; i < MAX_MENU_ITEMS; i++) {
			list[i] = nullptr;
		}
		num = 0;
	}
	Menu::Menu(const char* _desc) {
		title.desc = new char[strlen(_desc) + 1];
		strncpy(title.desc, _desc, strlen(_desc));
		title.desc[strlen(_desc)] = '\0';
		for (int i = 0; i < MAX_MENU_ITEMS; i++) {
			list[i] = nullptr;
		}
		num = 0;
	}
	Menu::~Menu() {
		if (title.desc != nullptr) {
			delete[] title.desc;
			title.desc = nullptr;
		}
		for (int i = 0; i < num; i++) {
			if (list[i] != nullptr)
				delete list[i];
			list[i] = nullptr;
		}
	}
	ostream& Menu::getTitle(ostream & os)const {
		if (title.desc != nullptr)
			os << title.desc;
		else {
			cin.clear();
			cin.ignore(2000, '\n');
		}
		return os;
	}
	ostream& Menu::display(ostream & os)const {
		if (title.desc != nullptr || list[0] != nullptr) {
			if (title.desc != nullptr)
				getTitle(os) << ":" << endl;
			for (int i = 0; i < num; i++) {
				cout << setw(2) << right << i + 1 << "- " << (const char*)* list[i] << endl;
			}
			cout << setw(2) << 0 << "- Exit" << endl << "> ";
		}
		return os;
	}
	Menu& Menu::operator <<(const char* _desc) {
		if (num < MAX_MENU_ITEMS) {
			list[num] = new MenuItem(_desc);
			num++;
		}
		return *this;
	}

	unsigned int Menu::getSelection()const {
		display();
		int i;
		bool check;
		do {
			cin >> i;
			check = false;
			if (i <0 || i> num || cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid Selection, try again: ";
				check = true;
			}
			else {
				cin.clear();
				cin.ignore(1000, '\n');
			}
		} while (check);
		return (unsigned int)i;
	}
	unsigned int Menu::operator~() const {
		return getSelection();
	}
	Menu::operator bool() {
		if (num > 0)
			return true;
		else
			return false;
	}
	const char* Menu::operator[](const int i)const {
		if (i > num)
			return list[0]->desc;
		else
			return list[i]->desc;
	}
	ostream& operator<<(ostream & os, Menu & m) {
		m.getTitle(os);
		return os;
	}
}
