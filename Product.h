#pragma once


#include <string>
#include <io.h>  //���������� ��� ������ � ������� � ����� ������� 
#include "Book.h"
#include "Vector_Book.h"


using namespace std;
class Work_books : public Vector_Book, Book
{
public:
	void using_book()
	{
		cout << R"(������ � �������:
1. C������� ������ � ����� �����
2. ���������� ���� �� ������
3. �����)";
		int task;
		cout << "������� ����� �������: ";
		cin >> task;// ���� ����� �������
		switch (task)
		{
		case 1:
			Book::SetNewBook();
			break;
		case 2:
			CountBooks();
			break;
		case 3:
			return;
		default:
			cout << "������ ������� �� ����������!" << endl;
			return;
		}
	}
};





