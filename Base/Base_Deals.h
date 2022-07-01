#pragma once

#include <iostream>
#include <map>
#include <string>

#include "Base/Base.h"
#include "Retail/Deal.h"

using std::map;
using std::pair;
using std::string;

class Base_Deals : public Base {
	map <string, Deal> _base;  //база данных продаж, структурированная по дате (включая время)
public:
	//метод получения указателя на базу
	auto* GetBase() {
		return &_base;
	}
};
