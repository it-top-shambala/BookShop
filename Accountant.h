#pragma once
#include <string>

using namespace std;

class Accountant
{
protected:
	string name;	
	float expense;
	float income;
	int quantity;
public:
	Accountant() 
	{
		//создание объекта Бухгалтер для хранения данных
	}
	void setIncome(float cost_price, float sale_price, int quantity)
	{
		//определение дохода
	}
	void showIncome()
	{
		// показ прибыли
	}
	void showSale()
	{
		//показ продаж
	}
};