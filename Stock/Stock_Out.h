#pragma once

#include "Stock/Stock.h"

using std::pair;

//класс продажи товара (можно создавать каждый день новый объект класса с актуальной датой продажи (рабочая смена))
class Stock_Out {
protected:
	//можно создать структуру Дата, пока просто string
	string _date;                       //дата продажи
	float _revenue;                     //выручка
	map <int, int> _sold_items;         //база проданного товара за день по коду и его кол-во
public:
	Stock_Out(string date) {
		_date = date;
		_revenue = 0;
	}
	//метод продажи товара путем поиска его в базе и изменения счетчиков наличия и проданных единиц
	//(скидка (коэффициент) берется из какой-нибудь базы данных бонусных карт покупателей, например)
	//метод возвращает profit (прибыль) принимается какой-то базой данных о прибыли
	float Deal(int code, int number, float discount) {
		Item* item = &(_stock.find(code)->second);
		float profit = 0; //выгода со сделки
		float cash = 0;   //сумма к оплате
		if (discount > 0) {
			cash = item->GetPriceOut() * discount;
		}
		else cash = item->GetPriceOut();

		_revenue += cash;

		//вывод cash (суммы для оплаты) на экран кассы

		profit = cash - item->GetPriceIn();

		item->CountInStockMinus(number);
		item->CountSoldPlus(number);

		if (_sold_items.find(code)->first) {
			_sold_items.find(code)->second += number;
		}
		else _sold_items.emplace(pair <int, int>(code, number));

		PrintReceipt(code, number, cash, discount);

		return profit;
	}
	void PrintReceipt(int code, int number, float price, float discount) {
		//печать чека:
		//_date (дата продажи)
		//code (вывод данных о книге по коду (нужны геттеры)
		//number (кол-во)
		//price (цена) и тд
	}
};










