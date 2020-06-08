#define _CRT_SECURE_NO_WARNINGS

#include "MainClass.h"
#include "TextFile.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    MainClass<string, int> spsk1;
    spsk1.addLast("Редиска", 100, 12.50, "20:01:2020");
    spsk1.addLast("Картошка",99, 23.80 , "20:01:2020");
    spsk1.addLast("Груша", 30, 1.50, "20:02:2019");
    spsk1.addLast("Морковь", 28, 5.50, "20:03:2019");
    spsk1.addLast("Капуста", 45, 1.50, "20:04:2019");

    spsk1.Sort(3);
    cout << spsk1;

    spsk1.outputWithCondition(10);
    spsk1.outputWithCondition(MainClass<string,int>::cconvertor2("01-01-2020"), 10);
    TextFile<string, int>::WriteInFile(spsk1);
    TextFile<string, int>::ReadFromFile();
}