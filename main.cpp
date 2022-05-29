#include <iostream>
#include "IsKPeriodic.h"

// тесирование работы функции периодичности строки IsKPeriodic
int main()
{
	//проверка работы в кратной строке с кратностью 3
	std::string str = "abcabcabcabcab";
	
	IsKPeriodic(str, 2);
	IsKPeriodic(str, 3);

	//проверка работы в не кратной строке
	str = "abcabcabe";
	IsKPeriodic(str, 2);

	return 0;
}