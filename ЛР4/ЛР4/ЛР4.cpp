#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>


using namespace std;

struct Products {
	char name[40];
	int quantity;
	double price;
	char receiptdate[12];
};

class TextFile {
private:
	Products object;
	char fileName[20] = "file.dat";
	int count = 0;
public:
	TextFile(bool flag);
	void WriteInFile();
	void Sort();
	void Print();
};

TextFile::TextFile(bool flag) {
	FILE* f = std::fopen(this->fileName, "rb");//r - read; b - binary
	if (flag)
	{
		while (std::fread(&object, sizeof(Products), 1, f)) {
			++count;
		}
	}
}
class MyExeption : public exception
{
public:
	MyExeption(const char* msg, string dataState) : exception(msg)
	{
		this->dataState = dataState;
	}

	string getDataState()
	{
		return dataState;
	}
private:
	string dataState = NULL;
};

void TextFile::WriteInFile() {
	char c = 'n';
	fstream file;
	file.open(this->fileName, ios::binary | ios::out);
	this->count = 0;
	do
	{
		if (c == 'y')
		{
			cin.clear();
			cin.ignore(10000, '\n');
		}
		cout << "Наименование товара: " << endl;
		cin.getline(object.name, 40);
		cout << "Количество товара: " << endl;
		cin >> object.quantity;
		try
		{
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				object.quantity = rand() % 998 + 1;
				throw 1;
			}
		}
		catch (...)
		{
			cout << "Введено не верное зачение, параметру Цена присвоено значение " << object.quantity << endl;
		}
		cout << "Цена товара(за штуку): " << endl;
		cin >> object.price;
		try
		{
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				object.price = rand() % 998 + 1;
				throw 1;
			}
		}
		catch (...)
		{
			cout << "Введено не верное зачение, параметру Количество присвоено значение " << object.price << endl;
		}
		cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "Дата поступления товара" << endl;
		cin.getline(object.receiptdate, 11);
		cout << "Добавить еще? y/n" << endl;
		file.write(reinterpret_cast<char*>(&object), sizeof(Products));
		cin >> c;
		++this->count;
		system("cls");
	} while (c == 'y');
	file.close();
}

void TextFile::Sort() {
	FILE* f = std::fopen(this->fileName, "r+");
	Products elem, nextelem;
	int k = count / 2;
	while (k > 0) {
		for (int i = 0; i < count; i++) {
			std::fseek(f, i * (sizeof(Products)), SEEK_SET);
			std::fread(&elem, sizeof(Products), 1, f);
			for (int j = i + k; j < count; j += k) {
				std::fseek(f, j * (sizeof(Products)), SEEK_SET);
				std::fread(&nextelem, sizeof(Products), 1, f);
				if (elem.price > nextelem.price) {
					std::fseek(f, j * (sizeof(Products)), SEEK_SET);
					std::fwrite(&elem, sizeof(Products), 1, f);
					std::fseek(f, i * (sizeof(Products)), SEEK_SET);
					std::fwrite(&nextelem, sizeof(Products), 1, f);
					elem = nextelem;
				}
			}
		}
		--k;
	}
	std::fclose(f);
}

void TextFile::Print() {
	FILE* f;
	f = std::fopen(this->fileName, "rb");
	cout << setw(20) << "Наименование" << setw(20) << "Количество" << setw(20) << "Цена" << setw(20) << "Дата поступения" << endl;
	for (int i = 0; i < count; i++) {
		std::fread(&object, sizeof(Products), 1, f);
		cout << setw(20) << object.name << setw(20) << object.quantity << setw(20) << object.price << setw(20) << object.receiptdate << endl;
	}
	std::fclose(f);
}

int main()
{
	setlocale(LC_ALL, "rus");
	TextFile* a = new TextFile(0);
	try {
		a->WriteInFile();
	}
	catch (MyExeption & ex)
	{
		cout << "Было введено не верное значение " << ex.what() << endl;
		a->WriteInFile();
	}
	a->Print();
	cout << endl;
	a->Sort();
	a->Print();
	return 0;
}
