#pragma once
#include <string>
#include "Product.h"
#include "Storage.h"
#include <vector>
#include "ProductBayer.h"
#include "Book.h"
using namespace std;
class BookBayer: public ProductBayer
{
public:
	float rate;
	Book* book;
	virtual bayBook(Product* product,Storage* storage) override
	{
		product->sale_price=rate* book->cost_price;
		product = book;
		storage->storage.push_back(product);
	}
};