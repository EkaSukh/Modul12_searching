#include <iostream>
#include "IsKPeriodic.h"

// ����������� ������ ������� ������������� ������ IsKPeriodic
int main()
{
	//�������� ������ � ������� ������ � ���������� 3
	std::string str = "abcabcabcabcab";
	
	IsKPeriodic(str, 2);
	IsKPeriodic(str, 3);

	//�������� ������ � �� ������� ������
	str = "abcabcabe";
	IsKPeriodic(str, 2);

	return 0;
}