#pragma once
#include <string>
#include "Sale.h"
#include "Accountant.h"

using namespace std;

class Wholesale : public Sale, public Accountant
{
	virtual void saleProduct(int quantity) override
	{
		if (this->quantity >= quantity)
		{
			this->quantity -= quantity;
			setIncome(this->cost_price, this->sale_price, quantity);
		}
	}
	
};