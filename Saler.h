#pragma once
#include <string>
#include "Product.h"

using namespace std;

class Sale : public Product
{
public:
	virtual void saleProduct(int quantity) = 0;
};
