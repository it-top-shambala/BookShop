#pragma once

#include <iostream>
#include <map>
#include "Base/Base.h"

using std::map;
using std::pair;

class Base_Sold : public Base {
	map <int, int> _base; //база кол-ва проданных товаров, структурированная по коду товара
public:
	//метод получения указателя на базу
	auto* GetBase() {
		return &(_base);
	}
};