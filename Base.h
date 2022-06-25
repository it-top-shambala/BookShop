#pragma once

#include <iostream>
#include <map>

#include "Items/Item.h"
#include "Items/Item_Book.h"
#include "Items/Item_Pen.h"

using std::map;
using std::pair;

class Base {
protected:
	map <int, Item> _base; //база товаров, структурированная по коду товара
	static Base* _ptr;
public:
	//метод добавления товара в базу
	void Add(pair<int, Item> item) {
		_base.emplace(pair<int, Item>(item.first, item.second));
	}

	//метод поиска товара в базе по коду, если товар не найден, возвращает nullptr
	Item* Find(int code) {
		Item* item = nullptr;
		if (_base.find(code) != _base.end()) {
			item = &(_base.find(code)->second);
		}
		return item;
	}
	static Base* GetPtr() {
		return _ptr;
	}
};