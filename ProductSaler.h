#pragma once
#include <string>
#include "Storage.h"
#include "Accountant.h"
#include "Product.h"
using namespace std;
class ProductSaler
{
public:
	virtual saleBook(Product* Product, Accountant* accountant, Storage* storage) = 0;
};