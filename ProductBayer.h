#pragma once
#include <string>
#include "Product.h"
#include "Storage.h"
using namespace std;
class ProductBayer
{
public:
	virtual bayBook(Product* book, Storage* storage) = 0;
};