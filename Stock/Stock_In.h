#pragma once


#include "Stock/Stock.h"

using std::cin;
using std::pair;

//дочерний класс приемки товара
class Stock_In {
protected:
	string _date; //дата приемки товара
public:
	Stock_In(string date) {
		_date = date;
	}
	//метод приемки товара и добавления его в базу
	Item* ChooseItem(string description) {
		Item* item = nullptr;
		int code;
		short year;
		int count_in_stock;
		float price_in;
		float markup;
		//каким-то образом будут запрашиваться эти данные (сканером штрих-кодов, например), но пока через консоль
		cin >> code;
		cin >> year;
		cin >> count_in_stock;
		cin >> price_in;
		cin >> markup;
		if (description == "book") {
			item = new Item_Book(code, description, year, count_in_stock, price_in, markup);
		}
		else if (description == "pen") {
			item = new Item_Pen(code, description, year, count_in_stock, price_in, markup);
		}
		if (item != nullptr) {
			_stock.emplace(pair <int, Item>(code, *item));
		}
		return item;
	}
	//TODO дописать метод добавления количества товара, который уже есть в базе
};