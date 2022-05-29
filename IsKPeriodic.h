#pragma once
#include <iostream>

//опорным массивом является lps массив
//если строка имеет период повторяемости, то значения lps[i] для первого периода равны 0
//далее занчения массива lps увеличиваются на 1

//фуекция подсчета занчений lps
void computeLPS(std::string pat, int* lps)
{
	//первый элемент всегда равен 0
	lps[0] = 0;

	//индексы движения по массиву
	int i = 1;
	int j = 0;

	//движение по массиву
	while (i < pat.size())
	{
		//условие увеличения значения в lps массиве
		if (pat[i] == pat[j])
		{
			j++;
			lps[i] = j;
			i++;
		}
		//условие движения по строке без совпадений
		else
		{
			if (j != 0)
				j = lps[j - 1];
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

//посдчет кратности строки
void IsKPeriodic(const std::string& str, int k)
{
	//проверка корректности введенного периода
	if (k <= 0)
	{
		std::cout << "The k value should be greater than zero";
		return;
	}

	//создание и подстчет массива lps
	size_t N = str.size();
	int* lps = new int[N];
	computeLPS(str, lps);

	//подсчет истинной кратности
	int count_s = 0;

	//движение по lps массиву
	for (int i = 0; i < N - 1; i++)
	{
		//условие увеличения кратности
		if (lps[i] == 0)
			++count_s;

		//условия нарушения кратности в строке
		if (lps[i] >= lps[i + 1] && lps[i] != 0)
		{
			std::cout << "string is not periodic\n";
			return;
		}
	}

//проверка истинной кратности к значению пользователя
	//совпадение кратностей
	if (k == count_s)
	{
		//целое число периодов
		if (N % count_s == 0)
			std::cout << "string is completely periodic to K = " << count_s << " symbols.\n";
		//не целое число периодов
		else
			std::cout << "sring has period of K = " << count_s << " symbols. Nubmer of periods is not an integer.\n";
	}
	//не совпадение кратностей
	else
		std::cout << "string has other period than K = " << k << std::endl;

	//удаление динамической памяти, выделенной для lps массива
	delete[] lps;
}

