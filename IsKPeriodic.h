#pragma once
#include <iostream>

//������� �������� �������� lps ������
//���� ������ ����� ������ �������������, �� �������� lps[i] ��� ������� ������� ����� 0
//����� �������� ������� lps ������������� �� 1

//������� �������� �������� lps
void computeLPS(std::string pat, int* lps)
{
	//������ ������� ������ ����� 0
	lps[0] = 0;

	//������� �������� �� �������
	int i = 1;
	int j = 0;

	//�������� �� �������
	while (i < pat.size())
	{
		//������� ���������� �������� � lps �������
		if (pat[i] == pat[j])
		{
			j++;
			lps[i] = j;
			i++;
		}
		//������� �������� �� ������ ��� ����������
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

//������� ��������� ������
void IsKPeriodic(const std::string& str, int k)
{
	//�������� ������������ ���������� �������
	if (k <= 0)
	{
		std::cout << "The k value should be greater than zero";
		return;
	}

	//�������� � �������� ������� lps
	size_t N = str.size();
	int* lps = new int[N];
	computeLPS(str, lps);

	//������� �������� ���������
	int count_s = 0;

	//�������� �� lps �������
	for (int i = 0; i < N - 1; i++)
	{
		//������� ���������� ���������
		if (lps[i] == 0)
			++count_s;

		//������� ��������� ��������� � ������
		if (lps[i] >= lps[i + 1] && lps[i] != 0)
		{
			std::cout << "string is not periodic\n";
			return;
		}
	}

//�������� �������� ��������� � �������� ������������
	//���������� ����������
	if (k == count_s)
	{
		//����� ����� ��������
		if (N % count_s == 0)
			std::cout << "string is completely periodic to K = " << count_s << " symbols.\n";
		//�� ����� ����� ��������
		else
			std::cout << "sring has period of K = " << count_s << " symbols. Nubmer of periods is not an integer.\n";
	}
	//�� ���������� ����������
	else
		std::cout << "string has other period than K = " << k << std::endl;

	//�������� ������������ ������, ���������� ��� lps �������
	delete[] lps;
}

