#include <iostream>

#include "Items/Item.h"
#include "Items/Item_Book.h"
#include "Items/Item_Pen.h"
#include "Base/Base.h"
#include "Base/Base_Sold.h"
#include "Shop.h"

int main() {
	Shop BookShop;
	BookShop.ItemAdd("book");
	BookShop.ItemSell(12345,1,0.75);
	BookShop.Analytics(4, 12345);
	BookShop.Analytics(3, 12345);
	BookShop.Analytics(7, 12345);
	BookShop.Analytics(8, 12345);
	BookShop.Analytics(9, 12345);
	BookShop.Analytics(10, 12345);
}
