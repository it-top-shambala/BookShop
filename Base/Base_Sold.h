#pragma once

#include <iostream>
#include <map>

using std::map;
using std::pair;
using std::cout;
using std::endl;

class Base_Sold {
	map <int, int> _base; //база кол-ва проданных товаров, структурированная по коду товара
public:
	//метод добавления товара и кол-ва в базу
	void Add(pair<int, int> item) {

		if (_base.find(item.first) != _base.end()) {
			_base.find(item.first)->second += item.second;
		}
		else _base.emplace(pair<int, int>(item.first, item.second));
	}
	//метод поиска товара по коду и получения кол-ва проданных единиц
	int Find(int code) {
		int item = 0;
		if (_base.find(code) != _base.end()) {
			item = _base.find(code)->first;
		}
		return item;
	}
	//метод получения количества проданных единиц определенного товара
	int GetCount(int code) {
		int count = 0;
		if (_base.find(code) != _base.end()) {
			count = _base.find(code)->second;
		}
		return count;
	}
	//метод получения общего количества товаров в базе
	int GetBaseSize() {
		return _base.size();
	}
	//метод вывода на экран всей базы
	void Show() {
		for (auto i : _base) {
			cout << i.first << " " << i.second << endl;
		}
	}
	//метод вывода на экран определенного товара из базы
	void Show(int code) {
		if (_base.find(code) != _base.end()) {
			cout<<_base.find(code)->first << " " << _base.find(code)->second << endl;
		}
		else cout << "Item's not found!" << endl;
	}
};