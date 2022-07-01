#pragma once

#include "Items/Item.h"

//класс Ручка
class Item_Pen : public Item {
protected:
	string _ink_color;    //цвет чернил
	string _manufacturer; //производитель
public:
	Item_Pen(int code, string description, short year, int count_in_stock, float price_in, float markup) : Item(code, description, year, count_in_stock, price_in, markup) {}

	void SetPenInfo() {
		//чтобы не загромождать конструктор, здесь будет запрашиваться ввод информации о ручке
	}
};