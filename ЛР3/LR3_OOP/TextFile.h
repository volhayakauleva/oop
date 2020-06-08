#pragma once
#include <fstream>
#include "MainClass.h"

template <typename T1, typename T2>
class TextFile
{
public:
	static void ReadFromFile();
	static void WriteInFile(MainClass<T1, T2> element);
};

