#include "TextFile.h"

void TextFile<string, int>::WriteInFile(MainClass<string, int> element)
{
    ofstream outFile("text.txt", ofstream::out);
    elements<string, int>* current = element.first;
    while (current != NULL)
    {
        outFile << current->name << " "
            << current->value << " "
            << current->cost << " "
            << current->receiptDate.tm_mday << ":" << current->receiptDate.tm_mon << ":" << current->receiptDate.tm_year << " "
            << endl;
        current = current->next;
    }
    outFile.close();
}

void TextFile<string, int>::ReadFromFile()
{
    std::ifstream in("text.txt");
    string name;
    int value;
    double cost;
    string getdate;

    MainClass <string, int> spsk2;
    if (in.is_open())
    {
        while (in >> name >> value >> cost >> getdate)
        {
            spsk2.addLast(name, value, cost, getdate.c_str());
        }
    }
    in.close();
    int chose = 0;
    cout << endl << "Выбор поля для сортировки (0-3)" << endl;
    cin >> chose;
    spsk2.Sort(chose);

    tm test = spsk2.convertor("01:01:2020");
    spsk2.outputWithCondition(spsk2.convertor("01:01:2020"), 1);
    spsk2.outputWithCondition(1);
    spsk2.outputWithCondition(test);
}