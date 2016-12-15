
#include "stdafx.h"
#include "stdlib.h"
#include "CTableTemplate.h"

CTable::CTable()
{
	s_name = "Without params";
	tab = new int[i_tabSize];
	for (int i = 0; i < i_tabSize; i++)
	{
		tab[i] = -1;
	}
	cout << "bezp: " << s_name << endl;

}
CTable::CTable(int size, string sName)
{
	s_name = sName;
	tab = new int[size];
	for (int i = 0; i < size; i++)
	{
		tab[i] = -1;
	}
	cout << "parametr: " << s_name << endl;

}
CTable::CTable(CTable &pcOther)
{
	s_name = pcOther.s_name + "_copy";
	tab = new int[pcOther.i_tabSize];
	for (int i = 0; i < pcOther.i_tabSize; i++)
	{
		tab[i] = pcOther.tab[i];
	}

	cout << "kopiuj: " << s_name << endl;

}
CTable::~CTable()
{
	delete[] tab;
	cout << "usuwam: " << s_name << endl;
}
void CTable::vSetName(string sName)
{
	s_name = sName;
}

string CTable::sSetTabSize(int iSize)
{
	if (iSize <= 0)
		return "error";
	else
	{
		int *temp_tab = new int[iSize];

		for (int i = 0; i < i_tabSize; i++)
		{

			temp_tab[i] = tab[i];
		}


		delete[]tab;
		tab = temp_tab;

		i_tabSize = iSize;
		return "done";
	}
}
string CTable::sAssignNumber(int iPlace, int iNr)
{
	if (iPlace >= 0 && iPlace <i_tabSize)
	{
		tab[iPlace] = iNr;
		return "done";
	}
	else
		return "error";
}
int CTable::iGetNumber(int iPlace)
{
	if ((iPlace <= 0) || (iPlace > i_tabSize))
		return  -1;
	else
		return tab[iPlace];
}
int CTable::iGetSize()
{
	return i_tabSize;
}
string CTable::sChangeATabToB(CTable cA, CTable cB)
{
	cA.s_name = cB.s_name;
	cA.i_tabSize = cB.i_tabSize;
	int *piTemp_tab = new int[cB.i_tabSize];
	for (int i = 0; i < cB.i_tabSize; i++)
	{
		piTemp_tab[i] = cB.tab[i];
	}
	delete[] cA.tab;
	cA.tab = piTemp_tab;
	return "done";
}

string CTable::sGetName()
{
	return s_name;
}

string CTable::sInfo()
{
	string s;
	s = s_name + " len: " + to_string(i_tabSize) + " wartosci: ";
	for (int i = 0; i < i_tabSize; i++)
	{
		s = s + to_string(tab[i]) + ", ";
	}
	return s;
}
CTable CTable::cClone(CTable cA)
{
	CTable cB = CTable();
	cB.s_name = cA.s_name;
	cB.sSetTabSize(cA.i_tabSize);
	return cB;

}