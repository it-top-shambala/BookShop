#pragma once

#include <iostream>
#include <map>
#include <string>

#include "Items/Item.h"
#include "Items/Item_Book.h"
#include "Items/Item_Pen.h"

using std::map;
using std::pair;
using std::cout;
using std::endl;
using std::string;

class Base {
	map <int, Item> _base; //база товаров, структурированная по коду товара
public:
	//метод добавления товара в базу
	void Add(pair<int, Item> item) {
		//если товар уже есть в базе, увеличиваем его кол-во
		if (_base.find(item.first) != _base.end()) {
			_base.find(item.first)->second.CountInStockPlus(item.second.GetCountInStock());
		}
		//иначе, добавляем в базу
		else _base.emplace(pair<int, Item>(item.first, item.second));
	}

	//метод поиска товара в базе по коду, если товар не найден, возвращает nullptr
	Item* Find(int code) {
		Item* item = nullptr;
		if (_base.find(code) != _base.end()) {
			item = &(_base.find(code)->second);
		}
		return item;
	}
	//метод получения количества определенного товара в базе
	int GetCount(int code) {
		int count = 0;
		if (_base.find(code) != _base.end()) {
			count = _base.find(code)->second.GetCountInStock();
		}
		return count;
	}
	//метод получения общего кол-ва товаров в базе
	int GetBaseSize() {
		return _base.size();
	}
	//метод вывода на экран всей базы
	void Show() {
		for (auto i : _base) {
			cout << i.first << " "<<i.second.GetDescription() <<" "<< i.second.GetCountInStock() << endl;
		}
	}
	//метод вывода на экран определенного товара и остатков его на складе
	void Show(int code) {
		if (_base.find(code) != _base.end()) {
			cout << _base.find(code)->first << " " << _base.find(code)->second.GetDescription() << " " << _base.find(code)->second.GetCountInStock() << endl;
		}
		else cout << "Item's not found!" << endl;
	}
};