#pragma once

#include <iostream>
#include <map>
#include <string>

#include "Base/Base_Items.h"
#include "Base/Base_Sold.h"
#include "Base/Base_Deals.h"
#include "Retail/Deal.h"

using std::map;
using std::cout;
using std::endl;
using std::string;

//статический класс вывода данных из баз на экран
class Base_Browser {
public:
	//метод вывода на экран всей базы (для базы товаров <int,Item>)
	static void Show(map<int, Item>* base) {
		if (base != nullptr) {
			for (auto i : *base) {
				cout << i.first << " " << i.second.GetDescription() << " " << i.second.GetCountInStock() << endl;
			}
		}
		else cout << "Base is empty!" << endl;
	}
	//метод вывода на экран определенного товара и остатков его на складе (для базы товаров <int,Item>)
	static void Show(map<int, Item>* base, int code) {
		if (base != nullptr) {
			if (base->find(code) != base->end()) {
				cout << base->find(code)->first << " " << base->find(code)->second.GetDescription() << " " << base->find(code)->second.GetCountInStock() << endl;
			}
			else cout << "Item's not found!" << endl;
		}
		else cout << "Base is empty!" << endl;
	}
	//метод вывода на экран всей базы проданных товаров (<int,int>)
	static void Show(map<int, int>* base) {
		if (base != nullptr) {
			for (auto i : *base) {
				cout << i.first << " " << i.second << endl;
			}
		}
		else cout << "Base is empty!" << endl;
	}
	//метод вывода на экран определенного товара из базы
	static void Show(map<int, int>* base, int code) {
		if (base != nullptr) {
			if (base->find(code) != base->end()) {
				cout << base->find(code)->first << " " << base->find(code)->second << endl;
			}
			else cout << "Item's not found!" << endl;
		}
		else cout << "Base is empty!" << endl;
	}
	//метод вывода на экран всей базы сделок (<string,Deal>)
	static void Show(map<string, Deal>* base) {
		if (base != nullptr) {
			for (auto i : *base) {
				cout << i.first << " " << " " << i.second.GetSalesman() << " " << i.second.GetCode() << " " << i.second.GetNumber() << " " << i.second.GetCash() << endl;
			}
		}
		else cout << "Base is empty!" << endl;
	}
	//метод вывода на экран определенной сделки по дате
	static void Show(map<string, Deal>* base, string date) {
		if (base != nullptr) {
			if (base->find(date) != base->end()) {
				cout << base->find(date)->first << " " << " " << " " << base->find(date)->second.GetSalesman() << " " << base->find(date)->second.GetCode() << " " << base->find(date)->second.GetNumber() << " " << base->find(date)->second.GetCash() << endl;
			}
			else cout << "Item's not found!" << endl;
		}
		else cout << "Base is empty!" << endl;
	}
};