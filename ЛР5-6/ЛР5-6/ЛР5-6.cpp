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

using namespace std;

struct Product
{
	string Name;
	int quantity;
	double cost;
	string receiptDate;
	Product() { Name = ""; quantity = 0; cost = 0; receiptDate = ""; }
};

//ШАБЛОН КЛАССА "Пара"
template <typename T1, typename T2>
class Pair
{
public:
	T1 key;
	T2 value;
	Pair(T1 s, T2 s1) //конструктор с параметрами
	{
		key = s;
		value = s1;
	}
	Pair() {};
	T2 get_value() //получить значение
	{
		return value;
	}
	T1 get_key() //получить ключ
	{
		return key;
	}
	void set_key(T1 k)
	{
		key = k;
	}
	void set_value(T2 k)
	{
		value = k;
	}
	void show()
	{
		cout << "Пара:" << endl;
		cout << "[" << key << "]: " << endl;
		cout << setw(2) << value.Name << setw(15) << value.quantity << setw(15) << value.cost << setw(15) << value.receiptDate << endl;
	}
};

template <typename T1, typename T2>
class Map
{
public:
	Pair<T1, T2>* map;
	int size;

	class Iterator
	{
		Pair<T1, T2>* cur;
		int size;
		int iter = 0;
	public:
		Iterator(Pair<T1, T2>* first, int s) :cur(first) { size = s; };

		int iterate()
		{
			return iter;
		}

		Pair<T1, T2> Current_element()
		{
			return cur[iter];
		}

		void swap(Pair<T1, T2> s, int itr)
		{
			cur[itr] = s;
		}

		void Current()
		{
			cur[iter].show();
		}


		Pair<T1, T2> Second()
		{
			return cur[1];
			iter = 1;
		}

		bool is_end()
		{
			return (iter <= size - 1);
		}

		bool is_begin()
		{
			return (iter >= 0);
		}

		void Next()
		{
			iter++;
		}

		void Prev()
		{
			iter--;
		}

		Pair<T1, T2> Begin()
		{
			iter = 0;
			return cur[iter];
		}

		Pair<T1, T2> End()
		{
			iter = size - 1;
			return cur[size - 1];
		}

		void display(bool fl)
		{
			if (fl == false)
			{
				for (int i = 0; i < size; i++)
				{
					cur[i].show();
				}
			}
			if (fl == true)
			{
				for (int i = size - 1; i >= 0; i--)
				{
					cur[i].show();
				}
			}
		}

		void operator !()
		{
			iter = 0;
			cout << "Сброс итератора выполнен." << endl;
		}

		void reset()
		{
			iter = 0;
		}
	};


	class Algorithms
	{
	public:
		Pair<T1, T2>* cur;
		int size;

		Algorithms(Pair<T1, T2>* first, int s) :cur(first) { size = s; };

		list<std::pair<int, Product>> ChekCondition(int props)
		{
			Map<int, Product>::Iterator iter2 = Map<int, Product>::Iterator(cur, size);
			list<std::pair<int, Product>> mylist;
			std::list<std::pair<int, Product>>::iterator it = mylist.begin();
			for (iter2.Begin(); iter2.is_end(); iter2.Next())
			{
				if (iter2.Current2().get_key() > props)
					mylist.push_back(pair<int, Product>(iter2.Current2().get_key(), iter2.Current2().get_value()));
			}
			return mylist;
		}

		int return_size()
		{
			return size;
		}

		Pair<T1, T2>* return_map()
		{
			return cur;
		}

		void sort()
		{
			for (int i = 0; i < size; i++) {
				bool flag = true;
				for (int j = 0; j < size - (i + 1); j++) {
					if (map[j].get_key() > map[j + 1].get_key()) {
						flag = false;
						swap(map[j], map[j + 1]);
					}
				}
				if (flag) {
					break;
				}
			}
		}

		void show()
		{
			Map<int, Product>::Iterator iter2 = Map<int, Product>::Iterator();
			for (iter2.Begin(); iter2.is_end(); iter2.Next())
			{
				iter2.Current();
			}
		}
	};

	friend class Pair<T1, T2>;
	Map() {};
	Map(int size = 0)
	{
		map = new Pair<T1, T2>[size];
	}

	bool is_empty(T1 key)
	{
		bool flag = true;
		for (int i = 0; i < size; i++)
		{
			if (map[i].get_key() == key)
			{
				cout << "Запись с ключом [" << key << "] уже существует." << endl;
				return false;
			}
		}
		return flag;
	}

