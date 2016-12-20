// ZMPO_4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "CTableTemplate.h"

	class Person
	{
	 
		string* _name;
		int _age;
		
	//Person(){}
	public:
	 Person(string name, int age)
	{
		_name = new string(name);
		_age = age;
		cout << "Nameeee of person: " + *_name
			<< endl;
	}
	 ~Person() { delete _name; }
	 string getName() { return *_name; }
	 int getAge() { return _age; }
	 Person & operator = (Person &pcOther)
	 {
		 delete _name;
		 _name = new string (pcOther.getName());
		 _age = pcOther._age;
		cout << "porownania" << endl;
		 return (*this);

	 }
	 Person(Person & pcOther)
	 {
		 _name = new string(pcOther.getName());
		 _age = pcOther._age;
	 	 cout << "kopiujacy osoba "+ pcOther.getName() << endl;
	 }
	};
	
	int main()
	{
		int isSize=NULL;// = 3;
		string sDef;
		bool end = false;
		bool *taken = new bool[isSize];
		for (int i=0; i<isSize; i++)
		{
			taken[i] = false;
		}
		cout << "Ile obiektow klasy CTable chcesz utworzyc?" << endl;
		cin >> isSize;
		
		CTable<Person> **c_TabP = new CTable<Person>*[3];
		Person p1 ("laura", 18);
		Person p2("dominik", 22);
		cout << p1.getName()<<endl;
		c_TabP[1] = new CTable<Person>(10, "pierwsza");
		c_TabP[1]->vAssignData(5, p1);
		cout << c_TabP[1]->DataGetData(5).getName();
		(c_TabP[2])=new CTable<Person>(*c_TabP[1]);
		cout << "new name " << endl;;
		cout << c_TabP[2]->sGetName();
		cout << (c_TabP[2]->DataGetData(5)).getAge() << endl;;
		cout << (c_TabP[2]->DataGetData(5)).getName() << endl;;
		cout << (c_TabP[2]->DataGetData(5)).getName() << endl;;
		c_TabP[2]->vSetTabSize(20);
		cout << c_TabP[2]->iGetSize() << endl;;
		c_TabP[2]->vAssignData(15, p2);
		cout << (c_TabP[2]->DataGetData(15)).getAge() << endl;;
		cout << (c_TabP[2]->DataGetData(5)).getAge() << endl;;
		cout << c_TabP[2]->iGetSize() << endl;
		cin.get(); 	cin.get();
		c_TabP[1]->clear();
		cin.get(); 	cin.get();
		try
		{
			(c_TabP[1]->DataGetData(5));
		}
		catch(out_of_range)
		{
			cout << "thats the problem, why couldnt just tell me where do you have problem????" << endl;
		}

		cin.get(); 	cin.get();
		CTable<int> **c_Tab = new CTable<int>*[isSize];
		while (end != true)
		{
			cout << "Podaj komende: " << endl;
			cin >> sDef;
			if (sDef == "createDef")
			{
				int nrTablicy;
				cout << "NrTablicy: ";
				cin >> nrTablicy;
				if (nrTablicy >= 0 && nrTablicy < isSize && taken[nrTablicy]!=true)
				{
					createDef(c_Tab, nrTablicy);
					taken[nrTablicy] = true;
				}
				else
					cout << "Nie mam takiego pola tablicy lub zajete. Sprobuj ponownie.";

			}
			else if (sDef == "create")
			{
				int nrTablicy, rozmiar;
				string nazwaTablicy;
				cout << "nrTablicy: ";
				cin >> nrTablicy;
				if (nrTablicy >= 0 && nrTablicy < isSize&& taken[nrTablicy] != true)
				{
					cout << "rozmiarTablicy: ";
					cin >> rozmiar;
					cout << "nazwaTablicy: " << endl;
					cin >> nazwaTablicy;
					create(c_Tab, nrTablicy, rozmiar, nazwaTablicy);
				}
				else
					cout << "Nie mam takiego pola tablicy lub jest zajete. Sprobuj ponownie.";
			}
			else if (sDef == "createCopy")
			{
				int nrTablicy, nrTablicyDoKopiowania;
				cout << "nrTablicy: ";
				cin >> nrTablicy;
				if (nrTablicy >= 0 && nrTablicy < isSize&& taken[nrTablicy] != true)
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
					cout << "Nie mam takiego pola tablicy lub nie jest zajete. Sprobuj ponownie.";

			}
			else if (sDef == "setValue")
			{
				int nrTablicy, nrPozycji, wartosc;
				cout << "nrTablicy: ";
				cin >> nrTablicy;
				if (nrTablicy >= 0 && nrTablicy < isSize&& taken[nrTablicy] != false)
				{
					cout << "nrPozycji: ";
					cin >> nrPozycji;
					cout << "wartosc: ";
					cin >> wartosc;
					setValue(c_Tab, nrTablicy, nrPozycji, wartosc);

				}
				else
					cout << "Nie mam takiego pola tablicy lub jest puste. Sprobuj ponownie.";

			}
			else if (sDef == "getValue")
			{
				int nrTablicy, nrPozycji;
				cout << "nrTablicy: ";
				cin >> nrTablicy;
				if (nrTablicy >= 0 && nrTablicy < isSize&& taken[nrTablicy] != false)
				{
					cout << "nrPozycji: ";
					cin >> nrPozycji;
					cout << "Wartosc danej tablicy: " << getValue(c_Tab, nrTablicy, nrPozycji);
				}
				else
					cout << "Nie mam takiego pola tablicy lub nie jest zajete. Sprobuj ponownie.";

			}
			else if (sDef == "setName")
			{
				int nrTablicy;
				string nazwaTablicy;
				cout << "nrTablicy: ";
				cin >> nrTablicy;
				if (nrTablicy >= 0 && nrTablicy < isSize && taken[nrTablicy] != false)
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
				if (nrTablicy >= 0 && nrTablicy < isSize && taken[nrTablicy] != false)
				{
					cout << "Nazwa danej tablicy: " << getName(c_Tab, nrTablicy) << endl;
				}
				else
					cout << "Nie mam takiego pola tablicylub jest puste. Sprobuj ponownie.";

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
				if (nrTablicy >= 0 && nrTablicy < isSize && taken[nrTablicy] != false)
				{
					cout << deleteObject(c_Tab, nrTablicy) << endl;
					taken[nrTablicy] = false;
				}
				else
					cout << "Nie mam takiego pola tablicy lub nie jest zajete . Sprobuj ponownie.";
			}
			else if (sDef == "clear")
			{
				int nrTablicy;
				cout << "nrTablicy: ";
				cin >> nrTablicy;
				if (nrTablicy >= 0 && nrTablicy < isSize && taken[nrTablicy] != false)
				{

					cout << clear(c_Tab, nrTablicy) << endl;
				}
				else
					cout << "Nie mam takiego pola tablicy lub nie jest zajete. Sprobuj ponownie.";
			}
			else if (sDef == "setSize")
			{
				int nrTablicy;
				int tabSize;
				cout << "nrTablicy: ";
				cin >> nrTablicy;
				if (nrTablicy >= 0 && nrTablicy < isSize && taken[nrTablicy] != false)
				{
					cout << "tabSize: ";
					cin >> tabSize;
					cout << setSize(c_Tab, nrTablicy, tabSize) << endl;
				}
				else
					cout << "Nie mam takiego pola tablicy lub nie jest zajete. Sprobuj ponownie.";
			}
			else if (sDef == "end")
			{
				end = true;
				for(int i = 0; i<isSize; i++)
				{
					if(taken[i] != false)
						delete c_Tab[i];
				}
				delete c_Tab;
			}
			else
				cout << "Nieznana komenda. Sprobuj ponownie.";
		}

		delete[]c_Tab;
		cin.get();
		getchar();
		return(0);
	}



