// LR_5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <iomanip>
#include <typeinfo>
#include <ostream>
#include <istream>
#include <locale.h>
#include <list>
#include <map>
#include <string>
#include <iterator>

using namespace std;

struct Product //наименьшая структура (сотрудник)
{
	string name;
	int quantity;
	double price;
	string receiptdate;
	Product() { name = ""; quantity = 0; price = 0; receiptdate = ""; }
};

map <int, Product> my_map;

void addelement()
{
	int k;
	Product sv;

	bool chek = true;
	while (chek)
	{
		cout << "Введите ключ: " << endl;
		cin >> k;
		if (!cin)
		{
			cout << "Ошибка ввода." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;;

		}
		cout << "Введите наименование: " << endl;
		cin >> sv.name;
		cout << "Введите количество: " << endl;
		cin >> sv.quantity;
		if (!cin)
		{
			cout << "Ошибка ввода." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		cout << "Введите стоимость: " << endl;
		cin >> sv.price;
		if (!cin)
		{
			cout << "Ошибка ввода." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;;
		}
		cout << "Введите дату поступления: " << endl;
		cin >> sv.receiptdate;
		chek = false;

	}

	my_map[k] = sv;
}

void display()
{
	for (map<int, Product>::iterator it = my_map.begin(); it != my_map.end(); ++it)
	{
		cout << "Пара: " << endl;
		Product sv = it->second;
		cout << "[" << it->first << "]" << endl;
		cout << setw(5) << sv.name << setw(15) << sv.quantity << setw(15) << sv.price <<
			setw(15) << sv.receiptdate << endl;
	}
}

class Algorithms
{
	map<int, Product> map_alg;
	int iter = 0;
public:
	Algorithms(map<int, Product> map_alg_) :map_alg(map_alg_) { };



	void delete_element(int key, Product st_del)
	{
		Product k;
		int s = 0;
		bool is_found = false;
		//auto iter1
		for (map<int, Product>::iterator iter1 = map_alg.begin(); iter1 != map_alg.end(); ++iter1)  //Цикл 1 пока начало не настигент предпоследний элемент
		{
			k = iter1->second;
			s = iter1->first;
			if (s == key || (k.name == st_del.name && k.quantity == st_del.quantity && k.price == st_del.price
				&& k.receiptdate == st_del.receiptdate))
			{
				is_found = true;
				cout << "Пара найдена. Она удалена." << endl;
				map_alg.erase(iter1);
				break;
			}
		}
		if (is_found == false)
		{
			cout << "Пара не найдена." << endl;
		}

	}

	map<int, Product> return_map()
	{
		return map_alg;
	}

	void display()
	{
		for (map<int, Product>::iterator it = map_alg.begin(); it != map_alg.end(); ++it)
		{
			cout << "Пара: " << endl;
			Product sv = it->second;
			cout << "[" << it->first << "]" << endl;
			cout << setw(5) << sv.name << setw(15) << sv.quantity << setw(15) << sv.price <<
				setw(15) << sv.receiptdate << endl;
		}
	}

	void sort()
	{
		Product sotr1, sotr2;
		int key1, key2;
		bool sort_tr = false;
		while (sort_tr == false)
		{
			for (map<int, Product>::iterator it = map_alg.begin(); it != map_alg.end(); ++it)
			{
				sotr1 = it->second;
				key1 = it->first;
				for (map<int, Product>::iterator it2 = it; it2 != map_alg.end(); ++it2)
				{
					if (it2 != it)
					{
						sotr2 = it2->second;
						key2 = it2->first;
						if (sotr1.name[0] > sotr2.name[0])
						{
							map_alg.at(key1) = sotr2;
							map_alg.at(key2) = sotr1;
						}
						break;
					}

				}
			}
			sort_tr = sort_true();
		}
	}

	bool sort_true()
	{
		Product sotr1, sotr2;
		int key1, key2;
		for (map<int, Product>::iterator it = map_alg.begin(); it != map_alg.end(); ++it)
		{
			sotr1 = it->second;
			key1 = it->first;
			for (map<int, Product>::iterator it2 = it; it2 != map_alg.end(); ++it2)
			{
				if (it2 != it)
				{
					sotr2 = it2->second;
					key2 = it2->first;
					if (sotr1.name[0] > sotr2.name[0])
					{
						return false;
					}
					//break;
				}

			}
		}
		return true;
	}

	void find(int key, Product sv)
	{
		Product k;
		int s = 0;
		bool is_found = false;
		//auto iter1
		for (map<int, Product>::iterator iter1 = map_alg.begin(); iter1 != map_alg.end(); ++iter1)  //Цикл 1 пока начало не настигент предпоследний элемент
		{
			k = iter1->second;
			s = iter1->first;
			if (s == key && k.name == sv.name && k.quantity == sv.quantity && k.price == sv.price
				&& k.receiptdate == sv.receiptdate)
			{
				is_found = true;
				cout << "Пара найдена." << endl;
				cout << "Пара: " << endl;
				//sotrudnik sv = it->second;
				cout << "[" << iter1->first << "]" << endl;
				cout << setw(10) << k.name << setw(10) << k.quantity << setw(10) << k.price <<
					setw(10) << k.receiptdate << endl;
				break;
			}
		}
		if (is_found == false)
		{
			cout << "Пара не найдена." << endl;
		}
	}
};

void menu()
{
	int chose = 0;
	while (chose != 3)
	{
		cout << "1 - Добавить элемент, 2 - Вывод, 3 - Выход" << endl;
		cin >> chose;
		switch (chose)
		{
		case 1: addelement(); system("pause"); break;
		case 2: display(); system("pause"); break;
		}
	}
}

int main()
{
	int z;
	setlocale(LC_ALL, "Russian");
	menu();
	cout << "Создание алгоритма. В качестве параметра передаем наш map" << endl;
	Algorithms alg(my_map);
	cout << "Вывод map через алгоритм" << endl;
	alg.display();
	cout << "---------------------------------Сортировка----------------------------------" << endl;
	// alg.sort();
	alg.sort();
	alg.display();
	cout << "------------------------------------Поиск------------------------------------" << endl;
	cout << "Введите данные для поиска..." << endl;
	int k;
	Product sv;
	cout << "Введите ключ: " << endl;
	cin >> k;
	if (!cin)
	{
		cout << "Ошибка ввода." << endl;
		cin.clear();
		cin.ignore(10000, '\n');

	}
	cout << "Введите наименование: " << endl;
	cin >> sv.name;

	cout << "Введите количество: " << endl;
	cin >> sv.quantity;
	if (!cin)
	{
		cout << "Ошибка ввода." << endl;
		cin.clear();
		cin.ignore(10000, '\n');
	}
	cout << "Введите стоимость: " << endl;
	cin >> sv.price;
	if (!cin)
	{
		cout << "Ошибка ввода." << endl;
		cin.clear();
		cin.ignore(10000, '\n');
	}
	cout << "Введите дату поступления: " << endl;
	cin >> sv.receiptdate;
	cout << "Поиск черз алгоритм..." << endl;
	alg.find(k, sv);
	cout << "------------------------------------Вывод------------------------------------" << endl;
	cout << "Вывод map через алгоритм" << endl;
	alg.display();
	cout << "---------------------------------Удаление------------------------------------" << endl;
	cout << "Введите данные для удаления..." << endl;
	cout << "Введите ключ: " << endl;
	cin >> k;
	if (!cin)
	{
		cout << "Ошибка ввода." << endl;
		exit(0);
	}
	cout << "Введите ключ: " << endl;
	cin >> k;
	if (!cin)
	{
		cout << "Ошибка ввода." << endl;
		cin.clear();
		cin.ignore(10000, '\n');

	}
	cout << "Введите наименование: " << endl;
	cin >> sv.name;
	cout << "Введите количество: " << endl;
	cin >> sv.quantity;
	if (!cin)
	{
		cout << "Ошибка ввода." << endl;
		cin.clear();
		cin.ignore(10000, '\n');
	}
	cout << "Введите стоимость: " << endl;
	cin >> sv.price;
	if (!cin)
	{
		cout << "Ошибка ввода." << endl;
		cin.clear();
		cin.ignore(10000, '\n');
	}
	cout << "Введите дату поступления: " << endl;
	cin >> sv.receiptdate;
	cout << "Удаление черз алгоритм..." << endl;
	alg.delete_element(k, sv);
	cout << "------------------------------------Вывод------------------------------------" << endl;
	cout << "Вывод map через алгоритм" << endl;
	alg.display();
	cout << "---------------------------------Сортировка----------------------------------" << endl;
	alg.sort();
	cout << "-----------------Сортировка по наименованию--------" << endl;
	alg.display();
	cout << "-------------------Исходный словарь----------------" << endl;
	display();
	cout << "Получение словаря после алгоритмов..." << endl;
	my_map = alg.return_map();
	cout << "-------------------Конечный словарь----------------" << endl;
	display();
	system("pause");
}