#pragma once
#include <string>

using namespace std;

class Accountant
{
public:
	double bank;
	float expense;
	float income;	

	Accountant() 
	{
		bank = 10000;
		expense = 0;
		income = 0;
	}
	void setIncome()
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