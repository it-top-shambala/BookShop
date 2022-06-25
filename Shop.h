#pragma once

#include <iostream>
#include <string>
#include <map>

#include "Items/Item.h"
#include "Items/Item_Book.h"
#include "Items/Item_Pen.h"
#include "Base/Base.h"
#include "Base/Base_Sold.h"

using std::string;
using std::map;
using std::pair;
using std::cin;
using std::cout;
using std::endl;

//класс магазин
class Shop {
protected:
	Base _base;                  //база товаров, структурированная по коду товара
	Base_Sold _base_sold;        //база проданного товара, структурированная по коду и кол-ву проданных единиц  
	string _date;                //дата может обновляться, подтягивая системное время (как вариант)
	float _revenue;              //выручка	
	float _profit;               //прибыль   
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
		////каким-то образом будут запрашиваться эти данные (сканером штрих-кодов, например), но пока через консоль
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
			_base.Add(pair<int,Item>(code, *item));
		}	
	}

	//метод продажи товара путем поиска его в базе и изменения счетчика наличия - члена класса Item
	//(скидка (коэффициент) берется из какой-нибудь базы данных бонусных карт покупателей, например)
	//можно вынести продажу в отдельный класс Deal, сделка бы принимала дату, ФИО продавца, код товара, скидку, печатался бы чек
	//каждый раз новый объект создавался бы и помещался в базу сделок (но это пока избыточно)
	void ItemSell(int code, int number, float discount) {
		Item* item = _base.Find(code);
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
			_base_sold.Add(pair <int, int>(code, number));
			PrintReceipt(code, number, cash);
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
		case 1: _base.GetBaseSize();
			break;
		case 2: _base.GetCount(code);
			break;
		case 3: _base.Show();
			break;
		case 4: _base.Show(code);
			break;
		case 5: _base_sold.GetBaseSize();
			break;
		case 6: _base_sold.GetCount(code);
			break;
		case 7: _base_sold.Show();
			break;
		case 8: _base_sold.Show(code);
			break;
		case 9: cout << GetProfit() << endl;
			break;
		case 10: cout << GetRevenue() << endl;
			break;
		default:
			break;
		}
	}

	void PrintReceipt(int code, int number, float price) {
		//печать чека:
		//_date (дата продажи)
		//code (вывод данных о книге по коду (нужны геттеры)
		//number (кол-во)
		//price (цена) и тд
	}
};

