#pragma once

#include <iostream>
#include <map>
#include <string>

using std::map;
using std::string;

//класс сделка
class Deal {
	string _salesman;  //ФИО продавца
	int _code;         //код проданного товара
	int _number;       //кол-во
	float _cash;       //выручка
public:
	Deal(string salesman, int code, int number, float cash) {
		_salesman = salesman;
		_code = code;
		_number = number;
		_cash = cash;
	}
	void PrintReceipt(int code, int number, float price) {
		//печать чека:
		//_date (дата продажи)
		//code (вывод данных о книге по коду (нужны геттеры)
		//number (кол-во)
		//price (цена) и тд
	}
	int GetCode() {
		return _code;
	}
	int GetNumber() {
		return _number;
	}
	float GetCash() {
		return _cash;
	}
	string GetSalesman() {
		return _salesman;
	}
};
