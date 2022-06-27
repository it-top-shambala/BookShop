#pragma once

#include <string>
#include "ReadWriteVectorFromFile.h"

class Category_Book : Read_Write_Vector
{
public:
	string PathFileBook;

	Category_Book(string _path)
	{
		PathFileBook = _path;//���� � ����� � �������� ����
	}

	void GetFileBook()
	{
		ReadVectorFromFile(PathFileBook);//������ ������� ����
	}
	void SetFileBook()
	{
		WriteVectorFromFile(PathFileBook);//������ ������� ����
	}

};


