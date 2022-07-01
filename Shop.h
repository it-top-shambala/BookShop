#pragma once

#include <iostream>
#include <string>
#include <map>

#include "Items/Item.h"
#include "Items/Item_Book.h"
#include "Items/Item_Pen.h"
#include "Base/Base.h"
#include "Base/Base_Items.h"
#include "Base/Base_Sold.h"
#include "Base/Base_Deals.h"
#include "Base/Base_Browser.h"
#include "Retail/Deal.h"

using std::string;
using std::map;
using std::pair;
using std::cin;
using std::cout;
using std::endl;

//класс магазин
class Shop {
protected:
	Base_Items _base_items;          //база товаров, структурированная по коду товара
	Base_Sold _base_sold;            //база проданного товара, структурированная по коду и кол-ву проданных единиц  
	Base_Deals _base_deals;          //база продаж
	string _date="2022.07.01.16:00"; //дата может обновляться, подтягивая системное время (как вариант) (инициализировал для теста)
	float _revenue;                  //выручка	
	float _profit;                   //прибыль   
public: 
	Shop() {
		_revenue = 0;
		_profit = 0;
	}
	//метод приема товара
	void ItemAdd(string description) {
		Item* item = nullptr;
		int code;
		short year;
		int count_in_stock;
		float price_in;
		float markup;
		//каким-то образом будут запрашиваться эти данные (сканером штрих-кодов, например), но пока через консоль
		cout << "Input code: "; cin >> code;
		cout << "Input year: "; cin >> year;
		cout << "Input quantity: "; cin >> count_in_stock;
		cout << "Input purchase price: "; cin >> price_in;
		cout << "Input markup: "; cin >> markup;
		if (description == "book") {
			item = new Item_Book(code, description, year, count_in_stock, price_in, markup);
		}
		else if (description == "pen") {
			item = new Item_Pen(code, description, year, count_in_stock, price_in, markup);
		}

		//если прописать virtual функцию в классе-родителе Item - такая штука уже не работает
		//pair ругается на полиморфный класс

		/*if (dynamic_cast<Item_Book*>(item)) {
			_stock.emplace(pair <int, Item>(code, *(dynamic_cast<Item_Book*>(item))));
		}
		else if (dynamic_cast<Item_Pen*>(item)) {
			_stock.emplace(pair <int, Item>(code, *(dynamic_cast<Item_Pen*>(item))));
		}*/
		//а иначе, у нас не будет доступа к уникальным полям дочерних классов класса Item

		if (item != nullptr) {
			_base_items.Add(_base_items.GetBase(), code, *item);
		}
	}

	//метод продажи (переработанный)
	void ItemSell(int code, int number, float discount, string salesman) {
		Item* item = _base_items.Find(_base_items.GetBase(), code);
		if (item) {
			float cash = 0;   //сумма к оплате
			if (discount > 0) {
				cash = item->GetPriceOut() * discount;
			}
			else cash = item->GetPriceOut();
			//вывод cash (суммы для оплаты) на экран кассы
			_revenue += cash;
			_profit += (cash - item->GetPriceIn());
			item->CountInStockMinus(number);
			//добавляем код и кол-во проданного товара в базу
			_base_sold.Add(_base_sold.GetBase(), code, number);
			Deal deal(salesman, code, number, cash);
			deal.PrintReceipt(code, number, cash);
			_base_deals.Add(_base_deals.GetBase(), _date, deal);
		}
		else cout << "Item's not found!" << endl;
	}

	//метод получения выручки
	float GetRevenue() {
		return _revenue;
	}

	//метод получения прибыли
	float GetProfit() {
		return _profit;
	}

	//метод проведения аналитики (тестовый)
	void Analytics(int select, int code) {
    //здесь собираются и используются все нужные функции баз и полей класса (лень делать меню) тестовый вывод!
		switch (select) {
		case 1: _base_items.GetBaseSize(_base_items.GetBase());
			break;
		case 2: _base_items.GetCount(_base_items.GetBase(), code);
			break;
		case 3: Base_Browser::Show(_base_items.GetBase());
			break;
		case 4: Base_Browser::Show(_base_items.GetBase(), code);
			break;
		case 5: _base_sold.GetBaseSize(_base_sold.GetBase());
			break;
		case 6: _base_sold.GetCount(_base_sold.GetBase(), code);
			break;
		case 7: Base_Browser::Show(_base_sold.GetBase());
			break;
		case 8: Base_Browser::Show(_base_sold.GetBase(), code);
			break;
		case 9: Base_Browser::Show(_base_deals.GetBase());
			break;
		case 10: Base_Browser::Show(_base_deals.GetBase(),_date);
			break;
		case 11: cout << GetProfit() << endl;
			break;
		case 12: cout << GetRevenue() << endl;
			break;
		default:
			break;
		}
	}
};

