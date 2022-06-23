#pragma once
#include <string>
#include "Manufacturer.h"
using namespace std;

class Book : public Manufacturer
{
public:
	string name;
	string autor;
	int pages;
	string genre;
	float cost_price;
};
