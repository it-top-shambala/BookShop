#pragma once

#include <iostream>
#include <map>
#include <string>

#include "Items/Item.h"
#include "Items/Item_Book.h"
#include "Items/Item_Pen.h"
#include "Retail/Deal.h"

using std::map;
using std::pair;
using std::string;

//базовый класс базы данных
class Base {
public:
	//метод добавления товара в базу (для базы товаров <int,Item>)
	void Add(map<int,Item>* _base, int code, Item item) {
		//если товар уже есть в базе, увеличиваем его кол-во
		if (_base->find(code) != _base->end()) {
			_base->find(code)->second.CountInStockPlus(item.GetCountInStock());
		}
		//иначе, добавляем в базу
		else _base->emplace(pair<int, Item>(code, item));
	}
	//перегрузка метода добавления товара в базу (для базы проданного товара <int,int>)
	void Add(map<int, int>* _base, int code, int number){
		//если товар уже есть в базе, увеличиваем его кол-во
		if (_base->find(code) != _base->end()) {
			_base->find(code)->second += number;
		}
		//иначе добавляем в базу
		else _base->emplace(pair<int, int>(code, number));
	}
	//перегрузка метода добавления сделки в базу (для базы сделок <string,Deal>)
	void Add(map<string, Deal>* _base, string date, Deal deal) {
        _base->emplace(pair<string,Deal>(date, deal));
	}
	//метод поиска товара в базе по коду (для базы товаров <int,Item>)
	Item* Find(map<int, Item>* _base, int code) {
		Item* item = nullptr;
		if (_base->find(code) != _base->end()) {
			item = &(_base->find(code)->second);
		}
		return item;
	}
	//метод поиска сделки в базе сделок по дате (для базы сделок <string,Deal>)
	Deal* Find(map<string, Deal>* _base, string date) {
		Deal* deal = nullptr;
		if (_base->find(date) != _base->end()) {
			deal = &(_base->find(date)->second);
		}
		return deal;
	}
	//метод получения количества определенного товара в базе (для базы товаров <int,Item>)
	int GetCount(map<int, Item>* _base, int code) {
		int count = 0;
		if (_base->find(code) != _base->end()) {
			count = _base->find(code)->second.GetCountInStock();
		}
		return count;
	}
	//метод получения количества проданных единиц определенного товара (для базы проданных товаров <int,int>)
	int GetCount(map<int, int>* _base, int code) {
		int count = 0;
		if (_base->find(code) != _base->end()) {
			count = _base->find(code)->second;
		}
		return count;
	}
	//метод получения общего количества товаров в базе
	int GetBaseSize(map<int, Item>* _base) {
		return _base->size();
	}
	//метод получения общего количества товаров в базе проданных товаров
	int GetBaseSize(map<int, int>* _base) {
		return _base->size();
	}
	//метод получения общего количества сделок в базе сделок
	int GetBaseSize(map<string, Deal>* _base) {
		return _base->size();
	}
};