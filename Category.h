#pragma once

#include <string>
#include "ReadWriteVectorFromFile.h"

class Category_Book : Read_Write_Vector
{
public:
	string PathFileBook;

	Category_Book(string _path)
	{
		PathFileBook = _path;//путь к файлу с вектором книг
	}

	void GetFileBook()
	{
		ReadVectorFromFile(PathFileBook);//чтение вектора книг
	}
	void SetFileBook()
	{
		WriteVectorFromFile(PathFileBook);//запись вектора книг
	}

};


