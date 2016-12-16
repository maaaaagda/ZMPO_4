#pragma once
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;


const int DEF_SIZE = 5;
template <typename Data>
class CTable
{
	string s_name;
	int i_tabSize = DEF_SIZE;
	Data **tab;
	

public:
	CTable();
	CTable(int, string);
	CTable(CTable &pcOther);
	~CTable();
	void vSetName(string sName);
	string sGetName();
	void vSetTabSize(int iSize);
	void vAssignData(int iPlace, Data &iNr);
	Data & DataGetData(int iPlace);
	int iGetSize();
	//string sInfo();
	
};

template <typename Data>
CTable<Data>::CTable()
{
	s_name = "Without params";
	tab = new Data*[i_tabSize];
	for (int i = 0; i < i_tabSize; i++)
	{
		tab[i] = NULL;
	}
	cout << "bezp: " << s_name << endl;

}
template <typename Data>
CTable<Data>::CTable(int size, string sName)
{
	i_tabSize = size;
	s_name = sName;
	tab = new Data*[size];
	for (int i = 0; i < size; i++)
	{
		tab[i] = NULL;
	} 
	cout << "parametr: " << s_name << endl;
	
}
template <typename Data>
CTable<Data>::CTable::CTable(CTable &pcOther)
{
	cout << "kopiuj: " << s_name << endl;
	cout << "inside kopiuj 1" << endl;
	cin.get();
	cin.get();
	s_name = pcOther.s_name + "_copy";
	if (tab != NULL)delete[] tab;
	tab = new Data*[pcOther.i_tabSize];
	cout << "inside kopiuj 2 " << endl;
	cin.get();
	cin.get();
	for (int i = 0; i < pcOther.i_tabSize; i++)
	{
		if (pcOther.tab[i] != NULL)
		{
			cout << "inside kopiuj 3 =!null" << endl;
			cin.get();
			cin.get();
			tab[i] = new Data(*pcOther.tab[i]);
			cout << "kopiuj 4 nameeeeeeeeee" + (*tab[i]).getName()+" "+to_string(i);

		}
		else
		{
			tab[i] = NULL;
		}
	}

}
template <typename Data>
CTable<Data>::CTable::~CTable()
{
	for(int i=0; i<i_tabSize; i++)
	{
		if (tab[i] != NULL)
			delete tab[i];
	}
	delete[] tab;	//usun¹c forem porzadnie
	cout << "usuwam: " << s_name << endl;
}
template <typename Data>
void CTable<Data>::vSetName(string sName)
{
	s_name = sName;
}
template <typename Data>
void CTable<Data>::vSetTabSize(int iSize)
{
	if (iSize <= 0)
		throw out_of_range("Out of range");
	
	{
		Data **temp_tab = new Data*[iSize];

		for (int i = 0; i < i_tabSize; i++)
		{
			if(tab[i]!=NULL)
			{
				cout << "inside loop" << endl;
				cin.get();
				cin.get();
				temp_tab[i] = new Data (*tab[i]);

				cout << "inside loop 2" << endl;
				cin.get();
				cin.get();
			}
			else
			{
				temp_tab[i] = NULL;
			}
			
		}
		if (iSize>i_tabSize)
		{
			for (int i = i_tabSize; i<iSize; i++)
			{

				temp_tab[i] = NULL;
			}
		}

		delete[]tab;
		tab = temp_tab;

		i_tabSize = iSize;
		
	}
}
template <typename Data>
void CTable<Data>::vAssignData(int iPlace, Data& iNr)
{
	if (iPlace < 0 || iPlace >= i_tabSize)
	{
		throw out_of_range("Out of range");
	}
	tab[iPlace] = new Data(iNr);
}
template <typename Data>
Data &CTable<Data>::DataGetData(int iPlace)
{
	cout << "getdata 1" << endl;
	cin.get();
	cin.get();
	if ((iPlace <= 0) || (iPlace > i_tabSize))
	{
		cout << "getdata wrong size" << endl;
		cin.get();
		cin.get();
		throw out_of_range("Out of range");
	}
	cout << "getdata 2 outside" << endl;
	cin.get();
	cin.get();
	cout << "getdata plzzzzzzz"+ (*tab[iPlace]).getName() << endl;
	cin.get();
	cin.get();
	return *tab[iPlace];
	
		
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
/*
template <typename Data>
string CTable<Data>::sInfo()
{
	string s;
	s = s_name + " len: " + to_string(i_tabSize) + " wartosci: ";
	for (int i = 0; i < i_tabSize; i++)
	{
		s = s + (*tab[i]) + ", ";
	}
	return s;
}
*/


