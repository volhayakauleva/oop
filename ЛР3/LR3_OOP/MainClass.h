#define _CRT_SECURE_NO_WARNINGS
#ifndef _MAINCLASS_H_
#define _MAINCLASS_H_
#include <cstring>
#include <fstream>
#include <iomanip>
#include <stdlib.h>ммм
#include <time.h>
#include <ctime>
#include <iostream>

using namespace std;
template <typename T1, typename T2>
struct elements {
    T1 name;
    T2 value;
    double cost;
    tm receiptDate;
    struct elements* next;

    elements()
    {
        next = NULL;
    }
};
template <typename T1, typename T2>
class MainClass
{
private:
   
    
public:

    elements<T1, T2>* first;
    MainClass();
    int Count();
    void addLast(T1 name, T2 value, double cost, const char* receiptDate);
    tm convertor(const char* str);
    static tm cconvertor2(const char* str);
    void addAfter(elements<T1, T2>* p, T1 name, T2 value, double cost, const char* receiptDate);
    void Sort(int pole);
    void swap(elements<T1, T2>* q, elements<T1, T2>* p);
    void outputWithCondition(double needcost);
    void outputWithCondition(tm needdate);
    void outputWithCondition(tm needdate, double needcost);
    bool compateTwoDates(tm d1, tm d2);
    //переопределен метод вывода
    friend ostream& operator<< (ostream& str, const MainClass<T1, T2>& ov)
    {
        elements<T1, T2>* current = ov.first;
        while (current != NULL)
        {
            str << current->name << " " << current->value << " " << current->cost << " "
                << current->receiptDate.tm_mday << ":" << current->receiptDate.tm_mon
                << ":" << current->receiptDate.tm_year << endl;
            current = current->next;
        }
        return str;
    }
};
#endif
