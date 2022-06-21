#pragma once
# include <string>
using namespace std;

class Product
{
protected:
	string name;
	string autor;
	string publisher_name;
	int pages;
	string genre;
	int year;
	float cost_price;
	float sale_price;
	int quantity;
public:
	Product(const int& rate)
	{
		sale_price = cost_price * rate;
	}
};