	void insert(T1 key_, T2 value_)
	{
		bool _is_not = false;
		_is_not = is_empty(key_);
		if (_is_not == true)
		{
			Map <T1, T2> tmp(size + 1); //Временный map
			for (int i = 0; i < size; i++)
			{
				tmp.map[i] = map[i]; //сохраняем поэлементно текущий мар
			}
			Pair<T1, T2> sf; //создаем элемент и задаем значения
			sf.set_key(key_);
			sf.set_value(value_);
			tmp.map[size] = sf;
			delete[] map;
			map = tmp.map;
			size++;
			sort();
		}
	}

	void sort()
	{
		for (int i = 0; i < size; i++) {
			bool flag = true;
			for (int j = 0; j < size - (i + 1); j++) {
				if (map[j].get_key() > map[j + 1].get_key()) {
					flag = false;
					swap(map[j], map[j + 1]);
				}
			}
			if (flag) {
				break;
			}
		}
	}
	Pair<T1, T2>* get_map()
	{
		return map;
	}

	int count()
	{
		return size;
	}

	void show()
	{
		sort();
		for (int i = 0; i < size; i++)
		{
			map[i].show();
		}
	}

	Pair<T1, T2> operator[] (const T1 & key)
	{
		bool flag = false;
		for (int i = 0; i < size; i++)
		{
			if (map[i].get_key() == key)
			{
				flag = true;
				cout << "############ Найденная пара ############" << endl;
				map[i].show();
				cout << "########################################" << endl;
				return map[i];
				break;
			}
		}
		if (flag == false)
		{
			cout << "############ Найденная пара ############" << endl;
			cout << "Такой пары нет." << endl;
			cout << "########################################" << endl;
			return map[0];
		}

	}

	void ChengeValue(T1 key)
	{
		bool flag = false;
		int index;
		for (int i = 0; i < size; i++)
		{
			if (map[i].get_key() == key)
			{
				flag = true;
				cout << "############ Найденная пара ############" << endl;
				map[i].show();
				index = i;
				cout << "########################################" << endl;
				break;
			}
		}
		if (flag == true)
		{
			T2 sotr_n;
			cout << "Введите наименование: " << endl;
			cin >> sotr_n.Name;
			cout << "Введите количество: " << endl;
			cin >> sotr_n.quantity;
			cout << "Введите стоимость: " << endl;
			cin >> sotr_n.cost;
			if (!cin)
			{
				cout << "Ошибка ввода." << endl;
				exit(0);
			}
			cout << "Введите дату поступления: " << endl;
			cin >> sotr_n.receiptDate;
			if (!cin)
			{
				cout << "Ошибка ввода." << endl;
				exit(0);
			}
			cout << "Введите новый ключ: " << endl;
			T1 k;
			cin >> k;
			if (!cin)
			{
				cout << "Ошибка ввода." << endl;
				exit(0);
			}
			map[index].set_value(sotr_n);
			map[index].set_key(k);
		}
		else
		{
			cout << "Такой пары нет." << endl;
		}
	}

	void sort(int props)
	{
		for (int counter = 1; counter < size; counter++)
		{
			auto temp = map[counter];
			auto item = counter - 1;
			while (item >= 0 && compare(map[item], temp, props))
			{
				map[item + 1] = map[item]; // перестановка элементов массива
				map[item] = temp;
				item--;
			}
		}
		for (int i = 0; i < size; i++)
		{
			map[i].show();
		}
	}
	bool compare(Pair<T1, T2> first, Pair<T1, T2> second, int props)
	{
		auto left = first.get_value();
		auto right = second.get_value();
		switch (props)
		{
		case 1: return left.Name[0] > right.Name[0] ? true : false;
		case 2: return left.quantity > right.quantity ? true : false;
		case 3: return left.cost > right.cost ? true : false;
		case 4: return left.receiptDate[0] > right.receiptDate[0] ? true : false;
		default: return left.cost > right.cost ? true : false;
		}
	}

	void erase(T1 key)
	{
		bool flag = false;
		for (int i = 0; i < size; i++)
		{
			if (map[i].get_key() == key)
			{
				flag = true;
			}
		}
		if (flag == true)
		{
			Map <T1, T2> tmp(size - 1); //создаем временный мар
			int f = 0;
			for (int i = 0; i < size; i++)
			{
				if (map[i].get_key() != key)
				{
					tmp.map[f] = map[i];
					f++;
				}
			}
			delete[] map;
			map = tmp.map;
			size--;
		}
		else {
			cout << "Такой пары нет" << endl;
		}
		sort();
	}

