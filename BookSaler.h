#pragma once
#include <string>

#include <vector>
#include "ProductSaler.h"
#include "Book.h"
using namespace std;
class BookSaler : public ProductSaler
{
public:
	Book* book;
	virtual saleBook(Product* Product, Accountant* accountant, Storage* storage) override
	{	
		book = dynamic_cast<Book*>(storage->storage.back());
		accountant->income += (storage->storage.back()->sale_price) - (book->cost_price);		
		storage->storage.pop_back;
	}
};
