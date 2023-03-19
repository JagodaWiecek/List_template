
#include<iostream>
#include<fstream>
#include<string>

#include "Nag³ówek.h"

using namespace std;

template<typename T>
Element<T>::Element(T Data)
{
	Element<T>::data = Data;
}
template<typename T>
void Element<T>::add(T Data)
{
	if (next == nullptr)
	{
		shared_ptr<Element<T>> d(new Element(Data));
		next = d;
	}
	else
	{
		next->add(Data);
	}
}
template<typename T>
T& Element<T>::get(unsigned int n) 
{
	if (n == 0)
		return data;
	if (next == nullptr)
		throw;
	else 
		return next->get(n - 1);
}
template<typename T>
const T& Element<T>::get(unsigned int n) const
{
	if (n == 0)
		return data;
	if (next == nullptr)
		throw;
	else
		return next->get(n - 1);
}
template<typename T>
int Element<T>::size() const
{
	if (next == nullptr)
		return 1;
	else
		return next->size() + 1;
}
template<typename T>
void Element<T>::erase(unsigned int n)
{
	if (next == nullptr)
		throw;
	else if (n == 0)
		next = next->next;
	else
		return next->erase(n - 1);
}
template<typename T>
void Element<T>::swap()
{
	std::swap(next, next->next);
}
//----------------------------------------------------------------------
template<typename T>
List<T>::List(const initializer_list<T> tab)
{
	for (T tablica : tab  )
	{
		List::add(tablica);
	}
}
template<typename T>
List<T>::List(const List& datas)
{
	int n = datas.size();
	for (int i = 0; i < n; i++) {
		List::add(datas.get(i));
	}
}
template<typename T>
List<T>::List(List&& datas)
{
	List::first = datas.first;
	datas.first.reset();
}

template<typename T>
void List<T>::add(T Data)
{
	if (first == nullptr)
	{
		shared_ptr<Element<T>> d(new Element<T>(Data));
		first = d;
	}
	else
		first->add(Data);
}
template<typename T>
T& List<T>::get(unsigned int n) 
{
	if (first == nullptr)
		throw;
	else
		return first->get(n);
}
template<typename T>
const T& List<T>::get(unsigned int n) const
{
	if (first == nullptr)
		throw;
	else
		return first->get(n);
}
template<typename T>
int List<T>::size() const
{
	if (first == nullptr)
		return 0;
	else
		return first->size();
}
template<typename T>
void List<T>::erase(unsigned int n)
{
	if (first == nullptr)
		throw;
	else if (n == 0)
		first = first->next;
	else
		return first->erase(n-1);
}
template<typename T>
void List<T>::sort()
{
	int i, j;
	for (i = 0; i < List::size(); i++) 
	{
		for (j = 0; j < List::size() - i - 1; j++)
		{

			if (first->get(j) > first->next->get(j))
			{
				swap(List::get(j), List::get(j + 1));
			}
		}
	}
	
}

template<typename T>
List<T>& List<T>::operator=(const List& other)
{
	int n = other.size();
	for (int i = 0; i < n; i++) {
		List::add(other.get(i));
	}
	return *this;
}

template<typename T>
List<T>& List<T>::operator=(List&& other)
{
	List::first = other.first;
	other.first.reset();
	return *this;
}

