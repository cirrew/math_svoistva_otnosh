#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;



void pri(vector<string> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
	cout << endl;
}

int main()
{
	ifstream f;
	string str;
	system("chcp 1251 > null");
	string l;
	vector<string> matr;
	string fileName = "";
	system("cls");
	while (str!="n" && str!="N" && str!="0")
	{
		matr.clear();
		cout << "file? ";
		str = "";
		cin >> fileName;
		fileName += ".txt";
		f.open(fileName);
		if (!f)
		{
			system("cls");
			cout << "Файл не найден" << endl;
			continue;
		}
		while (getline(f, l))
		{
			matr.push_back(l);
		}
		pri(matr);
		for (int i = 0; i < matr.size(); i++)
		{
			l = matr[i];
			for (int j = 0; j < l.length(); j++)
			{
				if (l[j] == ' ')
				{
					l.erase(j, 1);
					j--;
				}
			}
			matr[i] = l;
		}
		bool ifCorr = true;
		if (matr.size() != 6)
		{
			ifCorr = false;
		}
		for (int i = 0; i < matr.size(); i++)
		{
			if (matr[i].length() != 6)
			{
				ifCorr = false;
			}
		}
		for (int i = 0; i < matr.size(); i++)
		{
			for (int j = 0; j < matr[i].length(); j++)
			{
				if (matr[i][j] != '0' && matr[i][j] != '1')
				{
					ifCorr = false;
				}
			}
		}
		if (ifCorr == false)
		{
			system("cls");
			cout << "Матрица не соответствует условиям" << endl;
			f.close();
			continue;
		}
		f.close();
		int q = 0;
		for (int i = 0; i < 6; i++)
		{
			if (matr[i][i] == '1')
			{
				q++;
			}
		}
		string reflex = "отношение";
		switch (q)
		{
		case 0:
		{
			reflex = "Антирефлексивное " + reflex;
			break;
		}
		case 6:
		{
			reflex = "Рефлексивное " + reflex;
			break;
		}
		default:
		{
			reflex = "Частично рефлексивное " + reflex;
			break;
		}
		}
		bool isSymmetr = true;
		bool isAsymmetr = true;
		string symmetr = "отношение";
		int symmetrCount = 0;
		for (int i = 0; i < 5; i++)
		{
			for (int j = i + 1; j < 6; j++)
			{
				if (matr[i][j] != matr[j][i])
				{
					isSymmetr = false;
				}
				if (matr[i][j] == matr[j][i] && matr[i][j] == '1')
				{
					symmetrCount++;
				}
			}
		}
		if (symmetrCount == 0)
		{
			isSymmetr = false;
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = i + 1; j < 6; j++)
			{
				if (matr[i][j] == matr[j][i] && matr[i][j] == '1')
				{
					isAsymmetr = false;
				}
			}
		}
		if (isSymmetr)
		{
			symmetr = "Симметричное " + symmetr;
		}
		if (isAsymmetr)
		{
			if (q == 6)
			{
				symmetr = "Антисимметричное " + symmetr;
			}
			else
			{
				if (q == 0)
				{
					symmetr = "Ассиметричное " + symmetr;
				}
				else
				{
					symmetr = "Никакой симметричности нет";
				}
			}
		}
		if (!isSymmetr && !isAsymmetr)
		{
			symmetr = "Никакой симметричности нет";
		}
		bool isTranzit = true;
		for (int i = 0; i < 6; i++) //строка первой точки
		{
			for (int j = 0; j < 6; j++) //столбец первой точки
			{
				for (int k = 0; k < 6; k++) //строка второй точки
				{
					for (int z = 0; z < 6; z++) //столбец второй точки
					{
						if (i != j && i != k && i != z && j != k && j != z && k != z)
						{
							if (matr[i][j] == '1' && matr[k][z] == '1')
							{
								if (matr[i][z] == '0')
								{
									isTranzit = false;
								}
							}
						}
					}
				}
			}
		}
		string tranzit = "ранзитивное отношение";
		if (isTranzit)
		{
			tranzit = "Т" + tranzit;
		}
		else
		{
			tranzit = "Не т" + tranzit;
		}
		bool isSvyazn = true;
		for (int i = 0; i < 5; i++)
		{
			for (int j = i + 1; j < 6; j++)
			{
				if (matr[i][j] == '0' && matr[j][i] == '0')
				{
					isSvyazn = false;
				}
			}
		}
		string svyazn = "вязное отношение";
		if (isSvyazn)
		{
			svyazn = "С" + svyazn;
		}
		else
		{
			svyazn = "Не с" + svyazn;
		}
		cout << reflex << endl << symmetr << endl << tranzit << endl << svyazn << endl;
		cout << "\n\nContinue? 'n' to exit\n" << endl;
		cin >> str;
		system("cls");
	}
	return 0;
}