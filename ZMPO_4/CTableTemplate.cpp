
#include "stdafx.h"
#include "stdlib.h"
#include "CTableTemplate.h"
/*
template <typename Data>
CTable<Data>::CTable()
{
	s_name = "Without params";
	tab = new int[i_tabSize];
	for (int i = 0; i < i_tabSize; i++)
	{
		tab[i] = NULL;
	}
	cout << "bezp: " << s_name << endl;

}
template <typename Data>
CTable<Data>::CTable(int size, string sName)
{
	s_name = sName;
	tab = new Data[size];
	for (int i = 0; i < size; i++)
	{
		tab[i] = NULL;
	}
	cout << "parametr: " << s_name << endl;
	//przy przekopiowywaniu maj¹ byc ustawione -jedynki
}
template <typename Data>
CTable<Data>::CTable::CTable(CTable &pcOther)
{
	s_name = pcOther.s_name + "_copy";
	tab = new Data[pcOther.i_tabSize];
	for (int i = 0; i < pcOther.i_tabSize; i++)
	{
		tab[i] = pcOther.tab[i];
	}

	cout << "kopiuj: " << s_name << endl;

}
template <typename Data>
CTable<Data>::CTable::~CTable()
{
	delete[] tab;
	cout << "usuwam: " << s_name << endl;
}
template <typename Data>
void CTable<Data>::vSetName(string sName)
{
	s_name = sName;
}
template <typename Data>
string CTable<Data>::sSetTabSize(int iSize)
{
	if (iSize <= 0)
		return "error";
	else
	{
		int *temp_tab = new Data[iSize];

		for (int i = 0; i < i_tabSize; i++)
		{

			temp_tab[i] = tab[i];
		}
		if(iSize>i_tabSize)
		{
			for (int i = i_tabSize; i<iSize; i++)
			{

				temp_tab[i] = NULL;
			}
		}

		delete[]tab;
		tab = temp_tab;

		i_tabSize = iSize;
		return "done";
	}
}
template <typename Data>
string CTable<Data>::sAssignNumber(int iPlace, Data iNr)
{
	if (iPlace >= 0 && iPlace <i_tabSize)
	{
		tab[iPlace] = iNr;
		return "done";
	}
	else
		return "error";
}
template <typename Data>
Data CTable<Data>::iGetData(int iPlace)
{
	if ((iPlace <= 0) || (iPlace > i_tabSize))
		return  NULL;  //can not be
	else
		return tab[iPlace];
}
template <typename Data>
int CTable<Data>::iGetSize()
{
	return i_tabSize;
}


template <typename Data>
string CTable<Data>::sGetName()
{
	return s_name;
}

template <typename Data>
string CTable<Data>::sInfo()
{
	string s;
	s = s_name + " len: " + to_string(i_tabSize) + " wartosci: ";
	for (int i = 0; i < i_tabSize; i++)
	{
		s = s + to_string(tab[i]) + ", ";
	}
	return s;
}
template <typename Data>
CTable<Data> CTable<Data>::cClone(CTable cA)
{
	CTable cB = CTable();
	cB.s_name = cA.s_name;
	cB.sSetTabSize(cA.i_tabSize);
	return cB;

}
*/