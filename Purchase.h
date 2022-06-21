#pragma once
#include <string>
#include "Product.h"
#include "Accountant.h"

using namespace std;

class Purchase : public Product
{
protected:
	int purchase_rate;
public:
	Purchase(const int& purchase_rate):Product(purchase_rate)
	{
		Purchase():Accountant(){}//TODO разработать передачу данных в конструктор бухгалтер или переопределить в конструктор товары
	}
	
	void setRate(int _rate)
	{
		purchase_rate =_rate
		return purchase_rate;
	}
};