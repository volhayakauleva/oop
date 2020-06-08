#define _CRT_SECURE_NO_WARNINGS
#include "MainClass.h"



MainClass<string,int>::MainClass() {
    first = NULL;
}


template<typename T1, typename T2>
int MainClass<T1, T2>::Count() {
    elements<T1, T2>* q = first;
    int i = 0;
    while (q->next != NULL) {
        i++;
        q = q->next;
    }
    return i + 1;
}


void MainClass<string,int>::addLast(string name, int value, double cost, const char* receiptDate) {
  
    elements<string, int>* q = first;
    if (first == NULL) {
        elements<string, int>* tmp = new elements<string, int>;
        tmp->name = name;
        tmp->value = value;
        tmp->cost = cost;
        tmp->receiptDate = convertor(receiptDate);

        tmp->next = NULL;
        first = tmp;
        return;
    }
    while (q != NULL) {
        if (q->next == NULL) {
            addAfter(q, name, value, cost, receiptDate);
            return;
        }
        q = q->next;
    }
}

template <> tm MainClass<string, int>::convertor(const char* str)
{
    int day, month, year;
    sscanf(str, "%d:%d:%d", &day, &month, &year);

    time_t rawtime;
    struct tm* timeinfo = { 0 };
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    timeinfo->tm_year = year;
    timeinfo->tm_mon = month;
    timeinfo->tm_mday = day;
    return *timeinfo;
}

tm MainClass<string, int>::cconvertor2(const char* str)
{
    int day, month, year;
    sscanf(str, "%d-%d-%d;", &day, &month, &year);
    struct tm timeinfo = { 0 };
    timeinfo.tm_year = year;
    timeinfo.tm_mon = month;
    timeinfo.tm_mday = day;
    timeinfo.tm_isdst = -1;
    return timeinfo;
};

template<typename T1, typename T2>
void MainClass<T1, T2>::addAfter(elements<T1, T2>* p, T1 name, T2 value, double cost, const char* receiptDate) {

    elements<string, int>* tmp = new elements<string, int>;
    tmp->name = name;
    tmp->value = value;
    tmp->cost = cost;
    tmp->receiptDate = convertor(receiptDate);
    tmp->next = p->next;
    p->next = tmp;
    p->next = tmp;
}


//template<typename T1, typename T2>
void MainClass<string, int>::Sort(int pole) {
    for (int d = (Count() / 2) + 1; d > 0; d--) {
        int i = 0;
        while (i + d < Count()) {
            elements<string, int>* tmp = first;
            int count = 0;
            while (count < i) {
                tmp = tmp->next;
                ++count;
            }
            elements<string, int>* q = tmp;
            while (count < i + d) {
                tmp = tmp->next;
                ++count;
            }
            elements<string, int>* p = tmp;
            switch (pole)
            {
            case 0:
                if (q->name[0] > p->name[0])
                {
                    swap(q, p);
                }
                break;
            case 1:
                if (q->value > p->value)
                {
                    swap(q, p);
                }
                break;
            case 2:
                if (q->cost > p->cost)
                {
                    swap(q, p);
                }
                break;
            case 3:

                if (compateTwoDates(q->receiptDate, p->receiptDate))
                {
                    swap(q, p);
                }
                break;
            default:
                throw "Ошибка сортировки";
            }

            ++i;
        }
    }
}

template<typename T1, typename T2>
void MainClass<T1, T2>::swap(elements<T1, T2>* q, elements<T1, T2>* p)
{
    T1 qvalue = q->name.substr(0, q->name.size());
    q->name = p->name.substr(0, p->name.size());
    p->name = qvalue;

    T2 qvalue2 = q->value;
    q->value = p->value;
    p->value = qvalue2;

    double tmpcost = q->cost;
    q->cost = p->cost;
    p->cost = tmpcost;

    tm tmpdate = q->receiptDate;
    q->receiptDate = p->receiptDate;
    p->receiptDate = tmpdate;
}

#pragma region перегруженные функции параметризованного вывода
void MainClass<string, int>::outputWithCondition(double needcost)
{
    elements<string, int>* current = this->first;
    while (current != NULL)
    {
        if (current->cost > needcost)
            cout << endl << setw(10) << left << current->name << setw(10) << left << current->value << setw(10) << left << current->cost << current->receiptDate.tm_mday << ":" << current->receiptDate.tm_mon
            << ":" << current->receiptDate.tm_year << endl;
        current = current->next;
    }
    cout << "###########################################";

}

void MainClass<string,int>::outputWithCondition(tm needdate)
{
    elements<string, int>* current = this->first;
    while (current != NULL)
    {
        if (compateTwoDates(current->receiptDate, needdate))
            cout << endl << setw(10) << left << current->name << setw(10) << left << current->value << setw(10) << left << current->cost << current->receiptDate.tm_mday << ":" << current->receiptDate.tm_mon
            << ":" << current->receiptDate.tm_year << endl;
        current = current->next;
    }
    cout << "###########################################";

}
void MainClass<string, int>::outputWithCondition(tm needdate, double needcost)
{
    elements<string, int>* current = this->first;
    while (current != NULL)
    {
        if (compateTwoDates(current->receiptDate, needdate) && current->cost > needcost)
            cout << endl << setw(10) << left << current->name << setw(10) << left << current->value << setw(10) << left << current->cost << current->receiptDate.tm_mday << ":" << current->receiptDate.tm_mon
            << ":" << current->receiptDate.tm_year << endl;
        current = current->next;
    }
    cout << "###########################################";
}

template<typename T1, typename T2>
bool MainClass<T1, T2>::compateTwoDates(tm d1, tm d2)
{
    long int date1 = d1.tm_year * 8784 + d1.tm_mday * 24 + (d1.tm_mon + 1) * 744;
    long int date2 = d2.tm_year * 8784 + d2.tm_mday * 24 + (d2.tm_mon + 1) * 744;

    return date1 > date2 ? true : false;
}
#pragma endregion




