#pragma once
#include <string>
#include "Sale.h"
#include "Accountant.h"

using namespace std;

class Retail : public Sale, public Accountant
{
	virtual void saleProduct(1) override
	{
		this->quantity -= 1;
		setIncome(this->cost_price, this->sale_price, 1);
		
	}

};