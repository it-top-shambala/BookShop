#pragma once

#include "Items/Item.h"

//класс Книга
class Item_Book : public Item {
protected:
	string _header;       //заголовок
	string _author;       //автор
	string _publisher;    //издательство
	string _genre;        //жанр
	short _pages;         //количество страниц
public:
	Item_Book(int code, string description, short year, int count_in_stock, float price_in, float markup) : Item(code, description, year, count_in_stock, price_in, markup) {
		_pages = 0;
	}

	void SetBookInfo() {
		//чтобы не загромождать конструктор, здесь будет запрашиваться ввод информации о книге
	}
};