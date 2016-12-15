#pragma once
#include <iostream>
#include <string>

using namespace std;


class CTable
{
	string s_name;
	int i_tabSize = 5;
	int *tab;

public:
	CTable();
	CTable(int, string);
	CTable(CTable &pcOther);
	~CTable();
	void vSetName(string sName);
	string sGetName();
	string sSetTabSize(int iSize);
	string sAssignNumber(int iPlace, int iNr);
	int iGetNumber(int iPlace);
	int iGetSize();
	string sChangeATabToB(CTable cA, CTable cB);
	string sInfo();
	CTable cClone(CTable cA);

};