template<typename T>
void List<T>::serialization(const string& nazwa)
{
	ofstream plik(nazwa, ios::binary);
	if (!plik) {
		std::cout << "blad pliku" << std::endl;
		return;
	}
	auto temp = first; 
	while (temp) {
		T a = temp->data; 
		plik.write((const char*)&a, sizeof a);
		temp = temp->next;
	}
	plik.close();
}
template<typename T>
void List<T>::deserialization(const string& nazwa) {
	ifstream plik(nazwa, ios::binary);
	if (!plik) {
		std::cout << "Nie mozna otworzyc pliku" << std::endl;
		return;
	}
	T elem;
	while (plik.read((char*)(&elem), sizeof(T))) {
		this->add(elem);
	}
	plik.close();
}
//---------------------------------------------------------------
student::student(string& pesel, string& imie, string& nazwisko, string& data, string& adres, string& mieszkanie, string& miasto)
{
	student::SetPESEL(pesel);
	student::SetImie(imie);
	student::SetNazwisko(nazwisko);
	student::SetData(data);
	student::SetAdres(adres);
	student::SetNR_mieszkania(mieszkanie);
	student::SetMiasto(miasto);
}
void student::SetPESEL(const string& pesel)
{
	student::PESEL = pesel;
}
void student::SetImie(const string& imie)
{
	student::imie = imie;
}
void student::SetNazwisko(const string& nazwisko)
{
	student::nazwisko = nazwisko;
}
void student::SetData(const string& data)
{
	student::data = data;
}
void student::SetAdres(const string& adres)
{
	student::adres = adres;
}
void student::SetNR_mieszkania(const string& mieszkanie)
{
	student::nr_mieszkania = mieszkanie;
}
void student::SetMiasto(const string& miasto)
{
	student::miasto = miasto;
}
string student::GetPesel()
{
	return student::PESEL;
}
string student::GetImie()
{
	return student::imie;
}
string student::GetNazwisko()
{
	return student::nazwisko;
}
string student::GetData()
{
	return student::data;
}
string student::GetAdres()
{
	return student::adres;
}
string student::GetNR_mieszkania()
{
	return student::nr_mieszkania;
}
string student::GetMiasto()
{
	return student::miasto;
}

void student::print(ostream& out)
{
	out << GetPesel() << " \t"<<GetImie()<<"\t"<<GetNazwisko()<<"\t"<<GetData()<<"\t"<<GetAdres()<<"\t"<<GetNR_mieszkania()<<"\t"<<GetMiasto();
}
//--------------------------------------------------------
oceny::oceny(string& pesel, string& przedmiot, double& ocena, string& zadanie)
{
	oceny::SetPESEL(pesel);
	oceny::SetPrzedmiot(przedmiot);
	oceny::SetOcena(ocena);
	oceny::SetZadanie(zadanie);
}
void oceny::SetPESEL(const string& pesel)
{
	oceny::PESEL = pesel;
}
void oceny::SetPrzedmiot(const string& przedmiot)
{
	oceny::przedmiot = przedmiot;
}
void oceny::SetOcena(const double& ocena)
{
	oceny::ocena = ocena;
}
void oceny::SetZadanie(const string& zadanie)
{
	oceny::zadanie = zadanie;
}
string oceny::GetPESEL()
{
	return oceny::PESEL;
}
string oceny::GetPrzedmiot()
{
	return oceny::przedmiot;
}
double oceny::GetOcena()
{
	return oceny::ocena;
}
string oceny::GetZadanie()
{
	return oceny::zadanie;
}

void oceny::print(ostream& out)
{
	out << GetPESEL() << "\t" << GetPrzedmiot() << "\t" << GetOcena() << "\t" << GetZadanie();
}

void wpisz1(List<student>& l, string osoby)
{
	ifstream out1(osoby);
	out1.seekg(0, out1.beg);
	string pesel, imie, nazwisko, data, adres, mieszkanie, miasto;
	if (out1)
	{
		while (out1 >> pesel >> imie >> nazwisko >> data >> adres >> mieszkanie >> miasto)
		{
			student s(pesel, imie, nazwisko, data, adres, mieszkanie, miasto);
			l.add(s);
		}
	}
	else
		cout << "error\n";
	out1.close();
}
void wpisz2(List<oceny>& O, string opis)
{
	ifstream out(opis);
	out.seekg(0, out.beg);
	string pesel, przedmiot, zadanie;
	double ocena;
	if (out)
	{
		while (out >> pesel >> przedmiot >> ocena >> zadanie)
		{
			oceny d(pesel, przedmiot, ocena, zadanie);
			O.add(d);
		}
	}
	else
		cout << "error\n";
	out.close();
		
}

void ListaPrzedmiotow(List<oceny> O, List<string>& przed)
{
	for (int i = 0; i < O.size(); i++)
	{
		bool wpis = false;
		for (int j = 0; j < przed.size() && !wpis; j++)
		{
			string temp = O.get(i).GetPrzedmiot();
			if (przed.get(j) == temp)
				wpis = true;
		}
		if (!wpis)
		{
			przed.add(O.get(i).GetPrzedmiot());
		}
	}
}

