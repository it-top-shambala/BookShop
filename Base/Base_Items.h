#pragma once

#include <iostream>
#include <map>

#include "Items/Item.h"
#include "Items/Item_Book.h"
#include "Items/Item_Pen.h"
#include "Base/Base.h"

using std::map;
using std::pair;

class Base_Items : public Base {
	map <int, Item> _base; //база товаров, структурированная по коду товара
public:
	//метод получения указателя на базу
	auto* GetBase(){
		return &(_base);
	}
};