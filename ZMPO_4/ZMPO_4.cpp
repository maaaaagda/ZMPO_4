// ZMPO_4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "CTableTemplate.h"



	string createDef(CTable **ctab, int nrTablicy)
	{
		ctab[nrTablicy] = new CTable();
		return "done";
	}
	string create(CTable **ctab, int nrTablicy, int rozmiar, string nazwaTablicy)
	{
		ctab[nrTablicy] = new CTable(rozmiar, nazwaTablicy);
		//(*ctab[nrTablicy]).sSetTabSize(rozmiar);
		return "done";

	}
	string createCopy(CTable **ctab, int nrTablicy, int nrTablicyDoKopiowania)
	{
		ctab[nrTablicy] = new CTable(*ctab[nrTablicyDoKopiowania]);
		return "done";
	}
	string setValue(CTable **ctab, int nrTablicy, int nrPozycji, int wartoœæ)
	{
		(*ctab[nrTablicy]).sAssignNumber(nrPozycji, wartoœæ);
		return "done";
	}

	int getValue(CTable **ctab, int nrTablicy, int nrPozycji)
	{
		return (*ctab[nrTablicy]).iGetNumber(nrPozycji);
	}

	string setName(CTable **ctab, int nrTablicy, string nazwaTablicy)
	{
		(*ctab[nrTablicy]).vSetName(nazwaTablicy);
		return "done";
	}

	string getName(CTable **ctab, int nrTablicy)
	{
		return (*ctab[nrTablicy]).sGetName();
	}
	int getSize(CTable **ctab, int nrTablicy)
	{
		return (*ctab[nrTablicy]).iGetSize();
	}
	string setSize(CTable **ctab, int nrTablicy, int rozmiarTablicy)
	{
		(*ctab[nrTablicy]).sSetTabSize(rozmiarTablicy);
		return "done";
	}
	string info(CTable **ctab, int nrTablicy)
	{
		return (*ctab[nrTablicy]).sInfo();
	}
	string deleteObject(CTable **ctab, int nrTablicy)
	{
		delete ctab[nrTablicy];
		return "done";
	}
	string clear(CTable **ctab, int nrTablicy)
	{
		for (int i = 0; i < (*ctab[nrTablicy]).iGetSize(); i++)
		{
			(*ctab[nrTablicy]).sAssignNumber(i, -1);
		}
		return "done";
	}


	int main()
	{
		int isSize;// = 3;
		string sDef;
		bool end = false;
		cout << "Ile obiektow klasy CTable chcesz utworzyc?" << endl;
		cin >> isSize;



		CTable **c_Tab = new CTable*[isSize];
		while (end != true)
		{
			cout << "Podaj komende: " << endl;
			cin >> sDef;
			if (sDef == "createDef")
			{
				int nrTablicy;
				cout << "NrTablicy: ";
				cin >> nrTablicy;
				if (nrTablicy >= 0 && nrTablicy < isSize)
				{
					createDef(c_Tab, nrTablicy);
				}
				else
					cout << "Nie mam takiego pola tablicy. Sprobuj ponownie.";

			}
			else if (sDef == "create")
			{
				int nrTablicy, rozmiar;
				string nazwaTablicy;
				cout << "nrTablicy: ";
				cin >> nrTablicy;
				if (nrTablicy >= 0 && nrTablicy < isSize)
				{
					cout << "rozmiarTablicy: ";
					cin >> rozmiar;
					cout << "nazwaTablicy: " << endl;
					cin >> nazwaTablicy;
					create(c_Tab, nrTablicy, rozmiar, nazwaTablicy);
				}
				else
					cout << "Nie mam takiego pola tablicy. Sprobuj ponownie.";
			}
			else if (sDef == "createCopy")
			{
				int nrTablicy, nrTablicyDoKopiowania;
				cout << "nrTablicy: ";
				cin >> nrTablicy;
				if (nrTablicy >= 0 && nrTablicy < isSize)
				{
					cout << "nrTablicyDoKOpiowania: ";
					cin >> nrTablicyDoKopiowania;
					if (nrTablicyDoKopiowania >= 0 && nrTablicyDoKopiowania < isSize)
					{
						createCopy(c_Tab, nrTablicy, nrTablicyDoKopiowania);
					}
					else
						cout << "Nie mam takiego pola tablicy. Spróbuj ponownie.";

				}
				else
					cout << "Nie mam takiego pola tablicy. Sprobuj ponownie.";

			}
			else if (sDef == "setValue")
			{
				int nrTablicy, nrPozycji, wartosc;
				cout << "nrTablicy: ";
				cin >> nrTablicy;
				if (nrTablicy >= 0 && nrTablicy < isSize)
				{
					cout << "nrPozycji: ";
					cin >> nrPozycji;
					cout << "wartosc: ";
					cin >> wartosc;
					setValue(c_Tab, nrTablicy, nrPozycji, wartosc);

				}
				else
					cout << "Nie mam takiego pola tablicy. Sprobuj ponownie.";

			}
			else if (sDef == "getValue")
			{
				int nrTablicy, nrPozycji;
				cout << "nrTablicy: ";
				cin >> nrTablicy;
				if (nrTablicy >= 0 && nrTablicy < isSize)
				{
					cout << "nrPozycji: ";
					cin >> nrPozycji;
					cout << "Wartosc danej tablicy: " << getValue(c_Tab, nrTablicy, nrPozycji);
				}
				else
					cout << "Nie mam takiego pola tablicy. Sprobuj ponownie.";

			}
			else if (sDef == "setName")
			{
				int nrTablicy;
				string nazwaTablicy;
				cout << "nrTablicy: ";
				cin >> nrTablicy;
				if (nrTablicy >= 0 && nrTablicy < isSize)
				{
					cout << "nazwaTablicy: ";
					cin >> nazwaTablicy;
					setName(c_Tab, nrTablicy, nazwaTablicy);
				}
				else
					cout << "Nie mam takiego pola tablicy. Sprobuj ponownie.";
			}
			else if (sDef == "getName")
			{
				int nrTablicy;
				cout << "nrTablicy: ";
				cin >> nrTablicy;
				if (nrTablicy >= 0 && nrTablicy < isSize)
				{
					cout << "Nazwa danej tablicy: " << getName(c_Tab, nrTablicy) << endl;
				}
				else
					cout << "Nie mam takiego pola tablicy. Sprobuj ponownie.";

			}
			else if (sDef == "info")
			{
				int nrTablicy;
				cout << "nrTablicy: ";
				cin >> nrTablicy;
				if (nrTablicy >= 0 && nrTablicy < isSize)
				{
					cout << "Informacje o danej tablicy: " << info(c_Tab, nrTablicy) << endl;
				}
				else
					cout << "Nie mam takiego pola tablicy. Sprobuj ponownie.";

			}
			else if (sDef == "deleteObject")
			{
				int nrTablicy;
				cout << "nrTablicy: ";
				cin >> nrTablicy;
				if (nrTablicy >= 0 && nrTablicy < isSize)
				{
					cout << deleteObject(c_Tab, nrTablicy) << endl;
				}
				else
					cout << "Nie mam takiego pola tablicy. Sprobuj ponownie.";
			}
			else if (sDef == "clear")
			{
				int nrTablicy;
				cout << "nrTablicy: ";
				cin >> nrTablicy;
				if (nrTablicy >= 0 && nrTablicy < isSize)
				{

					cout << clear(c_Tab, nrTablicy) << endl;
				}
				else
					cout << "Nie mam takiego pola tablicy. Sprobuj ponownie.";
			}
			else if (sDef == "setSize")
			{
				int nrTablicy;
				int tabSize;
				cout << "nrTablicy: ";
				cin >> nrTablicy;
				if (nrTablicy >= 0 && nrTablicy < isSize)
				{
					cout << "tabSize: ";
					cin >> tabSize;
					cout << setSize(c_Tab, nrTablicy, tabSize) << endl;
				}
				else
					cout << "Nie mam takiego pola tablicy. Sprobuj ponownie.";
			}
			else if (sDef == "end")
			{
				end = true;
			}
			else
				cout << "Nieznana komenda. Sprobuj ponownie.";
		}

		delete[]c_Tab;
		cin.get();
		getchar();
		return(0);
	}



