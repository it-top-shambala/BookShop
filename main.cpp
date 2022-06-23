#include <iostream>
#include <string>
#include <map>

#include "Items/Item.h"
#include "Items/Item_Book.h"
#include "Items/Item_Pen.h"
#include "Stock/Stock.h"
#include "Stock/Stock_In.h"
#include "Stock/Stock_Out.h"

using std::string;
using std::map;

int main() {

	Stock BookShop;
	//приемка товара образно
	Stock_In Ivanov ("Today");
	Item* book = Ivanov.ChooseItem("book");

	//продажа товара
	Stock_Out Petrov ("Today");
	Petrov.Deal(12345, 2, 0.75F);

	//пока ничего не работает :-(

	delete book;
	book = nullptr;
}