	void clear()
	{
		size = 0;
		map = new Pair<T1, T2>[0];
	}

	void testcopy() {
		Map<int, Product>::Iterator iter2 = Map<int, Product>::Iterator(this->get_map(), this->count());
		auto begin = iter2.Begin();
		auto end = iter2.End();
		Map<int, Product>::Algorithms alg = Map<int, Product>::Algorithms(this->get_map(), this->count());
		auto result = alg.ChekCondition(2);
		if (result.empty())
		{
			cout << "\nAll elements meet the condition" << endl;
		}
		else
		{
			cout << "\nItems not matching the condition" << endl;
			for (auto iter = result.begin(); iter != result.end(); iter++)
			{
				std::cout << "Ket: " << iter->first << "\t";
			}
		}
	}
};

Map<int, Product> addelement(Map<int, Product> my_map)
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
		cin >> sv.Name;
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
		cin >> sv.cost;
		if (!cin)
		{
			cout << "Ошибка ввода." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;;
		}
		cout << "Введите дату поступления: " << endl;
		cin >> sv.receiptDate;
		chek = false;

	}

	my_map.insert(k, sv); // Инсерт в map
	return my_map;
}
void output(Map<int, Product>::Iterator i)
{
	cout << "$$$$$$$$$$$$$$$$$$$$$ Цикл итератора прямой $$$$$$$$$$$$$$$$$$$$$" << endl;
	for (i.Begin(); i.is_end(); i.Next())
	{
		i.Current();
	}
	cout << "$$$$$$$$$$$$$$$$$$$$$ Цикл итератора обратный $$$$$$$$$$$$$$$$$$$" << endl;
	for (i.End(); i.is_begin(); i.Prev())
	{
		i.Current();
	}
}
void menu() {
	Map<int, Product> my_map(0);
	Map<int, Product>::Iterator i = Map<int, Product>::Iterator(my_map.get_map(), my_map.count());
	while (true)
	{
		int schose;
		cout << "1-Добавить элемент в map, 2- Вывод map, 3- Поиск по ключу, 4- Вывод количества записей, 5- Изменение map по ключу,"
			"\n6- Сортировка, 7- Удаление из map по ключу, 8- Инициализация итератора, 9- Вывод прямой(итератор),\n10- Вывод обратный(итератор)"
			"11- Сброс итератора, 12- Вывод прямой/обратный(Итератор циклы)" << endl;
		cin >> schose;
		switch (schose)
		{
		case 3: {int z; cout << "Введите ключ для поиска" << endl; cin >> z; if (!cin) { cout << "Ошибка ввода"; break; } my_map[z]; system("pause");  break; }
		case 2: {cout << "Вывод map:" << endl; my_map.show(); system("pause"); break; }
		case 1: {cout << "Добавление элементов в map" << endl; my_map = addelement(my_map); break; }
		case 4: {cout << "Количество записей: " << my_map.count() << endl; break; }
		case 5: {cout << "Введите ключ от пары в map, значение которой хотите изменить" << endl; int z; cin >> z; if (!cin) { cout << "Ошибка ввода" << endl; break; } my_map.ChengeValue(z); break; }
		case 6: {cout << "Сортировка Вставками(по объекту)" << endl; int z; cout << "Введите z(1-4)" << endl; cin >> z; if (!cin) { cout << "Ошибка ввода" << endl; break; }  my_map.sort(z); system("pause"); break; }
		case 7: {cout << "Введите ключ пары, которую хотите удалить" << endl; int z; cin >> z;   my_map.erase(z); my_map.show(); }
		case 8: {cout << "Инициализация итератора" << endl; i = Map<int, Product>::Iterator(my_map.get_map(), my_map.count()); }
		case 9: {cout << "Вывод прямой" << endl; i.display(false); system("pause"); break; }
		case 10: {cout << "Вывод обратный" << endl; i.display(true); system("pause"); break; }
		case 11: { !i; system("pause"); break; }
		case 12: {cout << "Вывод прямой/обратный" << endl; output(i); system("pause"); break; }
		case 13: {cout << "Тест копированя и проверки на соответсвие" << endl; my_map.testcopy(); system("pause"); break; }
		default:
			break;
		}
		system("cls");
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	menu();
}