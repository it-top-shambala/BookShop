#pragma once

#include <iostream>
#include <string>
#include <map>

#include "Items/Item.h"
#include "Items/Item_Book.h"
#include "Items/Item_Pen.h"

using std::string;
using std::map;

map <int, Item> _stock; //база товаров, структурированная по коду товара (пока объявим глобально)

//базовый класс базы товаров (изначально была задумка сделать этот класс базовым и содержащим базу) пока не реализовано и не работает
class Stock {
protected:
	//со статическим map не работает, доработать!!!
	//сделать класс базы данных и не наследоваться от него, прописать сеттеры и геттеры для map
};