double sredniaUcznia(string id,string przedmiot,List<oceny> o)
{
	int ilosc = 0;
	double suma = 0;
	for (int i = 0; i < o.size(); i++)
	{
		if (id == o.get(i).GetPESEL() && przedmiot == o.get(i).GetPrzedmiot())
		{
			suma = suma + o.get(i).GetOcena();
			ilosc++;
		}
	}

	if (ilosc == 0)
	{
		return 1;
	}
	else
	{
		double srednia = suma / ilosc;
		return srednia;
	}
}
void srednia(List<student>& s,List<oceny>& O, ofstream& in1) //do sredniej z jednego przedmiotu
{

	List<string> przed; //przedmioty jakie sa w liscie
	ListaPrzedmiotow(O, przed);
	for (int i = 0; i < s.size(); i++)
	{
		in1 << "*" << s.get(i).GetImie() << "  " << s.get(i).GetNazwisko() << "\nSrednia ocena z: \n";
		for (int j = 0; j < przed.size(); j++)
		{
			in1 << przed.get(j) << " - ";
			double sr = sredniaUcznia(s.get(i).GetPesel(), przed.get(j), O);
			in1 << sr << "\n"; //srednia ocena z konkretnego przedmiotu
		}
		in1 << "\n";
	}
}
void SredniaSzkoly(List<student>& s, List<oceny>& O, double& srednia)
{
	int ilosc = 0;
	List<string> przed; //przedmioty jakie sa w liscie
	ListaPrzedmiotow(O, przed);
	for (int i = 0; i < s.size(); i++)
	{
		
		for (int j = 0; j < przed.size(); j++){
		
			double sr = sredniaUcznia(s.get(i).GetPesel(), przed.get(j), O);
			ilosc++;
			srednia = srednia + sr;
		}
		
	}
	srednia = srednia / ilosc;

}
double SredniaUcznia(List<student>& s, List<oceny>& O,int idx) //do sredniej z jednego przedmiotu
{
	int ile = 0;
	double SR = 0;
	List<string> przed; //przedmioty jakie sa w liscie
	ListaPrzedmiotow(O, przed);
	for (int i = idx;; )
	{
		
		for (int j = 0; j < przed.size(); j++)
		{
			ile++;
			double sr = sredniaUcznia(s.get(i).GetPesel(), przed.get(j), O);
			SR = SR + sr;
		}
		return SR / ile;
	}
	
}
void sredniaOgolna(List<student>& s, List<oceny>& O, ofstream& in)
{
	double SredniaSzkolna = 0;
	double sredniaucznia = 0;
	SredniaSzkoly(s, O, SredniaSzkolna);
	in << "Srednia Szkoly : "<<SredniaSzkolna<<"\n\n";
	for (int i = 0; i < s.size(); i++)
	{
		in << s.get(i).GetPesel() << "\t" << s.get(i).GetImie() << "  " << s.get(i).GetNazwisko() << "\nSrednia ocena : ";
		sredniaucznia = SredniaUcznia(s, O, i);
		in << sredniaucznia<<"\n\n";
	}
	in << endl;

}
void IleRocznikow(List<student>& s, List<string>& Roczniki)
{
	for (int i = 0; i < s.size(); i++)
	{
		
		string temp1 = s.get(i).GetData();
		string temp2;
		for (int k = temp1.size() - 4; k < temp1.size(); k++) //zapisuje roczniki z daty
		{
			temp2.push_back(temp1[k]);
			
		}
		//cout << temp2;
		bool wpis = false;
		for (int j = 0; j< Roczniki.size() &&!wpis; j++)
		{
				if (Roczniki.get(j) == temp2)
					wpis = true;
		}
		if (!wpis)
			Roczniki.add(temp2);
	}
}
void WspolnyRok(List<student>& S, ofstream& in)
{
	List<string> Roczniki;
	IleRocznikow(S, Roczniki);
	Roczniki.sort();
	in << "*Uczniowie z rocznika: \n";
	for (int j = 0; j < Roczniki.size(); j++) 
	{
		in  <<"-" << Roczniki.get(j) << ":\n";
		for (int i = 0; i < S.size(); i++)
		{
			string temp1 = S.get(i).GetData();
			string temp2;
			for (int k = temp1.size() - 4; k < temp1.size(); k++) //zapisuje roczniki z daty
			{
				temp2.push_back(temp1[k]);

			}
			if (Roczniki.get(j) == temp2) {
				in << S.get(i).GetImie()<<"  "<<S.get(i).GetNazwisko()<<"  "<<S.get(i).GetData()<<" \n";
			}
			

		}
			in << endl;
	}
}
void Miasta(List<student>& S, List<string>& miasto)
{
	for(int i = 0; i < S.size(); i++)
	{
		bool wpis = false;
		for (int j = 0; j < miasto.size() && !wpis; j++)
		{
			string temp = S.get(i).GetMiasto();
			if (miasto.get(j) == temp)
				wpis = true;
		}
		if (!wpis)
			miasto.add(S.get(i).GetMiasto());
	}
}
void WspolnaMiasto(List<student>& S, ofstream& in)
{
	List<string> miasto;
	Miasta(S, miasto);
	in << "*Uczniowie mieszkajacy w jednym miescie: \n";
	for (int i = 0; i < miasto.size(); i++)
	{
		in <<"-" << miasto.get(i) << " : \n";
		for (int j = 0; j < S.size(); j++)
		{
			string temp = S.get(j).GetMiasto();
			if (miasto.get(i) == temp)
				in << S.get(j).GetImie() << "  " << S.get(j).GetNazwisko() << "\n";
		}
		in << endl;
	}
}
void Ulica(List<student>& S, List<string>& ulice)
{
	for (int i = 0; i < S.size(); i++)
	{
		bool wpis = false;
		for (int j = 0; j < ulice.size() && !wpis; j++)
		{
			string temp = S.get(i).GetAdres();
			if (ulice.get(j) == temp)
				wpis = true;
		}
		if (!wpis)
			ulice.add(S.get(i).GetAdres());
	}
}
void CzyUlica(List<student>& S, string Miasto,List<string>& UliceM)
{
	for (int i = 0; i < S.size(); i++)
	{
		if (S.get(i).GetMiasto()==Miasto) {
			bool wpis = false;
			for (int j = 0; j < UliceM.size(); j++)
			{
				string temp = S.get(i).GetAdres();
				if (UliceM.get(j) == temp)
					wpis = true;
			}
			if (!wpis)
				UliceM.add(S.get(i).GetAdres());
		}
	}
}
void WspolnaUlica(List<student>& S, ofstream& in)
{
	List<string> miasto;
	Miasta(S, miasto);
	in << "Uczniowie mieszkajacy w jednym miescie i na jednej ulicy: \n\n";
	for (int i = 0; i < miasto.size(); i++)
	{
		in << "*"<<miasto.get(i) << ": \n";
		List<string> Ulicem;
		CzyUlica(S, miasto.get(i), Ulicem);
		for (int j = 0; j < Ulicem.size(); j++)
		{
			in <<"-"<< Ulicem.get(j) << ": \n";
			for (int k = 0; k < S.size(); k++)
			{
				if(S.get(k).GetAdres()==Ulicem.get(j) && S.get(k).GetMiasto()==miasto.get(i))
					in<<  S.get(k).GetImie() << "  " << S.get(k).GetNazwisko() << "\n";
			}
			in << endl;
		}
		in << endl;
		
	}
}
void Wyswietlacz()
{
	cout << "Dziennik Szkolny\n1. Srednia uczniow z konkretnych przedmiotow\n2. Srednia szkoly i srednia ocen uczniow z calej ich pracy\n";
	cout << "3. Wypisz uczniow po roku urodzenia\n4. Wypisz uczniow mieszkajacych we wspolnych miastach\n5. Wypisz uczniow ktorzy mieszkaja na jednej ulicy\n";
	cout<<"Wybierz numer pliku jaki chcesz wygenerowac : ";
}
void menu(string& osoby, string& opis, string& wyj)
{
	List<student> S;
	List<oceny> O;
	wpisz1(S, osoby);
	wpisz2(O, opis);
	ofstream in(wyj);
	string numer;
	Wyswietlacz();
	cin >> numer;
	if (numer == "1")
		srednia(S, O, in);
	else if (numer == "2")
		sredniaOgolna(S, O, in);
	else if (numer == "3")
		WspolnyRok(S, in);
	else if (numer == "4")
		WspolnaMiasto(S, in);
	else if (numer == "5") 
		WspolnaUlica(S, in);
	else
		cout << "\nNie ma opcji generowania pliku z takim numerem";

}