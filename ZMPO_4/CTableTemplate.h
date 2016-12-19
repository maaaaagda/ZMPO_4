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
	string sInfo();
	
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
	s_name = pcOther.s_name + "_copy";
	if (tab != NULL)delete[] tab;
	tab = new Data*[pcOther.i_tabSize];
	i_tabSize = pcOther.i_tabSize;
	for (int i = 0; i < i_tabSize; i++)
	{
		if (pcOther.tab[i] != NULL)
		{
			tab[i] = new Data(*pcOther.tab[i]);
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
	delete[] tab;	
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
				temp_tab[i] = new Data (*tab[i]);
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
		for (int i = 0; i<i_tabSize; i++)
		{
			if (tab[i] != NULL)
				delete tab[i];
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
	if ((iPlace <= 0) || (iPlace > i_tabSize))
	{
		throw out_of_range("Out of range");
	}
	if(tab[iPlace]== nullptr)
		throw out_of_range("Data does not exist");
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

template <typename Data>
string CTable<Data>::sInfo()
{
	string s;
	s = s_name + " len: " + to_string(i_tabSize) + " wartosci: ";
	for (int i = 0; i < i_tabSize; i++)
	{
		s = s + (to_string(*tab[i])) + ", ";
	}
	return s;
}



template <typename Data>
string createDef(CTable<Data> **ctab, int nrTablicy)
{
	ctab[nrTablicy] = new CTable<Data>();
	return "done";
}
template <typename Data>
string create(CTable<Data> **ctab, int nrTablicy, int rozmiar, string nazwaTablicy)
{
	ctab[nrTablicy] = new CTable<Data>(rozmiar, nazwaTablicy);
	return "done";

}
template <typename Data>
string createCopy(CTable<Data> **ctab, int nrTablicy, int nrTablicyDoKopiowania)
{
	ctab[nrTablicy] = new CTable<Data>(*ctab[nrTablicyDoKopiowania]);
	return "done";
}
template <typename Data>
string setValue(CTable<Data> **ctab, int nrTablicy, int nrPozycji, Data wartoœæ)
{
	try
	{
		(*ctab[nrTablicy]).vAssignData(nrPozycji, wartoœæ);
		return "done";
	}
	catch(out_of_range)
	{
		return "error";
	}
	
}
template <typename Data>
Data getValue(CTable<Data> **ctab, int nrTablicy, int nrPozycji)
{
	try
	{
		return (*ctab[nrTablicy]).DataGetData(nrPozycji);
	}
	catch (out_of_range)
	{
		return NULL;
	}
	
}
template <typename Data>
string setName(CTable<Data> **ctab, int nrTablicy, string nazwaTablicy)
{
	(*ctab[nrTablicy]).vSetName(nazwaTablicy);
	return "done";
}
template <typename Data>
string getName(CTable<Data> **ctab, int nrTablicy)
{
	return (*ctab[nrTablicy]).sGetName();
}
template <typename Data>
int getSize(CTable<Data> **ctab, int nrTablicy)
{
	return (*ctab[nrTablicy]).iGetSize();
}
template <typename Data>
string setSize(CTable<Data> **ctab, int nrTablicy, int rozmiarTablicy)
{
	try
	{
		(*ctab[nrTablicy]).vSetTabSize(rozmiarTablicy);
		return "done";
	}
	catch (out_of_range)
	{
		return "error";
	}
	
}
template <typename Data>
string info(CTable<Data> **ctab, int nrTablicy)
{
	return (*ctab[nrTablicy]).sInfo();
}

template <typename Data>
string deleteObject(CTable<Data> **ctab, int nrTablicy)
{
	delete ctab[nrTablicy];
	return "done";
}
template <typename Data>
string clear(CTable<Data> **ctab, int nrTablicy)
{
	for (int i = 0; i < (*ctab[nrTablicy]).iGetSize(); i++)
	{
		ctab[nrTablicy] = NULL;
	}
	return "done";
}

