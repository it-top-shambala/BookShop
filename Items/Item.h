#pragma once

#include <iostream>
#include <string>

using std::string;

//базовый класс номенклатуры товара в магазине
class Item {
protected:
	int _code;             //код товара
	string _description;   //описание товара
	short _year;           //год издания/производства
	int _count_in_stock;   //количество единиц в наличии
	int _count_sold;       //количество проданных единиц
	int _defective;        //количество бракованных/испорченных единиц
	float _price_in;       //закупочная цена
	float _price_out;      //цена продажи
	float _markup;         //процент наценки (цена продажи будет вычисляться путем умножения на заложенный коэффициент)

	Item(int code, string description, short year, int count_in_stock, float price_in, float markup) {
		_code = code;
		_description = description;
		_year = year;
		_count_in_stock = count_in_stock;
		_count_sold = 0;
		_defective = 0;
		_price_in = price_in;
		_markup = markup;
		_price_out = _price_in * _markup;
	}
public:
	float GetPriceIn() {
		return _price_in;
	}
	float GetPriceOut() {
		return _price_out;
	}
	void CountInStockPlus(int number) {
		_count_in_stock += number;
	}
	void CountInStockMinus(int number) {
		_count_in_stock -= number;
	}
	void CountSoldPlus(int number) {
		_count_sold += number;
	}
};